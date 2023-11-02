/******************************************************************************
 *
 * Module: application
 *
 * File Name: main.c
 *
 * Description: Developing a system that measure the distance and display it on LCD.
 *
 * Author: Bilal Mohamed
 *
 *******************************************************************************/


#include "../HAL/ultrasonic.h"
#include "../HAL/lcd.h"
#include <avr/io.h> /* To use the SREG register */


void main(void)
{
	uint16 distance = 0;

	//Initialize the Ultrasonic driver
	Ultrasonic_init();

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	//Initialize the LCD driver
	LCD_init();

	LCD_displayString("Distance = ");

	while(1)
	{
		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,10);

		LCD_intgerToString(distance);

		if(distance < 10 )
			LCD_displayString("  ");
		else if (distance < 100)
			LCD_displayString(" ");

		LCD_displayString(" cm");
	}
}
