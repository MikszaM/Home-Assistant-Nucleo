/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


/**
 *
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░NUCLEO-F103RB░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█▄▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC10─█12█───PC11░░░░░░░░░░░░░░░░░░░░░░░PC9───█12█─PC8-M2SF░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC12─█34█───PD2░░░░░░░░░░░░░░░░░░M2IN1-PB8─█─█34█─PC6-M1SF░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░VDD─█56█───E5V░░░░░░░░░░░░░░░░░░M2IN2-PB9─█─█56█─PC5░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░BOOT0─█78█───GND░░░░░░░░░░░░░░░░░░░░░░░AVDD─█─█78█─U5V░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░NC─█90█─█─NC░░░░░░░░░░░░░░░░░░░░░░░░░GND─█─█90█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░NC─█12█─█─IOREF░░░░░░░░░░░░░░░░░░LED-PA5─█─█12█─PA12░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA13─█34█─█─RESET░░░░░░░░░░░░░░░░░░░A2-PA6─█─█34█─PA11░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA14─█56█─█─+3V3░░░░░░░░░░░░░░░░░░░░B2-PA7─█─█56█─PB12░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PA15─█78█─█─+5V░░░░░░░░░░░░░░░░░░M1IN1-PB6─█─█78█─PB11-SDA░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░GND─█90█─█─GND░░░░░░░░░░░░░░░░░░░░░░░░PC7─█─█90█─GND░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░M1IN2-PB7─█12█─█─GND░░░░░░░░░░░░░░░░░░░░░░░░PA9─▀─█12█─PB2░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC13─█34█─█─VIN░░░░░░░░░░░░░░░░░░░░░░░░PA8─█─█34█─PB1░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC14─█56█───NC░░░░░░░░░░░░░░░░░░░░SCL-PB10─█─█56█─PB15░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░PC15─█78█─█─PA0-A1░░░░░░░░░░░░░░░░░░░░░PB4─█─█78█─PB14░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PD0─█90█─█─PA1-B1░░░░░░░░░░░░░░░░░░░░░PB5─█─█90█─PB13░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PD1─█12█─█─PA4-M1FB░░░░░░░░░░░░░░░░░░░PB3─█─█12█─AGND░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░VBAT─█34█─█─PB0░░░░░░░░░░░░░░░░░░░░░░░PA10─█─█34█─PC4-M2FB░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PC2─█56█─█─PC1-M2D1░░░░░░░USB_UART_TX-PA2─█─█56█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░PC3─█78█─█─PC0-M1D1░░░░░░░USB_UART_RX-PA3─█─█78█─NC░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█▀▀▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀█░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 *
 */
#include "stm32f1xx.h"
#include "UART_USB/uart_usb.h"
#include "DC_Motor_Driver/control.h"
#include "Encoder/encoder.h"
#include "IMU/imu.h"

//Additional functions
void led_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();

	 GPIO_InitTypeDef gpio;
	 gpio.Pin = GPIO_PIN_5;
	 gpio.Mode = GPIO_MODE_OUTPUT_PP;
	 gpio.Pull = GPIO_NOPULL;
	 gpio.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOA, &gpio);

}

volatile char c;
volatile uint16_t ms_passed;
uint16_t period=100;
volatile uint16_t var=0;


