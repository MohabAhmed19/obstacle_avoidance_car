/*
 * APP.c
 *
 * Created: 5/21/2023 12:05:05 AM
 *  Author: mohab
 */ 
#include "APP.h"
#include "../SERVICE/standard_types.h"
#include "../MCAL/timer0/TMR0_interface.h"
#include "../MCAL/timer1/timer1_interface.h"
#include "../HAL/lcd/LCD_interface.h"
#include "../HAL/keypad/KEYPAD_interface.h"
#include "../HAL/ultrasonic/ultrasonic.h"
#include "../HAL/Push_button/button.h"

#define move_mask 0b00000011

#define frd_mask  0b01010000
#define left_mask 0b10010000
#define right_mask 0b01100000
#define back_mask 0b10100000
static uint8_t dir_mask = right_mask;

void APP_init(void)
{
	for(int i=0;i<8;i++)
	{
		MOTOR_init(i, DIO_PORTC);
	}
	uint8_t count_5_sec=0;
	uint8_t PB_state=0;
	TMR0_init();
	BUTTON_init(1,DIO_PORTB);
	LCD_init();
	KEYPAD_init();
	TMR0_delayms(50);
			
	USONIC_init();
	LCD_writestr("Press 1 to start");
	while(KEYPAD_getpressedkey() != '1' );
	LCD_goto(0,0);
	LCD_writestr("Set def. rotation");
	LCD_goto(1,0);
	LCD_writestr("right");
	while(count_5_sec<60)
	{
		BUTTON_read(1,DIO_PORTB,&PB_state);
		if(PB_state==1)
		{
			dir_mask = dir_mask==left_mask? right_mask:left_mask;
			while(PB_state==1)
			{
				BUTTON_read(1,DIO_PORTB,&PB_state);
			}
		}
		
		TMR0_delayms(50);
		LCD_goto(1,0);
		if(dir_mask==left_mask)
		{
			LCD_writestr("left ");
		}
		else
		LCD_writestr("right");
		count_5_sec++;
	}
	LCD_sendcmd(LCD_CLEAR);
}


void APP_start(void)
{
	static uint8_t count_5_sec=0;
	uint8_t distance;
	static uint8_t next_mask=frd_mask;
	static uint8_t next_speed=0;
	USONIC_getdistance(&distance);
	
	if(KEYPAD_getpressedkey() == '2')
	{
		count_5_sec=0;
		MOTOR_off(move_mask,DIO_PORTC);
		LCD_sendcmd(LCD_CLEAR);
		
		LCD_goto(0,0);
		TMR0_delayms(10);
		LCD_writestr("   ROBOT IS");
		LCD_goto(1,4);
		LCD_writestr("STOPPED");
		while(KEYPAD_getpressedkey()!= '1');
	}
	
	if(distance>=70)
	{
		if(count_5_sec<33)
		{
			next_speed=30;
			count_5_sec++;
			TMR0_delayms(10);
		}
		else
		{
			next_speed=50;
		}
		next_mask = frd_mask;	
	}
	else if(distance>=30)
	{
		count_5_sec=0;
		next_speed=30;
		next_mask = frd_mask;
	}
	else if(distance>=20)
	{
		count_5_sec=0;
		MOTOR_off(0xff,DIO_PORTC);
		next_speed=30;
		next_mask=dir_mask;
		
	}
	else
	{
		count_5_sec=0;
		next_speed=30;
		next_mask=back_mask;
	}
	
	MOTOR_off(0xff,DIO_PORTC);
	MOTOR_on(next_mask,DIO_PORTC);
	MOTOR_control(move_mask, DIO_PORTC, next_speed);
	
	USONIC_getdistance(&distance);
	
	LCD_goto(0,0);
	TMR0_delayms(10);
	LCD_writestr(" Speed:");
	LCD_writeint(next_speed);
	LCD_writestr("% dir:");
	switch (next_mask)
	{
		case frd_mask:
		LCD_writestr("F");
		break;
		case back_mask:
		LCD_writestr("B");
		break;
		case right_mask:
		LCD_writestr("R");
		break;
		case left_mask:
		LCD_writestr("L");
		break;
	}
	LCD_goto(1,0);
	LCD_writestr("   Dist.:");
	LCD_writeint(distance);
	LCD_writestr("      ");
}