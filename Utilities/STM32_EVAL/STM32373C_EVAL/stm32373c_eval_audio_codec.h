/**
  ******************************************************************************
  * @file    stm32373c_eval_audio_codec.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   This file contains all the functions prototypes for the 
  *          stm32373c_eval_audio_codec.c driver.
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
#ifndef __STM32373C_EVAL_AUDIOCODEC_H
#define __STM32373C_EVAL_AUDIOCODEC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32373c_eval.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM32373C_EVAL
  * @{
  */
    
/** @defgroup STM32373C_EVAL_AUDIO_CODEC 
  * @{
  */    


/** @defgroup STM32373C_EVAL_AUDIO_CODEC_Exported_Types
  * @{
  */
  
/**
  * @}
  */

/** @defgroup STM32373C_EVAL_AUDIO_CODEC_Exported_Constants
  * @{
  */ 

/*----------------------------------------------------------------------------
             CONFIGURATION: Audio Codec Driver Configuration parameters
  ----------------------------------------------------------------------------*/
/* Audio Transfer mode (DMA, Interrupt or Polling) */
#define AUDIO_MAL_MODE_NORMAL         /* Uncomment this line to enable the audio 
                                         Transfer using DMA */
/* #define AUDIO_MAL_MODE_CIRCULAR */ /* Uncomment this line to enable the audio 
                                         Transfer using DMA */

/* For the DMA modes select the interrupt that will be used */
#define AUDIO_MAL_DMA_IT_TC_EN   /* Uncomment this line to enable DMA Transfer Complete interrupt */
/* #define AUDIO_MAL_DMA_IT_HT_EN */  /* Uncomment this line to enable DMA Half Transfer Complete interrupt */
/* #define AUDIO_MAL_DMA_IT_TE_EN */  /* Uncomment this line to enable DMA Transfer Error interrupt */

/* Select the interrupt preemption priority and subpriority for the DMA interrupt */
#define EVAL_AUDIO_IRQ_PREPRIO           0   /* Select the preemption priority level(0 is the highest) */
#define EVAL_AUDIO_IRQ_SUBRIO            0   /* Select the sub-priority level (0 is the highest) */

/* Uncomment the following line to use the default Codec_TIMEOUT_UserCallback() 
   function implemented in stm32373c_eval_audio_codec.c file.
   Codec_TIMEOUT_UserCallback() function is called whenever a timeout condition 
   occurs during communication (waiting on an event that doesn't occur, bus 
   errors, busy devices ...). */   
/* #define USE_DEFAULT_TIMEOUT_CALLBACK */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
                    OPTIONAL Configuration defines parameters
  ----------------------------------------------------------------------------*/
/* I2C clock speed configuration (in Hz) 
  WARNING: 
   Make sure that this define is not already declared in other files (ie. 
  stm32373c_eval.h file). It can be used in parallel by other modules. */

/* I2C TIMING Register define when I2C clock source is SYSCLK */
/* set TIMING to 0xC062121F to reach 100 KHz speed (Rise time = 640ns, Fall time = 20ns) */

#define CODEC_I2C_TIMING             0xC062121F

/* Uncomment defines below to select standard for audio communication between 
  Codec and I2S peripheral */
#define I2S_STANDARD_PHILLIPS
/* #define I2S_STANDARD_MSB */
/* #define I2S_STANDARD_LSB */

/* Uncomment the defines below to select if the Master clock mode should be 
  enabled or not */
#define CODEC_MCLK_ENABLED
/* #deine CODEC_MCLK_DISABLED */

/* Uncomment this line to enable verifying data sent to codec after each write 
  operation */
#define VERIFY_WRITTENDATA 
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
                    Hardware Configuration defines parameters
  ----------------------------------------------------------------------------*/
/* Audio Reset Pin definition */
#define AUDIO_RESET_GPIO_CLK           RCC_AHBPeriph_GPIOD
#define AUDIO_RESET_PIN                GPIO_Pin_11
#define AUDIO_RESET_GPIO               GPIOD

/* I2S peripheral configuration defines */
#define CODEC_I2S                      SPI1
#define CODEC_I2S_CLK                  RCC_APB2Periph_SPI1
#define CODEC_I2S_ADDRESS              0x4001300C
#define CODEC_I2S_GPIO_AF              GPIO_AF_5
#define CODEC_I2S_IRQ                  SPI1_IRQn
#define CODEC_I2S_GPIO_CLOCK           (RCC_AHBPeriph_GPIOC)
#define CODEC_I2S_WS_PIN               GPIO_Pin_6
#define CODEC_I2S_SCK_PIN              GPIO_Pin_7
#define CODEC_I2S_SD_PIN               GPIO_Pin_9
#define CODEC_I2S_MCK_PIN              GPIO_Pin_8
#define CODEC_I2S_WS_PINSRC            GPIO_PinSource6
#define CODEC_I2S_SCK_PINSRC           GPIO_PinSource7
#define CODEC_I2S_SD_PINSRC            GPIO_PinSource9
#define CODEC_I2S_MCK_PINSRC           GPIO_PinSource8
#define CODEC_I2S_GPIO                 GPIOC
#define CODEC_I2S_MCK_GPIO             GPIOC

 /* I2S DMA channel definitions */
#define AUDIO_MAL_DMA_CLOCK            RCC_AHBPeriph_DMA1
#define AUDIO_MAL_DMA_CHANNEL          DMA1_Channel3
#define AUDIO_MAL_DMA_IRQ              DMA1_Channel3_IRQn
#define AUDIO_MAL_DMA_FLAG_TC          DMA1_FLAG_TC3
#define AUDIO_MAL_DMA_FLAG_HT          DMA1_FLAG_HT3
#define AUDIO_MAL_DMA_FLAG_TE          DMA1_FLAG_TE3

