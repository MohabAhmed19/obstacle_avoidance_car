/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 3 March , 2020                       */
/* Version : V01                                  */
/* Hint    : common macros                        */
/**************************************************/

#ifndef COMMON_MACROS_H_INCLUDED
#define COMMON_MACROS_H_INCLUDED

/*macro to set a specific bit*/
#define set_bit(byte,bit_num) (byte |= (1<<bit_num))

/*macro to clear a specific bit*/
#define clear_bit(byte,bit_num) (byte &= (~(1<<bit_num)))

/*macro to toggle a specific bit*/
#define toggle_bit(byte,bit_num) (byte ^= (1<<bit_num))

/*macro to check if a bit is set*/
#define bit_is_set(byte,bit_num) (byte & (1<<bit_num))

/*macro to check if bit is cleared*/
#define bit_is_clear(byte,bit_num) (!(byte & (1<<bit_num)))

/*macro to perform right circular*/
#define cir_right(byte,bits) (byte = (byte >> bits) | (byte << (8-bits)))

/*macro to perform left circular*/
#define cir_left(byte,bits) (byte = (byte << bits) | (byte >> (8-bits)))

/*macro to display a specific flag*/
#define get_bit(byte,flag_num) (byte = ((byte >> flag_num) & 0X01))

/*macro to set a mask*/
#define Set_mask(mask,portNumber) ((portNumber) |= mask)

/*macro to clear a mask*/
#define Clear_mask(mask,portNumber) ((portNumber) &= ~(mask))




#endif // COMMON_MACROS_H_INCLUDED
