/**
  ******************************************************************************
  * @file    adc.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all interrupt handlers   
  ******************************************************************************
  */
#include "stm8l15x_it.h"
#include "zigbee.h"
/** @addtogroup IT_Functions
  * @{
  */
INTERRUPT_HANDLER(NonHandledInterrupt, 0)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief TRAP interrupt routine
  * @par Parameters:
  * None
  * @retval 
  * None
*/
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief FLASH Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(FLASH_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief DMA1 channel0 and channel1 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(DMA1_CHANNEL0_1_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief DMA1 channel2 and channel3 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(DMA1_CHANNEL2_3_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief RTC Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
/*SD card writer counter*/
INTERRUPT_HANDLER(RTC_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief External IT PORTE/F and PVD Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTIE_F_PVD_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PORTB Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTIB_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PORTD Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTID_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN1 Interrupt routine.
  * For PAUSE button
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI0_IRQHandler, 8)
{
  upd_flag = 1;
  pause_state = (~pause_state) & 1;
  EXTI_ClearITPendingBit(EXTI_IT_Pin0);
}
/**
  * @brief External IT PIN1 Interrupt routine.
  * For WHEELS button
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI1_IRQHandler, 9)
{
  upd_flag = 1;
  wheels_state = (~wheels_state) & 1;
  EXTI_ClearITPendingBit(EXTI_IT_Pin1);
}

/**
  * @brief External IT PIN2 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */

INTERRUPT_HANDLER(EXTI2_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN3 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI3_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN4 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI4_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN5 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI5_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN6 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI6_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief External IT PIN7 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(EXTI7_IRQHandler, 15)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief LCD start of new frame Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(LCD_IRQHandler, 16)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief CLK switch/CSS/TIM1 break Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(SWITCH_CSS_BREAK_DAC_IRQHandler, 17)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief ADC1/Comparator Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(ADC1_COMP_IRQHandler, 18)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief TIM2 Update/Overflow/Trigger/Break Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM2_UPD_OVF_TRG_BRK_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief Timer2 Capture/Compare Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM2_CAP_IRQHandler, 20)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief Timer3 Update/Overflow/Trigger/Break Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM3_UPD_OVF_TRG_BRK_IRQHandler, 21)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief Timer3 Capture/Compare Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM3_CAP_IRQHandler, 22)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief TIM1 Update/Overflow/Trigger/Commutation Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_COM_IRQHandler, 23)
{
}
/**
  * @brief TIM1 Capture/Compare Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(TIM1_CAP_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}

/**
  * @brief TIM4 Update/Overflow/Trigger Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
/**/
INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, 25)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief SPI1 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(SPI1_IRQHandler, 26)
{
}
/**
  * @brief USART1 TX Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(USART1_TX_IRQHandler, 27)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @brief USART1 RX Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(USART1_RX_IRQHandler, 28)
{
    uartRxBuf[rx_buf_counter] = USART_ReceiveData8(USART1);
    rx_buf_counter++;
    USART_ClearITPendingBit(USART1, USART_IT_RXNE); 
}

/**
  * @brief I2C1 Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
INTERRUPT_HANDLER(I2C1_IRQHandler, 29)
{
  /* In order to detect unexpected events during development,
   it is recommended to set a breakpoint on the following instruction.
*/
}
/**
  * @}
  */
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
