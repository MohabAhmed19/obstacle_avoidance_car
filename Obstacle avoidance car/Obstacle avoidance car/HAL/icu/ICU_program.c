/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 19 May , 2021                                   **/
/** Version : V01                                             **/
/** Hint    : implementation of input capture unit APIs       **/
/***************************************************************/

/** INCLUDE LIBRARIES  **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYERS' FILES **/
#include "../../MCAL/int0/INT_interface.h"
#include "../../MCAL/timer1/timer1_interface.h"

/** INCLUDE DRIVER FILES **/
#include "ICU_interface.h"
#include "ICU_config.h"

/**************************************************************/
/** FUNCTION TO INITIALIZE THE ICU ON SPECIFIC PIN           **/
/** ARGUMENTS : u8_a_pin EXTERNAL INTERRUPT PIN              **/
/** RETURN    : VOID                                         **/
/**************************************************************/
en_a_icuerrorstatus ICU_init(void)
{
	en_a_icuerrorstatus en_a_returnstatus = VALID_ICU_INIT ;
	
	#if ICU_EXTI_PIN ==  ICU_EXTI0
		INT0_init();  /** USE EXTERNAL INTERRUPT 0 PIN **/
		
	#elif ICU_EXTI_PIN ==  ICU_EXTI1
		INT1_init();  /** USE EXTERNAL INTERRUPT 1 PIN **/
		
	#elif ICU_EXTI_PIN ==  ICU_EXTI2
		INT2_init();  /** USE EXTERNAL INTERRUPT 2 PIN **/
	#else 
		en_a_returnstatus = NOTVALID_ICU_INIT ; /** NOT VALID PIN **/
	#endif
	
	return en_a_returnstatus ; /** RETURN THE STATUS **/
		
}


/**************************************************************/
/** FUNCTION TO GET THE VALUE OF TIMER WHEN EVENT HAPPENS    **/
/** ARGUMENTS : u8_a_pin EXTERNAL INTERRUPT PIN              **/
/** RETURN    : VOID                                         **/
/**************************************************************/
uint16t ICU_getvalue(void)
{
	uint16t u16_l_time = 0 ; /** LOCAL VARIABLE TO RETURN THE TIME STAMP **/
	
	TMR1_getvalue(&u16_l_time) ; /** GET THE VALUE FROM TIMER1 REGISTER **/
	
	return u16_l_time ; /** RETURN THE TIME STAMP **/
}

