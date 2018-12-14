/*
 * odometry.h
 *
 *  Created on: 14.09.2018
 *      Author: Micha³M
 */

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

#define WHEEL_DIAMETER 90
#define WHEEL_DISTANCE 188

#define PI 3.1415926

#define TPPOS 100

#include "stm32f1xx.h"

#endif /* ODOMETRY_H_ */

double * calc_pos(int16_t cr, int16_t cl);
