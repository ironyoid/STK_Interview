/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all system functions    
  ******************************************************************************
  */
#ifndef __SYS_FNC_H
#define __SYS_FNC_H

#include "defines.h"
void delay_10us_sp(uint32_t ms);
void delay_ms_sp(uint32_t ms);
uint8_t Bytes2Int(uint8_t *data, uint8_t length);
#endif