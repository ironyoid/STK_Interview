        //PWR_PVDClearITPendingBit();
        ADC_ClearITPendingBit  ( ADC1, ADC_IT_EOC);
        ADC_ClearITPendingBit  ( ADC1, ADC_IT_AWD);
        ADC_ClearITPendingBit  ( ADC1, ADC_IT_OVER);
        RTC_ClearITPendingBit(RTC_IT_WUT);
        RELAY_OFF;
        LED_OFF;
        Relay=0;
        Counter_40=0;
        Counter_h4=4320;
        //delay_ms(10);
        ADC_DeInit(ADC1);
        SPI_DeInit(SPI1);
        ADC_Cmd(ADC1, DISABLE);
        SPI_Cmd(SPI1, DISABLE);
        //delay_ms(10);
        CLK_PeripheralClockConfig(CLK_Peripheral_ADC1, DISABLE); // Запрещение ADC
        CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, DISABLE); // Разрешение SPI
        //delay_ms(10);
        // конфигурирование выводов портов для LCD
        power=0;
        /* Port A in output push-pull 0 */
        GPIO_Init(GPIOA, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);
        GPIO_Init(GPIOA, GPIO_Pin_1, GPIO_Mode_In_PU_No_IT);     // Вывод Reset подтягиваем к +
        GPIO_Init(GPIOA,  GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow); // GPIO_Pin_0 | GPIO_Pin_1 | 
        /* Port B in output push-pull 0 */
        GPIO_Init(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
        /* Port C in output push-pull 0 */
        GPIO_Init(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_7, GPIO_Mode_Out_PP_High_Slow); // GPIO_Pin_5 | GPIO_Pin_6 | 
        /* Port D in output push-pull 0 */
        GPIO_Init(GPIOD, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
        GPIO_Init(GPIOD, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3, GPIO_Mode_Out_PP_High_Slow);
        /* Port E in output push-pull 0 */
        GPIO_Init(GPIOE, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
        /* Port F in output push-pull 0 */
        GPIO_Init(GPIOF, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);
        CFG->GCR|=CFG_GCR_AL;
