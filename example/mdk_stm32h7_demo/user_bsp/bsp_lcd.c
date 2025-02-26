/**
 * @file bsp_lcd.c
 * @author Leon Shan (813475603@qq.com)
 * @brief LCD driver for ST7789 controller.
 * @version 1.0.0
 * @date 2021-08-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "cmsis_os2.h"
#include "bsp_lcd.h"

static void bsp_lcd_write_data(uint8_t data)
{
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
    hal_device_write_sync("spi_0", &data, 1, HAL_MAX_DELAY);
    gpio_set_high(LCD_CS);
}

static void bsp_lcd_write_ndata(uint8_t *data, uint16_t size)
{
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
    hal_device_write_sync("spi_0", data, size, HAL_MAX_DELAY);
    gpio_set_high(LCD_CS);
}

static void bsp_lcd_write_command(uint8_t command)
{
    gpio_set_low(LCD_CS);
    gpio_set_low(LCD_DC);
    hal_device_write_sync("spi_0", &command, 1, HAL_MAX_DELAY);
    gpio_set_high(LCD_CS);
}
static void bsp_lcd_set_cursor(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
	bsp_lcd_write_command(0x2A);
    x1 = __REV16(x1 + 20);
    x2 = __REV16(x2 + 20);
    y1 = __REV16(y1);
    y2 = __REV16(y2);
    bsp_lcd_write_ndata((uint8_t *)&x1, 2);
    bsp_lcd_write_ndata((uint8_t *)&x2, 2);

	bsp_lcd_write_command(0x2B);
    bsp_lcd_write_ndata((uint8_t *)&y1, 2);
    bsp_lcd_write_ndata((uint8_t *)&y2, 2);
}
void bsp_lcd_put_pixel(uint16_t x, uint16_t y, uint16_t color)
{
	bsp_lcd_set_cursor(x, y, x, y);
	bsp_lcd_write_command(0x2C);
	color = __REV16(color);
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
    hal_device_write_sync("spi_0", (uint8_t *)&color, 2, HAL_MAX_DELAY);
    gpio_set_high(LCD_CS);
}
void bsp_lcd_fill_color_slow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
	bsp_lcd_set_cursor(x0, x1, y0, y1);
	bsp_lcd_write_command(0x2C);
	color = __REV16(color);
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
    for (uint32_t i = 0; i < (x1 - x0 + 1) *(y1 - y0 + 1); i++)
        hal_device_write_sync("spi_0", (uint8_t *)&color, 2, HAL_MAX_DELAY);
    gpio_set_high(LCD_CS);
}
void bsp_lcd_fill_color_normal(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
	bsp_lcd_set_cursor(x0, x1, y0, y1);
	bsp_lcd_write_command(0x2C);
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
	uint16_t *line_buffer = memory_alloc_align(BANK_DMA, 32, (x1 - x0 + 1) * 2);
    uint32_t i = 0;
    uint32_t col = (x1 - x0 + 1);
    uint32_t row = (y1 - y0 + 1);
    uint32_t send_count = col << 1;
	for(i = 0; i < col; i++)
		line_buffer[i] = __REV16(color);
    HAL_RAM_CLEAN_PRE_SEND(line_buffer, send_count);
    for(i = 0; i < row; i++) {
        hal_device_write_async("spi_0", (uint8_t *)line_buffer, send_count, osWaitForever);
	}
	// SPI2 CS HIGH
	gpio_set_high(LCD_CS);
	memory_free(BANK_DMA, line_buffer);
}
void bsp_lcd_fill_frame(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t *color_map)
{
	bsp_lcd_set_cursor(x0, x1, y0, y1);
	bsp_lcd_write_command(0x2C);
	uint32_t size = (x1 - x0 + 1) * (y1 - y0 + 1) * 2;
    gpio_set_low(LCD_CS);
    gpio_set_high(LCD_DC);
	for(uint32_t i = 0; i < size;) {
        uint16_t send_count = (uint16_t) (size > UINT16_MAX ? UINT16_MAX : size);
        HAL_RAM_CLEAN_PRE_SEND(color_map, send_count);
        rte_error_t result = hal_device_write_async("spi_0", (uint8_t*)color_map, send_count, osWaitForever);
        if (result == RTE_SUCCESS) {
            color_map += send_count;
            i += send_count;
        } else {
            continue;
        }
	}
	// SPI2 CS HIGH
	gpio_set_high(LCD_CS);
}
void bsp_lcd_init(void)
{
    gpio_set_low(LCD_RST);
	rte_delay_ms(100);
    gpio_set_high(LCD_RST);
    rte_delay_ms(100);
    bsp_lcd_write_command(0x01);
    rte_delay_ms(50);

    bsp_lcd_write_command(0x11);
    rte_delay_ms(100);

    bsp_lcd_write_command(0x36);
    bsp_lcd_write_data(0xA0);

    bsp_lcd_write_command(0x3A);
    bsp_lcd_write_data(0x05);

    bsp_lcd_write_command(0xB2);
    bsp_lcd_write_data(0x0C);
    bsp_lcd_write_data(0x0C);
    bsp_lcd_write_data(0x00);
    bsp_lcd_write_data(0x33);
    bsp_lcd_write_data(0x33);

    bsp_lcd_write_command(0xB7);
    bsp_lcd_write_data(0x35);

    bsp_lcd_write_command(0xBB);    //VCOM Setting
    bsp_lcd_write_data(0x32);

    bsp_lcd_write_command(0xC0);    //LCM Control
    bsp_lcd_write_data(0x2C);

    bsp_lcd_write_command(0xC2);   //VDV and VRH Command Enable
    bsp_lcd_write_data(0x01);

    bsp_lcd_write_command(0xC3);  //VRH Set
    bsp_lcd_write_data(0x15);

    bsp_lcd_write_command(0xC4);  //VDV Set
    bsp_lcd_write_data(0x20);

    bsp_lcd_write_command(0xC6);
    bsp_lcd_write_data(0x0F);

    bsp_lcd_write_command(0xD0);   //Power Control
    bsp_lcd_write_data(0xA4);
    bsp_lcd_write_data(0xA1);

    bsp_lcd_write_command(0xE0);
    bsp_lcd_write_data(0xD0);
    bsp_lcd_write_data(0x04);
    bsp_lcd_write_data(0x0D);
    bsp_lcd_write_data(0x11);
    bsp_lcd_write_data(0x13);
    bsp_lcd_write_data(0x2B);
    bsp_lcd_write_data(0x3F);
    bsp_lcd_write_data(0x54);
    bsp_lcd_write_data(0x4C);
    bsp_lcd_write_data(0x18);
    bsp_lcd_write_data(0x0D);
    bsp_lcd_write_data(0x0B);
    bsp_lcd_write_data(0x1F);
    bsp_lcd_write_data(0x23);

    bsp_lcd_write_command(0xE1);
    bsp_lcd_write_data(0xD0);
    bsp_lcd_write_data(0x04);
    bsp_lcd_write_data(0x0C);
    bsp_lcd_write_data(0x11);
    bsp_lcd_write_data(0x13);
    bsp_lcd_write_data(0x2C);
    bsp_lcd_write_data(0x3F);
    bsp_lcd_write_data(0x44);
    bsp_lcd_write_data(0x51);
    bsp_lcd_write_data(0x2F);
    bsp_lcd_write_data(0x1F);
    bsp_lcd_write_data(0x1F);
    bsp_lcd_write_data(0x20);
    bsp_lcd_write_data(0x23);

    bsp_lcd_write_command(0x21);
	bsp_lcd_write_command(0x29);
    gpio_set_high(LCD_BLK);
    uint32_t start_tick = rte_get_tick_ms();
    bsp_lcd_fill_color_normal(0, 0, 239, 320, 0x1234);
    uint32_t end_tick = rte_get_tick_ms();
    RTE_LOGI("lcd fill time %d ms", end_tick - start_tick);
    uint16_t *image = memory_alloc_align(BANK_DMA, 32, 50 * 50 * sizeof(uint16_t));
    memset(image, 0x5678, 50 * 50 * sizeof(uint16_t));
    bsp_lcd_fill_frame(10, 10, 59, 59, image);
    memory_free(BANK_DMA, image);
}
