//#include "COTS/4-LIB/STD_TYPES.h"

#include "COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/2-HAL/3-LCD/CLCD_interface.h"
#include "COTS/2-HAL/1-SW/SW_interface.h"

void main()
{
	u8 Local_u8CLCDFlag=0;

#define CLCD_NO_STRING 0
#define CLCD_CONTAIN_STRING 1


	SW_str sw1 = {SW_enumPORTB,SW_enumPIN0,SW_enumPullUpInternal};
	SW_str sw2 = {SW_enumPORTB,SW_enumPIN1,SW_enumPullUpInternal};

	CLCD_voidInit();
	SW_voidInit(&sw1);
	SW_voidInit(&sw2);
	DIO_u8SetPinDirection(DIO_enumPORTB,DIO_enumPIN2,DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_enumPORTB,DIO_enumPIN3,DIO_enumPIN_OUTPUT);
	while(1){
		if(SW_enumGetValue(&sw1)==SW_enumON){
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN2,DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN3,DIO_enumPIN_LOW);
			CLCD_voidClear();
			CLCD_voidSendString("Clockwise");
			while(SW_enumGetValue(&sw1)==SW_enumON){

			}
		}else if(SW_enumGetValue(&sw2)==SW_enumON){
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN3,DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN2,DIO_enumPIN_LOW);
			CLCD_voidClear();
			CLCD_voidSendString("Counter Clock");
			while(SW_enumGetValue(&sw2)==SW_enumON){

			}
		}else{
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN3,DIO_enumPIN_LOW);
			DIO_u8SetPinValue(DIO_enumPORTB,DIO_enumPIN2,DIO_enumPIN_LOW);
			CLCD_voidClear();
			CLCD_voidSendString("Motor Stopped");
			while(SW_enumGetValue(&sw1)==SW_enumOFF&&SW_enumGetValue(&sw2)==SW_enumOFF){

			}
		}

	}
}
