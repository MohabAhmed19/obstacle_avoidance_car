/******************************************************************/
/* Author  : Team2                                                */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Configuration file of Timer 0                        */
/******************************************************************/



#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "../../SERVICE/standard_types.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

/****************************************************************/
/** FUNCTION TO INITIALIZE KEY PAD */
/** ARGUMENTS : VOID */
/** RETURN : ERROR STATUS */
/****************************************************************/
void KEYPAD_init(void) ;


/****************************************************************/
/** FUNCTION TO GET THE PRESSED KEY KEY PAD */
/** ARGUMENTS : VOID */
/** RETURN : uint8_t */
/****************************************************************/
uint8_t KEYPAD_getpressedkey(void) ;


#endif /* ADC_INTERFACE_H_ */
