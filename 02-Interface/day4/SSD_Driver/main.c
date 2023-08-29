/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  MCAL                       *************************/
/************************         SWC:    DIO                        *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "COTS/2-HAL/2-SSD/SSD_interface.h"
#include "avr/delay.h"

void main(){
	SSD_str SSD1 = {SSD_enumPORTD,SSD_enumCOMMON_ANODE,SSD_enumPORTA,SSD_enumPIN0};
	SSD_str SSD2 = {SSD_enumPORTD,SSD_enumCOMMON_CATHODE,SSD_enumPORTA,SSD_enumPIN1};


	SSD_voidInitialization(&SSD1);
	SSD_voidInitialization(&SSD2);

	SSD_voidEnable(&SSD1);
	SSD_voidEnable(&SSD2);

	while(1){
		for(int j=0;j<SSD_MAX;j++){
			for (int i=0;i<SSD_MAX;i++){
				for(int a=0;a<10;a++){
					SSD_voidEnable(&SSD1);
					SSD_voidDisable(&SSD2);
					SSD_voidSetNumber(&SSD1,i);
					_delay_ms(20);
					SSD_voidEnable(&SSD2);
					SSD_voidDisable(&SSD1);
					SSD_voidSetNumber(&SSD2,j);
					_delay_ms(20);
				}
			}
		}



	}
}
