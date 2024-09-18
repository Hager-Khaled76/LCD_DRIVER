/*
 * LCD_prog.c
 *
 *  Created on: Sep 11, 2024
 *      Author: hager
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include "util/delay.h"


ES_t LCD_enumInit(void)
{
	ES_t Local_enummErrorState = ES_NOK;
    _delay_ms(30);

    /* all controle pins will be output */
    DIO_enumSetPinDirection(RS_PORT , RS_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(RW_PORT , RW_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(EN_PORT , EN_PIN , DIO_u8OUTPUT);

    /* and last 4 bits will be output*/
    DIO_enumSetPinDirection(D7_PORT , D7_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D6_PORT , D6_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D5_PORT , D5_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D4_PORT , D4_PIN , DIO_u8OUTPUT);

    _delay_ms(35);
    // function set

#if LCD_MODE == EIGHT_BIT

    DIO_enumSetPinDirection(D3_PORT , D3_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D2_PORT , D2_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D1_PORT , D1_PIN , DIO_u8OUTPUT);
    DIO_enumSetPinDirection(D0_PORT , D0_PIN , DIO_u8OUTPUT);

    // function set
    LCD_invidSendCommend(0x38);//0b001'1' 1000 => eight it
#elif LCD_MODE == FOUR_BIT
    // function set
    LCD_invidSendCommend(0x28);//0b001'0' 1000 => four bit
#endif
    _delay_ms(1);
    // display ON/OFF
    LCD_invidSendCommend(0x0f);
    _delay_ms(1);
    // display clear
    LCD_invidSendCommend(0x01);
    _delay_ms(2);
    // entry mode set
    LCD_invidSendCommend(0x06);


    Local_enummErrorState = ES_OK;
	return Local_enummErrorState;
}



ES_t LCD_enumDisplayData(u8 Copy_u8Data)
{
	ES_t Local_enummErrorState = ES_NOK;

	DIO_enumSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);

   LCD_vidlatch(Copy_u8Data);


    Local_enummErrorState = ES_OK;
	return Local_enummErrorState;
}




ES_t LCd_enumSendCommand(u8 Copy_u8Commnd)
{
	ES_t Local_enummErrorState = ES_NOK;


    // set rs as command
	DIO_enumSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);

   LCD_vidlatch(Copy_u8Commnd);

    Local_enummErrorState = ES_OK;
	return Local_enummErrorState;
}



/* Local function*/
static void LCD_vidlatch(u8 Copy_u8Data)
{

	// set rw as write operation   , ENABLE is LOW
	DIO_enumSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

   //write Data
	DIO_enumSetPinValue(D7_PORT , D7_PIN , (Copy_u8Data>>7)&1);
	DIO_enumSetPinValue(D6_PORT , D6_PIN , (Copy_u8Data>>6)&1);
	DIO_enumSetPinValue(D5_PORT , D5_PIN , (Copy_u8Data>>5)&1);
	DIO_enumSetPinValue(D4_PORT , D4_PIN , (Copy_u8Data>>4)&1);

#if LCD_MODE == EIGHT_BIT

	DIO_enumSetPinValue(D3_PORT , D3_PIN , (Copy_u8Data>>3)&1);
	DIO_enumSetPinValue(D2_PORT , D2_PIN , (Copy_u8Data>>2)&1);
	DIO_enumSetPinValue(D1_PORT , D1_PIN , (Copy_u8Data>>1)&1);
	DIO_enumSetPinValue(D0_PORT , D0_PIN , (Copy_u8Data>>0)&1);

#elif LCD_MODE == FOUR_BIT


#endif

   // ENABLE IS LATCH
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

	_delay_ms(10);

}


static inline void LCD_invidSendCommend(u8 Copy_u8Command)
{
    // set rs as command
	DIO_enumSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);

	// set rw as write operation   , ENABLE is LOW
	DIO_enumSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

   //write Data
	DIO_enumSetPinValue(D7_PORT , D7_PIN , (Copy_u8Command>>7)&1);
	DIO_enumSetPinValue(D6_PORT , D6_PIN , (Copy_u8Command>>6)&1);
	DIO_enumSetPinValue(D5_PORT , D5_PIN , (Copy_u8Command>>5)&1);
	DIO_enumSetPinValue(D4_PORT , D4_PIN , (Copy_u8Command>>4)&1);
	DIO_enumSetPinValue(D3_PORT , D3_PIN , (Copy_u8Command>>3)&1);
	DIO_enumSetPinValue(D2_PORT , D2_PIN , (Copy_u8Command>>2)&1);
	DIO_enumSetPinValue(D1_PORT , D1_PIN , (Copy_u8Command>>1)&1);
	DIO_enumSetPinValue(D0_PORT , D0_PIN , (Copy_u8Command>>0)&1);

   // ENABLE IS LATCH
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);


}


ES_t LCD_enumDisplayString(u8 * Copy_pu8String)
{
	ES_t Local_enummErrorState = ES_NOK;

	if( Local_enummErrorState != NULL)
	{
		for(u8 count=0;Copy_pu8String[count];count++)
		{
			LCD_enumDisplayData(Copy_pu8String[count]);
		}
		return Local_enummErrorState;
	}
	else
	{
		Local_enummErrorState = ES_NULL_POINTER;
	}

	return Local_enummErrorState ;

}



