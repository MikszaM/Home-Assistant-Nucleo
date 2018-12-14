/*
 * encoder.h
 *
 *  Created on: 18.07.2018
 *      Author: Micha³M
 */
#include "stm32f1xx.h"

#ifndef ENCODER_H_
#define ENCODER_H_



#endif /* ENCODER_H_ */

#define ENCODER_TIMER1 TIM2
#define ENCODER_TIMER2 TIM3

#define TIM2_INTERRUPT TIM2_IRQn
#define TIM3_INTERRUPT TIM3_IRQn

#define TIM2_INT_HANDLER TIM2_IRQHandler
#define TIM3_INT_HANDLER TIM3_IRQHandler

#define GPIO_ENCODER_ON __HAL_RCC_GPIOA_CLK_ENABLE()
#define ENCODER1_CLK_ON __HAL_RCC_TIM2_CLK_ENABLE()
#define ENCODER2_CLK_ON __HAL_RCC_TIM3_CLK_ENABLE()

#define A1_ENCODER1_1_PORT GPIOA
#define A1_ENCODER1_1_PIN GPIO_PIN_0

#define B1_ENCODER1_2_PORT GPIOA
#define B1_ENCODER_2_PIN GPIO_PIN_1

#define A2_ENCODER2_1_PORT GPIOA
#define A2_ENCODER2_1_PIN GPIO_PIN_6

#define B2_ENCODER2_2_PORT GPIOA
#define B2_ENCODER2_2_PIN GPIO_PIN_7

#define TICKS_PER_TURN 1920
#define OBSERVABLE_POSITIONS_PER_TURN 120




TIM_HandleTypeDef encoder1;
TIM_HandleTypeDef encoder2;
TIM_Encoder_InitTypeDef encConfig;

void encoder_init();
void enc1_counted();
void enc2_counted();
uint16_t  get_position(uint8_t motor);
int16_t  get_full_turns(uint8_t motor);
int16_t  get_part_turns(uint8_t motor);
int16_t  get_observable_positions(uint8_t motor);
