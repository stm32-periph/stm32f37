/**
  ******************************************************************************
  * @file    stm32f37x_comp.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   This file contains all the functions prototypes for the COMP firmware 
  *          library.
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
#ifndef __STM32F37X_COMP_H
#define __STM32F37X_COMP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f37x.h"

/** @addtogroup STM32F37x_StdPeriph_Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief  COMP Init structure definition  
  */
  
typedef struct
{

  uint32_t COMP_InvertingInput;     /*!< Selects the inverting input of the comparator.
                                          This parameter can be a value of @ref COMP_InvertingInput */

  uint32_t COMP_Output;             /*!< Selects the output redirection of the comparator.
                                          This parameter can be a value of @ref COMP_Output */

  uint32_t COMP_OutputPol;           /*!< Selects the output polarity of the comparator.
                                          This parameter can be a value of @ref COMP_OutputPolarity */

  uint32_t COMP_Hysteresis;         /*!< Selects the hysteresis voltage of the comparator.
                                          This parameter can be a value of @ref COMP_Hysteresis */

  uint32_t COMP_Mode;               /*!< Selects the operating mode of the comparator
                                         and allows to adjust the speed/consumption.
                                          This parameter can be a value of @ref COMP_Mode */

}COMP_InitTypeDef;

/* Exported constants --------------------------------------------------------*/
   
/** @defgroup COMP_Exported_Constants
  * @{
  */ 

/** @defgroup COMP_Selection
  * @{
  */

#define COMP_Selection_COMP1                    ((uint32_t)0x00000000) /*!< COMP1 Selection */
#define COMP_Selection_COMP2                    ((uint32_t)0x00000010) /*!< COMP2 Selection */

#define IS_COMP_ALL_PERIPH(PERIPH) (((PERIPH) == COMP_Selection_COMP1) || \
                                    ((PERIPH) == COMP_Selection_COMP2))
 
/**
  * @}
  */ 

/** @defgroup COMP_InvertingInput
  * @{
  */

#define COMP_InvertingInput_1_4VREFINT          ((uint32_t)0x00000000) /*!< 1/4 VREFINT connected to comparator inverting input */
#define COMP_InvertingInput_1_2VREFINT          COMP_CSR_COMP1INSEL_0  /*!< 1/2 VREFINT connected to comparator inverting input */
#define COMP_InvertingInput_3_4VREFINT          COMP_CSR_COMP1INSEL_1  /*!< 3/4 VREFINT connected to comparator inverting input */
#define COMP_InvertingInput_VREFINT             ((uint32_t)0x00000030) /*!< VREFINT connected to comparator inverting input */
#define COMP_InvertingInput_DAC1OUT1            COMP_CSR_COMP1INSEL_2  /*!< DAC1_OUT1 (PA4) connected to comparator inverting input */
#define COMP_InvertingInput_DAC1OUT2            ((uint32_t)0x00000050) /*!< DAC1_OUT2 (PA5) connected to comparator inverting input */
#define COMP_InvertingInput_DAC2OUT1            ((uint32_t)0x00000070) /*!< DAC2_OUT1 (PA6) connected to comparator inverting input */
#define COMP_InvertingInput_IO                  ((uint32_t)0x00000060) /*!< I/O (PA0 for COMP1 and PA2 for COMP2) connected to comparator inverting input */

#define IS_COMP_INVERTING_INPUT(INPUT) (((INPUT) == COMP_InvertingInput_1_4VREFINT) || \
                                        ((INPUT) == COMP_InvertingInput_1_2VREFINT) || \
                                        ((INPUT) == COMP_InvertingInput_3_4VREFINT) || \
                                        ((INPUT) == COMP_InvertingInput_VREFINT)    || \
                                        ((INPUT) == COMP_InvertingInput_DAC1OUT1)   || \
                                        ((INPUT) == COMP_InvertingInput_DAC1OUT2)   || \
                                        ((INPUT) == COMP_InvertingInput_DAC2OUT1)   || \
                                        ((INPUT) == COMP_InvertingInput_IO))
/**
  * @}
  */ 
  
/** @defgroup COMP_Output
  * @{
  */

#define COMP_Output_None                  ((uint32_t)0x00000000) /*!< COMP output isn't connected to other peripherals */
#define COMP_Output_TIM5IC4               ((uint32_t)0x00000600) /*!< COMP output connected to TIM5 Input Capture 4 */
#define COMP_Output_TIM4IC1               ((uint32_t)0x00000200) /*!< COMP output connected to TIM4 Input Capture 1 */
#define COMP_Output_TIM5OCREFCLR          COMP_CSR_COMP1OUTSEL   /*!< COMP output connected to TIM5 OCREF Clear */
#define COMP_Output_TIM4OCREFCLR          ((uint32_t)0x00000300) /*!< COMP output connected to TIM4 OCREF Clear */
#define COMP_Output_TIM15BKIN             COMP_CSR_COMP1OUTSEL_0 /*!< COMP output connected to TIM15 Break Input (BKIN) */
#define COMP_Output_TIM16BKIN             COMP_CSR_COMP1OUTSEL_0 /*!< COMP output connected to TIM16 Break Input (BKIN) */
#define COMP_Output_TIM2IC4               COMP_CSR_COMP1OUTSEL_2 /*!< COMP output connected to TIM2 Input Capture 4 */
#define COMP_Output_TIM2OCREFCLR          ((uint32_t)0x00000500) /*!< COMP output connected to TIM2 OCREF Clear */
#define COMP_Output_TIM3IC1               ((uint32_t)0x00000600) /*!< COMP output connected to TIM3 Input Capture 1 */
#define COMP_Output_TIM3OCREFCLR          COMP_CSR_COMP1OUTSEL   /*!< COMP output connected to TIM3 OCREF Clear */


