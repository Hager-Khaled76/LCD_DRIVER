/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: hager
 */

#include "stdTypes.h"

#include "errorStates.h"

#include "DIO_int.h"

#include "LCD_int.h"

#include "util/delay.h"

int main()
{

	LCD_enumInit();
/*
	LCD_enumDisplayData('H');
	LCD_enumDisplayData('A');
	LCD_enumDisplayData('G');
	LCD_enumDisplayData('E');
	LCD_enumDisplayData('R');
	LCD_enumDisplayData(' ');
	LCD_enumDisplayData('^');
	LCD_enumDisplayData('^');

*/
	LCD_enumDisplayString("hager");

	_delay_ms(3000);

	LCd_enumSendCommand(0x01);// clear


	while(1);

return 0;
}
