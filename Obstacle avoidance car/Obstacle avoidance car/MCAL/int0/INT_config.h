/*******************************************************/
/* Author  : Mustafa Mohammed Abdou                    */
/* Date    : 4 April, 2023                             */
/* Version : V01                                       */
/* Hint    : Configuration file of external interrupt  */
/*******************************************************/


#ifndef EXTERNAL_INTERRUPT_CONFIG_H_
#define EXTERNAL_INTERRUPT_CONFIG_H_

#define EXINT0_PORT  PORTD          /** PORT OF EXTERNAL INTERRUPT 0 **/
#define EXTINT0_PIN  DIO_PIN2       /** PIN OF EXTERNAL INTERRUPT 0 **/


#define EXTINT1_PORT   PORTD        /** PORT OF EXTERNAL INTERRUPT 1 **/
#define EXTINT1_PIN    DIO_PIN3     /** PIN OF EXTERNAL INTERRUPT 1 **/


#define EXTINT2_PORT   PORTB        /** PORT OF EXTERNAL INTERRUPT 2 **/
#define EXTINT2_PIN    DIO_PIN3     /** PIN OF EXTERNAL INTERRUPT 2 **/


#define GLOBAL_INTERRUPT_STATE   GLOBAL_INTERRUPT_STATE_ENABLE /** ACTIVATE GLOBAL INTERRUPTS **/

#define EXTERNAL_INT0_TRIGGER    INT_TRIGGER_RISING_EDGE  /** TRIGGERING ACTION IS RISING EDGE **/

#define EXTERNAL_INT1_TRIGGER    INT_TRIGGER_RISING_EDGE  /** TRIGGERING ACTION IS RISING EDGE **/

#define EXTERNAL_INT2_TRIGGER    INT_TRIGGER_RISING_EDGE  /** TRIGGERING ACTION IS RISING EDGE **/

#endif /* EXTERNAL_INTERRUPT_CONFIG_H_ */