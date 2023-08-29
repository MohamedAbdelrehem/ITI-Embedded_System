/*
 * ICU.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mohamed
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ICU.h"

void ICU_Init(void){
	/*	Input Capture Noise Canceler */
	SET_BIT(TCCR1B,ICNC1);

	DIO_SetPinMode(DIO_PORTD,DIO_PIN6,DIO_PIN_INPUT_FLOATING);
}

void ICU_SetEdge (ICU_EdgeType Copy_edge)
{

	switch (Copy_edge)
	{
	case ICU_EDGE_FALLING:
		CLR_BIT(TCCR1B,ICES1);
		break;
	case ICU_EDGE_RAISING:
		CLR_BIT(TCCR1B,ICES1);
		break;
	default:
		break;
	}
}


void ICU_EnableNotification(void){
	//enable interrupt capture unit
	SET_BIT(TIMSK,TICIE1);
}

void ICU_DisableNotification(void){
	//enable interrupt capture unit
	CLR_BIT(TIMSK,TICIE1);
}
