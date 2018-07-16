/*
 * signal_flag.c
 *
 *  Created on: 16.07.2018
 *      Author: Micha³M
 */


#include "stm32f1xx.h"
#include "signal_flag.h"

void signal_flag_init(){
	SF_GPIO_CLOCK_ON;

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_IT_FALLING;
	gpio.Pin = M1SF_PIN;
	HAL_GPIO_Init(M1SF_PORT, &gpio);

	gpio.Mode = GPIO_MODE_IT_FALLING;
	gpio.Pin = M2SF_PIN;
	HAL_GPIO_Init(M2SF_PORT, &gpio);

	HAL_NVIC_EnableIRQ(SF_EXTI);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==M1SF_PIN) signal_detected(1);
	if(GPIO_Pin==M2SF_PIN) signal_detected(2);
}
