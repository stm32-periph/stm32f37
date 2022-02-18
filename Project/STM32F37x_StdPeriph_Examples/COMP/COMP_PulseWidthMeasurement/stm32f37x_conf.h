/**
  ******************************************************************************
  * @file    COMP/COMP_PulseWidthMeasurement/stm32f37x_conf.h 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Library configuration file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2012 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F37X_CONF_H
#define __STM32F37X_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Comment the line below to disable peripheral header file inclusion */
#include "stm32f37x_adc.h"
#include "stm32f37x_can.h"
#include "stm32f37x_cec.h"
#include "stm32f37x_crc.h"
#include "stm32f37x_comp.h"
#include "stm32f37x_dac.h"
#include "stm32f37x_dbgmcu.h"
#include "stm32f37x_dma.h"
#include "stm32f37x_exti.h"
#include "stm32f37x_flash.h"
#include "stm32f37x_gpio.h"
#include "stm32f37x_syscfg.h"
#include "stm32f37x_i2c.h"
#include "stm32f37x_iwdg.h"
#include "stm32f37x_pwr.h"
#include "stm32f37x_rcc.h"
#include "stm32f37x_rtc.h"
#include "stm32f37x_sdadc.h"
#include "stm32f37x_spi.h"
#include "stm32f37x_tim.h"
#include "stm32f37x_usart.h"
#include "stm32f37x_wwdg.h"
#include "stm32f37x_misc.h"  /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
#define USE_FULL_ASSERT    1

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __STM32F37X_CONF_H */

