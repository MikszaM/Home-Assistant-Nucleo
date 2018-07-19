/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "DC_Motor_Driver/signal_flag.h"
#include "Encoder/encoder.h"
#include "UART_USB/uart_usb.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32f1xx_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}
void SF_HANDLER(void)
{
	HAL_GPIO_EXTI_IRQHandler(M1SF_PIN);
	HAL_GPIO_EXTI_IRQHandler(M2SF_PIN);
}
void USART2_IRQHandler(){

	HAL_UART_IRQHandler(&uart);
}
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&encoder2);
}
