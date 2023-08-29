/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  APP                        *************************/
/************************         APP:    LCD/KEYPAD                 *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/
#include <stdlib.h>
#include <avr/delay.h>

#include "COTS/4-LIB/STD_TYPES.h"

#include "COTS/2-HAL/4-Keypad/KPD_interface.h"
#include "COTS/2-HAL/3-LCD/CLCD_interface.h"

void resetCalcVars(void);
u16 claculator();
void WelcomeFunc();

u8 u8KeypadVal;
u16 numStr[10]; // To store numeric input string
u16 operands[10],operandsNum=0;
/* operators	*/
u8 operator[10],operatorsNum=0;
/* Result	*/
u16 result = 0;
u8 flag=1;
void main(){
	/* USE KEYPAD_config.h to Configure buttons layout*/
	CLCD_voidInit();
	KPD_voidInit();

	resetCalcVars();

	WelcomeFunc();

	while(1){
		u8KeypadVal=KPD_u8GetPressedKey();
		if(flag){
			CLCD_voidGoToXY(0,0);
			if((u8KeypadVal=='+'||u8KeypadVal=='-'||u8KeypadVal=='/'||u8KeypadVal=='x')){
				flag=0;
				CLCD_voidInit();
				CLCD_voidSendString("ANS");
				operands[operandsNum]= result;
			}else if(u8KeypadVal>=0&&u8KeypadVal<=9)
				CLCD_voidInit();
		}

		if(u8KeypadVal!=KPD_enumNOT_PRESSED){
			if(u8KeypadVal=='C'){
				resetCalcVars();
				//Clear LCD
				CLCD_voidClear();
			}
			else if (u8KeypadVal=='E')
			{
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("Result=");

				result=claculator();
				itoa(result,numStr,10);
				CLCD_voidSendString(numStr);
			}
			else if(u8KeypadVal>=0&&u8KeypadVal<=9){
				flag=0;

				operands[operandsNum]= (operands[operandsNum]*10)+u8KeypadVal;

				itoa(u8KeypadVal,numStr,10);
				CLCD_voidSendString(numStr);
			}
			else
			{
				CLCD_voidSendData(u8KeypadVal);
				operator[operatorsNum] = u8KeypadVal;
				operatorsNum++;
				operandsNum++;
				operator[operatorsNum] = '\0';
			}
		}
	}
}

u16 claculator(){
	u8 Local_u8OpCounter=0;
	u16 Local_u8Result=operands[Local_u8OpCounter];
	while(operator[Local_u8OpCounter] != '\0'){
		switch(operator[Local_u8OpCounter]){
		case '+':
			Local_u8Result+=operands[Local_u8OpCounter+1];
			break;
		case '-':
			Local_u8Result-=operands[Local_u8OpCounter+1];
			break;
		case '/':
			Local_u8Result/=operands[Local_u8OpCounter+1];
			break;
		case 'x':
			Local_u8Result*=operands[Local_u8OpCounter+1];
			break;
		}
		Local_u8OpCounter++;
	}
	flag=1;
	resetCalcVars();
	return Local_u8Result;
}

void resetCalcVars(void)
{
	//clear operands array
	for (int i = 0; i < sizeof(operands) / sizeof(operands[0]); i++) {
		operands[i] = 0; // Set each element to zero
	}
	operandsNum=0;
	//clear operators array
	for (int i = 0; i < sizeof(operator) / sizeof(operator[0]); i++) {
		operator[i] = 0; // Set each element to zero
	}

	operatorsNum=0;
}

void WelcomeFunc(){
	CLCD_voidGoToXY(0,5);
	CLCD_voidSendString("CASIA");
	CLCD_voidGoToXY(1,4);
	CLCD_voidSendString("Welcome");
_delay_ms(700);
CLCD_voidClear();
}
