/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Configuration file of LCD                            */
/******************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE   BIT_MODE_4               /** LCD OPERATING MODE **/

#define LCD_8BIT_DATA_PORT   DIO_PORTA      /** 8 BIT MODE DATA PORT    **/  
#define LCD_8BIT_CMD_PORT    DIO_PORTA      /** 8 BIT MODE COMMAND PORT **/  

#define LCD_4BIT_DATA_PORT   DIO_PORTA      /** 4 BIT MODE DATA PORT      **/ 
#define LCD_4BIT_CMD_PORT    DIO_PORTA     /** 4 BIT MODE COMMAND PORT   **/ 

#define LCD_RS_PIN           DIO_PIN1       /** RS PIN     **/
#define LCD_RW_PIN           DIO_PIN2       /** R/W PIN    **/
#define LCD_E_PIN            DIO_PIN3       /** ENABLE PIN **/

#define LCD_D0_PIN           DIO_PIN0       /** LCD DATA PINS **/
#define LCD_D1_PIN           DIO_PIN1
#define LCD_D2_PIN           DIO_PIN2
#define LCD_D3_PIN           DIO_PIN3
#define LCD_D4_PIN           DIO_PIN4
#define LCD_D5_PIN           DIO_PIN5
#define LCD_D6_PIN           DIO_PIN6
#define LCD_D7_PIN           DIO_PIN7


#endif /* ADC_CONFIG_H_ */