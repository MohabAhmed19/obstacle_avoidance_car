/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 19 May , 2021                                   **/
/** Version : V01                                             **/
/** Hint    : interface file of input capture unit            **/
/***************************************************************/

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

/** MACROS TO CONFIGURE THE PIN OF ICU **/
#define ICU_EXTI0    0
#define ICU_EXTI1    1
#define ICU_EXTI2    2

/**	ENUM TO RETURN ERROR STATUS **/
typedef enum {VALID_ICU_INIT  , NOTVALID_ICU_INIT} en_a_icuerrorstatus ;

/**************************************************************/
/** FUNCTION TO INITIALIZE THE ICU ON SPECIFIC PIN           **/
/** ARGUMENTS : VOID                                         **/
/** RETURN    : VOID                                         **/
/**************************************************************/
en_a_icuerrorstatus ICU_init(void);


/**************************************************************/
/** FUNCTION TO GET THE VALUE OF TIMER WHEN EVENT HAPPENS    **/
/** ARGUMENTS : u8_a_pin EXTERNAL INTERRUPT PIN              **/
/** RETURN    : VOID                                         **/
/**************************************************************/
uint16t ICU_getvalue(void);




#endif /* ICU_INTERFACE_H_ */