#define IS_COMP_OUTPUT(OUTPUT) (((OUTPUT) == COMP_Output_None)         || \
                                ((OUTPUT) == COMP_Output_TIM5IC4)      || \
                                ((OUTPUT) == COMP_Output_TIM4IC1)      || \
                                ((OUTPUT) == COMP_Output_TIM5OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TIM4OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TIM15BKIN)    || \
                                ((OUTPUT) == COMP_Output_TIM16BKIN)    || \
                                ((OUTPUT) == COMP_Output_TIM2IC4)      || \
                                ((OUTPUT) == COMP_Output_TIM2OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TIM3IC1)      || \
                                ((OUTPUT) == COMP_Output_TIM3OCREFCLR))
/**
  * @}
  */ 

/** @defgroup COMP_OutputPolarity
  * @{
  */
#define COMP_OutputPol_NonInverted          ((uint32_t)0x00000000)  /*!< COMP output on GPIO isn't inverted */
#define COMP_OutputPol_Inverted             COMP_CSR_COMP1POL       /*!< COMP output on GPIO is inverted */

#define IS_COMP_OUTPUT_POL(POL) (((POL) == COMP_OutputPol_NonInverted)  || \
                                 ((POL) == COMP_OutputPol_Inverted))

/**
  * @}
  */ 

/** @defgroup COMP_Hysteresis
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the hysteresis level */
#define COMP_Hysteresis_No                         0x00000000           /*!< No hysteresis */
#define COMP_Hysteresis_Low                        COMP_CSR_COMP1HYST_0 /*!< Hysteresis level low */
#define COMP_Hysteresis_Medium                     COMP_CSR_COMP1HYST_1 /*!< Hysteresis level medium */
#define COMP_Hysteresis_High                       COMP_CSR_COMP1HYST   /*!< Hysteresis level high */

#define IS_COMP_HYSTERESIS(HYSTERESIS)    (((HYSTERESIS) == COMP_Hysteresis_No) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_Low) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_Medium) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_High))
/**
  * @}
  */

/** @defgroup COMP_Mode
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the power consumption values */
#define COMP_Mode_HighSpeed                     0x00000000           /*!< High Speed */
#define COMP_Mode_MediumSpeed                   COMP_CSR_COMP1MODE_0 /*!< Medium Speed */
#define COMP_Mode_LowPower                      COMP_CSR_COMP1MODE_1 /*!< Low power mode */
#define COMP_Mode_UltraLowPower                 COMP_CSR_COMP1MODE   /*!< Ultra-low power mode */

#define IS_COMP_MODE(MODE)    (((MODE) == COMP_Mode_UltraLowPower) || \
                               ((MODE) == COMP_Mode_LowPower)      || \
                               ((MODE) == COMP_Mode_MediumSpeed)   || \
                               ((MODE) == COMP_Mode_HighSpeed))
/**
  * @}
  */

/** @defgroup COMP_OutputLevel
  * @{
  */ 
/* When output polarity is not inverted, comparator output is high when
   the non-inverting input is at a higher voltage than the inverting input */
#define COMP_OutputLevel_High                   COMP_CSR_COMP1OUT
/* When output polarity is not inverted, comparator output is low when
   the non-inverting input is at a lower voltage than the inverting input*/
#define COMP_OutputLevel_Low                    ((uint32_t)0x00000000)

/**
  * @}
  */ 

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/*  Function used to set the COMP configuration to the default reset state ****/
void COMP_DeInit(void);

/* Initialization and Configuration functions *********************************/
void COMP_Init(uint32_t COMP_Selection, COMP_InitTypeDef* COMP_InitStruct);
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct);
void COMP_Cmd(uint32_t COMP_Selection, FunctionalState NewState);
void COMP_SwitchCmd(FunctionalState NewState);
uint32_t COMP_GetOutputLevel(uint32_t COMP_Selection);

/* Window mode control function ***********************************************/
void COMP_WindowCmd(FunctionalState NewState);

/* COMP configuration locking function ****************************************/
void COMP_LockConfig(uint32_t COMP_Selection);

#ifdef __cplusplus
}
#endif

#endif /*__STM32F37X_COMP_H */

/**
  * @}
  */ 

/**
  * @}
  */

