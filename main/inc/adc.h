/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with adc     
  ******************************************************************************
  */
#ifndef __ADC_H
#define __ADC_H

#include "defines.h"
#define PWR_ADC          (ADC_Channel_3)
#define ADC_TRESH_UP    2100.0
#define ADC_TRESH_DOWN  1400.0
#define PWR_SW_OFF        (GPIOB->ODR&= (uint8_t)(~GPIO_Pin_0));  
#define PWR_SW_ON         (GPIOB->ODR |= GPIO_Pin_0);
#pragma location=0x4910
__no_init uint32_t Factory_VREFINT;
void ADCInit(void);
void ADCDeInit(void);
uint8_t CalculatePercenVin(ADC_Channel_TypeDef channel);
#endif