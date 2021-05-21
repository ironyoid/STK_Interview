/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with adc     
  ******************************************************************************
  */
#include "adc.h"

/**
 *  @brief: ADC init
 */
void ADCInit(void)
{
    CLK_PeripheralClockConfig(CLK_Peripheral_ADC1, ENABLE);
    ADC_Init(ADC1, ADC_ConversionMode_Single, ADC_Resolution_10Bit, ADC_Prescaler_1);
    ADC_SamplingTimeConfig(ADC1, ADC_Group_SlowChannels, ADC_SamplingTime_384Cycles);
    ADC_Cmd(ADC1, ENABLE);
    
}
/**
 *  @brief: ADC deinit
 */
void ADCDeInit(void)
{
    ADC_VrefintCmd(DISABLE);
    ADC_ChannelCmd(ADC1, channel, DISABLE);
    ADC_Cmd(ADC1, DISABLE);
    ADC_DeInit(ADC1);
    CLK_PeripheralClockConfig(CLK_Peripheral_ADC1, DISABLE);
    
}
/**
 *  @brief: Read ADC
 */
static uint16_t ReadADC(ADC_Channel_TypeDef channel)
{
    PWR_SW_ON;
    ADC_VrefintCmd(ENABLE);
    ADC_ChannelCmd(ADC1, channel, ENABLE);
    ADC_SoftwareStartConv(ADC1);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0);
    PWR_SW_OFF;
    return ADC_GetConversionValue(ADC1);
}
/**
 *  @brief: Read Vref
 */
static uint16_t ReadVref(void)
{
    uint16_t res;
    uint16_t factory_ref_voltage;
    uint8_t count;
    ADC_VrefintCmd(ENABLE);
    ADC_ChannelCmd(ADC1, ADC_Channel_Vrefint, ENABLE);
    ADC_SoftwareStartConv(ADC1);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0);
    uint16_t res = ADC_GetConversionValue(ADC1);

    if (Factory_VREFINT != 0)
    {
        factory_ref_voltage = 0x600 + Factory_VREFINT;
    }
    else
    {
        factory_ref_voltage = 1671;
    }

    res = (factory_ref_voltage * 3000) / res;

    ADC_ChannelCmd(ADC1, ADC_Channel_Vrefint, DISABLE);

    return res;
}

/**
 *  @brief: Calculate real Vin value
 */
static float CalculateTrueVin(ADC_Channel_TypeDef channel)
{
    uint16_t vin = ReadADC(channel);
    uint16_t vref = ReadVref(void);
    return (((float)vin / 1024.0) * vref);
}

uint8_t CalculatePercenVin(ADC_Channel_TypeDef channel)
{
    float vin = CalculateTrueVin(channel) - ADC_TRESH_DOWN;
    if((vin >= 0) && (vin <= (ADC_TRESH_UP - ADC_TRESH_DOWN)))
    {
       return (uint8_t)((vin * 100) / (ADC_TRESH_UP - ADC_TRESH_DOWN)); 
    }
    else if(vin < 0)
    {
       return 0;
    }
    else if (vin >= (ADC_TRESH_UP - ADC_TRESH_DOWN))
    {
        return 100;
    }
}

