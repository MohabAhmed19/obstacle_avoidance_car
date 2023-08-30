/*
 * motor.h
 *
 * Created: 4/6/2023 6:10:51 PM
 *  Author: Team 2
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../../MCAL/dio/DIO_interface.h"
#include "../../MCAL/timer0/TMR0_interface.h"
#define f_g_tPeriod 100 //T-Period is 100 milliseconds

/************************************************************************/
/*Description: Initialize a motor pin as an output                      */
/*@param u8_a_pinNumber pin number                                      */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
err_state MOTOR_init(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber);

/************************************************************************/
/*Description: Sets a motor pin as HIGH                                 */
/*@param u8_a_mask mask for the pins                                    */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
err_state MOTOR_on(uint8_t u8_a_mask, uint8_t u8_a_portNumber);

/************************************************************************/
/*Description: Sets a motor pin as LOW                                  */
/*@param u8_a_mask u8_a_mask for the pins                               */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
err_state MOTOR_off(uint8_t u8_a_mask, uint8_t u8_a_portNumber);

/*****************************************************************************************************************************************************************************/
/*Description: Controls the motor speed depending on the given percentage of the maximum speed by setting the duty cycle to the required max_speed percentage (Uses timer 0) */
/*@param u8_a_mask u8_a_mask for the pins                                                                                                                                    */
/*@param u8_a_portNumber port number                                                                                                                                         */
/*@param f_a_speedPercentage duty cycle                                                                                                                                      */
/*@param f_a_tPeriod T-Period                                                                                                                                                */
/*****************************************************************************************************************************************************************************/
err_state MOTOR_control(uint8_t u8_a_mask, uint8_t u8_a_portNumber,int f_a_speedPercentage);





#endif /* MOTOR_H_ */