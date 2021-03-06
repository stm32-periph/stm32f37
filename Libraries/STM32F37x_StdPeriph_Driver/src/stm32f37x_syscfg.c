/**
  ******************************************************************************
  * @file    stm32f37x_syscfg.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the SYSCFG peripheral:
  *           + Remapping the memory mapped at 0x00000000  
  *           + Remapping the DMA channels
  *           + Enabling I2C fast mode plus driving capability for I2C pins   
  *           + Configuring the EXTI lines connection to the GPIO port
  *           + Configuring the CLASSB requirements
  *   
  *  @verbatim
 ===============================================================================
                     ##### How to use this driver #####
 ===============================================================================
    [..]
  
               The SYSCFG registers can be accessed only when the SYSCFG 
               interface APB clock is enabled.
               To enable SYSCFG APB clock use:
               RCC_APB2PeriphClockCmd(RCC_APBPeriph_SYSCFG, ENABLE).
  *  @endverbatim
  *
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f37x_syscfg.h"

/** @addtogroup STM32F37x_StdPeriph_Driver
  * @{
  */

/** @defgroup SYSCFG 
  * @brief SYSCFG driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Reset value od SYSCFG_CFGR1 register */
#define CFGR1_CLEAR_MASK            ((uint32_t)0x7C000000)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SYSCFG_Private_Functions
  * @{
  */ 

/** @defgroup SYSCFG_Group1 SYSCFG Initialization and Configuration functions
 *  @brief   SYSCFG Initialization and Configuration functions 
 *
@verbatim
 ===============================================================================
        ##### SYSCFG Initialization and Configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes the SYSCFG registers to their default reset values.
  * @param  None
  * @retval None
  * @note   MEM_MODE bits are not affected by APB reset.
  * @note   MEM_MODE bits took the value from the user option bytes.
  * @note   CFGR2 register is not affected by APB reset.
  * @note   CLASSB configuration bits are locked when set.
  * @note   To unlock the configuration, perform a system reset.
  */
void SYSCFG_DeInit(void)
{
  /* Set SYSCFG_CFGR1 register to reset value without affecting MEM_MODE bits */
  SYSCFG->CFGR1 &= SYSCFG_CFGR1_MEM_MODE;

  /* Set FPU Interrupt Enable bits to default value */
  SYSCFG->CFGR1 |= 0x7C000000;

  /* Set EXTICRx registers to reset value */
  SYSCFG->EXTICR[0] = 0;
  SYSCFG->EXTICR[1] = 0;
  SYSCFG->EXTICR[2] = 0;
  SYSCFG->EXTICR[3] = 0;

  /* Set CFGR2 register to reset value */
  SYSCFG->CFGR2 = 0;
}

/**
  * @brief  Configures the memory mapping at address 0x00000000.
  * @param  SYSCFG_MemoryRemap: selects the memory remapping.
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_MemoryRemap_Flash: Main Flash memory mapped at 0x00000000  
  *            @arg SYSCFG_MemoryRemap_SystemMemory: System Flash memory mapped at 0x00000000
  *            @arg SYSCFG_MemoryRemap_SRAM: Embedded SRAM mapped at 0x00000000
  * @retval None
  */
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap)
{
  uint32_t tmpctrl = 0;

  /* Check the parameter */
  assert_param(IS_SYSCFG_MEMORY_REMAP(SYSCFG_MemoryRemap));

  /* Get CFGR1 register value */
  tmpctrl = SYSCFG->CFGR1;

  /* Clear MEM_MODE bits */
  tmpctrl &= (uint32_t) (~SYSCFG_CFGR1_MEM_MODE);

  /* Set the new MEM_MODE bits value */
  tmpctrl |= (uint32_t) SYSCFG_MemoryRemap;

  /* Set CFGR1 register with the new memory remap configuration */
  SYSCFG->CFGR1 = tmpctrl;
}

