/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with zigbee module     
  ******************************************************************************
  */
#ifndef __ZIGBEE_H
#define __ZIGBEE_H
#include "defines.h"
#define DEVICE_ID   0x01

uint8_t uartRxBuf[64];
uint8_t rx_buf_counter;
uint8_t uartTxBuf[64];

#endif