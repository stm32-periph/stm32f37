/**
  ******************************************************************************
  * @file    system_stm32f37x.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Header File.
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

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f37x_system
  * @{
  */  
  
/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_STM32F37X_H
#define __SYSTEM_STM32F37X_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup STM32F37x_System_Includes
  * @{
  */

/**
  * @}
  */


/** @addtogroup STM32F37x_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup STM32F37x_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F37x_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F37x_System_Exported_Functions
  * @{
  */
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_STM32F37X_H */

/**
  * @}
  */
  
/**
  * @}
  */  

