/**
  @page USART_AutoBaudRate USART AutoBaudRate Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    USART/USART_AutoBaudRate/readme.txt 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Description of the USART AutoBaudRate Example.
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

This example provides a description of how to use the Auto BaudRate capability
of the USART via the HyperTerminal.

First, the USART2 is configured to detect BaudRate automatically with StartBit
Measurement Method (Any character starting with a bit at 1 should be sent to USART 
to detect Baud Rate).

After configuration, the USART waits until a data is received via HyperTerminal
to launch auto-detection of Baud Rate phase. The end of this phase is monitored 
by ABRF flag.

The result of auto-detection is indicated by Eval_Board LEDs. If an error occurred 
in Auto BaudRate phase ABRE flag is set and LED3 is turned on. If this phase is 
completed successfully, LED2 is turned on and the received data is transmitted to
HyperTerminal.

The USART2 is configured as follow:
    - BaudRate = 9600 baud (any value can be chosen)  
    - Word Length = 8 Bits 
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled

@par Directory contents 

  - USART/USART_AutoBaudRate/stm32f37x_conf.h    Library Configuration file
  - USART/USART_AutoBaudRate/stm32f37x_it.c      Interrupt handlers
  - USART/USART_AutoBaudRate/stm32f37x_it.h      Interrupt handlers header file
  - USART/USART_AutoBaudRate/main.c              Main program
  - USART/USART_AutoBaudRate/system_stm32f37x.c  STM32F37x system source file
  
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
    - Connect a null-modem female/female RS232 cable between the DB9 connector 
      CN12 and PC serial port.
    - Make sure that JP6 is in position 2<->3 

  - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = User can select any BaudRate
    - flow control: None 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F37x_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 
 */