//Main function
int main(void) {
	SystemCoreClock = 8000000;
	HAL_Init();
	usb_uart_init();
	printf("Hello world !\n");
	//dc_driver_init();
	imu_init();

	led_init();

	uint16_t value;
	uint8_t hours;
	uint8_t my_hour;

	float v;
	int16_t a_x,a_y,a_z,g_x,g_y,g_z,m_x,m_y,m_z;
	float ax,ay,az,gx,gy,gz,mx,my,mz,br;
	uint32_t b_r;
	while (1) {

		switch (c) {
			case 'f':
				m2_forward(100);
				m1_forward(100);
				send_string("Full speed forward\r\n");
				c=' ';
				break;
			case 'q':
				m1_backward(30);
				m2_backward(30);
				send_string("30% speed backward\r\n");
				c=' ';
				break;
			case 's':
				m1_stop();
				m2_stop();
				send_string("Motors stop\r\n");
				c=' ';
				break;
			case 'r':
				value = fb_read(0);
				v = (float)value * 3.3f / 4096.0f;
				printf("ADC0 = %d (%.3fV)\n", value, v);
				value = fb_read(1);
				v = (float)value * 3.3f / 4096.0f;
				printf("ADC1 = %d (%.3fV)\n", value, v);
				c=' ';
				break;
			case 'd':
				disable_motors();
				send_string("Motors disabled\r\n");
				c=' ';
				break;
			case 'e':
				enable_motors();
				send_string("Motors enabled\r\n");
				c=' ';
				break;
			case 'l':
				printf("%.3f\n",PI*WHEEL_DIAMETER);
				c=' ';
				break;
			case 'h':
				hours=read_hour();
				printf("%d\n",hours);
				c=' ';
				break;
			case 'w':
				my_hour=19;
				write_hour(my_hour);
				c=' ';
				break;
			case 'c':
				printf("Acc and gyro: (0x%02X)\n", read_register8(ACC_AND_GYRO_ADDRESS,0x0f));
				printf("Magnetometer: (0x%02X)\n", read_register8(MAGNETOMETER_ADDRESS,0x0f));
				printf("Barometer: (0x%02X)\n", read_register8(BAROMETER_ADDRESS,0x0f));
				printf("Acc enabled?: (0x%02X)\n", read_register8(ACC_AND_GYRO_ADDRESS,0x10));
				printf("Gyro enabled?: (0x%02X)\n", read_register8(ACC_AND_GYRO_ADDRESS,0x11));
				printf("Magn enabled?: (0x%02X)\n", read_register8(MAGNETOMETER_ADDRESS,0x22));
				printf("Baro enabled?: (0x%02X)\n", read_register8(BAROMETER_ADDRESS,0x20));

				c=' ';
				break;
			case 'p':
				acc_init();
				gyro_init();
				magn_init();
				baro_init();
				break;
			case 'a':
				a_x = read_acc('x');
				a_y = read_acc('y');
				a_z = read_acc('z');
				ax = a_x * ACC_MAX / ACC_BITS;
				ay = a_y * ACC_MAX / ACC_BITS;
				az = a_z * ACC_MAX / ACC_BITS;
				printf("X = %.2f   Y = %.2f   Z = %.2f\n", ax, ay, az);
				break;
			case 'g':
				g_x = read_gyro('x');
				g_y = read_gyro('y');
				g_z = read_gyro('z');
				gx = g_x * GYRO_MAX / GYRO_BITS;
				gy = g_y * GYRO_MAX / GYRO_BITS;
				gz = g_z * GYRO_MAX / GYRO_BITS;
				printf("X = %.2f   Y = %.2f   Z = %.2f\n", gx, gy, gz);
				break;
			case 'm':
				m_x = read_magn('x');
				m_y = read_magn('y');
				m_z = read_magn('z');
				mx = m_x * MAGN_MAX / MAGN_BITS;
				my = m_y * MAGN_MAX / MAGN_BITS;
				mz = m_z * MAGN_MAX / MAGN_BITS;
				printf("X = %.2f   Y = %.2f   Z = %.2f\n", mx, my, mz);
				break;
			case 'b':
				b_r = read_baro();
				br = b_r / BARO_BITS;
				printf("Baro = %.2f  \n", br);
				break;
			}
		 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		 HAL_Delay(100);
		 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		 HAL_Delay(100);
	}
}

//Interrupt handlers - remember to  o keep them as short as possible
void signal_detected(int motor){
	printf("Error signal on motor %d detected!\n",motor);
}

void data_received(char data[DATA_LENGTH]){
	c=data[0];
	send_string("Received data : ");
	for(int i = 0; i<DATA_LENGTH;i++){
		send_char(data[i]);
	}
	send_string("\n\r");

}
void enc_counted(uint8_t motor){
	printf("Counter: %d\n",get_position(motor));
	printf("Full turns: %d\n",get_full_turns(motor));
	printf("Part turns: %d\n",get_part_turns(motor));
	printf("Positions: %d\n",get_observable_positions(motor));
}


void HAL_SYSTICK_Callback(){
	ms_passed++;
	if(ms_passed%period==0){
		//send_string("One second passed\r");
		//var+=1;
		//if(var>10) var = 0;
		//printf("%d %d\n",var,var+1);
	}
}
