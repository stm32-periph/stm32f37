/**
  @page CEC_ListenMode CEC Listen mode example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    CEC/CEC_ListenMode/readme.txt  
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Description of the CEC Listen mode example.
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

This example provides a basic communication between two HDMI-CEC devices using 
interrupts and an spy CEC device which receives messages addressed to different
destination. 

The first CEC device send a command to the other CEC devices. The spy device 
can receive the data when Listen mode option is enabled.
The data transfer is managed using CEC_IRQHandler in stm32f37x_it.c file.

The example illustrates the use of the CEC communication between three devices 
(3 x STM32373C-EVAL boards). A device can send a frame to the other device by 
pressing the Joystick button(LEFT/RIGHT)on the EVAL board and an spy device
receives this message. 

- Hardware Description

To use this example, you need to load it on three STM32373C-EVAL boards (let's call 
them Device_1, Device_2 and Device_3) then connect these boards through CEC lines
(PB8 or HDMI connectors) and GND.
In the firmware example, uncomment the dedicated line in the main.h file  to use
the CEC peripheral as STM32 device_1 or as STM32 device_2 or as STM32 device_3.

- Software Description

At each joystick buttons press:
- The CEC device sends the specific command (Volume Up, Volume Down, OSD Name or
  CEC Version) to the specific device and the spy device receives the message
  command.

- The sender device can send a frame to the other device by pressing the JoyStick 
  button on the EVAL board. Sending status is signaled by lightening and though 
  as follow:
   - If Joystick RIGHT, LEFT, Up or Down is pressed and the data transmission is 
     succeeded ==> Green Led(LD1) is ON.
   - If Joystick RIGHT, LEFT, Up or Down is pressed and the data transmission is 
     failed ==> Red Led(LD3) is ON.    
 
- The Receiver device receive data, Received data is signaled by LED lightening and 
  though as follow:
   - OSD Name   : Joystick RIGHT and data correctly received ==> LD1, LD2 ON and LD3,LD4 OFF, 
   - CEC Version: Joystick LEFT and data correctly received  ==> LD3, LD4 ON and LD1,LD2 OFF,
   - Volume Up  : Joystick UP and data correctly received    ==> LD1, LD2, LD3 and LD4 are ON,
   - Volume Down: Joystick DOWN and data correctly received  ==> LD1, LD2, LD3 and LD4 are OFF.
   - If an error occurs during reception ==> Only LD3(Red LED) is ON.

@par Directory contents 

  - CEC/CEC_ListenMode/stm32f37x_conf.h    Library Configuration file
  - CEC/CEC_ListenMode/stm32f37x_it.c      Interrupt handlers
  - CEC/CEC_ListenMode/stm32f37x_it.h      Interrupt handlers header file
  - CEC/CEC_ListenMode/main.c              Main program
  - CEC/CEC_ListenMode/main.c              Main program header file
  - CEC/CEC_ListenMode/system_stm32f37x.c  STM32F37x system source file
  
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
    Connect the boards by using one of the two following alternatives:
    - A HDMI Cables between all boards HDMI-CEC connectors (CN1 or CN2) on 
      STM32373C-EVAL . 
    - Use a simple wire between all devices CEC Lines (PB.8), in this case don't 
      forget to connect all boards grounds together.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F37x_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 
 */
