/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed
 */

#include "COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/1-MCAL/3-EXTI/EXTI_interface.h"
#include "COTS/2-HAL/1-SW/SW_interface.h"
#include "COTS/2-HAL/0-LED/LED_interface.h"

	LED_str led1={LED_enumPORTC,LED_enumPIN0,LED_enumCON_SOURCE};
	SW_str sw1={SW_enumPORTD,SW_enumPIN2,SW_enumPullUpInternal};
void main(){
	EXTI_voidInterruptInit();
	EXTI_voidInterruptPinEnable(EXTI_enumINT0);
	GIE_voidEnable();

	SW_voidInit(&sw1);
	LED_voidInit(&led1);
	LED_voidTurnOff(&led1);

	while(1){

	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	LED_voidToggle(&led1);
	EXTI_voidInterruptPinDisable(EXTI_enumINT0);

}
