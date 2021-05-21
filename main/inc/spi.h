/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains hardware SPI functions    
  ******************************************************************************
  */
#ifndef __SPI_H
#define __SPI_H

#include "defines.h"
#define CS_LOW          (GPIOB->ODR&= (uint8_t)(~GPIO_Pin_4));  
#define CS_HIGH         (GPIOB->ODR |= GPIO_Pin_4);

void SPI_SendDataByte (const uint8_t data);
void SPI_SendDataBlock (const uint8_t *buff, uint8_t btx);	
void SPIInit(void);
void SPIDeInit(void);
#endif