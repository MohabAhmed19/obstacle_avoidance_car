/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : implementation of LCD APIs                           */
/******************************************************************/


/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE INTERFACE FILE OF LOWER LAYERS **/
#include "../../MCAL/dio/DIO_interface.h"
#include "../../MCAL/dio/DIO_private.h"

#include "../../MCAL/timer0/TMR0_interface.h"
#include "../../MCAL/timer0/TMR0_config.h"

/** INCLUDE DRIVER FILES **/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/**********************************************************/
/** FUNCTION TO INITIALIZE LCD                            */
/** ARGUMENTS   : VOID                                    */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_init(void)
{
	LCD_status en_a_lcdinitstatus = VALID__LCD_INIT ; /** VARIABLE TO OLD THE RETURN STATUS OF THE FUNCTION **/
	
	TMR0_init();
	
		#if LCD_MODE  == BIT_MODE_8    /** IF LCD CONFIGURED AS 8 BIT MODE **/
		
		DIO_setpindir(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT); /** SET RS PIN AS OUTPUT PIN **/
		DIO_setpindir(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT); /** SET RW PIN AS OUTPUT PIN **/
		DIO_setpindir(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);  /** SET E PIN AS OUTPUT PIN  **/
		
		DIO_setportdir(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT); /** SET THE DIRECTION OF LCD PORT AS OUTPUT **/
		
		TMR0_delayms(20);  /** DELAY FOR LCD TO BE INITIALIZED **/
		
		/** SEND SOME COMMANDS TO THE LCD FOR INITIAL SET   **/
		
		LCD_sendcmd(LCD_8BIT_MODE);   /** SEND COMMAND FOR LCD TO SET 8 BIT OPERATION MODE ( 2 LINES , 5*8 MATRIX ) **/
		LCD_sendcmd(LCD_CURSOR_OFF);  /** NO NEED FOR CURSOR SO IT IS OFF                  **/
		LCD_sendcmd(LCD_CURSOR_INC);  /** DIRECTION OF WRITING FROM LEFT TO RIGHT          **/
		LCD_sendcmd(LCD_RETURN_HOME); /** CURSOR STARTS FROM ITS HOME POSITION             **/
		LCD_sendcmd(LCD_CLEAR);       /** CLEAR THE LCD                                    **/
		
		
		#elif LCD_MODE == BIT_MODE_4    /** IF LCD CONFIGURED AS 4 BIT MODE **/
		
		DIO_setpindir(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT); /** SET RS PIN AS OUTPUT PIN **/
		DIO_setpindir(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT); /** SET RW PIN AS OUTPUT PIN **/
		DIO_setpindir(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);  /** SET E PIN AS OUTPUT PIN  **/
		
		DIO_setpindir(LCD_4BIT_DATA_PORT , LCD_D4_PIN , DIO_PIN_OUTPUT); /** 4 DATA PINS AS OUTPUT **/
		DIO_setpindir(LCD_4BIT_DATA_PORT , LCD_D5_PIN , DIO_PIN_OUTPUT);
		DIO_setpindir(LCD_4BIT_DATA_PORT , LCD_D6_PIN , DIO_PIN_OUTPUT);
		DIO_setpindir(LCD_4BIT_DATA_PORT , LCD_D7_PIN , DIO_PIN_OUTPUT);
		
		TMR0_delayms(20); /** DELAY FOR LCD TO BE INITIALIZED **/
		
		/** SEND SOME COMMANDS TO THE LCD FOR INITIAL SET   **/
		
		LCD_sendcmd(LCD_4BIT_MODE_CMD1); /** SEND THREE COMMANDS FOR LCD TO SET 4 BIT OPERATION MODE ( 2 LINES , 5*8 MATRIX ) **/
		LCD_sendcmd(LCD_4BIT_MODE_CMD2);
		LCD_sendcmd(LCD_4BIT_MODE_CMD3);
		
		LCD_sendcmd(LCD_CURSOR_OFF);     /** NO NEED FOR CURSOR SO IT IS OFF                  **/
		LCD_sendcmd(LCD_CURSOR_INC);     /** DIRECTION OF WRITING FROM LEFT TO RIGHT          **/
		LCD_sendcmd(LCD_RETURN_HOME);    /** CURSOR STARTS FROM ITS HOME POSITION             **/
		LCD_sendcmd(LCD_CLEAR);          /** CLEAR THE LCD                                    **/
		
		#endif 
		
}


/**********************************************************/
/** FUNCTION TO SEND COMMAND TO LCD                       */
/** ARGUMENTS   : COMMAND                                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_sendcmd(uint8_t u8_a_cmd)
{
	TMR0_init();
	
		#if LCD_MODE  == BIT_MODE_8    /** IF LCD CONFIGURED AS 8 BIT MODE **/
		
		DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);  /** COMMAND MODE       **/
		DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  /** WRITE TO LCD MODE  **/
		DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);   /** PREPARE FOR LATCH  **/
		
		DIO_setportvalue(PORTA , u8_a_cmd);  /** SEND THE COMMAND **/
		
		DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);  /** LATCH **/
		TMR0_delayms(1); /** HIGH **/
		
		DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  /** LATCH **/
		TMR0_delayms(5); /** LOW **/
		
		#elif LCD_MODE == BIT_MODE_4    /** IF LCD CONFIGURED AS 4 BIT MODE **/
		
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);  /** COMMAND MODE       **/
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  /** WRITE TO LCD MODE  **/
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);   /** PREPARE FOR LATCH  **/
		
		PORTA = ((u8_a_cmd & 0xF0) | (PORTA & 0x0F)); /** SEND THE MSB(HIGH NIBBLE) **/
		
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); /** LATCH **/
		TMR0_delayms(1);
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  /** LATCH **/
		
		
		PORTA = (((u8_a_cmd << 4) & 0xF0) | (PORTA & 0x0F)); /** SEND THE LSB(LOW NIBBLE) **/
		
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); /** LATCH **/
		TMR0_delayms(1);
		
		DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);    /** LATCH **/
		
		TMR0_delayms(5); /** 5 ms BEFORE SENDING THE NEXT COMMAND **/
		
		#endif
}


