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
#include "COTS/2-HAL/1-SW/SW_interface.h"
#include "COTS/2-HAL/0-LED/LED_interface.h"
#include "avr/delay.h"
#include "avr/io.h"
void main()
{

	SW_str button1 = {SW_enumPORTA,SW_enumPIN0,SW_enumPullUpInternal};

	SW_voidInitialize(&button1);

	//LED Configuration
	LED_str led1 ={LED_enumPORTA,LED_enumPIN1,LED_enumCON_SINK};
	LED_str led2 ={LED_enumPORTA,LED_enumPIN2,LED_enumCON_SOURCE};


	LED_voidInitialization(&led1);
	LED_voidInitialization(&led2);

	while(1){

		if(SW_enumGetValue(&button1)==SW_enumON){
			LED_voidToggle(&led1);
			LED_voidToggle(&led2);
			_delay_ms(400);
		}
	}
}




