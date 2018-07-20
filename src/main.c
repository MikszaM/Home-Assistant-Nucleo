/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


/**
 *
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░NUCLEO-F103RB░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█▄▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC10─█12█───PC11-░░░░░░░░░░░░░░░░░░░░░░PC9───█12█─PC8-M2SF░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC12─█34█───PD2░░░░░░░░░░░░░░░░░░M2IN1-PB8─█─█34█─PC6-M1SF░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░VDD─█56█───E5V░░░░░░░░░░░░░░░░░░M2IN2-PB9─█─█56█─PC5░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░BOOT0─█78█───GND░░░░░░░░░░░░░░░░░░░░░░░AVDD─█─█78█─U5V░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░NC─█90█─█─NC░░░░░░░░░░░░░░░░░░░░░░░░░GND─█─█90█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░NC─█12█─█─IOREF░░░░░░░░░░░░░░░░░░LED-PA5─█─█12█─PA12░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA13─█34█─█─RESET░░░░░░░░░░░░░░░░░░░A2-PA6─█─█34█─PA11░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA14─█56█─█─+3V3░░░░░░░░░░░░░░░░░░░░B2-PA7─█─█56█─PB12░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA15─█78█─█─+5V░░░░░░░░░░░░░░░░░░M1IN1-PB6─█─█78█─PB11░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░GND─█90█─█─GND░░░░░░░░░░░░░░░░░░░░░░░░PC7─█─█90█─GND░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░M1IN2-PB7─█12█─█─GND░░░░░░░░░░░░░░░░░░░░░░░░PA9─▀─█12█─PB2░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC13─█34█─█─VIN░░░░░░░░░░░░░░░░░░░░░░░░PA8─█─█34█─PB1░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC14─█56█───NC░░░░░░░░░░░░░░░░░░░░░░░░PB10─█─█56█─PB15░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC15─█78█─█─PA0-A1░░░░░░░░░░░░░░░░░░░░░PB4─█─█78█─PB14░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PD0─█90█─█─PA1-B1░░░░░░░░░░░░░░░░░░░░░PB5─█─█90█─PB13░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PD1─█12█─█─PA4-M1FB░░░░░░░░░░░░░░░░░░░PB3─█─█12█─AGND░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░VBAT─█34█─█─PB0░░░░░░░░░░░░░░░░░░░░░░░PA10─█─█34█─PC4-M2FB░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PC2─█56█─█─PC1-M2D1░░░░░░░USB_UART_TX-PA2─█─█56█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PC3─█78█─█─PC0-M1D1░░░░░░░USB_UART_RX-PA3─█─█78█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█▀▀▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 *
 */
#include "stm32f1xx.h"
#include "UART_USB/uart_usb.h"
#include "DC_Motor_Driver/control.h"
#include "Encoder/encoder.h"

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
void turn_counted(){
	printf("Counter: %d\n",get_position(1));
	printf("Full turns: %d\n",get_full_turns(1));
	printf("Part turns: %d\n",get_part_turns(1));
	printf("Positions: %d\n",get_observable_positions(1));
}