/**********************************************************/
/** FUNCTION TO DISPLAY CHARACTER ON LCD                  */
/** ARGUMENTS   : CHARACTER                               */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writechar(uint8_t u8_a_chr)
{
	
	#if LCD_MODE  == BIT_MODE_8    /** IF LCD CONFIGURED AS 8 BIT MODE **/
	
	DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);  /** DATA MODE         **/
	DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);   /** WRITE TO LCD MODE **/
	DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);    /** DATA MODE         **/
	
	PORTA = u8_a_chr;  /** SEND THE CHARACTER **/
	
	DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); /** LATCH **/
	TMR0_delayms(1);
	
	DIO_setpinvalue(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  /** LATCH **/
	
	TMR0_delayms(5); /** 5 ms BEFORE SENDING THE NEXT CHARACTER **/
	
	#elif LCD_MODE == BIT_MODE_4    /** IF LCD CONFIGURED AS 4 BIT MODE **/
	
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);  /** DATA MODE         **/
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);   /** WRITE TO LCD MODE **/
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);    /** DATA MODE         **/
	
	
	PORTA = ((u8_a_chr & 0xF0) | (PORTA & 0x0F)); /** SEND THE MSB (HIGH NIBBLE) **/
	
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); /** LATCH **/
	TMR0_delayms(1);
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW); /** LATCH **/
		
	PORTA = (((u8_a_chr << 4) & 0xF0) | (PORTA & 0x0F)); /** SEND THE LSB (LOW NIBBLE) **/
	
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); /** LATCH **/
	TMR0_delayms(1);
	DIO_setpinvalue(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  /** LATCH **/
	
	TMR0_delayms(5); /** 5 ms BEFORE SENDING THE NEXT CHARACTER **/
	
	#endif
}



/**********************************************************/
/** FUNCTION TO DISPLAY STRING ON LCD                     */
/** ARGUMENTS   : STRING                                  */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writestr(uint8_t* u8_s_str)
{
	uint8_t u8_a_letter = 0;   /** VARIABLE SIMULATES LETTER **/
	
	while (u8_s_str[u8_a_letter] != '\0') /** WHILE LETTER ISN'T NULL **/
	{
		LCD_writechar(u8_s_str[u8_a_letter]); /** SEND LETTER TO LCD **/	
		u8_a_letter++; /** JUMP TO THE NEXT LETTER **/
	}
}


/**********************************************************/
/** FUNCTION TO JUMP TO SPECIFIC POSITION ON LCD          */
/** ARGUMENTS   : ROW , COLUMN (POSITION)                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status  LCD_goto(uint8_t u8_a_row , uint8_t u8_a_column)
{
	uint8_t positions[2] = {0x80 , 0xC0}; /** POSITIONS OF 1st & 2nd ROWS **/
	
	LCD_sendcmd(positions[u8_a_row] + u8_a_column); /** GO TO SPECIFIC MATRIX **/
}

/**********************************************************/
/** FUNCTION TO WRITE CUSOMIZED CHARACTER ON THE LCD      */
/** ARGUMENTS   : PATTERN , OCATION IN CGRAM              */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writecustomchar(uint8_t * u8_a_pattern , uint8_t u8_a_location)
{
	uint8_t u8_a_patterncounter = 0 ; /** ITERATOR ON THE ROWS OF CHARACTER PATTERN **/
	
	LCD_sendcmd( 0x40 + (u8_a_location * 8) ); /** SEND COMMAND TO LCD TO WRITE TO ITS RAM **/
	
	for(u8_a_patterncounter = 0 ; u8_a_patterncounter < 8 ; u8_a_patterncounter++)
	{
		LCD_writechar(u8_a_pattern[u8_a_patterncounter]); /** STORE 8 BYTES (PATTERN) **/
	}
}

/**********************************************************/
/** FUNCTION TO WRITE INT ON THE LCD                      */
/** ARGUMENTS   : ROW , COLUMN (POSITION)                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writeint(sint32_t s32_a_num)
{
	uint8_t i = 0 , k ;
	
	uint8_t number[10];
	
	/* In case of negative numbers */
	if(s32_a_num < 0)
	{
		s32_a_num *= -1;
		
		while(s32_a_num > 0)
		{
			number[i] = (s32_a_num % 10) + 48;  //Equivalent ASCII of number
			s32_a_num /= 10;
			i++;
		}
		number[i] = '-'; // storing the negative sign
		
		for(k = i+1 ; k > 0 ; k--)
		{
			LCD_writechar(number[k - 1]); //Display each number
		}
	}
	/* Zero case */
	else if(s32_a_num == 0)
	{
		LCD_writechar('0');
	}
	
	/* In case of positive numbers */
	else if(s32_a_num > 0)
	{
		while(s32_a_num > 0)
		{
			number[i] = (s32_a_num % 10) + 48; //Equivalent ASCII of number
			s32_a_num /= 10;
			i++;
		}
		
		for(k = i ; k > 0 ; k--)
		{
			LCD_writechar(number[k-1]); //Display each number
		}
	}
}