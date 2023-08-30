/*
 * button.h
 *
 * Created: 4/5/2023 11:11:28 PM
 *  Author: Team 2
 */ 
#include "../../MCAL/dio/DIO_interface.h"

#ifndef BUTTON_H_
#define BUTTON_H_

/************************************************************************/
/*Description: Initialize a button as an Input                          */
/*@param u8_a_pinNumber  pin number                                     */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
err_state BUTTON_init(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber);

/************************************************************************/
/*Description: Read a button current state                              */
/*@param u8_a_pinNumber     pin number                                  */
/*@param u8_a_portNumber    port number                                 */
/*@param *en_a_value             refrence to store the read value in    */
/************************************************************************/
err_state BUTTON_read(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber, uint8_t *en_a_value);





#endif /* BUTTON_H_ */