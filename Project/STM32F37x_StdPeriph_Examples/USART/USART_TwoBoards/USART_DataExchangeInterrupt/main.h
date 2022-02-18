/**
  ******************************************************************************
  * @file    USART/USART_TwoBoards/USART_DataExchangeInterrupt/main.h 
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

/* Exported typedef ----------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Exported define -----------------------------------------------------------*/

/* USER_TIMEOUT value for waiting loops. This timeout is just guarantee that the
   application will not remain stuck if the USART communication is corrupted. 
   You may modify this timeout value depending on CPU frequency and application
   conditions (interrupts routines, number of data to transfer, baudrate, CPU
   frequency...). */ 
#define USER_TIMEOUT                    ((uint32_t)0x64) /* Waiting 1s */

/* USART Mode Selected */
#define USART_MODE_TRANSMITTER           0x00
#define USART_MODE_RECEIVER              0x01      
/* USART Transaction Type */
#define USART_TRANSACTIONTYPE_CMD        0x00
#define USART_TRANSACTIONTYPE_DATA       0x01

/* USART Communication boards Interface */
#define USARTx                           USART2
#define USARTx_CLK                       RCC_APB1Periph_USART2
#define USARTx_APBPERIPHCLOCK            RCC_APB1PeriphClockCmd
#define USARTx_IRQn                      USART2_IRQn

#define USARTx_TX_PIN                    GPIO_Pin_5                
#define USARTx_TX_GPIO_PORT              GPIOD                       
#define USARTx_TX_GPIO_CLK               RCC_AHBPeriph_GPIOD
#define USARTx_TX_SOURCE                 GPIO_PinSource5
#define USARTx_TX_AF                     GPIO_AF_7

#define USARTx_RX_PIN                    GPIO_Pin_6               
#define USARTx_RX_GPIO_PORT              GPIOD                    
#define USARTx_RX_GPIO_CLK               RCC_AHBPeriph_GPIOD
#define USARTx_RX_SOURCE                 GPIO_PinSource6
#define USARTx_RX_AF                     GPIO_AF_7

#define TXBUFFERSIZE                     (countof(TxBuffer) - 1)
#define RXBUFFERSIZE                     TXBUFFERSIZE

/* Joystick Commands */
#define CMD_RIGHT                        0x55
#define CMD_LEFT                         0xAA
#define CMD_UP                           0x33
#define CMD_DOWN                         0xCC
#define CMD_SEL                          0xFF 

#define CMD_ACK                          0x66 

/* Define numbers of bytes to transmit from TxBuffer */
#define CMD_RIGHT_SIZE                   0x01
#define CMD_LEFT_SIZE                    0x05
#define CMD_UP_SIZE                      0x14
#define CMD_DOWN_SIZE                    0x1E
#define CMD_SEL_SIZE                     TXBUFFERSIZE

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t GetVar_NbrOfData(void);

#endif /* __MAIN_H */

