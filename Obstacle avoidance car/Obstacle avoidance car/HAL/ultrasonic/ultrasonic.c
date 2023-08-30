/*
 * ultrasonic.c
 *
 * Created: 5/20/2023 9:41:48 PM
 *  Author: mohab
 */ 
#include "ultrasonic.h"

#include "../../MCAL/timer0/TMR0_interface.h"
#include "../../MCAL/timer1/timer1_interface.h"
#include "../../MCAL/dio/DIO_interface.h"

void USONIC_init(void)
{
	DIO_setpindir(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_setpindir(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	TMR1_init();
}

EN_USONIC_STATUS USONIC_getdistance(uint8_t *u8_a_distance)
{
	
	uint8_t echo=0;
	uint16t duration_ticks=0;
	double duration_us=0;
	int distance=0;
	
	DIO_setpinvalue(DIO_PORTD, DIO_PIN1, DIO_PIN_HIGH);
	TMR0_delaymicos(10);
	DIO_setpinvalue(DIO_PORTD, DIO_PIN1, DIO_PIN_LOW);
	DIO_readpin(DIO_PORTD, DIO_PIN2, &echo);
	DIO_setpinvalue(DIO_PORTB, DIO_PIN7, DIO_PIN_HIGH);
	while(echo)
	{
		DIO_readpin(DIO_PORTD, DIO_PIN2, &echo);
	}
	TMR1_start();
	while(!echo)
	{
		DIO_readpin(DIO_PORTD, DIO_PIN2, &echo);
	}
	DIO_setpinvalue(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
	//TMR1_start();
	TMR1_setvalue(0);
	while(echo)
	{
		DIO_readpin(DIO_PORTD, DIO_PIN2, &echo);
	}
	
	TMR1_getvalue(&duration_ticks);
	DIO_setpinvalue(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
	//TMR1_stop();
	duration_us = duration_ticks *8;
	distance = duration_us * 0.017;
	*u8_a_distance = +distance>255? 255:distance;
	
	return USONIC_SUCCESS;
}