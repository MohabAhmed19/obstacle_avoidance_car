/*
 * ultrasonic.h
 *
 * Created: 5/20/2023 9:41:32 PM
 *  Author: mohab
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../SERVICE/standard_types.h"

typedef enum {USONIC_SUCCESS, USONIC_FAIL} EN_USONIC_STATUS;


void USONIC_init(void);

EN_USONIC_STATUS USONIC_getdistance(uint8_t *distance);


#endif /* ULTRASONIC_H_ */