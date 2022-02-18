/**
  @page truestudio TrueSTUDIO Project Template for STM32F37x devices
 
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   This sub-directory contains all the user-modifiable files needed to
  *          create a new project linked with the STM32F37x Standard Peripherals
  *          Library and working with TrueSTUDIO software toolchain.
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
 
 @par Directory contents
 
 -  .cproject/.project: A pre-configured project file with the provided library
                        structure that produces an executable image with TrueSTUDIO.

 - stm32_flash.ld:             This file is the TrueSTUDIO linker script used to 
                               place program code (readonly) in internal FLASH and
                               data (readwrite, Stack and Heap)in internal SRAM. 
                               You can customize this file to your need.
                                                          
 @par How to use it ?

 - Open the TrueSTUDIO toolchain.
 - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace 
   directory.
 - Click on File->Import, select General->'Existing Projects into Workspace' 
   and then click "Next". 
 - Browse to the TrueSTUDIO workspace directory and select the project: 
   - STM320518_EVAL: to configure the project for STM32F37x devices.
 - Rebuild all project files: Select the project in the "Project explorer" 
   window then click on Project->build project menu.
 - Run program: Select the project in the "Project explorer" window then click 
   Run->Debug (F11)

 @note The needed define symbols for this config are already declared in the
       preprocessor section: USE_STDPERIPH_DRIVER, STM32F37X, USE_STM32373C_EVAL 

 
 */