#define Audio_MAL_IRQHandler           DMA1_Channel3_IRQHandler
#define AUDIO_MAL_DMA_PERIPH_DATA_SIZE DMA_PeripheralDataSize_HalfWord
#define AUDIO_MAL_DMA_MEM_DATA_SIZE    DMA_MemoryDataSize_HalfWord
#define DMA_MAX_SZE                    0xFFFF

/* I2C peripheral configuration defines (control interface of the audio codec) */
#define CODEC_I2C                      I2C2
#define CODEC_I2C_CLK                  RCC_APB1Periph_I2C2
#define CODEC_I2C_GPIO_CLOCK           RCC_AHBPeriph_GPIOB
#define CODEC_I2C_GPIO_AF              GPIO_AF_4
#define CODEC_I2C_GPIO                 GPIOA
#define CODEC_I2C_SCL_PIN              GPIO_Pin_9
#define CODEC_I2C_SDA_PIN              GPIO_Pin_10
#define CODEC_I2S_SCL_PINSRC           GPIO_PinSource9
#define CODEC_I2S_SDA_PINSRC           GPIO_PinSource10

/* Maximum Timeout values for flags and events waiting loops. These timeouts are
   not based on accurate values, they just guarantee that the application will 
   not remain stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define CODEC_FLAG_TIMEOUT             ((uint32_t)0x1000)
#define CODEC_LONG_TIMEOUT             ((uint32_t)(300 * CODEC_FLAG_TIMEOUT))
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
                        Audio Codec User defines
  ----------------------------------------------------------------------------*/
/* Codec output DEVICE */
#define OUTPUT_DEVICE_SPEAKER         1
#define OUTPUT_DEVICE_HEADPHONE       2
#define OUTPUT_DEVICE_BOTH            3
#define OUTPUT_DEVICE_AUTO            4

/* Volume Levels values */
#define DEFAULT_VOLMIN                0x00
#define DEFAULT_VOLMAX                0xFF
#define DEFAULT_VOLSTEP               0x04

#define AUDIO_PAUSE                   0
#define AUDIO_RESUME                  1

/* Codec POWER DOWN modes */
#define CODEC_PDWN_HW                 1
#define CODEC_PDWN_SW                 2

/* MUTE commands */
#define AUDIO_MUTE_ON                 1
#define AUDIO_MUTE_OFF                0
/*----------------------------------------------------------------------------*/
/**
  * @}
  */ 

/** @defgroup STM32373C_EVAL_AUDIO_CODEC_Exported_Macros
  * @{
  */ 
#define VOLUME_CONVERT(x)    ((Volume > 100)? 100:((uint8_t)((Volume * 255) / 100)))
#define DMA_MAX(x)           (((x) <= DMA_MAX_SZE)? (x):DMA_MAX_SZE)

/**
  * @}
  */ 

/** @defgroup STM32373C_EVAL_AUDIO_CODEC_Exported_Functions
  * @{
  */ 

uint32_t EVAL_AUDIO_Init(uint16_t OutputDevice, uint8_t Volume, uint32_t AudioFreq);
uint32_t EVAL_AUDIO_DeInit(void);
uint32_t EVAL_AUDIO_Play(uint16_t* pBuffer, uint32_t Size);
uint32_t EVAL_AUDIO_PauseResume(uint32_t Cmd);
uint32_t EVAL_AUDIO_Stop(uint32_t CodecPowerDown_Mode);
uint32_t EVAL_AUDIO_VolumeCtl(uint8_t Volume);
uint32_t EVAL_AUDIO_Mute(uint32_t Command);

uint32_t Codec_SwitchOutput(uint8_t Output);

/* User Callbacks: user has to implement these functions in his code if
  they are needed. -----------------------------------------------------------*/

/* This function is called when the requested data has been completely transferred.
   In Normal mode (when  the define AUDIO_MAL_MODE_NORMAL is enabled) this function
   is called at the end of the whole audio file.
   In circular mode (when  the define AUDIO_MAL_MODE_CIRCULAR is enabled) this 
   function is called at the end of the current buffer transmission. */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size);

/* This function is called when half of the requested buffer has been transferred 
   This callback is useful in Circular mode only (when AUDIO_MAL_MODE_CIRCULAR 
   define is enabled)*/
void EVAL_AUDIO_HalfTransfer_CallBack(uint32_t pBuffer, uint32_t Size);

/* This function is called when an Interrupt due to transfer error on or peripheral
   error occurs. */
void EVAL_AUDIO_Error_CallBack(void* pData);

/* Codec_TIMEOUT_UserCallback() function is called whenever a timeout condition 
   occurs during communication (waiting on an event that doesn't occur, bus 
   errors, busy devices ...) on the Codec control interface (I2C).
   You can use the default timeout callback implementation by uncommenting the 
   define USE_DEFAULT_TIMEOUT_CALLBACK in stm32373c_eval_audio_codec.h file.
   Typically the user implementation of this callback should reset I2C peripheral
   and re-initialize communication or in worst case reset all the application. */
uint32_t Codec_TIMEOUT_UserCallback(void);
void Audio_MAL_IRQHandler(void);
void Audio_MAL_Play(uint32_t Addr, uint32_t Size);
 
#endif /* __STM32373C_EVAL_AUDIOCODEC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */    


