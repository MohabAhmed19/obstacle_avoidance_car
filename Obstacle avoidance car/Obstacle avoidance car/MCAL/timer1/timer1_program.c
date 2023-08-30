/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/ 
/** Hint    : Implementation of TMR1 APIs                     **/
/***************************************************************/ 

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE FILES OF LOWER LAYERS **/
#include "../dio/DIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "timer1_interface.h"
#include "timer1_private.h"
#include "timer1_config.h"

uint32_t u32_gs_NO_OF_OVS = 0 ; /** GLOBAL STATIC VARIABLE HOLDS THE NUBER OF OVERFLOWS **/
 
/******************************************************************************/
/** FUNCTION TO INITIALIZE TMR1 ACCORDING TO CONFIGURATION FILE              **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF INITIALIZATION                  **/
/******************************************************************************/
TMR1_status TMR1_init(void)
{
	#if TMR1_CLK_SOURCE == TMR1_EXTERNAL_CLK_SOURCE
	 
	  /* SET THE T1 CLK BIT AS INPUT */
	 DIO_setpindir(DIO_PORTB , DIO_PIN1 , DIO_PIN_INPUT);
	
	 #if TMR1_COUNTING_ACTION == EXTERNAL_RISING_EDGE
	 
	  set_bit(TCCR1B , 0);
	  set_bit(TCCR1B , 1);
	  set_bit(TCCR1B , 2);
	  
	 #elif TMR1_COUNTING_ACTION == EXTERNAL_FALLING_EDGE
	 
	 clear_bit(TCCR1B , 0);
	 set_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 #endif
	 
	#elif TMR1_CLK_SOURCE == TMR1_INTERNAL_CLK_SOURCE
	
	 #if TMR1_MODE == NORMAL_MODE
	  
	  clear_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* NON PWM MODE */
	  set_bit(TCCR1A , 2);
	  set_bit(TCCR1A , 3);
	  
	  /* ENABLE INTERRUPT */
	 // set_bit(SREG , 7);   /** ENABLE GLOBAL INTTERUPTS **/
	  //set_bit(TIMSK , 2);  /** NABLE TMR1 INTERRUPT **/
	  
	 #elif TMR1_MODE == CTC_UNITA_MODE
	  
	  /* SET THE OC1A BIT AS OUTPUT */
	  DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	  
	   clear_bit(TCCR1A , 0);
	   clear_bit(TCCR1A , 1);
	   set_bit(TCCR1B , 3);
	   clear_bit(TCCR1B , 4);
	   
	   /* NON PWM MODE */
	   set_bit(TCCR1A , 3);
	   
	   /* ENABLE INTERRUPT */
	   set_bit(SREG , 7);
	   set_bit(TIMSK , 4);
	   
	   /* ACTION ON COMPARE MATCH OF UNIT A */
	   #if COMPARE_ACTION == SET_ON_COMPARE 
	    
		set_bit(TCCR1A , 6);
		set_bit(TCCR1A , 7);
		
	   #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	   
	    clear_bit(TCCR1A , 6);
	    set_bit(TCCR1A , 7);
		
	   #elif COMPARE_ACTION == TOGGLE_ON_COMPARE
	    
		set_bit(TCCR1A , 6);
		clear_bit(TCCR1A , 7);
	   #endif 
	  
	 #elif TMR1_MODE == CTC_UNITB_MODE
	  
	  /* SET THE OC1B BIT AS OUTPUT */
	  //DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	  
	  clear_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* NON PWM MODE */
	  set_bit(TCCR1A , 2);
	  
	  /* ENABLE INTERRUPT */
	  set_bit(SREG , 7);
	  set_bit(TIMSK , 3);
	  
	  /* ACTION ON COMPARE MATCH OF UNIT B */
	  #if COMPARE_ACTION == SET_ON_COMPARE
	  
	  set_bit(TCCR1A , 4);
	  set_bit(TCCR1A , 5);
	  
	  #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	  
	  clear_bit(TCCR1A , 4);
	  set_bit(TCCR1A , 5);
	  
	  #elif COMPARE_ACTION == TOGGLE_ON_COMPARE
	  
	  set_bit(TCCR1A , 4);
	  clear_bit(TCCR1A , 5);
	  #endif
	  
	 #elif TMR1_MODE == PWM_8BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	  /* SET THE OC1B BIT AS OUTPUT */
	  DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	  /* SET THE OC1B BIT AS OUTPUT */
	  DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PWM_9BIT_MODE
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	#endif

	 #elif TMR1_MODE == PWM_10BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PWM_ADAPTED_TOP
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  set_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PHASE_CORRECT_8BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);

	  /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif
	  
	 #elif TMR1_MODE == PHASE_CORRECT_9BIT_MODE
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PHASE_CORRECT_10BIT_MODE
	 
	 set_bit(TCCR1A , 0);
	 set_bit(TCCR1A , 1);
	 clear_bit(TCCR1B , 3);
	 clear_bit(TCCR1B , 4);

	 /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_setpindir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif
	#endif
