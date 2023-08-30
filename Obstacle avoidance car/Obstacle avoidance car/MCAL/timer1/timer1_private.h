/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 11 April, 2023                                  **/
/** Version : V01                                             **/ 
/** Hint    : TMR1  registers                                 **/
/***************************************************************/ 


#define TCCR1A   (* ((volatile uint8_t *) (0x4F)))
#define TCCR1B   (* ((volatile uint8_t *) (0x4E)))

/*** YOU CAN ACCESS EACH BYTE SEPERATELY OR ACESS THE TWO BYTES IN TCNT1 **/
#define TCNT1H   (* ((volatile uint8_t *)  (0x4D)))
#define TCNT1L   (* ((volatile uint8_t *)  (0x4C))) 
#define TCNT1    (* ((volatile uint16t *) (0x4C)))

/*** YOU CAN ACCESS EACH BYTE SEPERATELY OR ACESS THE TWO BYTES IN OCR1A **/
#define OCR1AH (* ((volatile uint8_t *)  (0x4B)))
#define OCR1AL (* ((volatile uint8_t *)  (0x4A)))
#define OCR1A  (* ((volatile uint16t *)  (0x4A)))

/*** YOU CAN ACCESS EACH BYTE SEPERATELY OR ACESS THE TWO BYTES IN OCR1B **/
#define OCR1BH  (* ((volatile uint8_t *)   (0x49)))
#define OCR1BL  (* ((volatile uint8_t *)   (0x48)))
#define OCR1B   (* ((volatile uint16t *)   (0x48)))

/*** YOU CAN ACCESS EACH BYTE SEPERATELY OR ACESS THE TWO BYTES IN ICR1 **/
#define ICR1H   (* ((volatile uint8_t *)    (0x47)))
#define ICR1L   (* ((volatile uint8_t *)    (0x46)))
#define ICR1    (* ((volatile uint16t *)    (0x46)))
#define TIFR    (* ((volatile uint8_t *)    (0x58)))
#define TIMSK   (* ((volatile uint16t *)    (0x59)))
#define SREG    (* ((volatile uint8_t *)    (0x5F)))



