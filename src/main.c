/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f1xx.h"
#include "UART_USB/uart_usb.h"
#include "DC_Motor_Driver/control.h"
void SystemClock_Config(void) {
	RCC_ClkInitTypeDef clkinitstruct = { 0 };
	RCC_OscInitTypeDef oscinitstruct = { 0 };

	/* Configure PLL ------------------------------------------------------*/
	/* PLL configuration: PLLCLK = (HSI / 2) * PLLMUL = (8 / 2) * 16 = 64 MHz */
	/* PREDIV1 configuration: PREDIV1CLK = PLLCLK / HSEPredivValue = 64 / 1 = 64 MHz */
	/* Enable HSI and activate PLL with HSi_DIV2 as source */
	oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	oscinitstruct.HSEState = RCC_HSE_OFF;
	oscinitstruct.LSEState = RCC_LSE_OFF;
	oscinitstruct.HSIState = RCC_HSI_ON;
	oscinitstruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	oscinitstruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	oscinitstruct.PLL.PLLState = RCC_PLL_ON;
	oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
	oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL16;
	if (HAL_RCC_OscConfig(&oscinitstruct) != HAL_OK) {
		/* Initialization Error */
		while (1)
			;
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
	clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2) != HAL_OK) {
		/* Initialization Error */
		while (1)
			;
	}
}



int main(void) {
	SystemClock_Config();
	SysTick_Config(SystemCoreClock / 1000);
	//SystemClock_Config();
	HAL_Init();
	usb_uart_init();
	printf("Hello world !\n");
	dc_driver_init();

	uint16_t value;
	float v;
	while (1) {
		char c = receive_char();
			switch (c) {
				case 'f':
					m1_pwm(100);
					m2_pwm(100);
					m2_forward();
					m1_forward();
					send_char(c);
					break;
				case 'b':
					m1_pwm(50);
					m2_pwm(50);
					m1_backward();
					m2_backward();
					send_char(c);
					break;
				case 's':
					//m1_pwm(0);
					//m2_pwm(0);
					m1_stop();
					m2_stop();
					send_char(c);
					break;
				case 'r':
					value = fb_read(0);
					v = (float)value * 3.3f / 4096.0f;
					printf("ADC0 = %d (%.3fV) ", value, v);
					value = fb_read(1);
					v = (float)value * 3.3f / 4096.0f;
					printf("ADC1 = %d (%.3fV)\n", value, v);
					break;
			}
	}
}

void signal_detected(int motor){
	printf("Signal on motor %d detected!\n",motor);
}


