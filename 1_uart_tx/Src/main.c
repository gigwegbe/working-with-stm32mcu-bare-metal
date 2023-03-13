/**
 ******************************************************************************
 * @file           : main.c
 * @author         : George Igwegbe
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f446xx.h"


#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)

int main(void)
{

	while(1)
	{


	}
}

void uar2_tx_init(void){
	/**********Configure the uart gpio pin********/
	/*Enable clock access to gpioa*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER &=~(1U<<5);

	/*Set PA2 alternate function type to UART_TX (AFO7)*/
	GPIOA->AFR[0] != (1U<<8);
	GPIOA->AFR[0] != (1U<<9);
	GPIOA->AFR[0] != (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/**********Configure the uart module*********/

	/*Enable clock access to uart2*/
	RCC->APB1ENR |= UART2EN;

	/*Confgure baudrare*/
	/*Configure the tranfer direction*/
	/*Enable uart module*/

}
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk){

}

static compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate){
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
