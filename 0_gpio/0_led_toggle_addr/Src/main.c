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

#define PERIPH_BASE        (0X40000000UL)
#define AHB1PERIPH_OFFSET  (0X00020000UL)
#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET       (0x0000UL) //0x 0000 0000

#define GPIOA_BASE 		   (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET 		   (0x3800UL)
#define RCC_BASE           (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET    (0x30UL)
#define RCC_AHB1EN_R	   (*(volatile unsigned int *) (RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET      (0x00UL)
#define GPIOA_MODE_R       (*(volatile unsigned int *) (GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET 	   (0x14UL)
#define GPIOA_OD_R		   (*(volatile unsigned int *) (GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN			   (1U<<0) // shift 1 to position 0

#define PIN5 			   (1U<<5)
#define LED_PIN 			PIN5



int main(void){
	/* Enable clock access to GPIOA */
	RCC_AHB1EN_R |= GPIOAEN;

	/* Set PA5 as output pin */
	GPIOA_MODE_R |= (1U<<10); // Set bit 10 to 1
	GPIOA_MODE_R &=~(1U<<11); // Set bit 11 to 0

	while(1)
	{
		// Set PA5 High i.e turn on the LED
//		GPIOA_OD_R |= LED_PIN;

		// Toggle PA5
		GPIOA_OD_R ^= LED_PIN;

		// Add delay
		for(int i=0;i<100000; i++){

		}


	}
}


