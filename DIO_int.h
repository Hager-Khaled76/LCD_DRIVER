/*
 * DIO_int.h
 *
 *  Created on: Aug 11, 2024
 *      Author: hager
 */
// here high level design end API can supported , function and user can see it


//  ����� �� ��� ��� ���� ����� �� �� ��� include to stdTypes

#include "errorStates.h"
#include "stdTypes.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_


#define DIO_u8PORTA        0
#define DIO_u8PORTB        1
#define DIO_u8PORTC        2
#define DIO_u8PORTD        3


#define DIO_u8PIN0    0
#define DIO_u8PIN1    1
#define DIO_u8PIN2    2
#define DIO_u8PIN3    3
#define DIO_u8PIN4    4
#define DIO_u8PIN5    5
#define DIO_u8PIN6    6
#define DIO_u8PIN7    7

#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1


#define DIO_u8LOW      0
#define DIO_u8HIGH     1
#define DIO_u8FLOAT    0
#define DIO_u8PULL_UP  1

//here prototype
ES_t DIO_enumInt(void);   //methode to write func

ES_t DIO_enumSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value);

ES_t DIO_enumSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value);

ES_t DIO_enumTogPortValue(u8 Copy_u8PortID );

ES_t DIO_enumGetPortValue(u8 Copy_u8PortID , u8 * Copy_pointeru8Value);      // ���� ������� ������� �� ��pin register

// work on pins level
// set,get will pass pin id ,port id
ES_t DIO_enumSetPinDirection(u8 Copy_u8PortID ,u8 Copy_u8PinID,  u8 Copy_u8Value);

ES_t DIO_enumSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8Value);

ES_t DIO_enumTogPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID );

ES_t DIO_enumGetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 * Copy_pointeru8Value);




#endif /* DIO_INT_H_ */
