/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 11 April, 2023                                 **/
/** Version : V01                                             **/ 
/** Hint    : TMR1 configuration file                         **/
/***************************************************************/ 

#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

/**********************************************************************/
/**          MACRO TO SET THE SOURCE OF TMR1 COCK                    **/
/**  AVAILABLE CHOICES : 1 - TMR1_INTERNAL_CLK_SOURCE                **/
/**                      2 - TMR1_EXTERNAL_CLK_SOURCE                **/
/**********************************************************************/                         
#define TMR1_CLK_SOURCE        TMR1_INTERNAL_CLK_SOURCE 


/**********************************************************************/
/**          MACRO TO SET THE COUNTING TRIGGERING ACTION             **/
/**  AVAILABLE CHOICES : 1 - EXTERNAL_FALLING_EDGE                   **/
/**                      2 - EXTERNAL_RISING_EDGE                    **/
/**********************************************************************/
#define TMR1_COUNTING_ACTION   EXTERNAL_RISING_EDGE


/**********************************************************************/
/**          MACRO TO SET THE OPERATING MODE OF TMR1                 **/
/**  AVAILABLE CHOICES : 1 - NORMAL_MODE                             **/
/**                      2 - CTC_UNITA_MODE                          **/
/**                      3 - CTC_UNITB_MODE                          **/ 
/**                      4 - PWM_UNITA_INVERTING_MODE                **/
/**                      5 - PWM_UNITA_NON_INVERTING_MODE            **/
/**                      6 - PWM_UNITB_INVERTING_MODE                **/
/**                      7 - PWM_8BIT_MODE                           **/
/**                      8 - PWM_9BIT_MODE                           **/
/**                      9 - PWM_10BIT_MODE                          **/
/**                      10 - PWM_ADAPTED_TOP                        **/
/**                      11 - PHASE_CORRECT_UNITA_INVERTING_MODE     **/
/**                      12 - PHASE_CORRECT_UNITB_INVERTING_MODE     **/
/**                      13 - PHASE_CORRECT_UNITA_NON_INVERTING_MODE **/
/**                      14 - PHASE_CORRECT_UNITB_NON_INVERTING_MODE **/
/**                      15 - PHASE_CORRECT_8BIT_MODE                **/
/**                      16 - PHASE_CORRECT_9BIT_MODE                **/
/**                      17 - PHASE_CORRECT_10BIT_MODE               **/
/**********************************************************************/
#define TMR1_MODE              NORMAL_MODE 

#define PWM_MODE               PWM_10BIT_MODE

#define PHASE_CORRECT_MODE     PHASE_CORRECT_UNITA_INVERTING_MODE 
/**********************************************************************/
/**          MACRO TO SET THE PRESCALLER CONFIGURATION               **/
/**  AVAILABLE CHOICES : 1 - NO_PRESCALER                            **/
/**                      2 - PRESCALER_8                             **/
/**                      3 - PRESCALER_64                            **/
/**                      4 - PRESCALER_256                           **/
/**                      5 - PRESCALER_1024                          **/
/**********************************************************************/
#define TMR1_PRESCALLER_VALUE       PRESCALER_64      


/**********************************************************************/
/**          MACRO TO SET THE ACTION IN COMPARE MODE                 **/
/**  AVAILABLE CHOICES : 1 - SET_ON_COMPARE                          **/
/**                      2 - CLEAR_ON_COMPARE                        **/
/**                      3 - TOGGLE_ON_COMPARE                       **/
/**********************************************************************/
#define COMPARE_ACTION   TOGGLE_ON_COMPARE
 

#endif /* TMR1_CONFIG_H_ */