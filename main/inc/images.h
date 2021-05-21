/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file would be contains all imagges burned into FLASH but now 
  * there are only header to take memory
  * 
  ******************************************************************************
  */
#ifndef __IMAGES_H
#define __IMAGES_H
#include "defines.h"

uint8_t finish_ico[4096];    
uint8_t pause_ico[4096];
uint8_t desinfection_ico[4096];
uint8_t wait_ico[4096];
uint8_t in_progress_ico[4096];
uint8_t rssi_ico[4096];
uint8_t controller_ico[256];
uint8_t robot_ico[256];
uint8_t state_ico[1280];
uint8_t ok_ico[1280];
uint8_t err1_ico[1280];
uint8_t err2_ico[1280];
uint8_t err3_ico[1280];
uint8_t err4_ico[1280];
uint8_t numbers[10][256];
#endif