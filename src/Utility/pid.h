/*
 * pid.h
 *
 *  Created on: 14.09.2018
 *      Author: Micha³M
 */

#ifndef PID_H_
#define PID_H_
#include "stm32f1xx.h"

#endif /* PID_H_ */

//#define TP 10
//#define KP 2.0f
//#define KD 0.05f
//#define KI 0.5f

#define TP 10
#define KP 2.4f
#define KD 0.1f
#define KI 0.0f

#define KP_2 2.4f
#define KD_2 0.1f
#define KI_2 0.0f

#define Y_UPPER_LIM 30
#define Y_LOWER_LIM 7

#define Y_UPPER_LIM_2 60
#define Y_LOWER_LIM_2 14

void pid_init(float new_kp,float new_kd,float new_ki, uint16_t new_ylim);
int16_t pid_calc(int16_t target, int16_t x);
int16_t pid_calc_2(int16_t target_2, int16_t x_2);
