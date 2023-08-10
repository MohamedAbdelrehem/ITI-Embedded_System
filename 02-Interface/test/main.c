/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamed
 */
#include "avr/io.h"
#include "BIT_MATH.h"
# define F_CPU 8000000UL
#include "avr/delay.h"
void main(void){
	DDRA = 0xff;
	PORTA = 1;
			_delay_ms(500);
	while(1)
	{
		for(int i=0;i<7;i++){
			PORTA<<=1;
			_delay_ms(500);
		}
		for(int i=0;i<7;i++){
					PORTA>>=1;
					_delay_ms(500);
				}

	}
}
