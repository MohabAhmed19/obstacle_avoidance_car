/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 16 April , 2023                      */
/* Version : V01                                  */
/* Hint    : Program file of DIO                  */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"


/** INCLUDE DRIVER FILES **/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE DIRECTION OF SPECIFIC PIN   */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinDirection_t                                       */
/******************************************************************/
PinDirection_t DIO_setpindir(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t u8_a_pindir)
{
	PinDirection_t en_a_dirstate = VALID_DIRECTION ; /** VARIABLE TO RETURN THE STATUS OF DIRECTION **/
	
	switch(u8_a_pindir) /** SWITCH CASE ON THE DIRECTION VALUE **/
	{
		case DIO_PIN_INPUT:  /* INPUT CASE  */
		
		switch(u8_a_portid) /** SWITCH CASE ON THE PORT ID */
		{
			case DIO_PORTA:
			clear_bit(DDRA , u8_a_pinid);           /** CONFIGURE THIS PIN IN PORTA AS INPUT PIN **/
			break;
			
			case DIO_PORTB:
			clear_bit(DDRB , u8_a_pinid);           /** CONFIGURE THIS PIN IN PORTB AS INPUT PIN **/
			break;
			
			case DIO_PORTC:
			clear_bit(DDRC , u8_a_pinid);           /** CONFIGURE THIS PIN IN PORTC AS INPUT PIN **/
			break;
			
			case DIO_PORTD:
			clear_bit(DDRD , u8_a_pinid);           /** CONFIGURE THIS PIN IN PORTD AS INPUT PIN **/
			break;
			
			default: /** DO NOTHING **/
			en_a_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
			break;
		} 
		break;
		
		case DIO_PIN_OUTPUT:  /* OUTPUT CASE  */
		
		switch(u8_a_portid) /** SWITCH CASE ON THE PORT ID */
		{
			case DIO_PORTA:
			set_bit(DDRA , u8_a_pinid);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			break;
			
			case DIO_PORTB:
			set_bit(DDRB , u8_a_pinid);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			break;
			
			case DIO_PORTC:
			set_bit(DDRC , u8_a_pinid);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			break;
			
			case DIO_PORTD:
			set_bit(DDRD , u8_a_pinid);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			break;
			
			default:  /** DO NOTHING **/
			en_a_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
			break;
		} 
		break;
		 
		 
		default:  /** DIRECTION ISN'T INPUT OR OUTPUT */
		en_a_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
		break ; 
	} 
	
	return en_a_dirstate ; /** RETURN THE STATE OF FUNCTION **/
}


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinValue_t                                           */
/******************************************************************/
PinValue_t DIO_setpinvalue(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t u8_a_pinval)
{
	
	PinValue_t en_a_valstate = VALID_VALUE ; /** VARIABLE TO RETURN THE STATUS OF VALUE **/ 
	
	switch(u8_a_pinval)
	{
		case DIO_PIN_LOW:  /** IN CASE PIN VALUE IS LOW */
		
		switch(u8_a_portid)  /** SWITCH CASE ON THE PORT ID */ 
		{
			case DIO_PORTA:
			clear_bit(PORTA , u8_a_pinid);       /** SET THIS PIN AS DIO_PIN_LOW **/
			break;
			
			case DIO_PORTB:
			clear_bit(PORTB , u8_a_pinid);       /** SET THIS PIN AS DIO_PIN_LOW **/
			break;
			
			case DIO_PORTC:
			clear_bit(PORTC , u8_a_pinid);       /** SET THIS PIN AS DIO_PIN_LOW **/
			break;
			
			case DIO_PORTD:
			clear_bit(PORTD , u8_a_pinid);       /** SET THIS PIN AS DIO_PIN_LOW **/
			break;
			
			default:
			en_a_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
			break;
		} 
		break;
		
		case DIO_PIN_HIGH:
		
		switch(u8_a_portid)
		{
			case DIO_PORTA:
			set_bit(PORTA , u8_a_pinid);         /** SET THIS PIN AS DIO_PIN_HIGH  **/
			break;
			
			case DIO_PORTB:
			set_bit(PORTB , u8_a_pinid);         /** SET THIS PIN AS DIO_PIN_HIGH  **/
			break;
			
			case DIO_PORTC:
			set_bit(PORTC , u8_a_pinid);         /** SET THIS PIN AS DIO_PIN_HIGH  **/
			break;
			
			case DIO_PORTD:
			set_bit(PORTD , u8_a_pinid);         /** SET THIS PIN AS DIO_PIN_HIGH  **/
			break;
			
			default:
			en_a_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
			break;
		} 
		break;
		
		default :
		en_a_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
		break ;
	} 
	
	return en_a_valstate ; /** RETURN THE FINAL STATE OF THE FUNCTION */
}


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO GET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : u8_a_portid , PINID , POINTER TO SET THE VALUE IN IT      */
/* RETURNS : PinRead_t                                            */
/******************************************************************/
PinRead_t DIO_readpin(uint8_t u8_a_portid , uint8_t u8_a_pinid , uint8_t* u8_a_val)
{
	PinRead_t en_a_Pinstate = VALID_READ ;  /** VARIABLE TO HOLD THE FUNCTION ERROR STATE */
	
	switch(u8_a_portid)  /** SWITCH CASE ON PORT ID **/
	{
		case DIO_PORTA:               /** PORTA  **/
		*u8_a_val = get_bit(PINA , u8_a_pinid); /** GET THE VALUE OF THE BIT **/
		break;
		
		case DIO_PORTB:               /** PORTB  **/
		*u8_a_val = get_bit(PINB , u8_a_pinid); /** GET THE VALUE OF THE BIT **/
		break;
		
		case DIO_PORTC:               /** PORTC  **/
		*u8_a_val = get_bit(PINC , u8_a_pinid); /** GET THE VALUE OF THE BIT **/
		break;
		
		case DIO_PORTD:               /** PORTD  **/
		*u8_a_val = get_bit(PIND , u8_a_pinid); /** GET THE VALUE OF THE BIT **/
		break;
		
		default:
		en_a_Pinstate = NOT_VALID_READ ;  /** READ IS NOT VALID  **/
		break;
	} 
	
	return en_a_Pinstate ; /** RETURN THE FINAL STATE OF THE FUNCTION **/	
}

