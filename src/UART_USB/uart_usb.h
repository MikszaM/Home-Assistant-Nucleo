/*
 * uart_usb.h
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#include "stm32f1xx.h"
#ifndef UART_USB_H_
#define UART_USB_H_



#endif /* UART_USB_H_ */

#define BAUDRATE 115200
#define DATA_LENGTH 1

UART_HandleTypeDef uart;

void send_string(const char* s);
void send_char(char c);
int __io_putchar(int ch);
void usb_uart_init();
void receive_char(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* uart);
