/*
 * LCD_config.h
 *
 *  Created on: Sep 11, 2024
 *      Author: hager
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*        LCD MODE             */
#define LCD_MODE  EIGHT_BIT

/*      CONTROLE PINS         */
#define RS_PORT   DIO_u8PORTA
#define RS_PIN    DIO_u8PIN0

#define RW_PORT  DIO_u8PORTA
#define RW_PIN   DIO_u8PIN5

#define EN_PORT  DIO_u8PORTA
#define EN_PIN   DIO_u8PIN7


/* do not use conatination becouse if i dont have complet port so use it
/*      DATA  PINS         */
#define D7_PORT   DIO_u8PORTB
#define D7_PIN    DIO_u8PIN0

#define D6_PORT  DIO_u8PORTB
#define D6_PIN   DIO_u8PIN5

#define D5_PORT  DIO_u8PORTB
#define D5_PIN   DIO_u8PIN7

#define D4_PORT   DIO_u8PORTC
#define D4_PIN    DIO_u8PIN0

#define D3_PORT  DIO_u8PORTC
#define D3_PIN   DIO_u8PIN5

#define D2_PORT  DIO_u8PORTC
#define D2_PIN   DIO_u8PIN7

#define D1_PORT  DIO_u8PORTD
#define D1_PIN   DIO_u8PIN0

#define D0_PORT  DIO_u8PORTD
#define D0_PIN   DIO_u8PIN5

#endif /* LCD_CONFIG_H_ */