#endif
}


/******************************************************************************/
/** FUNCTION TO START TMR1 (ASSIGN THE PRESCALLER CONFIGURATION)             **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF START                           **/
/******************************************************************************/
TMR1_start_status TMR1_start(void)
{
  TMR1_start_status en_a_startstatus = TMR1_NOT_VALID_START ; /** VARIABLE TO HOLD THE RETURN STATUS **/
  
  #if TMR1_CLK_SOURCE == TMR1_INTERNAL_CLK_SOURCE /** ALLOWED ONLY IF INTERNAL CLK SOURCE **/
	 
         /** SET THE VALUES OF CONFIGURED PRESCALLER **/ 
	 #if TMR1_PRESCALLER_VALUE == PRESCALER_1024 
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);

	 en_a_startstatus = TMR1_VALID_START ; /** STATUS IS VALID **/

	 #elif TMR1_PRESCALLER_VALUE == PRESCALER_256
	 
	 clear_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 
         en_a_startstatus = TMR1_VALID_START ; /** STATUS IS VALID **/

	 #elif TMR1_PRESCALLER_VALUE == PRESCALER_64
	 
	 set_bit(TCCR1B , 0);
	 set_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);

         en_a_startstatus = TMR1_VALID_START ; /** STATUS IS VALID **/
	 
	 #elif TMR1_PRESCALLER_VALUE == NO_PRESCALER
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);
         
         en_a_startstatus = TMR1_VALID_START ; /** STATUS IS VALID **/

	 #endif
	#endif

  return en_a_startstatus ; /** RETURN THE FINAL STATUS **/
}



/******************************************************************************/
/** FUNCTION TO SET DELAY IN MS                                              **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF DELAY                           **/
/******************************************************************************/
TMR1_delay_status TMR1_setdelayms(uint32_t DELAY_MS)
{
	uint32_t u32_a_overflowcounter = 0 ;
	
	TMR1_delay_status en_a_delaystatus = TMR1_NOT_VALID_DELAY   ; /** VARIABLE TO RETURN THE STATUS **/
	
	/***************************************************************************/
	/**            THESE CALCULATIONS ARE DONE USING F_CPU = 1 MHZ            **/
	/***************************************************************************/
	
	#if TMR1_PRESCALLER_VALUE == PRESCALER_1024  /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	 
        u32_gs_NO_OF_OVS = (DELAY_MS / 67108864);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/ 
	
        TCNT1 = 0 ;   /** SET THE INITIAL VALUE IN TCNT1 REGISTER **/
	
	  en_a_delaystatus = TMR1_VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TMR1_PRESCALLER_VALUE == PRESCALER_256

	  u32_gs_NO_OF_OVS = (DELAY_MS / 16777.216);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	  TCNT1 = 0 ;   /** SET THE INITIAL VALUE IN TCNT REGISTER **/
	
	  en_a_delaystatus = TMR1_VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TMR1_PRESCALLER_VALUE == PRESCALER_64
		
	  u32_gs_NO_OF_OVS = (DELAY_MS / 4194.304);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	  TCNT1 = 0 ;   /** SET THE INITIAL VALUE IN TCNT1 REGISTER **/
	
	  en_a_delaystatus = TMR1_VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TMR1_PRESCALLER_VALUE == NO_PRESCALER
	
	  u32_gs_NO_OF_OVS = (DELAY_MS / 65.536);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	  TCNT1 = 0 ;   /** SET THE INITIAL VALUE IN TCNT1 REGISTER **/
	
	  en_a_delaystatus = TMR1_VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#endif
        
     TMR1_start();  /** START TMR1 **/
 	
 	while ( u32_a_overflowcounter < u32_gs_NO_OF_OVS ) /** STUCK IN THIS LOOP UNTILL THIS CONDITION IS FALSE **/ 		
 	{
  
 	  while( (TIFR & (1 << 2)) == 0); /** DO NOTHING UNTILL THIS FLAG RAISED (OVERFLOW HAPPENED) **/
 
 		set_bit(TIFR , 2);        /** CLEAR THE FLAG BY SOFTWARE **/ 			
 		u32_a_overflowcounter++ ; /** INCREASE THE OVERFLOWS BY ONE **/
 			
 	}
 		
 	u32_a_overflowcounter = 0 ; /** REINTIALIZE THE OVERFLOWS COUNTER TO 0 AGAIN **/
 
 		 
 	TMR1_stop();     /** STOP TMR1 TO START FROM 0 WHEN IT CALLED AGAIN **/
	
	
    return en_a_delaystatus ; /** RETURN THE FINAL STATUS **/
}

