/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Private file of Timer 0                              */
/******************************************************************/ 

#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H


/*************** TIMER0 Registers ********************/

#define SREG  (* (volatile uint8_t *) (0x5F))
#define TCCR0 (* (volatile uint8_t *) (0x53))
#define TCNT0 (* (volatile uint8_t *) (0x52))
#define OCR0  (* (volatile uint8_t *) (0x5C))
#define TIMSK (* (volatile uint8_t *) (0x59))
#define TIFR  (* (volatile uint8_t *) (0x58))



#endif