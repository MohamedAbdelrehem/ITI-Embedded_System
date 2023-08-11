/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

 main.c
-------------------------------------------------------- INTERFACING --------------------------------------------------------
------------------------------------------------------------ DAY 1 ------------------------------------------------------------

---------------------------------------------------- Assignment ----------------------------------------------------

Write a C code that apply 8 different animations on 8 LED string based on the value of 3 way DIP Switch as following:
| DIP Value | LED Action                        |
|-----------|-----------------------------------|
| 1         | Flashing every 500 ms             |
| 2         | Shifting Left every 250 ms        |
| 3         | Shifting Right every 250 ms       |
| 4         | 2-LEDs Converging every 300 ms    |
| 5         | 2-LEDs Diverging every 300 ms     |
| 6         | Ping Pong effect every 250 ms     |
| 7         | Incrementing (Snake effect) 300 ms|
| 8         | 2-LEDs Converging/Diverging 300 ms|

 */

#define F_CPU 8000000UL
#include "avr/io.h"
#include "avr/delay.h"
#include "STD_TYPES.h"
void animationSelect();

void main(void)
{
//	input DIP Switch
	DDRA = 0x00;
	PINA=0xFF;
//	output 8 LEDs
	DDRB = 0xFF;
	PORTB=0x00;
	while(1){
		animationSelect();
	}
}
void animationSelect(){
	static u8 start=1,counter=0;
	u8 right,left;
	switch (PINA) {
				case 0b11111110:
//					Flashing every 500 ms
					PORTB=0xff;
					_delay_ms(500);
					PORTB=0x00;
					_delay_ms(500);
					break;
//		Shifting Left every 250 ms
				case 0b11111101:
					if(start||PORTB==0x00){
						PORTB=0x80;
						start=0;
					}
					_delay_ms(250);
					PORTB>>=1;
					break;
//		Shifting Right every 250 ms
				case 0b11111011:
					if(start||PORTB==0x00){
						PORTB=0x01;
						start=0;
					}
					_delay_ms(250);
					PORTB<<=1;
					break;
//		2-LEDs Converging every 300 ms
				case 0b11110111:
					if(start||counter==4){
						PORTB=0b10000001;
						start=0;
						counter=0;
					}
					_delay_ms(300);
						right=(PORTB&0x0f);
						left=(PORTB&0xf0);
						right<<=1;
						left>>=1;
						PORTB=right|left;
						counter++;
					break;
//		2-LEDs Diverging every 300 ms
				case 0b11101111:
					if(start||PORTB==0x00){
						PORTB=0b00011000;
						start=0;
					}
					_delay_ms(300);
						right=(PORTB&0x0f);
						left=(PORTB&0xf0);
						right>>=1;
						left<<=1;
						PORTB=right|left;
					break;
//		Ping Pong effect every 250 ms
				case 0b11011111:
					if(start||PORTB==0x01){
						PORTB=0x01;
						start=0;
						right=1;
						counter=0;
					}
					_delay_ms(250);
					if(right==1&&counter<7){
						PORTB<<=1;
						counter++;
					}else{
						PORTB>>=1;
					}
					break;
//		Incrementing (Snake effect) every 300 ms
				case 0b10111111:
					if(start){
							PORTB=0x01;
							start=0;
						}
						_delay_ms(250);
						//check if snake is full grown
					if(PORTB==0xFF){
						PORTB=0x01;
						_delay_ms(250);
					}
						PORTB=PORTB<<1|PORTB;

						break;
					break;
//		2-LEDs Converging/Diverging every 300 ms
				case 0b01111111:
					if(start||counter>5){
						PORTB=0b10000001;
						start=0;
						counter=0;
					}
					_delay_ms(300);
						right=(PORTB&0x0f);
						left=(PORTB&0xf0);
						if(counter<3){
							right<<=1;
							left>>=1;
							PORTB=right|left;
							counter++;
						}
						else if(counter>=3){
							right>>=1;
							left<<=1;
							PORTB=right|left;
							counter++;
						}
					break;
//		when all switches off
				default:
					start=1;
					PORTB=0x00;
					break;
			}
}


