/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with e-ink display
  *         ported from oficial arduino c++ lib.
  ******************************************************************************
  */
#ifndef __EINK_H
#define __EINK_H

#include "defines.h"

#define EPD_WIDTH       200
#define EPD_HEIGHT      200
#define DC_LOW          (GPIOB->ODR&= (uint8_t)(~GPIO_Pin_0));  
#define DC_HIGH         (GPIOB->ODR |= GPIO_Pin_0);
#define BUSY_PIN        (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2))
#define RST_LOW          (GPIOB->ODR&= (uint8_t)(~GPIO_Pin_1));  
#define RST_HIGH         (GPIOB->ODR |= GPIO_Pin_1);

void HDirInit(void);
void Clear(void);
void DisplayFrame(void);
void Sleep();
void SetFrameMemory(
        const unsigned char* image_buffer,
        int x,
        int y,
        int image_width,
        int image_height
);

#endif