/**
  * @brief  Configure the DMA channels remapping.
  * @param  SYSCFG_DMARemap: selects the DMA channels remap.
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_DMARemap_TIM17: Remap TIM17 DMA1 requests from channel1 to channel2
  *            @arg SYSCFG_DMARemap_TIM16: Remap TIM16 DMA1 requests from channel3 to channel4
  *            @arg SYSCFG_DMARemap_TIM6DAC1Ch1: Remap TIM6/DAC1 channel1 DMA requests from DMA2 channel 3 to DMA1 channel 3
  *            @arg SYSCFG_DMARemap_TIM7DAC1Ch2: Remap TIM7/DAC1 channel2 DMA requests from DMA2 channel 4 to DMA1 channel 4
  *            @arg SYSCFG_DMARemap_TIM18DAC2Ch1: Remap TIM18/DAC2 channel1 DMA requests from DMA2 channel 5 to DMA1 channel 5
  * @param  NewState: new state of the DMA channel remapping. 
  *         This parameter can be: ENABLE or DISABLE.
  * @note   When enabled, DMA channel of the selected peripheral is remapped
  * @note   When disabled, Default DMA channel is mapped to the selected peripheral
  * @note   By default TIM17 DMA requests is mapped to channel 1, 
  *         use SYSCFG_DMAChannelRemapConfig(SYSCFG_DMARemap_TIM17, Enable) to remap
  *         TIM17 DMA requests to channel 2 and use
  *         SYSCFG_DMAChannelRemapConfig(SYSCFG_DMARemap_TIM17, Disable) to map
  *         TIM17 DMA requests to channel 1 (default mapping)
  * @retval None
  */
void SYSCFG_DMAChannelRemapConfig(uint32_t SYSCFG_DMARemap, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_DMA_REMAP(SYSCFG_DMARemap));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Remap the DMA channel */
    SYSCFG->CFGR1 |= (uint32_t)SYSCFG_DMARemap;
  }
  else
  {
    /* use the default DMA channel mapping */
    SYSCFG->CFGR1 &= (uint32_t)(~SYSCFG_DMARemap);
  }
}

/**
  * @brief  Configure the I2C fast mode plus driving capability.
  * @param  SYSCFG_I2CFastModePlus: selects the pin.
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_I2CFastModePlus_PB6: Configure fast mode plus driving capability for PB6
  *            @arg SYSCFG_I2CFastModePlus_PB7: Configure fast mode plus driving capability for PB7
  *            @arg SYSCFG_I2CFastModePlus_PB8: Configure fast mode plus driving capability for PB8
  *            @arg SYSCFG_I2CFastModePlus_PB9: Configure fast mode plus driving capability for PB9
  *            @arg SYSCFG_I2CFastModePlus_I2C1: Configure fast mode plus driving capability for I2C1 pins
  *            @arg SYSCFG_I2CFastModePlus_I2C2: Configure fast mode plus driving capability for I2C2 pins
  * @param  NewState: new state of the DMA channel remapping. 
  *         This parameter can be: ENABLE or DISABLE.
  * @note   ENABLE: Enable fast mode plus driving capability for selected I2C pin
  * @note   DISABLE: Disable fast mode plus driving capability for selected I2C pin
  * @note  For I2C1, fast mode plus driving capability can be enabled on all selected
  *        I2C1 pins using SYSCFG_I2CFastModePlus_I2C1 parameter or independently
  *        on each one of the following pins PB6, PB7, PB8 and PB9.
  * @note  For remaining I2C1 pins (PA14, PA15...) fast mode plus driving capability
  *        can be enabled only by using SYSCFG_I2CFastModePlus_I2C1 parameter
  *        For all I2C2 pins fast mode plus driving capability can be enabled
  *        only by using SYSCFG_I2CFastModePlus_I2C2 parameter
  * @retval None
  */
void SYSCFG_I2CFastModePlusConfig(uint32_t SYSCFG_I2CFastModePlus, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_I2C_FMP(SYSCFG_I2CFastModePlus));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable fast mode plus driving capability for selected I2C pin */
    SYSCFG->CFGR1 |= (uint32_t)SYSCFG_I2CFastModePlus;
  }
  else
  {
    /* Disable fast mode plus driving capability for selected I2C pin */
    SYSCFG->CFGR1 &= (uint32_t)(~SYSCFG_I2CFastModePlus);
  }
}

/**
  * @brief Control the VBAT monitoring
  * @param  NewState: new state of the VBAT connection to ADC channel 18. 
  *         This parameter can be: ENABLE or DISABLE.
  * @note   ENABLE: Enable VBAT monitoring by connecting internally VBAT to ADC channel 18
  * @note   DISABLE: Disable VBAT monitoring by disconnecting VBAT from ADC channel 18
  * @retval None
  */
void SYSCFG_VBATMonitoringCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable VBAT monitoring */
    SYSCFG->CFGR1 |= SYSCFG_CFGR1_VBAT;
  }
  else
  {
    /* Disable VBAT monitoring */
    SYSCFG->CFGR1 &= ((uint32_t)~SYSCFG_CFGR1_VBAT);
  }
}

