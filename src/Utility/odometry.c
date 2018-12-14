/*
 * odometry.c
 *
 *  Created on: 14.09.2018
 *      Author: Micha³M
 */

#include "odometry.h"
#include "stm32f1xx.h"
#include "../Encoder/encoder.h"
#include <math.h>

#include "../UART_USB/uart_usb.h"

double P[3]={0,0,0}; //P[0] - x; P[1] - y; P[2] - fi

double d_center(int16_t cr, int16_t cl){
	return (double)(PI*WHEEL_DIAMETER*(cr+cl)/(2.0*OBSERVABLE_POSITIONS_PER_TURN*10.0));
}

double fi(int16_t cr, int16_t cl){
	return (double)((PI*WHEEL_DIAMETER*(double)(cr-cl))/(double)(OBSERVABLE_POSITIONS_PER_TURN*WHEEL_DISTANCE));
}


double * calc_pos(int16_t cr, int16_t cl){
	double dc=d_center(cr, cl);
	double cur_fi=fi(cr,cl);
	P[0]+=(double)(dc*cos(P[2]));
	//P[0]=dc*cos((P[2]*PI)/180+cur_fi/2.0);
	P[1]+=(double)(dc*sin(P[2]));
	//P[1]=dc*sin((P[2]*PI)/180+cur_fi/2.0);
	P[2]+=cur_fi;
	return P;
}
