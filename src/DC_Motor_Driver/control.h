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

#define M1_D1_PORT GPIOC
#define M1_D1_PIN GPIO_PIN_0
#define M2_D1_PORT GPIOC
#define M2_D1_PIN GPIO_PIN_1

void dc_driver_init();
void m1_forward(int dc);
void m1_backward(int dc);
void m1_stop();
void m2_forward(int dc);
void m2_backward(int dc);
void m2_stop();
void enable_motors();
void disable_motors();

uint16_t fb_read(int channel);
uint16_t position(uint8_t motor);

