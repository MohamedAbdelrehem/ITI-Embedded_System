
#include "avr/delay.h"
#include "COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/1-MCAL/3-EXTI/EXTI_interface.h"
#include "COTS/2-HAL/1-SW/SW_interface.h"
#include "COTS/2-HAL/0-LED/LED_interface.h"
#include "COTS/2-HAL/5-Stepper/STEPPER_interface.h"
#include "COTS/2-HAL/3-LCD/CLCD_interface.h"
#include "COTS/2-HAL/4-Keypad/KPD_interface.h"
#include "COTS/2-HAL/Servo/servo.h"
#include <string.h>
#include <stdlib.h>

/* Custome Char */
u8 letter1arr[8]={
		0b11000,
		0b11010,
		0b00010,
		0b11110,
		0b11100,
		0b11100,
		0b10100 };
u8 letter2arr[8]={
		0b11000,
		0b11001,
		0b00001,
		0b11110,
		0b11100,
		0b11100,
		0b10100 };

/* Stepper Motor INIT */

STEPPER_str stepper_x ={STEPPER_enumPORTA,STEPPER_enumPIN0,STEPPER_enumPIN1,STEPPER_enumPIN2,STEPPER_enumPIN3,0};
STEPPER_str stepper_y ={STEPPER_enumPORTD,STEPPER_enumPIN3,STEPPER_enumPIN4,STEPPER_enumPIN6,STEPPER_enumPIN7,1};


void welcome(void);
void medNo(u8 no);


u8 u8KeypadVal;

void main(){
	CLCD_voidInit();
	KPD_voidInit();
	STEPPER_voidInit(&stepper_x);
	STEPPER_voidInit(&stepper_y);

	servoInit();

	welcome();




	while(1){
		u8KeypadVal=KPD_u8GetPressedKey();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Enter the med No.");
		if(u8KeypadVal!=KPD_enumNOT_PRESSED){
			CLCD_voidSendString("Getting MED No:");
			char tempnumStr[10];
			itoa(u8KeypadVal,tempnumStr,10);

			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString(tempnumStr);
			medNo(u8KeypadVal);
			CLCD_voidClear();
			CLCD_voidSendString("Med is here :)");
			_delay_ms(2000);
			CLCD_voidClear();
		}
	}

}


void medNo(u8 no){
	u16 Local_u16StepperXAng;
	u16 Local_u16StepperYAng;
	if(no==1){
		Local_u16StepperXAng=90;
		Local_u16StepperYAng=270;
	}
	else if(no==2){
		Local_u16StepperXAng=180;
		Local_u16StepperYAng=270;
	}
	else if(no==3){
		Local_u16StepperXAng=270;
		Local_u16StepperYAng=270;
	}
	else if(no==4){
		Local_u16StepperXAng=90;
		Local_u16StepperYAng=180;
	}
	else if(no==5){
		Local_u16StepperXAng=180;
		Local_u16StepperYAng=180;
	}
	else if(no==6){
		Local_u16StepperXAng=270;
		Local_u16StepperYAng=180;
	}
	else if(no==7){
		Local_u16StepperXAng=90;
		Local_u16StepperYAng=90;
	}
	else if(no==8){
		Local_u16StepperXAng=180;
		Local_u16StepperYAng=90;
	}
	else if(no==9){
		Local_u16StepperXAng=270;
		Local_u16StepperYAng=90;
	}else{
		return ;
	}



	STEPPER_voidOn(STEPPER_CLOCK_WISE,200,Local_u16StepperXAng,&stepper_x);
	_delay_ms(500);
	STEPPER_voidOn(STEPPER_CLOCK_WISE,200,Local_u16StepperYAng,&stepper_y);
	_delay_ms(500);

	_delay_ms(1000);

	servoWrite(187);
	_delay_ms(2000);
	servoWrite(65);

	_delay_ms(1000);

	STEPPER_voidOn(STEPPER_ANTI_CLOCK_WISE,200,Local_u16StepperXAng,&stepper_x);
	_delay_ms(500);
	STEPPER_voidOn(STEPPER_ANTI_CLOCK_WISE,200,Local_u16StepperYAng,&stepper_y);
	_delay_ms(500);
}



void welcome(void)
{

	u8 local_u8Trial = 3;
	u8 local_u8MaxPasswordLenth = 4;
	char local_arrCorrectPassword[] = "1973";


	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString("Smart Pharmacy");
	_delay_ms(500);
	CLCD_voidClear();

	/******************>>password<<******************/

	char enteredPassword[local_u8MaxPasswordLenth + 1];   //+1 for '/0'
	u8 Local_u8PassLen = 0;

	CLCD_voidSendString("Enter Password: ");
	CLCD_voidGoToXY(1, 0);

	//check loop
	for (u8 Local_u8Iterations = 0; Local_u8Iterations < local_u8Trial; Local_u8Iterations++) {
		Local_u8PassLen = 0;

		while (1) {
			u8 u8KeypadVal = KPD_u8GetPressedKey();

			if (u8KeypadVal != KPD_enumNOT_PRESSED && Local_u8PassLen < local_u8MaxPasswordLenth) {
				enteredPassword[Local_u8PassLen] = u8KeypadVal + '0';
				CLCD_voidSendString("*");
				Local_u8PassLen++;
			}

			if (Local_u8PassLen >= local_u8MaxPasswordLenth) {
				break;
			}
		}

		enteredPassword[Local_u8PassLen] = '\0';

		if (strcmp(enteredPassword, local_arrCorrectPassword) == 0) {

			break;  // Correct password, exit the loop
		} else {
			CLCD_voidClear();
			CLCD_voidSendString("Wrong Password!");
			if (Local_u8Iterations < local_u8Trial - 1) {
				CLCD_voidSendString(" Try Again...");


				_delay_ms(600);
				CLCD_voidSendCommand(0x01);  // Clear screen
				CLCD_voidSendString("Enter Password: ");
				CLCD_voidGoToXY(1, 0);
			} else {
				CLCD_voidClear();
				CLCD_voidSendString(" Locked!");
				while (1);  // Lock the system after max trials
			}
		}
	}


	//

	CLCD_voidClear();
	CLCD_voidGoToXY(0,4);
    CLCD_voidSendString("Welcome!");


    for(u8 i=0;i<8;i++){
        CLCD_voidWriteSpecialCharacter(&letter1arr,0,0,12);
        _delay_ms(100);
        CLCD_voidWriteSpecialCharacter(&letter2arr,1,0,12);
        _delay_ms(100);
    }
    CLCD_voidClear();
}










