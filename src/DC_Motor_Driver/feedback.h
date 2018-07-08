/*
 * feedback.h
 *
 *  Created on: 11.03.2018
 *      Author: Micha³M
 */

#ifndef FEEDBACK_H_
#define FEEDBACK_H_



#endif /* FEEDBACK_H_ */

#define M1FB_PORT GPIOA
#define M1FB_PIN GPIO_PIN_0
#define M2FB_PORT GPIOA
#define M2FB_PIN GPIO_PIN_1

#define FEEDBACK_ADC ADC1
#define FEEDBACK_ADC_ON RCC_APB2Periph_ADC1

void feedback_init();
int adc_read(int channel);
void adc_calib();
