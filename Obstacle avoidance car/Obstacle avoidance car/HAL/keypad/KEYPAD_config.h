/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Configuration file of Timer 0                        */
/******************************************************************/



#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "../../MCAL/dio/DIO_interface.h"
#include "../../SERVICE/standard_types.h"
/******** Columns Definition *********/
#define COL_1  DIO_PIN5
#define COL_2  DIO_PIN6
#define COL_3  DIO_PIN7

/******** Rows Definition *********/
#define ROW_1  DIO_PIN2
#define ROW_2  DIO_PIN3
#define ROW_3  DIO_PIN4

/******** Buttons Definition ********/
#define BUTTON1    '1'
#define BUTTON2    '2'
#define BUTTON3    '3'
#define BUTTON4    '4'
#define BUTTON5    '5'
#define BUTTON6    '6'
#define BUTTON7    '7'
#define BUTTON8    '8'
#define BUTTON9    '9'

#endif /* ADC_CONFIG_H_ */
