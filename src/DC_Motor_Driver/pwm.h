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
#define PWM_FREQUENCY 8000
#define MAX_DUTY_CYCLE 100 //Duty cycle is now in percents

#define PWM_TIMER TIM4

#define GPIO_PWM_ON __HAL_RCC_GPIOB_CLK_ENABLE()
#define PWM_TIMER_ON __HAL_RCC_TIM4_CLK_ENABLE()

#define M1IN1_PWM_1_PORT GPIOB	//Assuming that it's connected to channel 1 and 2
#define M1IN1_PWM_1_PIN GPIO_PIN_6	//if not changes required in pwm.c

#define M1IN2_PWM_2_PORT GPIOB
#define M1IN2_PWM_2_PIN GPIO_PIN_7

#define M2IN1_PWM_3_PORT GPIOB
#define M2IN1_PWM_3_PIN GPIO_PIN_8

#define M2IN2_PWM_4_PORT GPIOB
#define M2IN2_PWM_4_PIN GPIO_PIN_9


void pwm_init();
void set_pwm1(int duty_cycle); //Duty cycle - range from 0 to MAX_DUTY_CYCLE - now 0-100
void set_pwm2(int duty_cycle);
void set_pwm3(int duty_cycle);
void set_pwm4(int duty_cycle);
