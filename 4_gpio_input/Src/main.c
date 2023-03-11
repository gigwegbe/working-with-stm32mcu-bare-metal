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
#define PIN5	(1U<<5)
#define LED_PIN PIN5

int main(void)
{

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

	while(1)
	{
		GPIOA->BSRR = LED_PIN;
		for (int i=0;i<100000;i++){}

		GPIOA->BSRR = (1U<<21);
		for (int i=0;i<100000;i++){}
	}
}