/******************************************************************************/
/** FUNCTION TO STOP TMR1                                                    **/
/** ARGUMENTS  : VOID                                                        **/
/** RETURN     : RETURNS THE ERROR STATUS OF STOP STATUS                     **/
/******************************************************************************/
TMR1_stop_status TMR1_stop(void)
{
     TMR1_stop_status en_a_stopstatus = TMR1_NOT_VALID_STOP ; /** VARIABLE TO HOLD THE RETURN STATUS  **/
	
     /* TURN THE CLOCK OFF */
     clear_bit(TCCR1B , 0);
     clear_bit(TCCR1B , 1);
     clear_bit(TCCR1B , 2);

     en_a_stopstatus = TMR1_NOT_VALID_STOP ; /** UPDATE THE STOP STATUS **/

     return en_a_stopstatus ; /** RETURN THE FINAL STATUS **/

}


/******************************************************************************/
/** FUNCTION TO CALCULATE THE NUMBER OF NEEDED OVERFLOWS                     **/
/** ARGUMENTS  : DELAY IN MS                                                 **/
/** RETURN     : RETURNS THE NUMBER OF OVS                                   **/
/******************************************************************************/
uint32_t TMR1_getovs(uint32_t u32_a_delay)
{
	uint32_t u32_a_ovs = 0 ;
	
	/********************************************************************/
	/**      THIS CALCULATIONS ARE DONE ON 1 MHZ F_CPU                 **/
	/********************************************************************/
	#if TMR1_PRESCALLER_VALUE == PRESCALER_1024  /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	
	u32_a_ovs = (u32_a_delay / 67108864);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	

	#elif TMR1_PRESCALLER_VALUE == PRESCALER_256

	u32_a_ovs = (u32_a_delay / 16777.216);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
		
	#elif TMR1_PRESCALLER_VALUE == PRESCALER_64
	
	u32_a_ovs = (u32_a_delay / 4194.304);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	

	#elif TMR1_PRESCALLER_VALUE == NO_PRESCALER
	
	u32_a_ovs = (u32_a_delay / 65.536);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	
	#endif
	
	return u32_a_ovs ;
}


/******************************************************************************/
/** FUNCTION TO GET THE VALUE OF TIMER 1 COUNTING REGISTER                   **/
/** ARGUMENTS  : u16_a_value                                                 **/
/** RETURN     : VOID                                                        **/
/******************************************************************************/
void TMR1_getvalue(uint16t * u16_a_value)
{
	*u16_a_value = TCNT1 ; /** GET THE VALUE FROM TIMER1 COUNTING REGISTER **/
}

void TMR1_setvalue(uint16t u16_a_value)
{
	TCNT1 = u16_a_value;
}