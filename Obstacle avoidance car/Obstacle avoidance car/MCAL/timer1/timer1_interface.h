/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/ 
/** Hint    : TMR1 APIs                                       **/
/***************************************************************/ 
#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


#define  F_CPU 8000000  /** DEFINE CPU FREQUENCY **/


/* CLOCK SOURCE */
#define TMR1_INTERNAL_CLK_SOURCE               0
#define TMR1_EXTERNAL_CLK_SOURCE               1

/* AVAILABLE OPTIONS OF EXTERNAL TRIGGER */
#define EXTERNAL_FALLING_EDGE                  0
#define EXTERNAL_RISING_EDGE                   1

/* INTERNAL CLOCK SOURCE OPTIONS */
#define NORMAL_MODE                            0

#define CTC_UNITA_MODE                         1
#define CTC_UNITB_MODE                         2

#define PWM_UNITA_INVERTING_MODE               3
#define PWM_UNITA_NON_INVERTING_MODE           4
#define PWM_UNITB_INVERTING_MODE               5
#define PWM_8BIT_MODE                          6
#define PWM_9BIT_MODE                          7
#define PWM_10BIT_MODE                         8
#define PWM_ADAPTED_TOP                        9

#define PHASE_CORRECT_UNITA_INVERTING_MODE     10
#define PHASE_CORRECT_UNITB_INVERTING_MODE     11
#define PHASE_CORRECT_UNITA_NON_INVERTING_MODE 12
#define PHASE_CORRECT_UNITB_NON_INVERTING_MODE 13
#define PHASE_CORRECT_8BIT_MODE                14
#define PHASE_CORRECT_9BIT_MODE                15
#define PHASE_CORRECT_10BIT_MODE               16

/* COMPARE ACTIONS */
#define SET_ON_COMPARE                         0
#define CLEAR_ON_COMPARE                       1
#define TOGGLE_ON_COMPARE                      2

/* PRESCALLER VALUES */
#define NO_PRESCALER                           0
#define PRESCALER_8                            1
#define PRESCALER_64                           2
#define PRESCALER_256                          3
#define PRESCALER_1024                         4



/** TYPEDEF FOR RETURN STATUS OF TMR1_init FUNCTION **/
typedef enum { TMR1_VALID_INIT  , TMR1_NOT_VALID_INIT } TMR1_status ; 


/** TYPEDEF FOR RETURN STATUS OF TMR1_start FUNCTION **/
typedef enum { TMR1_VALID_START  , TMR1_NOT_VALID_START } TMR1_start_status ; 


/** TYPEDEF FOR RETURN STATUS OF TMR1_stop FUNCTION **/
typedef enum { TMR1_VALID_STOP  , TMR1_NOT_VALID_STOP } TMR1_stop_status ; 


/** TYPEDEF FOR RETURN STATUS OF TMR1_setdelayms FUNCTION **/
typedef enum { TMR1_VALID_DELAY  , TMR1_NOT_VALID_DELAY } TMR1_delay_status ; 


/******************************************************************************/
/** FUNCTION TO INITIALIZE TMR1 ACCORDING TO CONFIGURATION FILE              **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF INITIALIZATION                  **/
/******************************************************************************/
TMR1_status TMR1_init(void);

/******************************************************************************/
/** FUNCTION TO START TMR1 (ASSIGN THE PRESCALLER CONFIGURATION)             **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF START                           **/
/******************************************************************************/
TMR1_start_status TMR1_start(void);


/******************************************************************************/
/** FUNCTION TO SET DELAY IN MS                                              **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF DELAY                           **/
/******************************************************************************/
TMR1_delay_status TMR1_setdelayms(uint32_t DELAY_MS);


/******************************************************************************/
/** FUNCTION TO STOP TMR1                                                    **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF STOP STATUS                     **/
/******************************************************************************/
TMR1_stop_status TMR1_stop(void);


/******************************************************************************/
/** FUNCTION TO CALCULATE THE NUMBER OF NEEDED OVERFLOWS                     **/
/** ARGUMENTS  : DELAY IN MS                                                 **/
/** RETURN     : RETURNS THE NUMBER OF OVS                                   **/
/******************************************************************************/
uint32_t TMR1_getovs(uint32_t u32_a_delay);

/******************************************************************************/
/** FUNCTION TO GET THE VALUE OF TIMER 1 COUNTING REGISTER                   **/
/** ARGUMENTS  : u16_a_value                                                 **/
/** RETURN     : VOID                                                        **/
/******************************************************************************/
void TMR1_getvalue(uint16t * u16_a_value);


void TMR1_setvalue(uint16t u16_a_value);



#endif /* TMR1_H_ */