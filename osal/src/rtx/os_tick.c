/**************************************************************************//**
 * @file     os_systick.c
 * @brief    CMSIS OS Tick SysTick implementation
 * @version  V1.0.3
 * @date     19. March 2021
 ******************************************************************************/
/*
 * Copyright (c) 2017-2021 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "os_tick.h"
#include "rtx_lib.h"

//lint -emacro((923,9078),SCB,SysTick) "cast from unsigned long to pointer"
#include DEVICE_HEADER_H

#ifdef  SysTick

#ifndef SYSTICK_IRQ_PRIORITY
#define SYSTICK_IRQ_PRIORITY    0xFFU
#endif

static uint8_t PendST __attribute__((section(".bss.os")));

// Setup OS Tick.
__WEAK int32_t OS_Tick_Setup (uint32_t freq, IRQHandler_t handler) {
  uint32_t load;
  (void)handler;

  if (freq == 0U) {
    //lint -e{904} "Return statement before end of function"
    return (-1);
  }

  load = (SystemCoreClock / freq) - 1U;
  if (load > 0x00FFFFFFU) {
    //lint -e{904} "Return statement before end of function"
    return (-1);
  }

  // Set SysTick Interrupt Priority
#if   ((defined(__ARM_ARCH_8M_MAIN__)   && (__ARM_ARCH_8M_MAIN__   != 0)) || \
       (defined(__ARM_ARCH_8_1M_MAIN__) && (__ARM_ARCH_8_1M_MAIN__ != 0)) || \
       (defined(__CORTEX_M)             && (__CORTEX_M             == 7U)))
  SCB->SHPR[11] = SYSTICK_IRQ_PRIORITY;
#elif  (defined(__ARM_ARCH_8M_BASE__)   && (__ARM_ARCH_8M_BASE__   != 0))
  SCB->SHPR[1] |= ((uint32_t)SYSTICK_IRQ_PRIORITY << 24);
#elif ((defined(__ARM_ARCH_7M__)        && (__ARM_ARCH_7M__        != 0)) || \
       (defined(__ARM_ARCH_7EM__)       && (__ARM_ARCH_7EM__       != 0)))
  SCB->SHP[11]  = SYSTICK_IRQ_PRIORITY;
#elif  (defined(__ARM_ARCH_6M__)        && (__ARM_ARCH_6M__        != 0))
  SCB->SHP[1]  |= ((uint32_t)SYSTICK_IRQ_PRIORITY << 24);
#else
#error "Unknown ARM Core!"
#endif

  SysTick->CTRL =  SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
  SysTick->LOAD =  load;
  SysTick->VAL  =  0U;

  PendST = 0U;

  return (0);
}

/// Enable OS Tick.
__WEAK void OS_Tick_Enable (void) {

  if (PendST != 0U) {
    PendST = 0U;
    SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
  }

  SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
}

/// Disable OS Tick.
__WEAK void OS_Tick_Disable (void) {

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

  if ((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) != 0U) {
    SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
    PendST = 1U;
  }
}

// Acknowledge OS Tick IRQ.
__WEAK void OS_Tick_AcknowledgeIRQ (void) {
  (void)SysTick->CTRL;
}

// Get OS Tick IRQ number.
__WEAK int32_t  OS_Tick_GetIRQn (void) {
  return ((int32_t)SysTick_IRQn);
}

// Get OS Tick clock.
__WEAK uint32_t OS_Tick_GetClock (void) {
  return (SystemCoreClock);
}

// Get OS Tick interval.
__WEAK uint32_t OS_Tick_GetInterval (void) {
  return (SysTick->LOAD + 1U);
}

// Get OS Tick count value.
__WEAK uint32_t OS_Tick_GetCount (void) {
  uint32_t load = SysTick->LOAD;
  return  (load - SysTick->VAL);
}

// Get OS Tick overflow status.
__WEAK uint32_t OS_Tick_GetOverflow (void) {
  return ((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) >> SCB_ICSR_PENDSTSET_Pos);
}

#endif  // SysTick

// OS Idle Thread
__WEAK __NO_RETURN void osRtxIdleThread (void *argument) {
  (void)argument;

  for (;;) {}
}

// OS Error Callback function
__WEAK uint32_t osRtxErrorNotify (uint32_t code, void *object_id) {
  (void)object_id;

  switch (code) {
    case osRtxErrorStackOverflow:
      // Stack overflow detected for thread (thread_id=object_id)
      break;
    case osRtxErrorISRQueueOverflow:
      // ISR Queue overflow detected when inserting object (object_id)
      break;
    case osRtxErrorTimerQueueOverflow:
      // User Timer Callback Queue overflow detected for timer (timer_id=object_id)
      break;
    case osRtxErrorClibSpace:
      // Standard C/C++ library libspace not available: increase OS_THREAD_LIBSPACE_NUM
      break;
    case osRtxErrorClibMutex:
      // Standard C/C++ library mutex initialization failed
      break;
    default:
      // Reserved
      break;
  }
  for (;;) {}
//return 0U;
}
