/*
 * LCD_int.h
 *
 *  Created on: Sep 11, 2024
 *      Author: hager
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enumInit(void);

ES_t LCD_enumDisplayData(u8 Copy_u8Data);

ES_t LCd_enumSendCommand(u8 Copy_u8Commnd);

//ES_t LCD_enumDisplayString(u8 * Copy_u8String);


#endif /* LCD_INT_H_ */
