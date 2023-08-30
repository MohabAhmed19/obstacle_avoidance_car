/***************************************************/
/* Author  : Mustafa Mohammed Abdou                */
/* Date    : 4 April, 2023                         */
/* Version : V01                                   */
/* Hint    : Interface file of external interrupt  */
/***************************************************/


#ifndef INT_PRIVATE_H_
#define INT_PRIVATE_H_

/*************** Interrupt Registers ********************/

#define SREG   (* (volatile uint8_t *) (0x5F))
#define GICR   (* (volatile uint8_t *) (0x5B))
#define GIFR   (* (volatile uint8_t *) (0x5A))
#define MCUCR  (* (volatile uint8_t *) (0x55))
#define MCUCSR (* (volatile uint8_t *) (0x54))



#endif /* INT_PRIVATE_H_ */