 #include "uart.h"

void UARTInit(void)
{
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE); 
  GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_Out_OD_HiZ_Slow); // TX
  GPIO_Init(GPIOC, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);     // RX
  USART_DeInit(USART1);
  USART_Init(USART1, 
             (uint32_t)UART_SPEED, 
             USART_WordLength_8b, 
             USART_StopBits_1,
             USART_Parity_No,
             (USART_Mode_TypeDef) (USART_Mode_Rx|USART_Mode_Tx));
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART1, USART_IT_OR, ENABLE);
  USART_Cmd(USART1, ENABLE);
}

void UARTDeInit(void)
{
  GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_Out_PP_Low_Slow);     // TX
  GPIO_Init(GPIOC, GPIO_Pin_2, GPIO_Mode_Out_PP_Low_Slow);     // RX 
  USART_DeInit(USART1);
  USART_ITConfig(USART1, USART_IT_TC, DISABLE);
  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
  USART_ITConfig(USART1, USART_IT_OR, DISABLE);
  USART_Cmd(USART1, DISABLE);
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1, DISABLE); 
}

void UART_SendDataBlock(char * data, uint16_t lenght)
{
  char sym;
  while(lenght--)
  {
    sym = *data++;
    UART_SendDataByte(sym);
  }
}

static void UART_SendDataByte(uint8_t sym)
{
    USART_SendData8(USART1, sym);
}

