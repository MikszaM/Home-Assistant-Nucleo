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
		gpio.Pin = M1IN1_PWM_1_PIN;
		gpio.Pull = GPIO_NOPULL;
		gpio.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(M1IN1_PWM_1_PORT, &gpio);

		gpio.Pin = M1IN2_PWM_2_PIN;
		HAL_GPIO_Init(M1IN2_PWM_2_PORT, &gpio);

		gpio.Pin = M2IN1_PWM_3_PIN;
		HAL_GPIO_Init(M2IN1_PWM_3_PORT, &gpio);

		gpio.Pin = M2IN2_PWM_4_PIN;
		HAL_GPIO_Init(M2IN2_PWM_4_PORT, &gpio);

		pwm.Instance = PWM_TIMER;
		pwm.Init.Period = MAX_DUTY_CYCLE - 1;
		pwm.Init.Prescaler = (STM_FREQUENCY/PWM_FREQUENCY) - 1;
		pwm.Init.ClockDivision = 0;
		pwm.Init.CounterMode = TIM_COUNTERMODE_UP;
		pwm.Init.RepetitionCounter = 0;
		pwm.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		HAL_TIM_PWM_Init(&pwm);

		TIM_OC_InitTypeDef oc;
		oc.OCMode = TIM_OCMODE_PWM1;
		oc.Pulse = 0;
		oc.OCPolarity = TIM_OCPOLARITY_HIGH;
		oc.OCNPolarity = TIM_OCNPOLARITY_LOW;
		oc.OCFastMode = TIM_OCFAST_ENABLE;
		oc.OCIdleState = TIM_OCIDLESTATE_SET;
		oc.OCNIdleState = TIM_OCNIDLESTATE_RESET;
		HAL_TIM_PWM_ConfigChannel(&pwm, &oc, TIM_CHANNEL_1);

		oc.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&pwm, &oc, TIM_CHANNEL_2);

		oc.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&pwm, &oc, TIM_CHANNEL_3);

		oc.Pulse = 0;
		HAL_TIM_PWM_ConfigChannel(&pwm, &oc, TIM_CHANNEL_4);

		HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_3);
		HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_4);

}

void set_pwm1(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_1,duty_cycle);
}
void set_pwm2(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_2,duty_cycle);
}
void set_pwm3(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_3,duty_cycle);
}
void set_pwm4(int duty_cycle){
	__HAL_TIM_SET_COMPARE(&pwm,TIM_CHANNEL_4,duty_cycle);
}



