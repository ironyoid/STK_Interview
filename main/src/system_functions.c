/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all system functions    
  ******************************************************************************
  */
#include "system_functions.h"

void delay_10us_sp(uint32_t ms) //very precision delay for us
{
  while(ms != 0) {
    uint8_t count = 3;
    while(count != 0) {count--;} // 1 nop - about 3us
    ms--;
  }
}

void delay_ms_sp(uint32_t ms)//very precision delay for ms
{
  delay_10us_sp(ms*100);
}

void MCUInit(void)
{
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI); // 16 Mhz
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
    CLK_HSICmd(ENABLE);

    SPIInit();
    ButtonsInit();
    ADCInit();
    UARTInit();
    HDirInit();
}

uint8_t Bytes2Int(uint8_t *data, uint8_t length)
{
    uint8_t res = 0;
    for(uint8_t i = 0; i < length; i++)
    {
        res = (res * 10) + (data[i] - 0x30);
    }
    return res;
}