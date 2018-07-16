/*
 * signal_flag.h
 *
 *  Created on: 16.07.2018
 *      Author: Micha³M
 */

#ifndef SIGNAL_FLAG_H_
#define SIGNAL_FLAG_H_



#endif /* SIGNAL_FLAG_H_ */


#define M1SF_PORT GPIOC
#define M1SF_PIN GPIO_PIN_6

#define M2SF_PORT GPIOC
#define M2SF_PIN GPIO_PIN_8

#define SF_EXTI EXTI9_5_IRQn
#define SF_HANDLER EXTI9_5_IRQHandler
#define SF_GPIO_CLOCK_ON __HAL_RCC_GPIOC_CLK_ENABLE();

void signal_flag_init();
