/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains hardware SPI functions    
  ******************************************************************************
  */
#include "spi.h"

void SPI_SendDataBlock (const uint8_t *buff, uint8_t btx)		
{
    CS_LOW;
	while (btx) {		/* Transmit the data block  */
		SPI1->DR = *buff++;
		while(!SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE));
        while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY));
		SPI1->DR;
		btx--;
	}
    CS_HIGH;
}

void SPI_SendDataByte (const uint8_t data)		
{
        CS_LOW;
		SPI1->DR = data;
		while(!SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE));
        while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY));
		SPI1->DR;
        CS_HIGH;
}

void SPIInit(void)
{
  /*SPI 8 Mhz, MSB, Master, Mode 0, without hardware CS controller*/
  CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, ENABLE);
  SPI_DeInit(SPI1);
        SPI_Init
      (
        SPI1,
        SPI_FirstBit_MSB, SPI_BaudRatePrescaler_2, SPI_Mode_Master,
        SPI_CPOL_Low, SPI_CPHA_1Edge,
        SPI_Direction_1Line_Tx, SPI_NSS_Soft, 0x00
      );

  SPI_Cmd(SPI1, ENABLE);
}

void SPIDeInit(void)
{
    SPI_DeInit(SPI1);
    SPI_Cmd(SPI1, DISABLE);
    CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, DISABLE);
}