/**
  * @brief  Enables or disables the selected SYSCFG interrupts.
  * @param  SYSCFG_IT: specifies the SYSCFG interrupt sources to be enabled or disabled.
  *          This parameter can be one of the following values:
  *           @arg SYSCFG_IT_IXC: Inexact Interrupt
  *           @arg SYSCFG_IT_IDC: Input denormal Interrupt
  *           @arg SYSCFG_IT_OFC: Overflow Interrupt
  *           @arg SYSCFG_IT_UFC: Underflow Interrupt
  *           @arg SYSCFG_IT_DZC: Divide-by-zero Interrupt
  *           @arg SYSCFG_IT_IOC: Invalid operation Interrupt
  * @param  NewState: new state of the specified SDADC interrupts.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SYSCFG_ITConfig(uint32_t SYSCFG_IT, FunctionalState NewState)  
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_SYSCFG_IT(SYSCFG_IT)); 

  if (NewState != DISABLE)
  {
    /* Enable the selected SYSCFG interrupts */
    SYSCFG->CFGR1 |= SYSCFG_IT;
  }
  else
  {
    /* Disable the selected SYSCFG interrupts */
    SYSCFG->CFGR1 &= ((uint32_t)~SYSCFG_IT);
  }
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  EXTI_PortSourceGPIOx: selects the GPIO port to be used as source 
  *                               for EXTI lines where x can be (A, B, C, D, E or F).
  * @param  EXTI_PinSourcex: specifies the EXTI line to be configured.
  *          This parameter can be EXTI_PinSourcex where x can be (0..15)
  * @retval None
  */
void SYSCFG_EXTILineConfig(uint8_t EXTI_PortSourceGPIOx, uint8_t EXTI_PinSourcex)
{
  uint32_t tmp = 0x00;

  /* Check the parameters */
  assert_param(IS_EXTI_PORT_SOURCE(EXTI_PortSourceGPIOx));
  assert_param(IS_EXTI_PIN_SOURCE(EXTI_PinSourcex));
  
  tmp = ((uint32_t)0x0F) << (0x04 * (EXTI_PinSourcex & (uint8_t)0x03));
  SYSCFG->EXTICR[EXTI_PinSourcex >> 0x02] &= ~tmp;
  SYSCFG->EXTICR[EXTI_PinSourcex >> 0x02] |= (((uint32_t)EXTI_PortSourceGPIOx) << (0x04 * (EXTI_PinSourcex & (uint8_t)0x03)));
}

/**
  * @brief  Connect the selected parameter to the break input of TIM15/TIM16/TIM17.
  * @note   The selected configuration is locked and can be unlocked by system reset
  * @param  SYSCFG_Break: selects the configuration to be connected to break
  *         input of TIM15/TIM16/TIM17
  *          This parameter can be any combination of the following values:
  *            @arg SYSCFG_Break_PVD: Connects the PVD event to the Break Input of TIM15/TIM16/TIM17.
  *            @arg SYSCFG_Break_SRAMParity: Connects the SRAM_PARITY error signal to the Break Input of TIM15/TIM16/TIM17 .
  *            @arg SYSCFG_Break_Lockup: Connects Lockup output of CortexM4 to the break input of TIM15/TIM16/TIM17.
  * @retval None
  */
void SYSCFG_BreakConfig(uint32_t SYSCFG_Break)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_LOCK_CONFIG(SYSCFG_Break));

  SYSCFG->CFGR2 |= (uint32_t) SYSCFG_Break;
}

/**
  * @brief  Checks whether the specified SYSCFG flag is set or not.
  * @param  SYSCFG_Flag: specifies the SYSCFG flag to check. 
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_FLAG_PE: SRAM parity error flag.
  * @retval The new state of SYSCFG_Flag (SET or RESET).
  */
FlagStatus SYSCFG_GetFlagStatus(uint32_t SYSCFG_Flag)
{
  FlagStatus bitstatus = RESET;

  /* Check the parameter */
  assert_param(IS_SYSCFG_FLAG(SYSCFG_Flag));

  /* Check the status of the specified SPI flag */
  if ((SYSCFG->CFGR2 & SYSCFG_CFGR2_SRAM_PE) != (uint32_t)RESET)
  {
    /* SYSCFG_Flag is set */
    bitstatus = SET;
  }
  else
  {
    /* SYSCFG_Flag is reset */
    bitstatus = RESET;
  }
  /* Return the SYSCFG_Flag status */
  return  bitstatus;
}

/**
  * @brief  Clear the selected SYSCFG flag.
  * @param  SYSCFG_Flag: selects the flag to be cleared.
  *          This parameter can be any combination of the following values:
  *            @arg SYSCFG_FLAG_PE: SRAM parity error flag.
  * @retval None
  */
void SYSCFG_ClearFlag(uint32_t SYSCFG_Flag)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_FLAG(SYSCFG_Flag));

  SYSCFG->CFGR2 |= (uint32_t) SYSCFG_Flag;
}

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

