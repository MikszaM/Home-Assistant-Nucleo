/*
 * feedback.c
 *
 *  Created on: 11.03.2018
 *      Author: Micha³M
 */

#include "feedback.h"
#include "stm32f1xx.h"

ADC_HandleTypeDef AdcHandle;

void feedback_init() {

	RCC_PeriphCLKInitTypeDef PeriphClkInit;

	__HAL_RCC_ADC1_CLK_ENABLE();
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
	PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

	GPIO_InitTypeDef gpioInit;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	gpioInit.Pin = M1FB_PIN;
	gpioInit.Mode = GPIO_MODE_ANALOG;
	gpioInit.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(M1FB_PORT, &gpioInit);

	ADC_ChannelConfTypeDef adcChannel;

	AdcHandle.Instance = FEEDBACK_ADC;
	AdcHandle.Init.ScanConvMode = DISABLE;
	AdcHandle.Init.ContinuousConvMode = ENABLE;
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle.Init.NbrOfDiscConversion = 1;
	AdcHandle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion = 1;

	HAL_ADC_Init(&AdcHandle);

	adcChannel.Channel = ADC_CHANNEL_1;
	adcChannel.Rank = ADC_REGULAR_RANK_1;
	adcChannel.SamplingTime = ADC_SAMPLETIME_41CYCLES_5;
	HAL_ADC_ConfigChannel(&AdcHandle, &adcChannel);
	HAL_ADC_Start(&AdcHandle);
	adc_calib();
}
int adc_read(int channel) {
	if (HAL_ADC_PollForConversion(&AdcHandle, 1000) == HAL_OK) {
		return HAL_ADC_GetValue(&AdcHandle);
	}
	return -1;
}
void adc_calib(){
	 if (HAL_ADCEx_Calibration_Start(&AdcHandle) != HAL_OK)
	  {
	    /* Calibration Error */
	   // Error_Handler();
	  }
}

