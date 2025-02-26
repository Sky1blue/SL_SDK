/**
 * @file mouse.h
 *
 */

#ifndef MOUSE_H
#define MOUSE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#define USE_MOUSE           1

#if USE_MOUSE

#include "lvgl.h"

#ifndef MONITOR_SDL_INCLUDE_PATH
#define MONITOR_SDL_INCLUDE_PATH <SDL.h>
#endif

#include MONITOR_SDL_INCLUDE_PATH

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the mouse
 */
void mouse_init(void);

/**
 * Get the current position and state of the mouse
 * @param indev_drv pointer to the related input device driver
 * @param data store the mouse data here
 */
void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

/**
 * It will be called from the main SDL thread
 */
void mouse_handler(SDL_Event *event);

/**********************
 *      MACROS
 **********************/

#endif /* USE_MOUSE */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MOUSE_H */
