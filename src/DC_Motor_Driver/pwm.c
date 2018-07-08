/*
 * pwm.c
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#include "pwm.h"
#include "stm32f1xx.h"

TIM_HandleTypeDef pwm;

void pwm_init() {

	GPIO_PWM_ON;
	PWM_TIMER_ON;
	GPIO_InitTypeDef gpio;

	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = M1D2_PWM_1_PIN;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(M1D2_PWM_1_PORT, &gpio);

	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = M2D2_PWM_2_PIN;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(M2D2_PWM_2_PORT, &gpio);




	pwm.Instance=PWM_TIMER;
	pwm.Init.Prescaler = (STM_FREQUENCY / PWM_FREQUENCY);
	pwm.Init.Period = MAX_DUTY_CYCLE - 1;
	pwm.Init.CounterMode = TIM_COUNTERMODE_UP;
	pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	pwm.Init.RepetitionCounter = 0;
	if (HAL_TIM_PWM_Init(&pwm) != HAL_OK)
		  {
		    while(1);
		  }

	TIM_OC_InitTypeDef channel;

	channel.OCMode = TIM_OCMODE_PWM1;
	channel.Pulse = 0;
	channel.OCIdleState = TIM_OCIDLESTATE_RESET;
	channel.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	channel.OCFastMode = TIM_OCFAST_DISABLE;
	channel.OCPolarity   = TIM_OCPOLARITY_HIGH;
	channel.OCNPolarity  = TIM_OCNPOLARITY_HIGH;

	HAL_TIM_PWM_ConfigChannel(&pwm,&channel,TIM_CHANNEL_1);

	HAL_TIM_PWM_Start_IT(&pwm,TIM_CHANNEL_1);

	HAL_TIM_PWM_ConfigChannel(&pwm,&channel,TIM_CHANNEL_2);

	HAL_TIM_PWM_Start_IT(&pwm,TIM_CHANNEL_2);
}

void set_pwm1(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_1,duty_cycle);
}
void set_pwm2(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_2,duty_cycle);
}
