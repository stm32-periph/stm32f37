/**
  ******************************************************************************
  * @file    PWR/PWR_Standby/main.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-December-2021
  * @brief   Main program body
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
#include "stm32f37x.h"
#include "stm32373c_eval.h"

/** @addtogroup STM32F37x_StdPeriph_Examples
  * @{
  */

/** @addtogroup PWR_Standby
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void RTC_Config(void);
static void SysTick_Configuration(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f37x.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f37x.c file
     */ 
 
  /* Configure Systick */
  SysTick_Configuration();
  
  /* Configures the KEY button */
  STM_EVAL_PBInit(BUTTON_KEY,BUTTON_MODE_GPIO);
  
  /* Configure LED3 */
  STM_EVAL_LEDInit(LED3);
   
  while(STM_EVAL_PBGetState(BUTTON_KEY) != RESET);
  
  /* Configure RTC clock source and prescaler */
  RTC_Config();
 
  while(1)
  {}
}

/**
  * @brief  Configures the RTC clock source.
  * @param  None
  * @retval None
  */
static void RTC_Config(void)
{
  RTC_InitTypeDef   RTC_InitStructure;
  RTC_AlarmTypeDef  RTC_AlarmStructure;
  RTC_TimeTypeDef   RTC_TimeStructure;

  /* Enable the PWR clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
  
  /* Allow access to Backup Domain */
  PWR_BackupAccessCmd(ENABLE);

  /* Enable the LSI OSC */
  RCC_LSICmd(ENABLE);
  
  /* Wait till LSI is ready */
  while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
  {}
  
  /* Check if the StandBy flag is set */
  if (PWR_GetFlagStatus(PWR_FLAG_SB) != RESET)
  {       
    /* Clear StandBy flag */
    PWR_ClearFlag(PWR_FLAG_SB);
    
    /*Waits until the RTC Time and Date registers (RTC_TR and RTC_DR) are 
      synchronized with RTC APB clock.*/
    RTC_WaitForSynchro();
    
    /* No need to configure the RTC as the RTC config(clock source, enable,
    prescaler,...) are kept after wake-up from STANDBY */
  }
  else
  {
    /* RTC Configuration ******************************************************/
    /* Reset Backup Domain */
    RCC_BackupResetCmd(ENABLE);
    RCC_BackupResetCmd(DISABLE);

    /* Select the RTC Clock Source */
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

    /* Enable the RTC Clock */
    RCC_RTCCLKCmd(ENABLE);
    
    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();
    
    RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;
    RTC_InitStructure.RTC_AsynchPrediv = 0x7F;
    RTC_InitStructure.RTC_SynchPrediv = 0x0138;
    
    RTC_Init(&RTC_InitStructure);
    
    /* Set the alarm X+5s */
    RTC_AlarmStructure.RTC_AlarmTime.RTC_H12     = RTC_H12_AM;
    RTC_AlarmStructure.RTC_AlarmTime.RTC_Hours   = 0x01;
    RTC_AlarmStructure.RTC_AlarmTime.RTC_Minutes = 0x00;
    RTC_AlarmStructure.RTC_AlarmTime.RTC_Seconds = 3;
    RTC_AlarmStructure.RTC_AlarmDateWeekDay = 0x31;
    RTC_AlarmStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date;
    RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_DateWeekDay;
    RTC_SetAlarm(RTC_Format_BCD, RTC_Alarm_A, &RTC_AlarmStructure);
  
    /* Enable RTC Alarm A Interrupt */
    RTC_ITConfig(RTC_IT_ALRA, ENABLE);
  
    /* Enable the alarm */
    RTC_AlarmCmd(RTC_Alarm_A, ENABLE);
  }
    
  /* Set the time to 01h 00mn 00s AM */
  RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
  RTC_TimeStructure.RTC_Hours   = 0x01;
  RTC_TimeStructure.RTC_Minutes = 0x00;
  RTC_TimeStructure.RTC_Seconds = 0x00;  
  
  RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);
   
  /* Clear Wakeup flag */
  PWR_ClearFlag(PWR_FLAG_WU);      
  
  RTC_ClearFlag(RTC_FLAG_ALRAF);
  
  /* Request to enter STANDBY mode (Wake Up flag is cleared in PWR_EnterSTANDBYMode function) */
  PWR_EnterSTANDBYMode(); 
}

/**
  * @brief  Configures the SysTick to generate an interrupt each 250 ms.
  * @param  None
  * @retval None
  */
static void SysTick_Configuration(void)
{
  /* SysTick interrupt each 250 ms */
  if (SysTick_Config((SystemCoreClock/8) / 4))
  { 
    /* Capture error */ 
    while (1);
  }

  /* Select AHB clock(HCLK) divided by 8 as SysTick clock source */
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);

  /* Set SysTick Preemption Priority to 1 */
  NVIC_SetPriority(SysTick_IRQn, 0x04);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* KEY can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */  

