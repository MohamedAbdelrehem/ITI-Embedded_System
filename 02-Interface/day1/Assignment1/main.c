/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

 main.c
-------------------------------------------------------- INTERFACING --------------------------------------------------------
------------------------------------------------------------ DAY 1 ------------------------------------------------------------

---------------------------------------------------- Assignment ----------------------------------------------------

Write a C code that simulate the traffic lightening system:
1- Turn On Green LED for 10 seconds
2- Turn On Yellow LED for 3 seconds
3- Turn On Red LED for 10 seconds
4- Apply these forever while counting the seconds down on a
two 7-segment displays.
 */
# define F_CPU 8000000UL
#include "avr/io.h"
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "SevenSegments.h"


void time7Seg(int val);

void main(void){
	//setup I/O
	DDRA=0xFF;
	DDRB=0xFF;
	PORTA=0x00;
	PORTA=0x00;
	while(1){
		PORTA=0x01;
		time7Seg(10);
		PORTA=0x02;
		time7Seg(3);
		PORTA=0x04;
		time7Seg(10);
	}
}

void time7Seg(int val){
	while(val!=0){
		if(val==10){
			PORTB=Seven_Segment(0);
			SET_BIT(PORTB,7);
		}else{

			PORTB=Seven_Segment(val);

		}
			_delay_ms(1000);

		val--;
	}
}
