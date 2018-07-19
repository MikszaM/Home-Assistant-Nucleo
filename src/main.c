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

//Additional functions
void led_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();

	 GPIO_InitTypeDef gpio;
	 gpio.Pin = GPIO_PIN_5;
	 gpio.Mode = GPIO_MODE_OUTPUT_PP;
	 gpio.Pull = GPIO_NOPULL;
	 gpio.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOA, &gpio);

}

volatile char c;
//Main function
int main(void) {
	SystemCoreClock = 8000000;
	HAL_Init();
	usb_uart_init();
	printf("Hello world !\n");
	dc_driver_init();



	led_init();

	uint16_t value;
	while (1) {
		float v;
		switch (c) {
			case 'f':
				m2_forward(100);
				m1_forward(100);
				send_string("Full speed forward\r\n");
				c=' ';
				break;
			case 'b':
				m1_backward(30);
				m2_backward(30);
				send_string("30% speed backward\r\n");
				c=' ';
				break;
			case 's':
				m1_stop();
				m2_stop();
				send_string("Motors stop\r\n");
				c=' ';
				break;
			case 'r':
				value = fb_read(0);
				v = (float)value * 3.3f / 4096.0f;
				printf("ADC0 = %d (%.3fV) ", value, v);
				value = fb_read(1);
				v = (float)value * 3.3f / 4096.0f;
				printf("ADC1 = %d (%.3fV)\n", value, v);
				c=' ';
				break;
			case 'd':
				disable_motors();
				send_string("Motors disabled\r\n");
				c=' ';
				break;
			case 'e':
				enable_motors();
				send_string("Motors enabled\r\n");
				c=' ';
				break;
			}
		 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		 HAL_Delay(100);
		 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		 HAL_Delay(100);
	}
}

//Interrupt handlers - remember to  o keep them as short as possible
void signal_detected(int motor){
	printf("Error signal on motor %d detected!\n",motor);
}

void data_received(char data[DATA_LENGTH]){
	c=data[0];
	send_string("Received data : ");
	for(int i = 0; i<DATA_LENGTH;i++){
		send_char(data[i]);
	}
	send_string("\n\r");

}


