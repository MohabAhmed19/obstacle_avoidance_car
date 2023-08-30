/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Configuration file of Timer 0                        */
/******************************************************************/ 

#ifndef TMR0_CONFIG_H
#define TMR0_CONFIG_H

/*******************************************************************/
/**                 TMR0 CLOCK SOURCE                             **/
/** AVAILABLE CHOICES     1 - INTERNAL_CLK_SRC                    **/
/**                       2 - EXTERNAL_CLK_SRC                    **/
/*******************************************************************/
#define TIMER0_CLK_SRC           INTERNAL_CLK_SRC

/*******************************************************************/
/**                 TMR0 EXTERNAL EDGE COUNTING ACTION            **/
/** AVAILABLE CHOICES     1 - FALLING_EDGE_CNT                    **/
/**                       2 - RISING_EDGE_CNT                     **/
/*******************************************************************/
#define CNT0_EXTERNAL_EDGE_MODE  RISING_EDGE_CNT

/*******************************************************************/
/**                 TMR0 OERATING MODE                            **/
/** AVAILABLE CHOICES     1 - TMR0_NORMAL_MODE                    **/
/**                       2 - TMR0_FASTPWM_NON_INVERTED_MODE      **/
/**                       3 - TMR0_FASTPWM_INVERTED_MODE          **/
/**                       4 - TMR_PHASE_CORRECT_NON_INVERTED_MODE **/
/**                       5 - TMR_PHASE_CORRECT_INVERTED_MODE     **/
/**                       6 - TMR0_CTC_MODE                       **/
/*******************************************************************/
#define TIMER0_MODE             TMR0_NORMAL_MODE


/*******************************************************************/
/**                     TMR0 PRESCALLER                           **/
/** AVAILABLE CHOICES     1 - NO_PRESCALER                        **/
/**                       2 - PRESCALER_8                         **/
/**                       3 - PRESCALER_64                        **/
/**                       4 - PRESCALER_256                       **/
/**                       5 - PRESCALER_1024                      **/
/*******************************************************************/
#define TIMER0_PRESCALER_VAL  PRESCALER_1024   



/*******************************************************************/
/**                     TMR0 ACTION ON COMPARE                    **/
/** AVAILABLE CHOICES     1 - SET_ON_COMPARE                      **/
/**                       2 - CLEAR_ON_COMPARE                    **/
/**                       3 - TOOGLE_ON_COMPARE                   **/
/*******************************************************************/
#define COMPARE_ACTION         TOOGLE_ON_COMPARE


#endif