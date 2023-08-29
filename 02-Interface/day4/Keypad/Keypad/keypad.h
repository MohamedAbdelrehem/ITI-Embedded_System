/*
 * keypad.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mohamed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_PIN_R1 DIO_PORTC,DIO_PIN0
#define KEYPAD_PIN_R2 DIO_PORTC,DIO_PIN1
#define KEYPAD_PIN_R3 DIO_PORTC,DIO_PIN2
#define KEYPAD_PIN_R4 DIO_PORTC,DIO_PIN3

#define KEYPAD_PIN_C1 DIO_PORTC,DIO_PIN4
#define KEYPAD_PIN_C2 DIO_PORTC,DIO_PIN5
#define KEYPAD_PIN_C3 DIO_PORTC,DIO_PIN6
#define KEYPAD_PIN_C4 DIO_PORTC,DIO_PIN7

typedef enum{
	KEYPAD_B00,
	KEYPAD_B01,
	KEYPAD_B02,
	KEYPAD_B03,
	KEYPAD_B04,
	KEYPAD_B05,
	KEYPAD_B06,
	KEYPAD_B07,
	KEYPAD_B08,
	KEYPAD_B09,
	KEYPAD_B10,
	KEYPAD_B11,
	KEYPAD_B12,
	KEYPAD_B13,
	KEYPAD_B14,
	KEYPAD_B15,
	KEYPAD_INVALID
}Keypad_ButtonType;

typedef enum {
KEYPAD_NOT_PRESSED,
KEYPAD_PRESSED
} Keypad_ButtonStateType;

void Keypad_Init (void);
Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button);

#endif /* KEYPAD_H_ */
