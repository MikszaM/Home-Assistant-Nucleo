/*
 * stepper.c
 *
 *  Created on: 18.10.2018
 *      Author: Micha�M
 */

#include "stepper.h"
#include "stm32f1xx.h"
// Konfiguracja silnika krokowego

// Po�o�enie wa�u silnika krokowego
volatile unsigned short step = 0;



void stepMotorConfiguration(void)
{
    // Uruchomienie zegar�w na portach A i C
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // Konfiguracja GPIO
    GPIO_InitTypeDef gpio;
    // Pin C8 - sterowanie kierunkiem obrot�w silnika
    gpio.Pin = GPIO_PIN_7;
    // Konfiguracja jako wyjscie
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    // Rezystory podci�gaj�ce s� wy��czone
    gpio.Pull = GPIO_NOPULL;
    // Niskie cz�stotliwo�ci prze��czania
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    // Inicjalizacja modu�u GPIOC
    HAL_GPIO_Init(GPIOC, &gpio);


    // Pin C6 - zbocze narastaj�ce spowoduje zrobienie kroku
    gpio.Pin = GPIO_PIN_8;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &gpio);

    // Pin A5 - do ustawiania rozdzielczo�ci kroku
    gpio.Pin = GPIO_PIN_3;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &gpio);

    // Pin A6 - do ustawiania rozdzielczo�ci kroku
    gpio.Pin = GPIO_PIN_4;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &gpio);

    // Pin A7 - do ustawiania rozdzielczo�ci kroku
    gpio.Pin = GPIO_PIN_5;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &gpio);

    // Ustawienie pracy sterownika silnika krokowego w trybie 1/16 kroku
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);

    // Wyb�r kierunku obrot�w przeciwnie do ruchu wskaz�wek zegara
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);

    // Inicjalizacja timera TIM2
    STEPPER_CLK_ON;
    stepper1.Instance = STEPPER_TIMER;
    stepper1.Init.Period = 10 - 1;
    stepper1.Init.Prescaler = 400 - 1;
    stepper1.Init.ClockDivision = 0;
    stepper1.Init.CounterMode = TIM_COUNTERMODE_UP;
    stepper1.Init.RepetitionCounter = 0;
    stepper1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&stepper1);
    // Powy�sza konfiguracja wyzwala przerwanie co 0.5 ms


    // W��czenie przerwa� od timera TIM2
    HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);
    // Start timera
    HAL_TIM_Base_Start_IT(&stepper1);
}

//// Obs�uga przerwa� od timera TIM2

// Funkcja generuj�ca sygna� do zrobienia kroku przez silnik krokowy w momencie przerwania od timera
void step_counted(){
//	 Generowane jest zbocze na pinie A6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	// Zwi�kszenie licznika krok�w
	step++;
	// Pe�ny obr�t wa�u przy obecnej konfiguracji wykonuje si� w 200*16 krokach
	step %= 200 * 16;
}



