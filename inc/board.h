/*
 * File      : board.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-09-22     Bernard      add board.h to this bsp
 */
// <<< Use Configuration Wizard in Context Menu >>>
#ifndef __BOARD_H__
#define __BOARD_H__
#include <stm32f4xx.h>
#include <stm32f4xx_hal.h>
#include <rtthread.h>

#ifdef STM32_PIN_NUMBERS
#define STM32F4XX_PIN_NUMBERS STM32_PIN_NUMBERS
#else
#define STM32F4XX_PIN_NUMBERS 64
#warning Need using this pkgs in stm32-bsp
#endif

#ifndef STM32_SRAM_SIZE
#define STM32_SRAM_SIZE 20
#warning Need using this pkgs in stm32-bsp
#endif

#define STM32_SRAM_END          (0x20000000 + STM32_SRAM_SIZE * 1024)

#ifdef __CC_ARM
    extern int Image$$RW_IRAM1$$ZI$$Limit;
    #define HEAP_BEGIN  ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
    #pragma section="HEAP"
    #define HEAP_BEGIN  (__segment_end("HEAP"))
#else
    extern int __bss_end;
    #define HEAP_BEGIN  ((void *)&__bss_end)
#endif

#define HEAP_END    STM32_SRAM_END
extern void rt_hw_board_init(void);
#endif

