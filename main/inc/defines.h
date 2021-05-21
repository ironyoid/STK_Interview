/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the system defines
  ******************************************************************************
  */
#ifndef __DEFINES_H
#define __DEFINES_H
#include <stdint.h>
#include "stm8l15x_conf.h"
#include <stdio.h>
#include <string.h>
typedef enum
{
    OK              = 0x00,
    ERR_1,
    ERR_2,
    ERR_3,
    ERR_4
}status_t;
typedef enum
{
    WAIT            = 0x00,
    IN_PROGRESS,
    DISINFECTION,
    FINISH,
    PAUSE
}mode_t;

uint8_t pause_state;
uint8_t wheels_state;
status_t status;
mode_t mode;
uint8_t robot_charge[4];
uint8_t request_upd_flag;
uint8_t button_upd_flag;
#define REQUEST_PERIOD      20      // Minutes
#endif