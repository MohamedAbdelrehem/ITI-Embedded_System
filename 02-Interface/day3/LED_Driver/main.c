/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  APP                        *************************/
/************************         SWC:    Main.c                     *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "./COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/4-LIB/STD_TYPES.h"
#include "COTS/2-HAL/0-LED/LED_interface.h"
#include "avr/delay.h"
#include "avr/io.h"
void main()
{
	u8 Local_u8InputValue;

	/*Set pin A0 as input*/
	DIO_u8SetPinDirection(DIO_enumPORTA,DIO_enumPIN0,DIO_enumPIN_INPUT);
	/*Activate Pull-up for pin A0*/
	DIO_u8SetPinValue(DIO_enumPORTA,DIO_enumPIN0,DIO_enumPIN_HIGH);

	//LED Configuration
	LED_str led1 ={LED_enumPORTA,LED_enumPIN1,LED_enumCON_SINK};
	LED_str led2 ={LED_enumPORTA,LED_enumPIN2,LED_enumCON_SOURCE};

	LED_voidInitialization(&led1);
	LED_voidInitialization(&led2);


	while(1){
		//read switch
		DIO_u8GetPinValue(DIO_enumPORTA,DIO_enumPIN0,&Local_u8InputValue);

		if(Local_u8InputValue==0){
			LED_voidToggle(&led1);
			LED_voidToggle(&led2);
			_delay_ms(400);
		}

	}
}
