/*
 * COPYRIGHT (C) 2012, Real-Thread Information Technology Ltd
 * All rights reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-04-14     Grissiom     initial implementation
 */

#include "ymodem.h"

static const uint16_t ccitt_table[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};
uint16_t CRC16(unsigned char *q, int len)
{
    uint16_t crc = 0;

    while (len-- > 0)
        crc = (crc << 8) ^ ccitt_table[((crc >> 8) ^ *q++) & 0xff];
    return crc;
}

// we could only use global varible because we could not use
// device_t->user_data(it is used by the serial driver)...
static struct rym_ctx *_rym_the_ctx;

/* SOH/STX + seq + payload + crc */
#define _RYM_SOH_PKG_SZ (1+2+128+2)
#define _RYM_STX_PKG_SZ (1+2+1024+2)

static enum rym_code _rym_read_code(
        struct rym_ctx *ctx,
        uint32_t timeout)
{
    uint32_t readlen = 1;
    rte_error_t result = RTE_ERR_TIMEOUT;
    /* Fast path */
    result = hal_device_read_sync(ctx->dev_name, ctx->buf, &readlen, timeout);
    if (result == SUCCESS)
        return (enum rym_code)(*ctx->buf);
    return RYM_CODE_NONE;
}

/* the caller should at least alloc _RYM_STX_PKG_SZ buffer */
static size_t _rym_read_data(
        struct rym_ctx *ctx,
        size_t len)
{
    /* we should already have had the code */
    uint8_t *buf = ctx->buf + 1;
    uint32_t readlen = 0;
    uint32_t received_len = 0;
    rte_error_t result = RTE_ERR_TIMEOUT;
    uint32_t start_tick = rte_get_tick();
    do {
        readlen = len - received_len;
        result = hal_device_read_async(ctx->dev_name, buf + received_len, &readlen, 500);
        received_len += readlen;
        if (result != RTE_SUCCESS)
            break;
        if (received_len >= len)
            break;
    } while (rte_time_consume(start_tick) <= RYM_WAIT_CHR_TICK);
    return received_len;
}

static size_t _rym_putchar(struct rym_ctx *ctx, uint8_t code)
{
    hal_device_write_sync(ctx->dev_name, &code, sizeof(code), HAL_MAX_DELAY);
    return 1;
}

static rte_error_t _rym_do_handshake(
        struct rym_ctx *ctx,
        int count)
{
    size_t i;
    uint16_t recv_crc, cal_crc;
    size_t data_sz = 0;
    ctx->stage = RYM_STAGE_ESTABLISHING;
    /* send C every second, so the sender could know we are waiting for it. */
    for (i = 0; i < count; i++) {
        _rym_putchar(ctx, RYM_CODE_C);
        data_sz = _rym_read_data(ctx, _RYM_SOH_PKG_SZ);
        if (data_sz == _RYM_SOH_PKG_SZ)
            break;
    }

    if (i == count) {
        return -RYM_ERR_TMO;
    }

    /* sanity check */
    if (ctx->buf[2] != 0 || ctx->buf[3] != 0xFF) {
        return -RYM_ERR_SEQ;
    }

    recv_crc = (uint16_t)(*(ctx->buf + data_sz - 1) << 8) | *(ctx->buf + data_sz);
    cal_crc = CRC16(ctx->buf + 4, data_sz - 5);
    if (recv_crc != cal_crc)
        return -RYM_ERR_CRC;

    /* congratulations, check passed. */
    if (ctx->on_begin && ctx->on_begin(ctx, ctx->buf + 4, data_sz - 5) != RYM_CODE_ACK)
        return -RYM_ERR_CAN;

    return RTE_SUCCESS;
}

static rte_error_t _rym_trans_data(
        struct rym_ctx *ctx,
        size_t data_sz,
        enum rym_code *code)
{
    const size_t tsz = 2 + data_sz + 2;
    uint16_t recv_crc;

    /* seq + data + crc */
    size_t i = _rym_read_data(ctx, tsz);
    if (i != tsz)
        return -RYM_ERR_DSZ;

    if ((ctx->buf[1] + ctx->buf[2]) != 0xFF)
    {
        return -RYM_ERR_SEQ;
    }

    /* As we are sending C continuously, there is a chance that the
     * sender(remote) receive an C after sending the first handshake package.
     * So the sender will interpret it as NAK and re-send the package. So we
     * just ignore it and proceed. */
    if (ctx->stage == RYM_STAGE_ESTABLISHED && ctx->buf[1] == 0x00)
    {
        *code = RYM_CODE_NONE;
        return RTE_SUCCESS;
    }

    ctx->stage = RYM_STAGE_TRANSMITTING;

    /* sanity check */
    recv_crc = (uint16_t)(*(ctx->buf+tsz-1) << 8) | *(ctx->buf+tsz);
    if (recv_crc != CRC16(ctx->buf+3, data_sz))
        return -RYM_ERR_CRC;

    /* congratulations, check passed. */
    if (ctx->on_data)
        *code = ctx->on_data(ctx, ctx->buf+3, data_sz);
    else
        *code = RYM_CODE_ACK;
    return RTE_SUCCESS;
}

