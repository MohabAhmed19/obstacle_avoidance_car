/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 16 April , 2023                      */
/* Version : V02                                  */
/* Hint    : Interface file of DIO                */
/**************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../SERVICE/standard_types.h"
/*****************************************************************/
/* INTERFACE FILE CONTAINS ALL PROTOTYPES AND CONFIGURATIONS     */
/* RELATED TO SPECIFIC MODULE                                    */
/*****************************************************************/

/***** MACRO FOR EACH PORT ACTS AS PORT ID  ***********/
#define DIO_PORTA         0
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3


/*********** MACRO FOR EACH PIN ACTS AS PIN ID **********/
#define DIO_PIN0          0
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

/********** MACROS FOR PIN DIRECTIONS ******************/
#define DIO_PIN_OUTPUT    1
#define DIO_PIN_INPUT     0

/********** MACROS FOR PORT DIRECTIONS *****************/
#define DIO_PORT_OUTPUT   0xFF
#define DIO_PORT_INPUT    0x00


/********* MACROS FOR OUTPUT PIN VALUES ***************/
#define DIO_PIN_HIGH      1
#define DIO_PIN_LOW       0


/*********** MACROS FOR OUTPUT PORT DIRECTIONS *********/
#define DIO_PORT_HIGH     0xFF
#define DIO_PORT_LOW      0x00


/** TYPE DEFINITION FOR PIN DIRECTION TO RETURN ITS STATE **/
typedef enum { VALID_DIRECTION , NOT_VALID_DIRECTION } PinDirection_t ;
	
/** TYPE DEFINITION FOR PIN VALUE TO RETURN ITS STATE  **/
typedef enum { VALID_VALUE , NOT_VALID_VALUE } PinValue_t ;

/** TYPE DEFINITION FOR PIN READ STATUS  **/
typedef enum { VALID_READ , NOT_VALID_READ } PinRead_t ; 

/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE DIRECTION OF SPECIFIC PIN   */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinDirection_t                                       */
/******************************************************************/
PinDirection_t DIO_setpindir(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t u8_a_pindir);

/*******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE DIRECTION OF SPECIFIC PORT   */
/* INPUT   : PORT , DIRECTION                                      */
/* RETURNS : PinDirection_t                                        */
/*******************************************************************/
PinDirection_t DIO_setportdir(uint8_t u8_a_portid , uint8_t u8_a_portdir);


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinValue_t                                           */
/******************************************************************/
PinValue_t DIO_setpinvalue(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t u8_a_pinval);

/*******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE VALUE OF SPECIFIC PORT       */
/* INPUT   : PORT , PINID , DIRECTION                              */
/* RETURNS : PinValue_t                                            */
/*******************************************************************/
PinValue_t DIO_setportvalue(uint8_t u8_a_portid , uint8_t u8_a_portval);


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO GET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : PORTID , PINID , POINTER TO SET THE VALUE IN IT      */
/* RETURNS : PinRead_t                                            */
/******************************************************************/
PinRead_t DIO_readpin(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t* u8_a_val);


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO TOGGLE SPECIFIC PIN                 */
/* INPUT   : PORTID , PINID                                       */
/* RETURNS : PinRead_t                                            */
/******************************************************************/
PinRead_t DIO_togglepin(uint8_t u8_a_portid , uint8_t u8_a_pinid );


void DIO_array_write(uint8_t u8_l_mask, uint8_t u8_l_portNumber, uint8_t u8_l_value);

#endif