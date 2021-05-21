/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with buttons
  ******************************************************************************
  */
 #include "buttons.h"

 void ButtonsInit(void)
 {
     GPIO_Init( GPIOD, GPIO_Pin_0, GPIO_Mode_In_PU_No_IT);      // PAUSE BUTTON
     EXTI_SetPinSensitivity(EXTI_Pin_0, EXTI_Trigger_Rising);   // Happens after button release
     GPIO_Init( GPIOD, GPIO_Pin_1, GPIO_Mode_In_PU_No_IT);      // WHEELS BUTTON
     EXTI_SetPinSensitivity(EXTI_Pin_1, EXTI_Trigger_Rising);   // Happens after button release
 }

  void ButtonsDeInit(void)
 {
     GPIO_Init( GPIOD, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow); // PAUSE BUTTON
     GPIO_Init( GPIOD, GPIO_Pin_1, GPIO_Mode_Out_PP_Low_Slow); // WHEELS BUTTON
 }
