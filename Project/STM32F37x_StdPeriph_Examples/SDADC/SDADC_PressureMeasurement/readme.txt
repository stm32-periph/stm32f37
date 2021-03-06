/**
  @page SDADC_PressureMeasurement SDADC Pressure measurement using MPX2102 sensor
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    SDADC/SDADC_PressureMeasurement/readme.txt 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   SDADC Pressure Measurement Example Description.
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

This example aims to show how to use the 16-bit resolution Sigma-Delta
Analog-to-Digital converter to perform differential pressure measurement using
the MPX2102A sensor mounted on the STM32373C-EVAL evaluation board.

 - The SDADC channel 8 is configured in differential mode.
   The external reference VREF (set to 3.3V on STM32373C-EVAL) is used as reference for SDADC.
   The conversion is triggered by TIM19 with interrupt enabled on end of injected conversion.
   A MPX2102A sensor is connected to SDADC1 channel 8P (PE8) and channel 8N (PE9).
   The MPX2102 sensitivity when powered by 3.3V is 3.3V * 40mV / 10V = 13.2mV/1000mB
                                                                     = 13.2 microV/mB
   To increase the sensitivity an external 45.1 gain using the operation amplifier
   TVS632 mounted on STM32373C-EVAL is used. The same opeartion amplifier is
   used to shift up the input voltage by 3.3V/10.0f = 0.33V
   Refer to STM32373C-EVAL user manual for more details about how the MPX2102 is
   connected to PE8 and PE9

 - The measured pressure is displayed on the LCD mounted on STM32373C-EVAL.
   In order to get an accurate measurement of pressure a calibration phase 
   should be added using a known pressure value.


@par Directory contents 

  - SDADC/SDADC_PressureMeasurement/stm32f37x_conf.h    Library Configuration file
  - SDADC/SDADC_PressureMeasurement/stm32f37x_it.c      Interrupt handlers
  - SDADC/SDADC_PressureMeasurement/stm32f37x_it.h      Interrupt handlers header file
  - SDADC/SDADC_PressureMeasurement/main.c              Main program
  - SDADC/SDADC_PressureMeasurement/main.h              Main header
  - SDADC/SDADC_PressureMeasurement/system_stm32f37x.c  STM32F37x system source file
  
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
    - Make sure that jumper JP16 and JP17 are fitted.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F37x_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 
 */
