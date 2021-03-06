/**
  @page COMP_LDR Comparator With LDR example.
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    COMP/COMP_LDR/readme.txt 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Description of Comparator With LDR example.
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
  @endverbatim

@par Example Description 

The STM32F37x microcontroller has an embedded comparator which can be used
in combination with DAC peripheral for more application like light intensity 
measurement(using the LDR sensor).

In this example when the luminosity changes the progress bar displayed on the color
LCD changes according to light intensity level detected on comparator.
 

@par Directory contents 

  - COMP/COMP_LDR/stm32f37x_conf.h    Library Configuration file
  - COMP/COMP_LDR/stm32f37x_it.c      Interrupt handlers
  - COMP/COMP_LDR/stm32f37x_it.h      Interrupt handlers header file
  - COMP/COMP_LDR/main.c              Main program
  - COMP/COMP_LDR/system_stm32f37x.c  STM32F37x system source file
  
@note The "system_stm32f37x.c" is generated by an automatic clock configuration 
      system and can be easily customized to your own configuration. 
      To select different clock setup, use the "STM32F37x_Clock_Configuration_V1.1.0.xls" 
      provided with the AN4132 package available on <a href="http://www.st.com/internet/mcu/family/141.jsp">  ST Microcontrollers </a>
         
@par Hardware and Software environment

  - This example runs on STM32F37x Devices.
  
  - This example has been tested with STMicroelectronics STM32373C-EVAL (STM32F37x)
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM32373C-EVAL Set-up
    - Make sure that the jumper JP16 is fitted


@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F37x_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 
 */
