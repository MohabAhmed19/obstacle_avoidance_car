/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : APIs of LCD (16 * 2) module                          */
/******************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define F_CPU 8000000

/** MACROS TO DEFINE THE POPERATING MODE OF LCD **/
#define BIT_MODE_4     0
#define BIT_MODE_8     1

/** MACROS FOR DIFFERENT LCD COMMANDS **/

#define LCD_CURSOR_OFF       0x0C
#define LCD_RETURN_HOME      0x02
#define LCD_CURSOR_INC       0x06
#define LCD_CLEAR            0x01

#define LCD_8BIT_MODE        0x38
#define LCD_4BIT_MODE_CMD1   0x33
#define LCD_4BIT_MODE_CMD2   0x32
#define LCD_4BIT_MODE_CMD3   0x28


/** TYPEDEF TO RETURN THE STATUS OF EACH FUNCTION  **/
typedef enum { VALID__LCD_INIT  , NOT_VALID_LCD_INIT } LCD_status ;

/**********************************************************/
/** FUNCTION TO INITIALIZE LCD                            */
/** ARGUMENTS   : VOID                                    */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_init(void);

/**********************************************************/
/** FUNCTION TO SEND COMMAND TO LCD                       */
/** ARGUMENTS   : COMMAND                                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_sendcmd(uint8_t u8_a_cmd);

/**********************************************************/
/** FUNCTION TO DISPLAY CHARACTER ON LCD                  */
/** ARGUMENTS   : CHARACTER                               */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writechar(uint8_t u8_a_chr);

/**********************************************************/
/** FUNCTION TO DISPLAY STRING ON LCD                     */
/** ARGUMENTS   : CHARACTER                               */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writestr(uint8_t* u8_s_str);

/**********************************************************/
/** FUNCTION TO JUMP TO SPECIFIC POSITION ON LCD          */
/** ARGUMENTS   : ROW , COLUMN (POSITION)                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status  LCD_goto(uint8_t u8_a_row , uint8_t u8_a_column);

/**********************************************************/
/** FUNCTION TO CLEAR THE LCD                             */
/** ARGUMENTS   : ROW , COLUMN (POSITION)                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_clear(void);


/**********************************************************/
/** FUNCTION TO WRITE INT ON THE LCD                      */
/** ARGUMENTS   : ROW , COLUMN (POSITION)                 */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writeint(sint32_t s32_a_num);


/**********************************************************/
/** FUNCTION TO WRITE CUSOMIZED CHARACTER ON THE LCD      */
/** ARGUMENTS   : PATTERN , OCATION IN CGRAM              */
/** RETURNS     : ERROR STATUS                            */
/**********************************************************/
LCD_status LCD_writecustomchar(uint8_t * u8_a_pattern , uint8_t u8_a_location);



#endif /* ADC_INTERFACE_H_ */