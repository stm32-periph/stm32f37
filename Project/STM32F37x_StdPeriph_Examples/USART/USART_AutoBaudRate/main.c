/**
  ******************************************************************************
  * @file    USART/USART_AutoBaudRate/main.c 
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

/** @addtogroup USART_AutoBaudRate
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void USART_Config(void);

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
    
  /* Initialize LEDs available on STM32373C-EVAL board ************************/
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  
  /* Configure and enable the systick timer to generate an interrupt each 1 ms */
  SysTick_Config((SystemCoreClock / 1000));
  
  /* USART configuration to use auto baudrate capability */
  USART_Config();
  
  /* If AutoBaudBate error occurred */
  if (USART_GetFlagStatus(USART2, USART_FLAG_ABRE) != RESET)
  {
    /* Turn on LED3 */
    STM_EVAL_LEDOn(LED3);
  }
  else
  {
    /* Turn on LED2 */
    STM_EVAL_LEDOn(LED2);
    
    /* Wait until RXNE flag is set */
    while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET)
    {}
    
    /* Wait until TXE flag is set */    
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
    {}
    
    /* Send received character */
    USART_SendData(USART2, USART_ReceiveData(USART2)); 
    
    /* clear the TE bit (if a transmission is on going or a data is in the TDR, it will be sent before
    efectivelly disabling the transmission) */
    USART_DirectionModeCmd(USART2, USART_Mode_Tx, DISABLE);
    
    /* Check the Transfer Complete Flag */
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
    {}
  }
  
  /* USART Disable */
  USART_Cmd(USART2, DISABLE);
    
  while(1)
  {}
}

/**
  * @brief Configure the USART Device to use the Auto BaudRate capability
  * @param  None
  * @retval None
  */
static void USART_Config(void)
{ 
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure; 
  
  /* Enable GPIOD clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD , ENABLE);
  
  /* Enable USART2 APB clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  
  /* USART2 Pins configuration **************************************************/
  GPIO_DeInit(GPIOD);
  
  /* Connect pin to Periph */
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_7);    
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_7); 
  
  /* Configure pins as AF pushpull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure); 
   
  /* USARTx configured as follow:
  - BaudRate = 9600 baud  
  - Word Length = 8 Bits
  - Stop Bit = 1 Stop Bit
  - Parity = No Parity
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled
  */
  
  USART_DeInit(USART2);
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART2, &USART_InitStructure);
  
    /* USART enable */
  USART_Cmd(USART2, ENABLE);
  
  /* Configure the AutoBaudRate method */
  USART_AutoBaudRateConfig(USART2, USART_AutoBaudRate_StartBit);
  
  /* Enable AutoBaudRate feature */
  USART_AutoBaudRateCmd(USART2, ENABLE);
  
  /* Wait until Receive enable acknowledge flag is set */
  while(USART_GetFlagStatus(USART2, USART_FLAG_REACK) == RESET)
  {}  
  
  /* Wait until Transmit enable acknowledge flag is set */  
  while(USART_GetFlagStatus(USART2, USART_FLAG_TEACK) == RESET)
  {}  
  
  /* Loop until the end of Autobaudrate phase */
  while(USART_GetFlagStatus(USART2, USART_FLAG_ABRF) == RESET)
  {}  
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
  /* User can add his own implementation to report the file name and line number,
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

