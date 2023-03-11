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

//Where is the led connected ?
// PORT: A
// PIN: 5
#include <stdint.h>

#define PERIPH_BASE        (0X40000000UL)
#define AHB1PERIPH_OFFSET  (0X00020000UL)
#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET       (0x0000UL) //0x 0000 0000

#define GPIOA_BASE 		   (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET 		   (0x3800UL)
#define RCC_BASE           (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN			   (1U<<0) // shift 1 to position 0

#define PIN5 			   (1U<<5)
#define LED_PIN 			PIN5

#define ___IO volatile

typedef struct
{
	volatile uint32_t MODER; /* GPIO port mode register, address offset:0x00 */
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR; /* GPIO port output data register, address offset: 0x14*/
} GPIO_TypeDef;


typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR; /* RCC AHB1 peripheral clock register */
} RCC_TypeDef;



#define RCC   ((RCC_TypeDef*) RCC_BASE)
#define GPIOA ((GPIO_TypeDef*) GPIOA_BASE)


int main(void){
	/* Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* Set PA5 as output pin */
	GPIOA->MODER |= (1U<<10); // Set bit 10 to 1
	GPIOA->MODER &=~(1U<<11); // Set bit 11 to 0

	while(1)
	{
		// Set PA5 High i.e turn on the LED
//		GPIOA->ODR |= LED_PIN;

		// Toggle PA5
		GPIOA->ODR ^= LED_PIN; // Set bit 11 to 0

		// Add delay
		for(int i=0;i<100000; i++){

		}


	}
}


