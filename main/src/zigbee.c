/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with zigbee module     
  ******************************************************************************
  */
#include "zigbee.h"
#include "uart.h"
#include "defines.h"
void ClearRXBuf(void)
{
    memset(uartRxBuf, 0, sizeof(uartRxBuf));
}

void ClearTXBuf(void)
{
    memset(uartTxBuf, 0, sizeof(uartTxBuf));
}

void BufferAddChar(uint8_t new_char, uint8_t position)
{
    uartTxBuf[position] = new_char;
}

void BufferAddString(uint8_t *new_part, uint8_t position, uint8_t count)
{
    uint8_t sym;
    while (count--)
    {
        sym = *new_part++;
        uartTxBuf[position++] = sym;
    }
}

void BufferAddInt(uint16_t new_int, uint8_t position)
{
    uartTxBuf[position + 1] = new_int;
    uartTxBuf[position] = (new_int >> 8);
}

uint16_t CRC16(uint8_t *data, uint16_t length)
{
    uint16_t crc = 0xFFFF;
    uint8_t i;
    while (length--)
    {
        crc ^= *data++ << 8;
        for (i = 0; i < 8; i++)
            crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
    }
    return crc;
}

uint8_t MakeCommandW(void)
{
    uint8_t tx_buf_counter = 0;
    BufferAddString("TQ", tx_buf_counter, 2);
    tx_buf_counter += 2;
    BufferAddChar((uint8_t)DEVICE_ID, tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar((uint8_t)'W', tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar((uint8_t)0x02, tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar(('0' + pause_state), tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar(('0' + wheels_state), tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddInt(CRC16(uartTxBuf, tx_buf_counter), tx_buf_counter);
    tx_buf_counter += 2;
    return tx_buf_counter;
}

uint8_t MakeCommandR(void)
{
    uint8_t tx_buf_counter = 0;
    BufferAddString("TQ", tx_buf_counter, 2);
    tx_buf_counter += 2;
    BufferAddChar((uint8_t)DEVICE_ID, tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar((uint8_t)'R', tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddChar((uint8_t)0x00, tx_buf_counter);
    tx_buf_counter += 1;
    BufferAddInt(CRC16(uartTxBuf, tx_buf_counter), tx_buf_counter);
    tx_buf_counter += 2;
    return tx_buf_counter;
}

void SendConfig(void)
{
   uint8_t length = MakeCommandW();
   UART_SendDataBlock(uartTxBuf, length);
}

void SendRequest(void)
{
   uint8_t length = MakeCommandR();
   UART_SendDataBlock(uartTxBuf, length);
}

uint8_t WaitForAnswer(void)
{
    uint16_t timeout = 2000;
    while (uartRxBuf[rx_buf_counter] != '\0')
    {
        if (timeout)
        {
            timeout--;
        }
        delay_ms_sp(1);

        if (!timeout)
        {
            rx_buf_counter = 0;
            ClearRXBuf();
            return 0;
        }
    }
}

uint8_t ParseAnswer()
{
    uint8_t err_flag = 0;
    uint8_t count = 0;
    uint8_t data[4];
    if ((uartRxBuf[count] == 'T') && (uartRxBuf[count + 1] == 'Q') && (uartRxBuf[count + 2] == (uint8_t)DEVICE_ID) && (uartRxBuf[count + 3] == 'A'))
    {
        count += 4;
        uint8_t length = uartRxBuf[count] - 4;      // 4 bytes took for [pause] [wheels] [status] [mode]
        count += 1;
        for (uint8_t i = 0; i < 4; i++)
        {
            if ((uartRxBuf[count] == '0') || (uartRxBuf[count] == '1'))
            {
                data[i] = (uartRxBuf[count] - '0');
            }
            else
            {
                err_flag = 1;
            }
            count += 1;
        }
    
        strncpy (robot_charge, &uartRxBuf[count], length);
        // uint8_t charge_tmp = Bytes2Int(&uartRxBuf[count], length);
        // if(charge_tmp <= 100)
        // {
        //     robot_charge = charge_tmp;
        // }
        // else
        // {
        //    err_flag = 1; 
        // }
    }
    else
    {
        err_flag = 1;
    }

    if(!err_flag)
    {
        pause_state     = data[0];
        wheels_state    = data[1];
        status          = (status_t)data[2];
        mode            = (mode_t)data[3];
    }

    return err_flag;
}
