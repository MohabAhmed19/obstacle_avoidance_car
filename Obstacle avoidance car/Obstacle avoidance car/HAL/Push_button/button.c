/*
 * button.c
 *
 * Created: 4/5/2023 11:11:38 PM
 *  Author: Team 2
 */ 
#include "button.h"

/************************************************************************/
/*Description: Initialize a button as an Input                          */
/*@param u8_a_pinNumber  pin number                                     */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
uint8_t BUTTON_init(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber)
{
    DIO_setpindir(u8_a_portNumber,u8_a_pinNumber,DIO_PIN_INPUT);
    return 0;
}

/************************************************************************/
/*Description: Read a button current state                              */
/*@param u8_a_pinNumber     pin number                                  */
/*@param u8_a_portNumber    port number                                 */
/*@param *en_a_value             refrence to store the read value in    */
/************************************************************************/
uint8_t BUTTON_read(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber, uint8_t *en_a_value)
{
    DIO_readpin(u8_a_portNumber,u8_a_pinNumber,en_a_value);
    return 0;
}