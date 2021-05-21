/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the hardware uart functions
  ******************************************************************************
  */
#ifndef __UART_H
#define __UART_H
#include "defines.h"
#define UART_SPEED      9600

void UARTInit(void);
void UARTDeInit(void);
void UART_SendDataByte(uint8_t sym);

#endif