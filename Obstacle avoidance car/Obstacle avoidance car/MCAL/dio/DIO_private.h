/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 16 April , 2023                      */
/* Version : V01                                  */
/* Hint    : Private file of DIO                  */
/**************************************************/

/* HEADER FILE GUARD */
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/****************************************************/
/* PRIVATE FILE CONTAINS THE PRIVATE DATA           */
/* RELATED TO EACH MODULE TO BE ACCESSED ONLY       */
/* BY THE MODULE ITSELF                             */
/****************************************************/

/*************** PORTA Registers ********************/
#define PORTA   (*((volatile uint8_t *) (0x3B))) 
#define DDRA    (*((volatile uint8_t *) (0x3A)))
#define PINA    (*((volatile uint8_t *) (0x39)))


/*************** PORTB Registers ********************/
#define PORTB (*((volatile uint8_t *) (0x38)))
#define DDRB  (*((volatile uint8_t *) (0x37)))
#define PINB  (*((volatile uint8_t *) (0x36)))


/*************** PORTC Registers ********************/
#define PORTC (*((volatile uint8_t *) (0x35)))
#define DDRC  (*((volatile uint8_t *) (0x34)))
#define PINC  (*((volatile uint8_t *) (0x33)))


/*************** PORTD Registers ********************/
#define PORTD (*((volatile uint8_t *) (0x32)))
#define DDRD  (*((volatile uint8_t *) (0x31)))
#define PIND  (*((volatile uint8_t *) (0x30)))




#endif