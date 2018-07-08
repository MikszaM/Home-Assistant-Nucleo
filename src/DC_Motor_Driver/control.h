/*
 * control.h
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#ifndef CONTROL_H_
#define CONTROL_H_



#endif /* CONTROL_H_ */

#define GPIO_CONTROL_ON __HAL_RCC_GPIOC_CLK_ENABLE()

#define M1_IN1_PORT GPIOC
#define M1_IN1_PIN GPIO_PIN_0
#define M1_IN2_PORT GPIOC
#define M1_IN2_PIN GPIO_PIN_1

#define M2_IN1_PORT GPIOC
#define M2_IN1_PIN GPIO_PIN_3
#define M2_IN2_PORT GPIOC
#define M2_IN2_PIN GPIO_PIN_2

void driver_init();
void m1_forward();
void m1_backward();
void m1_stop();
void m2_forward();
void m2_backward();
void m2_stop();
void m1_pwm(int dc);	//for informations about dc - duty cycle go to the pwm.h
void m2_pwm(int dc);
int fb_read(int channel);


