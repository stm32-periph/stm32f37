/**
  ******************************************************************************
  * @file    CEC/CEC_MultiAddress/main.h 
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
#include "stm32373c_eval_lcd.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below if you will use the CEC peripheral as a Device1 */
#define DEVICE_1   
/* Uncomment the line below if you will use the CEC peripheral as a Device2 */ 
//#define DEVICE_2     

#define DEVICE_ADDRESS_1               0x01  /* CEC device 1 address (sender)      */
#define DEVICE_ADDRESS_2               0x03  /* Tuner: CEC device 2 address        */
#define DEVICE_ADDRESS_3               0x05  /* Audio System: CEC device 3 address */

 /* Uncomment the define to use LCD */
#define LCD_DISPLAY       

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

