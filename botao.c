#include <avr/io.h>
#include "bits.h"

#define B0 !READBIT(PINB, 4)

char b0_prev = 0;

void buttonInit(void){
    SETBIT(DDRB, 4, 0);
    SETBIT(PORTB, 4, 1);
}

char b0(void){
    return(B0);
}

char button_rising(void){
    if(B0 && !b0_prev){
        b0_prev=B0;
        return(1);
    }else{
        b0_prev=B0;
        return(0);
    }
}

char button_falling(void){
    if(!B0 && b0_prev){
        b0_prev=B0;
        return(1);
    }else{
        b0_prev=B0;
        return(0);
    }
}