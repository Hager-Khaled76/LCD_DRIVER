/*
 * DIO_prog.c
 *
 *  Created on: Aug 11, 2024
 *      Author: hager
 */




/*  «·«Ì—ÌÊ— «· ŸÂ— Â‰« ÂÊ  — Ì» «·  include  ⁄‘«‰ ·«“„ ÌﬂÊ‰ guard file ›Êﬁ ÊÀ„ «·»«ﬁÌ
 * *
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_priv.h"
#include "DIO_config.h"




//here implementation to func

ES_t DIO_enumInt(void)   //methode to write func
{
	ES_t Local_enumErrorstate = ES_NOK;
	DDRA = CONC( PA_PIN7_DIR ,  PA_PIN6_DIR,  PA_PIN5_DIR,  PA_PIN4_DIR,  PA_PIN3_DIR, PA_PIN2_DIR , PA_PIN1_DIR,  PA_PIN0_DIR);
	DDRB = CONC( PB_PIN7_DIR ,  PB_PIN6_DIR,  PB_PIN5_DIR,  PB_PIN4_DIR,  PB_PIN3_DIR, PB_PIN2_DIR , PB_PIN1_DIR,  PB_PIN0_DIR);
	DDRC = CONC( PC_PIN7_DIR ,  PC_PIN6_DIR,  PC_PIN5_DIR,  PC_PIN4_DIR,  PC_PIN3_DIR, PC_PIN2_DIR , PC_PIN1_DIR,  PC_PIN0_DIR);
	DDRD = CONC( PD_PIN7_DIR ,  PD_PIN6_DIR,  PD_PIN5_DIR,  PD_PIN4_DIR,  PD_PIN3_DIR, PD_PIN2_DIR , PD_PIN1_DIR,  PD_PIN0_DIR);


	PORTA = CONC( PA_PIN7_VAL ,  PA_PIN6_VAL,  PA_PIN5_VAL,  PA_PIN4_VAL,  PA_PIN3_VAL, PA_PIN2_VAL , PA_PIN1_VAL,  PA_PIN0_VAL);
	PORTB = CONC( PB_PIN7_VAL ,  PB_PIN6_VAL,  PB_PIN5_VAL,  PB_PIN4_VAL,  PB_PIN3_VAL, PB_PIN2_VAL , PB_PIN1_VAL,  PB_PIN0_VAL);
	PORTC = CONC( PC_PIN7_VAL ,  PC_PIN6_VAL,  PC_PIN5_VAL,  PC_PIN4_VAL,  PC_PIN3_VAL, PC_PIN2_VAL , PC_PIN1_VAL,  PC_PIN0_VAL);
	PORTD = CONC( PD_PIN7_VAL,  PD_PIN6_VAL,  PD_PIN5_VAL,  PD_PIN4_VAL,  PD_PIN3_VAL, PD_PIN2_VAL , PD_PIN1_VAL,  PD_PIN0_VAL);

	Local_enumErrorstate = ES_NOK;
	return Local_enumErrorstate;
}


ES_t DIO_enumSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;     // worest case

	if(Copy_u8PortID <= DIO_PORTD)  // <=3
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
			 DDRA= Copy_u8Value;
			break;
		case DIO_PORTB:
			 DDRB= Copy_u8Value;
			break;
		case DIO_PORTC:
			 DDRC= Copy_u8Value;
			break;
		case DIO_PORTD:
			 DDRD= Copy_u8Value;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t DIO_enumSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8PortID <= DIO_PORTD)  // <=3
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
			 PORTA= Copy_u8Value;
			break;
		case DIO_PORTB:
			 PORTB= Copy_u8Value;
			break;
		case DIO_PORTC:
			 PORTC= Copy_u8Value;
			break;
		case DIO_PORTD:
			 PORTD= Copy_u8Value;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t DIO_enumTogPortValue(u8 Copy_u8PortID )
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8PortID <= DIO_PORTD)  // <=3
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
			 PORTA= ~PORTA;
			break;
		case DIO_PORTB:
			 PORTB= ~PORTB;
			break;
		case DIO_PORTC:
			 PORTC= ~PORTC;
			break;
		case DIO_PORTD:
			 PORTD= ~PORTD;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}


   return Local_enumErrorstate;
}


ES_t DIO_enumGetPortValue(u8 Copy_u8PortID , u8 * Copy_pointeru8Value)    // «ÃÌ» «·›«·ÌÊ «·„ÃÊœÂ ›Ì «·pin register , read value of pin reg and return in pointer
{
	ES_t Local_enumErrorstate = ES_NOK;
	if (Copy_pointeru8Value !=NULL)
	{
			if(Copy_u8PortID <= DIO_PORTD)  // <=3
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA:
					*Copy_pointeru8Value = PINA;
					break;
				case DIO_PORTB:
					*Copy_pointeru8Value = PINB;
					break;
				case DIO_PORTC:
					 *Copy_pointeru8Value = PINC;
					break;
				case DIO_PORTD:
					 *Copy_pointeru8Value = PIND;
					break;
				}
		}
		else
		{
			Local_enumErrorstate = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enumErrorstate = ES_NULL_POINTER;
	}


   return Local_enumErrorstate;
}





// work on pins level
// set,get will pass pin id ,port id

ES_t DIO_enumSetPinDirection(u8 Copy_u8PortID ,u8 Copy_u8PinID,  u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8PortID <=DIO_PORTD && Copy_u8PinID <=DIO_PIN7 && Copy_u8Value<= OUTPUT)
	{
		switch(Copy_u8PortID)     // will make mask(clear) and or with ddr then left shift eith numbit
		{
		case DIO_PORTA:
			DDRA &=~ (1<<Copy_u8PinID);     // mask==clear
 			DDRA |= (Copy_u8Value <<Copy_u8PinID);
 			/*
 			 * DDRA->101-1-1001  => output means:  val =1 ,pin =4
 		     mask => 101-0-1001  then or with value shift pin
 		     =====> 101-0-1001 | (1<<4)   ===1<<4=>000-1-0000
 		           101-0-1001  |  000-1-0000 = 101-1-1001
 			 * */

			break;
		case DIO_PORTB:
			DDRB &=~ (1<<Copy_u8PinID);
 			DDRB |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case DIO_PORTC:
			DDRC &=~ (1<<Copy_u8PinID);
 			DDRC |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case DIO_PORTD:
			DDRD &=~ (1<<Copy_u8PinID);
 			DDRD |= (Copy_u8Value <<Copy_u8PinID);
			break;
	}
}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t DIO_enumSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8PortID <=DIO_PORTD && Copy_u8PinID <=DIO_PIN7 && Copy_u8Value<= HIGH)
	{
		switch(Copy_u8PortID)     // will make mask(clear) and or with ddr then left shift eith numbit
		{
		case DIO_PORTA:
			PORTA &=~ (1<<Copy_u8PinID);
 			PORTA |= (Copy_u8Value <<Copy_u8PinID);
 			/*
 			 * DDRA->101-1-1001  => output means:  val =1 ,pin =4
 		     mask => 101-0-1001  then or with value shift pin
 		     =====> 101-0-1001 | (1<<4)   ===1<<4=>000-1-0000
 		           101-0-1001  |  000-1-0000 = 101-1-1001
 			 * */

			break;
		case DIO_PORTB:
			PORTB &=~ (1<<Copy_u8PinID);
 			PORTB |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case DIO_PORTC:
			PORTC &=~ (1<<Copy_u8PinID);
 			PORTC |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case DIO_PORTD:
			PORTD &=~ (1<<Copy_u8PinID);
 			PORTD |= (Copy_u8Value <<Copy_u8PinID);
			break;
	}

	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t DIO_enumTogPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8PinID <=  DIO_PIN7 &&Copy_u8PortID<=DIO_PORTD)  // <=7
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
			 PORTA^= (1<<Copy_u8PinID);
			break;
		case DIO_PORTB:
			 PORTB^=(1<< Copy_u8PinID);
			break;
		case DIO_PORTC:
			 PORTC^=(1<< Copy_u8PinID);
			break;
		case DIO_PORTD:
			 PORTD^=( 1<<Copy_u8PinID);
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t DIO_enumGetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 * Copy_pointeru8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if (Copy_pointeru8Value !=NULL)
	{
			if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <=DIO_PIN7)
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA:
					*Copy_pointeru8Value = ((PINA>>Copy_u8PinID)&1);  // to read(GET PIT) pin sepaarte   ⁄·Ï ÕœÂ Ê·Ì” «·pin ﬂ·Â
					break;
				case DIO_PORTB:
					*Copy_pointeru8Value = ((PINB>>Copy_u8PinID)&1);  // to read pin sepaarte   ⁄·Ï ÕœÂ Ê·Ì” «·pin
					break;
				case DIO_PORTC:
					 *Copy_pointeru8Value = ((PINC>>Copy_u8PinID)&1);   // to read pin sepaarte   ⁄·Ï ÕœÂ Ê·Ì” «·pin
					break;
				case DIO_PORTD:
					 *Copy_pointeru8Value = ((PIND>>Copy_u8PinID)&1);   // to read pin sepaarte   ⁄·Ï ÕœÂ Ê·Ì” «·pin
					break;
				}
		}
		else
		{
			Local_enumErrorstate = ES_OUT_OF_RANGE;
		}
	}
   return Local_enumErrorstate;
}
