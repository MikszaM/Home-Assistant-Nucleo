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


int main(void) {
	//SystemClock_Config();
	SystemCoreClock = 8000000; // taktowanie 8Mhz
	//SysTick_Config(SystemCoreClock / 1000);
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
					m2_forward(100);
					m1_forward(100);
					send_char(c);
					break;
				case 'b':
					m1_backward(30);
					m2_backward(30);
					send_char(c);
					break;
				case 's':
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
				case 'd':
					disable_motors();
					send_char(c);
					break;
				case 'e':
					enable_motors();
					send_char(c);
					break;
			}
	}
}

void signal_detected(int motor){
	printf("Signal on motor %d detected!\n",motor);
}


