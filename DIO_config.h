/*
 * DIO_config.h
 *
 *  Created on: Aug 11, 2024
 *      Author: hager
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

// here pin direction if input or output
//#define portA pin[0] direction

/* you can use INPUT or OUPUT */
#define PA_PIN0_DIR     INPUT
#define PA_PIN1_DIR     OUTPUT
#define PA_PIN2_DIR     OUTPUT
#define PA_PIN3_DIR     INPUT
#define PA_PIN4_DIR     OUTPUT
#define PA_PIN5_DIR     INPUT
#define PA_PIN6_DIR     INPUT
#define PA_PIN7_DIR     OUTPUT
/*10010110*/ /*  => b7 b6 b5 b4 b3 b2 b1 b0*/

#define PB_PIN0_DIR     INPUT
#define PB_PIN1_DIR     OUTPUT
#define PB_PIN2_DIR     OUTPUT
#define PB_PIN3_DIR     INPUT
#define PB_PIN4_DIR     OUTPUT
#define PB_PIN5_DIR     INPUT
#define PB_PIN6_DIR     INPUT
#define PB_PIN7_DIR     OUTPUT

#define PC_PIN0_DIR     INPUT
#define PC_PIN1_DIR     OUTPUT
#define PC_PIN2_DIR     OUTPUT
#define PC_PIN3_DIR     INPUT
#define PC_PIN4_DIR     OUTPUT
#define PC_PIN5_DIR     INPUT
#define PC_PIN6_DIR     INPUT
#define PC_PIN7_DIR     OUTPUT

#define PD_PIN0_DIR     INPUT
#define PD_PIN1_DIR     OUTPUT
#define PD_PIN2_DIR     OUTPUT
#define PD_PIN3_DIR     INPUT
#define PD_PIN4_DIR     OUTPUT
#define PD_PIN5_DIR     INPUT
#define PD_PIN6_DIR     INPUT
#define PD_PIN7_DIR     OUTPUT






#define PA_PIN0_VAL     FLOAT
#define PA_PIN1_VAL     HIGH
#define PA_PIN2_VAL     LOW
#define PA_PIN3_VAL     PULL_UP
#define PA_PIN4_VAL     HIGH
#define PA_PIN5_VAL     FLOAT
#define PA_PIN6_VAL     PULL_UP
#define PA_PIN7_VAL     LOW
/*01011010*/



#define PB_PIN0_VAL     FLOAT
#define PB_PIN1_VAL     HIGH
#define PB_PIN2_VAL     LOW
#define PB_PIN3_VAL     PULL_UP
#define PB_PIN4_VAL     HIGH
#define PB_PIN5_VAL     FLOAT
#define PB_PIN6_VAL     PULL_UP
#define PB_PIN7_VAL     LOW


#define PC_PIN0_VAL     FLOAT
#define PC_PIN1_VAL     HIGH
#define PC_PIN2_VAL     LOW
#define PC_PIN3_VAL     PULL_UP
#define PC_PIN4_VAL     HIGH
#define PC_PIN5_VAL     FLOAT
#define PC_PIN6_VAL     PULL_UP
#define PC_PIN7_VAL     LOW


#define PD_PIN0_VAL     FLOAT
#define PD_PIN1_VAL     HIGH
#define PD_PIN2_VAL     LOW
#define PD_PIN3_VAL     PULL_UP
#define PD_PIN4_VAL     HIGH
#define PD_PIN5_VAL     FLOAT
#define PD_PIN6_VAL     PULL_UP
#define PD_PIN7_VAL     LOW













#endif /* DIO_CONFIG_H_ */
