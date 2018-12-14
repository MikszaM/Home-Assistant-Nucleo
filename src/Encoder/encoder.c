/*
 * encoder.c
 *
 *  Created on: 18.07.2018
 *      Author: Micha³M
 */

#include "stm32f1xx.h"
#include "encoder.h"

int16_t observable_positions[2]={0,0};
int16_t full_turns[2]={0,0};
int16_t part_turns[2]={0,0};

void encoder_init(){
	  ENCODER1_CLK_ON;
	  ENCODER2_CLK_ON;
	  GPIO_ENCODER_ON;


	  encoder1.Instance = ENCODER_TIMER1;
	  encoder1.Init.Prescaler = 0;
	  encoder1.Init.CounterMode = TIM_COUNTERMODE_UP;
	  encoder1.Init.Period = (TICKS_PER_TURN/OBSERVABLE_POSITIONS_PER_TURN)-1;
	  encoder1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  encoder1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	  encConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	  encConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	  encConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	  encConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	  encConfig.IC1Filter = 15;
	  encConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	  encConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	  encConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	  encConfig.IC2Filter = 15;
	  HAL_TIM_Encoder_Init(&encoder1, &encConfig);

	  HAL_TIM_Encoder_Start(&encoder1, TIM_CHANNEL_ALL);
	  __HAL_TIM_CLEAR_IT(&encoder1, TIM_IT_UPDATE );
	  HAL_NVIC_EnableIRQ(TIM2_INTERRUPT);

	  HAL_TIM_Base_Start_IT(&encoder1);

	  encoder2.Instance = ENCODER_TIMER2;
	  encoder2.Init.Prescaler = 0;
	  encoder2.Init.CounterMode = TIM_COUNTERMODE_UP;
	  encoder2.Init.Period = (TICKS_PER_TURN/OBSERVABLE_POSITIONS_PER_TURN)-1;
	  encoder2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  encoder2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  HAL_TIM_Encoder_Init(&encoder2, &encConfig);

	  HAL_TIM_Encoder_Start(&encoder2, TIM_CHANNEL_ALL);
	  __HAL_TIM_CLEAR_IT(&encoder2, TIM_IT_UPDATE );
	  HAL_NVIC_EnableIRQ(TIM3_INTERRUPT);


	  HAL_TIM_Base_Start_IT(&encoder2);

}
int16_t get_full_turns(uint8_t motor){
	return full_turns[motor];
}
int16_t get_part_turns(uint8_t motor){
	return part_turns[motor];
}
int16_t get_observable_positions(uint8_t motor){
	return observable_positions[motor];
}
uint16_t  get_position(uint8_t motor){
	if(motor==0) return ENCODER_TIMER1->CNT;
	if (motor==1) return ENCODER_TIMER2->CNT;
	else return -1;
}

void enc1_counted(){
	if(get_position(1)<(TICKS_PER_TURN/(2*OBSERVABLE_POSITIONS_PER_TURN))){
		observable_positions[1]++;
	}
	else{
		observable_positions[1]--;
	}
	full_turns[1]=observable_positions[1]/OBSERVABLE_POSITIONS_PER_TURN;
	part_turns[1]=observable_positions[1]-(OBSERVABLE_POSITIONS_PER_TURN* full_turns[1]);
}
void enc2_counted(){
	if(get_position(0)<(TICKS_PER_TURN/(2*OBSERVABLE_POSITIONS_PER_TURN))){
		observable_positions[0]++;
	}
	else{
		observable_positions[0]--;
	}
	full_turns[0]=observable_positions[0]/OBSERVABLE_POSITIONS_PER_TURN;
	part_turns[0]=observable_positions[0]-(OBSERVABLE_POSITIONS_PER_TURN* full_turns[0]);

}



