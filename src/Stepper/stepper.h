/*
 * stepper.h
 *
 *  Created on: 18.10.2018
 *      Author: Micha³M
 */
#include "stm32f1xx.h"
#ifndef STEPPER_H_
#define STEPPER_H_

#define STEPPER_TIMER TIM1
#define TIM1_INTERRUPT TIM1_UP_IRQn

#define TIM1_INT_HANDLER TIM1_UP_IRQHandler
#define STEPPER_CLK_ON __HAL_RCC_TIM1_CLK_ENABLE()

#endif /* STEPPER_H_ */

void stepMotorConfiguration(void);
TIM_HandleTypeDef stepper1;
void step_counted();
