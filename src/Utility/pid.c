/*
 * pid.c
 *
 *  Created on: 14.09.2018
 *      Author: Micha³M
 */


#include "pid.h"
#include "stm32f1xx.h"

//#include "../UART_USB/uart_usb.h"

int16_t e, old_e = 0, sum_e = 0;


int16_t pid_calc(int16_t target, int16_t x){
	int16_t y = 0;
	e = target - x;
	sum_e += e;


	y = e*KP + (((e-old_e)*KD*1000)/TP)+((sum_e*TP*KI)/1000);
	if(y>0){
		if(y>Y_UPPER_LIM){
			y=Y_UPPER_LIM;

		}
		if(y<Y_LOWER_LIM) y=0;
	}
	else{
		if(y<-1*Y_UPPER_LIM){
			y=-1*Y_UPPER_LIM;
		}
		if(y>-1*Y_LOWER_LIM)y=0;
	}
//	printf("Pid prop. output: %d\n",(int16_t)(e*KP));
//	printf("Pid deriv. output: %d\n",(int16_t)(((e-old_e)*KD*1000)/TP));
//	printf("Pid integ. output: %d\n",(int16_t)((sum_e*TP*KI)/1000));
//	printf("Pid output: %d\n",y);

	old_e = e;
	return y;
}
int16_t e_2, old_e_2 = 0, sum_e_2 = 0;


int16_t pid_calc_2(int16_t target_2, int16_t x_2){
	int16_t y_2 = 0;
	e_2 = target_2 - x_2;
	sum_e_2 += e_2;


	y_2 = e_2*KP_2 + (((e_2-old_e_2)*KD_2*1000)/TP)+((sum_e_2*TP*KI_2)/1000);
	if(y_2>0){
		if(y_2>Y_UPPER_LIM_2){
			y_2=Y_UPPER_LIM_2;

		}
		if(y_2<Y_LOWER_LIM_2) y_2=0;
	}
	else{
		if(y_2<-1*Y_UPPER_LIM_2){
			y_2=-1*Y_UPPER_LIM_2;
		}
		if(y_2>-1*Y_LOWER_LIM_2)y_2=0;
	}
//	printf("Pid prop. output: %d\n",(int16_t)(e*KP));
//	printf("Pid deriv. output: %d\n",(int16_t)(((e-old_e)*KD*1000)/TP));
//	printf("Pid integ. output: %d\n",(int16_t)((sum_e*TP*KI)/1000));
//	printf("Pid output: %d\n",y);

	old_e_2 = e_2;
	return y_2;
}

