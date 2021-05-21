/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with buttons
  ******************************************************************************
  */
#ifndef __BUTTONS_H
#define __BUTTONS_H

#include "defines.h"
#define PAUSE_BUTTON          (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_0))  
#define WHEELS_BUTTON         (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1))
void ButtonsInit(void);
void ButtonsDeInit(void);
#endif