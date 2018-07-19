/*
 * uart_usb.c
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#include "stm32f1xx.h"
#include "uart_usb.h"
#include <string.h>

uint8_t value[DATA_LENGTH];

void send_char(char c) {
	HAL_UART_Transmit(&uart, (uint8_t*) &c, 1, 1000);
	//while (HAL_UART_GetState(&uart) != HAL_UART_STATE_READY){}
	//HAL_UART_Transmit_IT(&uart, (uint8_t*) &c, 1);
}

int __io_putchar(int ch) {
	if (ch == '\n'){
		send_char('\r');
	}
	 send_char(ch);
	 return ch;
}

void usb_uart_init() {
	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = GPIO_PIN_2;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Mode = GPIO_MODE_AF_INPUT;
	gpio.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA, &gpio);

	uart.Instance = USART2;
	uart.Init.BaudRate = BAUDRATE;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	uart.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart);

	HAL_NVIC_EnableIRQ(USART2_IRQn);
	receive_char();
}
void send_string(const char* s) {
	//while (HAL_UART_GetState(&uart) != HAL_UART_STATE_READY){}
	//HAL_UART_Transmit_IT(&uart, (uint8_t*) s, strlen(s) == HAL_BUSY);
    HAL_UART_Transmit(&uart, (uint8_t*) s, strlen(s),1000);
}
void receive_char(){
	HAL_UART_Receive_IT(&uart, &value, DATA_LENGTH);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* uart){
	receive_char();
	data_received(value);
}
