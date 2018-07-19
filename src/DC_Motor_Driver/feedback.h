/*
 * feedback.h
 *
 *  Created on: 11.03.2018
 *      Author: Micha³M
 */



#ifndef FEEDBACK_H_
#define FEEDBACK_H_



#endif /* FEEDBACK_H_ */

#define ADC_CHANNELS	2

#define M1FB_PORT GPIOA
#define M1FB_PIN GPIO_PIN_4
#define M1_CHANNEL ADC_CHANNEL_4



#define M2FB_PORT GPIOC
#define M2FB_PIN GPIO_PIN_4
#define M2_CHANNEL ADC_CHANNEL_14

#define FB_GPIO_CLOCK1_ON __HAL_RCC_GPIOA_CLK_ENABLE();
#define FB_GPIO_CLOCK2_ON __HAL_RCC_GPIOC_CLK_ENABLE();

#define FEEDBACK_ADC ADC1
#define FEEDBACK_ADC_ON __HAL_RCC_ADC1_CLK_ENABLE();

void feedback_init();
uint16_t adc_read(int channel);
