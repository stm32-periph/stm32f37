/**
  ******************************************************************************
  * @file    SDADC/SDADC_TempMeasurement/main.h 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Header for main.c module
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f37x.h"
#include "stm32373c_eval.h"
#include <stdio.h>
#include "stm32373c_eval/stm32373c_eval_lcd.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Messages to be displayed on LCD */
#define MESSAGE1   "    Temperature     "
#define MESSAGE2   "  Measurement PT100 "

/* Temperature sensor PT100 is connected to PE7 which corresponds to SDADC1 channel 3:
   Refer to STM32373C-EVAL user manual for more details about how the PT100 is
   connected to PE7 */
#define PT100_GPIO_PORT        GPIOE
#define PT100_GPIO_PIN         GPIO_Pin_7
#define PT100_GPIO_CLK         RCC_AHBPeriph_GPIOE
#define PT100_SDADC            SDADC1
#define PT100_SDADC_CLK        RCC_APB2Periph_SDADC1
#define PT100_SDADC_PWR        PWR_SDADCAnalog_1
#define PT100_SDADC_VREF       SDADC_VREF_Ext /* External reference is selected */
#define PT100_SDADC_GAIN       SDADC_Gain_8   /* Internal gain 8 is seleted */
#define SDADC_GAIN             (uint32_t)8    /* SDADC internal gain is set to 8: update this define
                                                 according to PT100_SDADC_GAIN */
#define PT100_SDADC_CHANNEL    SDADC_Channel_3
#define SDADCRESOL             (uint32_t) 65535 /* 2e16 - 1 */
#define SDADC_INIT_TIMEOUT     30 /* about two SDADC clock cycles after INIT is set */
#define SDADC_CAL_TIMEOUT      4*30720 /*  ~5.12 ms at 6 MHz  in a single calibration sequence */
#define SDADC_VREF             (float) 3.3f  /* SDADC external reference is set to 3.3V: update
                                                this define according to PT100_SDADC_VREF */
#define REFERENCE_RESISTOR     (uint32_t)1800 /* Reference resistor: labeled R33 on STM32373C-EVAL */
#define RESISTANCE_ZERODEGRE   (uint32_t)100  /* PT100 resistance at 0 deg C */
#define RESISTANCE_COEFFICIENT (float)0.385f

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);

#endif /* __MAIN_H */

