/*
 * File      : fal_cfg.h
 * This file is part of FAL (Flash Abstraction Layer) package
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include "rte_include.h"

#ifndef FAL_MALLOC
#define FAL_MALLOC                     rte_malloc
#endif

#ifndef FAL_CALLOC
#define FAL_CALLOC                     rte_calloc
#endif

#ifndef FAL_REALLOC
#define FAL_REALLOC                    rte_realloc
#endif

#ifndef FAL_FREE
#define FAL_FREE                       rte_free
#endif

#define fal_assert                     RTE_ASSERT

/* debug level log */
#define fal_log_d(...)                     log_out(LOG_LEVEL_DEBUG, __FILE__, __func__, __LINE__, "FAL", __VA_ARGS__)

/* error level log */
#define fal_log_e(...)                     log_out(LOG_LEVEL_ERROR, __FILE__, __func__, __LINE__, "FAL", __VA_ARGS__)

/* info level log */
#define fal_log_i(...)                     log_out(LOG_LEVEL_INFO, __FILE__, __func__, __LINE__, "FAL", __VA_ARGS__)

/* FAL flash and partition device name max length */
#ifndef FAL_DEV_NAME_MAX
#define FAL_DEV_NAME_MAX 24
#endif

#define FAL_PART_HAS_TABLE_CFG
#define NOR_FLASH_DEV_NAME             "norflash0"

/* ===================== Flash device Configuration ========================= */
extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &nor_flash0,                                                     \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                               \
{                                                                                    \
    {FAL_PART_MAGIC_WROD,    "user_app",   NOR_FLASH_DEV_NAME,                           0,      2048 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD,    "fm_area",    NOR_FLASH_DEV_NAME,                 2048 * 1024,      2048 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD,    "df_area",    NOR_FLASH_DEV_NAME,                 4096 * 1024,      2048 * 1024, 0}, \
    {FAL_PART_MAGIC_WORD,    "fdb_kvdb1",  NOR_FLASH_DEV_NAME,                 6144 * 1024,        16 * 1024, 0}, \
    {FAL_PART_MAGIC_WORD,    "fdb_tsdb1",  NOR_FLASH_DEV_NAME,                 6160 * 1024,        16 * 1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
