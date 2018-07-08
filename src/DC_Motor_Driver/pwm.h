/*
 * pwm.h
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#ifndef PWM_H_
#define PWM_H_



#endif /* PWM_H_ */

#define STM_FREQUENCY 8000000
#define PWM_FREQUENCY 10000
#define MAX_DUTY_CYCLE 100 //Duty cycle is now in percents

#define PWM_TIMER TIM3

#define GPIO_PWM_ON __HAL_RCC_GPIOA_CLK_ENABLE()
#define PWM_TIMER_ON __HAL_RCC_TIM3_CLK_ENABLE()

#define M1D2_PWM_1_PORT GPIOA	//Assuming that it's connected to channel 1 and 2
#define M1D2_PWM_1_PIN GPIO_PIN_6	//if not changes required in pwm.c

#define M2D2_PWM_2_PORT GPIOA
#define M2D2_PWM_2_PIN GPIO_PIN_7

void pwm_init();
void set_pwm1(int duty_cycle); //Duty cycle - range from 0 to MAX_DUTY_CYCLE - now 0-100
void set_pwm2(int duty_cycle);
