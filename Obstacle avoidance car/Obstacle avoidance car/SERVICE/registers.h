/*
 * registers.h
 *
 * Created: 4/5/2023 3:16:02 PM
 *  Author: Omar Taha
 */ 

/************************************************************************/
/* All microcontroller registers                                        */
/************************************************************************/
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "standard_types.h"

/************************************************************************/
/* DIO Registers								                        */
/************************************************************************/
//PORTA registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

//PORTB registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

//PORTC registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

//PORTD registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

/************************************************************************/
/* External Interrupts Registers                                        */
/************************************************************************/
#define SREG  *((volatile uint8_t*)0x5F)
#define GICR  *((volatile uint8_t*)0x5B)
#define GIFR  *((volatile uint8_t*)0x5A)
#define MCUCR *((volatile uint8_t*)0x55)

/************************************************************************/
/* Timers Registers                                                     */
/************************************************************************/
//Timer 0 registers (8-bit register)
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR  *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)

//Timer 1 registers (16-bit register)
#define TCCR1A *((volatile uint8_t*)0x4F)
#define TCCR1B *((volatile uint8_t*)0x4E)

//Timer 2 registers (8-bit register)
#define TCCR2 *((volatile uint8_t*)0x45)
#define TCNT2 *((volatile uint8_t*)0x44)




#endif /* REGISTERS_H_ */