#include "stm32h7xx.h"
#include "cmsis_os2.h"
#include "rte_include.h"
#include "hal_include.h"
#include "usart.h"
#include "flashdb.h"

static uint32_t boot_count = 0;
static time_t boot_time[10] = {0, 1, 2, 3};
static char default_version[] = "0.0";
static bool upgrade_status = false;

timer_impl_t *running_timer_id = 0;
/* default KV nodes */
static struct fdb_default_kv_node default_kv_table[] = {
        {"boot_count", &boot_count, sizeof(boot_count)}, /* int type KV */
        {"boot_time", &boot_time, sizeof(boot_time)},    /* int array type KV */
        {"current_version", default_version, sizeof(default_version)},
        {"upgrade_status", &upgrade_status, sizeof(upgrade_status)}
};
/* KVDB object */
struct fdb_kvdb kvdb = { 0 };
/* TSDB object */
struct fdb_tsdb tsdb = { 0 };

osThreadId_t system_thread_id;
int shell_getc(char *ch)
{
    uint32_t read_size = 1;
    if (hal_device_read_async("com_0", (uint8_t *)ch, &read_size, osWaitForever) != RTE_SUCCESS) {
        return 0;
    }
    return 1;
}

size_t rte_data_out(uint8_t *data, size_t length)
{
    hal_device_write_sync("com_0", data, length, HAL_MAX_DELAY);
    return length;
}

void start_shell(void)
{
    char input_user_name[64];
    char input_password[32];
retry:
    memset(input_user_name, 0, 64);
    memset(input_password, 0, 32);
    RTE_LOGI("plz input user name:");
    for (uint8_t i = 0; ; ) {
        uint32_t read_size = 1;
        hal_device_read_sync("com_0", (uint8_t *)input_user_name + i, &read_size, HAL_MAX_DELAY);
        i++;
        if (i >= sizeof(input_user_name) ||
            input_user_name[i - 1] == 0x0d) {
            input_user_name[i - 1] = 0;
            break;
        }
    }
    RTE_LOGI("plz input password:");
    for (uint8_t i = 0; ; ) {
        uint32_t read_size = 1;
        hal_device_read_sync("com_0", (uint8_t *)input_password + i, &read_size, HAL_MAX_DELAY);
        i++;
        if (i >= sizeof(input_password) ||
            input_password[i - 1] == 0x0d) {
            input_password[i - 1] = 0;
            break;
        }
    }
    if (strcmp("root", input_user_name) ||
        strcmp("root", input_password)) {
        RTE_LOGE("Sorry, we don't know you, you input %s %s", input_user_name, input_password);
        goto retry;
    }
    osThreadAttr_t shell_tconfig = {
        .name = "shell_task",
        .stack_size = 8192,
    };
    osThreadId_t shell_tid = osThreadNew(shell_task, NULL, &shell_tconfig);
}

static void running_timer(void *arg)
{
    gpio_toggle(GPIO_LED0);
}

__NO_RETURN void system_thread(void *argument)
{
    (void)argument;
    /* Init the rte */
    rte_init();
    /* Init all hal devices */
    hal_init();
    log_level_t log_level = LOG_LEVEL_INFO;
    log_control(LOG_CMD_SET_LEVEL, &log_level);
    log_control(LOG_CMD_SET_OUTPUT, rte_data_out);
    shell_printf("\r\r\r");
    RTE_LOGI("System boots at clk: %d", SystemCoreClock);
    /* Init all util-librarys */
    extern int fota_crc_init(void);
    fota_crc_init();
	/* partition initial */
    extern void driver_w25qxx_init(void);
    driver_w25qxx_init();
	fal_init();
	extern int fal_init_check(void);
	/* verify partition */
	fal_init_check();
#ifdef FDB_USING_KVDB
    {
        fdb_err_t result;
        /* KVDB Sample */
        struct fdb_default_kv default_kv;
        default_kv.kvs = default_kv_table;
        default_kv.num = sizeof(default_kv_table) / sizeof(default_kv_table[0]);
        /* Key-Value database initialization
        *
        *       &kvdb: database object
        *       "env": database name
        * "fdb_kvdb1": The flash partition name base on FAL. Please make sure it's in FAL partition table.
        *              Please change to YOUR partition name.
        * &default_kv: The default KV nodes. It will auto add to KVDB when first initialize successfully.
        *        NULL: The user data if you need, now is empty.
        */
        result = fdb_kvdb_init(&kvdb, "env", "user_kvdb", &default_kv, NULL);
        RTE_LOGI("flash database kvdb init result: %d", result);
        if (result == 0) {
            char *current_version = fdb_kv_get(&kvdb, "current_version");
            RTE_LOGI("current version %s", current_version ? current_version : "N/A");
            struct fdb_blob blob;
            uint32_t boot_count = 0;
            { /* GET the KV value */
                /* get the "boot_count" KV value */
                fdb_kv_get_blob(&kvdb, "boot_count", fdb_blob_make(&blob, &boot_count, sizeof(boot_count)));
                /* the blob.saved.len is more than 0 when get the value successful */
                if (blob.saved.len > 0) {
                    FDB_INFO("get the 'boot_count' value is %d", boot_count);
                } else {
                    FDB_INFO("get the 'boot_count' failed");
                }
            }

            { /* CHANGE the KV value */
                /* increase the boot count */
                boot_count ++;
                /* change the "boot_count" KV's value */
                fdb_kv_set_blob(&kvdb, "boot_count", fdb_blob_make(&blob, &boot_count, sizeof(boot_count)));
                FDB_INFO("set the 'boot_count' value to %d", boot_count);
            }
        }
    }
#endif /* FDB_USING_KVDB */
    timer_configuration_t config = TIMER_CONFIG_INITIALIZER;
    config.repeat_period_tick = 100;
    config.timer_callback = running_timer;
    timer_create_new(SUGAR_TIMER_GROUP, &config, &running_timer_id);
    bool if_upgrade_mode = false;
    for(uint8_t i = 0; i < 3; i++) {
        RTE_LOGI("press any key to go into OTA mode: %d", 3 - i);
        uint8_t data = 0;
        uint32_t read_size = 1;
        rte_error_t result = hal_device_read_sync("com_0", (uint8_t *)&data, &read_size, 1000);
        if (result == SUCCESS &&
            read_size == 1 &&
            data) {
            if_upgrade_mode = true;
            break;
        }
    }
    if (if_upgrade_mode == true) {
        start_shell();
    } else {
        osThreadAttr_t ota_tconfig = {
            .name = "ota_task",
            .stack_size = 8192,
        };
        extern __NO_RETURN void ota_thread(void *argument);
        osThreadId_t ota_tid = osThreadNew(ota_thread, NULL, &ota_tconfig);
    }
    for (;;) {
        timer_tick_handle();
        osDelay(1);
    }
}