/******************************************************************/
/* DESCRIBTION  : FUNCTION TO TOGGLE SPECIFIC PIN                 */
/* INPUT   : u8_a_portid , PINID                                  */
/* RETURNS : PinRead_t                                            */
/******************************************************************/
PinRead_t DIO_togglepin(uint8_t u8_a_portid , uint8_t u8_a_pinid )
{
	PinRead_t en_a_Pinreadstate = VALID_READ ;  /** VARIABLE TO HOLD THE FUNCTION ERROR STATE */
	
	switch(u8_a_portid) /** SWITCH ON THE PORT ID **/
	{
		case DIO_PORTA:
		toggle_bit(PORTA , u8_a_pinid);
		break;
		
		case DIO_PORTB:
		toggle_bit(PORTB , u8_a_pinid);
		break;
		
		case DIO_PORTC:
		toggle_bit(PORTC , u8_a_pinid);
		break;
		
		case DIO_PORTD:
		toggle_bit(PORTD , u8_a_pinid);
		break;
		
		default:
		/** DO NOTHING **/
		en_a_Pinreadstate = NOT_VALID_READ ; /** RETURN AN ERROR **/
		break;
	} 
	
	return en_a_Pinreadstate ; /** RETURN THE FINAL STATE OF THE FUNCTION **/
}


