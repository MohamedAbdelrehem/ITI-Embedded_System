#include "avr/io.h"

void Dio_SetPortMode ( Dio_PortType port , Dio_PortModeType mode )
{
	switch(port){
	case DIO_PORTA:
		DDRA = mode;
		break;
	case DIO_PORTB:
		DDRB = mode;
		break;
	case DIO_PORTC:
		DDRC = mode;
		break;
	case DIO_PORTD:
		DDRD = mode;
		break;
	}
}


void Dio_SetPortLevel ( Dio_PortType port , Dio_PortLevelType level ){
	switch(port)
	{
	case DIO_PORTA:
		PORTA = level;
		break;
	case DIO_PORTB:
		PORTB = level;
		break;
	case DIO_PORTC:
		PORTC = level;
		break;
	case DIO_PORTD:
		PORTD = level;
		break;
	default:
		break;
	}
}
Dio_PortLevelType Dio_ReadPortLevel (Dio_PortType port){
	DioPortLevel level = DIO_PORT_LOW;
	switch(port)
	{
	case DIO_PORTA:
		level = PINA;
		break;
	case DIO_PORTB:
		level = PINB;
		break;
	case DIO_PORTC:
		level = PINC;
		break;
	case DIO_PORTD:
		level = PIND;
		break;
	default:
		break;
	}
	return level;
}


void Dio_SetPinMode (Dio_PortType port , Dio_PinType pin , Dio_PinModeType mode){
	if(mode == DIO_PIN_OUTPUT){
		switch(port)
		{
		case DIO_PORTA:
			setBit(DDRA,pin);
			break;
		case DIO_PORTB:
			setBit(DDRB,pin);
			break;
		case DIO_PORTC:
			setBit(DDRC,pin);
			break;
		case DIO_PORTD:
			setBit(DDRD,pin);
			break;
		default :
			break;
		}
	}else if(mode == DIO_PIN_INPUT_FLOATING){

		switch(port)
		{
		case DIO_PORTA:
			clrBit(DDRA,pin);
			clrBit(PORTA,pin);
			break;
		case DIO_PORTB:
			clrBit(DDRB,pin);
			clrBit(PORTB,pin);
			break;
		case DIO_PORTC:
			clrBit(DDRC,pin);
			clrBit(PORTC,pin);
			break;
		case DIO_PORTD:
			clrBit(DDRD,pin);
			clrBit(PORTD,pin);
			break;
		default :
			break;
		}
	}else if(mode == DIO_PIN_INPUT_PULLUP){
		switch(port)
		{
		case DIO_PORTA:
			clrBit(DDRA,pin);
			setBit(PORTA,pin);
			break;
		case DIO_PORTB:
			clrBit(DDRB,pin);
			setBit(PORTB,pin);
			break;
		case DIO_PORTC:
			clrBit(DDRC,pin);
			setBit(PORTC,pin);
			break;
		case DIO_PORTD:
			clrBit(DDRD,pin);
			setBit(PORTD,pin);
			break;
		default :
			break;
		}
	}
}

void Dio_SetPinLevel (Dio_PortType port , Dio_PinType pin , Dio_PinLevelType level){
	if(level == STD_HIGH){
		switch(port)
		{
		case DIO_PORTA:
			setBit(PORTA,pin);
			break;
		case DIO_PORTB:
			setBit(PORTB,pin);
			break;
		case DIO_PORTC:
			setBit(PORTC,pin);
			break;
		case DIO_PORTD:
			setBit(PORTD,pin);
			break;
			dafault:
			break;
		}
	}else if(level == STD_LOW){
		switch(port)
		{
		case DIO_PORTA:
			clrBit(PORTA,pin);
			break;
		case DIO_PORTB:
			clrBit(PORTB,pin);
			break;
		case DIO_PORTC:
			clrBit(PORTC,pin);
			break;
		case DIO_PORTD:
			clrBit(PORTD,pin);
			break;
			dafault:
			break;
		}
	}
}

Dio_PinLevelType Dio_FlipPInLevel (Dio_PortType port , Dio_PinType pin){
	Dio_PinLevelType level = STD_HIGH;
	switch(port)
	{
	case DIO_PORTA:
		togBit(DDRA,pin);
		level = getBit(PORTA,pin);
		break;
	case DIO_PORTB:
		togBit(DDRB,pin);
		level = getBit(PORTB,pin);
		break;
	case DIO_PORTC:
		togBit(DDRC,pin);
		level = getBit(PORTC,pin);
		break;
	case DIO_PORTD:
		togBit(DDRD,pin);
		level = getBit(PORTD,pin);
		break;
	default :
		break;
	}
}

Dio_PinLevelType Dio_ReadPInLevel (Dio_PortType port , Dio_PinType pin){
	Dio_PinLevelType level = STD_LOW;

	switch(port)
	{
	case DIO_PORTA:
		if(getBit(PINA,pin) == 1){
			level = STD_HIGH;
		}else
		{
			level = STD_LOW;
		}
		break;
	case DIO_PORTB:
		if(getBit(PINB,pin) == 1){
			level = STD_HIGH;
		}else
		{
			level = STD_LOW;
		}
		break;
	case DIO_PORTC:
		if(getBit(PINB,pin) == 1){
			level = STD_HIGH;
		}else
		{
			level = STD_LOW;
		}
		break;
	case DIO_PORTD:
		setBit(PORTD,pin);
		break;
		dafault:
		break;
	}
}