static rte_error_t _rym_do_trans(struct rym_ctx *ctx)
{
    _rym_putchar(ctx, RYM_CODE_ACK);
    _rym_putchar(ctx, RYM_CODE_C);
    ctx->stage = RYM_STAGE_ESTABLISHED;

    while (1)
    {
        rte_error_t err;
        enum rym_code code;
        size_t data_sz, i;

        code = _rym_read_code(ctx,
                RYM_WAIT_PKG_TICK);
        switch (code)
        {
        case RYM_CODE_SOH:
            data_sz = 128;
            break;
        case RYM_CODE_STX:
            data_sz = 1024;
            break;
        case RYM_CODE_EOT:
            return RTE_SUCCESS;
        default:
            return -RYM_ERR_CODE;
        };

        err = _rym_trans_data(ctx, data_sz, &code);
        if (err != RTE_SUCCESS)
            return err;
        switch (code)
        {
        case RYM_CODE_CAN:
            /* the spec require multiple CAN */
            for (i = 0; i < RYM_END_SESSION_SEND_CAN_NUM; i++) {
                _rym_putchar(ctx, RYM_CODE_CAN);
            }
            return -RYM_ERR_CAN;
        case RYM_CODE_ACK:
            _rym_putchar(ctx, RYM_CODE_ACK);
            break;
        default:
            // wrong code
            break;
        };
    }
}

static rte_error_t _rym_do_fin(struct rym_ctx *ctx)
{
    enum rym_code code;
    uint16_t recv_crc;
    size_t i;
    size_t data_sz;

    ctx->stage = RYM_STAGE_FINISHING;
    /* we already got one EOT in the caller. invoke the callback if there is
     * one. */
    if (ctx->on_end)
        ctx->on_end(ctx, ctx->buf+3, 128);

    _rym_putchar(ctx, RYM_CODE_NAK);
    code = _rym_read_code(ctx, RYM_WAIT_PKG_TICK);
    if (code != RYM_CODE_EOT)
        return -RYM_ERR_CODE;

    _rym_putchar(ctx, RYM_CODE_ACK);
    _rym_putchar(ctx, RYM_CODE_C);

    code = _rym_read_code(ctx, RYM_WAIT_PKG_TICK);
    if (code == RYM_CODE_SOH)
    {
        data_sz = _RYM_SOH_PKG_SZ;
    }
    else if(code == RYM_CODE_STX)
    {
        data_sz = _RYM_STX_PKG_SZ;
    }
    else
        return -RYM_ERR_CODE;

    i = _rym_read_data(ctx, _RYM_SOH_PKG_SZ - 1);
    if (i != (_RYM_SOH_PKG_SZ-1))
        return -RYM_ERR_DSZ;

    /* sanity check
     */
    if (ctx->buf[1] != 0 || ctx->buf[2] != 0xFF)
        return -RYM_ERR_SEQ;

    recv_crc = (uint16_t)(*(ctx->buf+_RYM_SOH_PKG_SZ-2) << 8) | *(ctx->buf+_RYM_SOH_PKG_SZ-1);
    if (recv_crc != CRC16(ctx->buf+3, _RYM_SOH_PKG_SZ-5))
        return -RYM_ERR_CRC;

    /*next file transmission*/
    if (ctx->buf[3] != 0)
    {
        if (ctx->on_begin && ctx->on_begin(ctx, ctx->buf+3, data_sz-5) != RYM_CODE_ACK)
            return -RYM_ERR_CAN;
        return RTE_SUCCESS;
    }

    /* congratulations, check passed. */
    ctx->stage = RYM_STAGE_FINISHED;

    /* put the last ACK */
    _rym_putchar(ctx, RYM_CODE_ACK);

    return RTE_SUCCESS;
}

static rte_error_t _rym_do_recv(
        struct rym_ctx *ctx,
        int handshake_count)
{
    rte_error_t err;

    ctx->stage = RYM_STAGE_NONE;

    ctx->buf = rte_calloc(_RYM_STX_PKG_SZ);
    if (ctx->buf == NULL)
        return RTE_ERR_NO_MEM;
    RTE_LOGI("start handshake, plz use ymodem to send file!");
    err = _rym_do_handshake(ctx, handshake_count);
    if (err != RTE_SUCCESS) {
        RTE_LOGE("handshake error: %d", err);
        return err;
    }
    while (1) {
        err = _rym_do_trans(ctx);
        if (err != RTE_SUCCESS)
            return err;

        err = _rym_do_fin(ctx);
        if (err != RTE_SUCCESS)
            return err;
        if (ctx->stage == RYM_STAGE_FINISHED)
            break;
    }
    return err;
}

rte_error_t rym_recv_on_device(
        struct rym_ctx *ctx,
        char *dev_name,
        rym_callback on_begin,
        rym_callback on_data,
        rym_callback on_end,
        int handshake_count)
{
    rte_error_t res;
    uint16_t odev_flag;
    int int_lvl;

    RTE_ASSERT(_rym_the_ctx == 0);
    _rym_the_ctx = ctx;

    ctx->on_begin = on_begin;
    ctx->on_data  = on_data;
    ctx->on_end   = on_end;
    ctx->dev_name      = dev_name;
    res = _rym_do_recv(ctx, handshake_count);
    return res;
}