/*******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE DIRECTION OF SPECIFIC PORT   */
/* INPUT   : PORT , DIRECTION                                      */
/* RETURNS : PinDirection_t                                        */
/*******************************************************************/
PinDirection_t DIO_setportdir(uint8_t u8_a_portid , uint8_t u8_a_portdir)
{
	PinDirection_t en_a_portstatus = VALID_DIRECTION ; /** VARIABLE TO HOLD THE RETUN STATUS **/
	
	switch(u8_a_portid)
	{
		case DIO_PORTA:
		DDRA = u8_a_portdir;
		break;
		
		case DIO_PORTB:
		DDRB = u8_a_portdir;
		break;
		
		case DIO_PORTC:
		DDRC = u8_a_portdir;
		break;
		
		case DIO_PORTD:
		DDRD = u8_a_portdir;
		break;
		
		default:
		en_a_portstatus = NOT_VALID_DIRECTION ;
		break;
	} 
	
	return en_a_portstatus ;  /** RETURN THE FINAL STATUS **/
}

/*******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE VALUE OF SPECIFIC PORT       */
/* INPUT   : PORT , PINID , DIRECTION                              */
/* RETURNS : PinValue_t                                            */
/*******************************************************************/
PinValue_t DIO_setportvalue(uint8_t u8_a_portid , uint8_t u8_a_portval)
{
	PinValue_t en_a_portvaluestatus = VALID_VALUE ; /** VARIABLE TO HOLD THE STATUS OF THE FUNCTION **/
	
	switch(u8_a_portid)
	{
		case DIO_PORTA:
		PORTA = u8_a_portval;
		break;
		
		case DIO_PORTB:
		PORTB = u8_a_portval;
		break;
		
		case DIO_PORTC:
		PORTC = u8_a_portval;
		break;
		
		case DIO_PORTD:
		PORTD = u8_a_portval;
		break;
		
		default:
		en_a_portvaluestatus = NOT_VALID_VALUE ;
		break;
	}
	
	return en_a_portvaluestatus ; /** RETURN THE FINAL STATUS **/ 
}

/*******************************************************************************************/
/*Description: Sets an array of pins as DIO_PIN_HIGH or LOW depending on the state passed          */
/*@param u8_l_mask              pins mask                                                  */
/*@param u8_l_portNumber        port number                                                */
/*@param u8_l_value             mask desired state                                         */
/*******************************************************************************************/
void DIO_array_write(uint8_t u8_l_mask, uint8_t u8_l_portNumber, uint8_t u8_l_value)
{
	switch(u8_l_portNumber)
	{
		case DIO_PORTA:
		if(u8_l_value == DIO_PIN_LOW)
		{
			Clear_mask(u8_l_mask,PORTA);
		}
		else if(u8_l_value == DIO_PIN_HIGH)
		{
			Set_mask(u8_l_mask,PORTA);
		}
		else
		{
			// Error Handling
			return ;
		}
		break;
		
		case DIO_PORTB:
		if(u8_l_value == DIO_PIN_LOW)
		{
			Clear_mask(u8_l_mask,PORTB);
		}
		else if(u8_l_value == DIO_PIN_HIGH)
		{
			Set_mask(u8_l_mask,PORTB);
		}
		else
		{
			// Error Handling
			return ;
		}
		break;
		
		case DIO_PORTC:
		if(u8_l_value == DIO_PIN_LOW)
		{
			Clear_mask(u8_l_mask,PORTC);
		}
		else if(u8_l_value == DIO_PIN_HIGH)
		{
			Set_mask(u8_l_mask,PORTC);
		}
		else
		{
			// Error Handling
			return ;
		}
		break;
		
		case DIO_PORTD:
		if(u8_l_value == DIO_PIN_LOW)
		{
			Clear_mask(u8_l_mask,PORTD);
		}
		else if(u8_l_value == DIO_PIN_HIGH)
		{
			Set_mask(u8_l_mask,PORTD);
		}
		else
		{
			// Error Handling
			return ;
		}
		break;
		
		default:
		return ;
	}
	return ;
}