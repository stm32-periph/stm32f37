/**
  @page DAC_ADC Loopback DAC to ADC example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    DAC/DAC_ADC/readme.txt 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Description of the Loopback DAC to ADC example.
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

This example describes how to use the ADC1 and DAC1 to output on DAC1_OUT1 sampled
values of ADC1 channel5.
The ADC1 is configured to convert continuously ADC1 channel5 (PA5).
The End Of Conversion (EOC) interrupt is enabled and the conversion is triggered by software.

The DAC1 channel 1 is configured with output buffer disabled.

Each time the end of conversion interrupt occurs, converted value by ADC1 is written
in DAC1 channel 1 register.
Thus applied voltage on ADC1 channel5 (PA5) is output on DAC1_OUT1 (PA4).


@par Directory contents 

  - DAC/DAC_ADC/stm32f37x_conf.h    Library Configuration file
  - DAC/DAC_ADC/stm32f37x_it.c      Interrupt handlers
  - DAC/DAC_ADC/stm32f37x_it.h      Interrupt handlers header file
  - DAC/DAC_ADC/main.c              Main program
  - DAC/DAC_ADC/system_stm32f37x.c  STM32F37x system source file
  
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
    - Connect a variable power supply 0-3.3V to ADC1 Channel5 mapped on pin PA5.
    - Connect PA4 (DAC1_OUT1) pin to an oscilloscope.
    - Make sure that the jumper JP16 is fitted.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F37x_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 
 */
