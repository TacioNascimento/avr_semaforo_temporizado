#include <avr/io.h>
#include "bits.h"
#include "Semaforo.h"

void semaforoInit(void){
    for(int d=0; d<=4;d++){
        SETBIT(DDRC, d, 1);
        SETBIT(PORTC, d, 0);
    }
}

void setLight(unsigned char bit, unsigned char value){
    SETLIGHT(PORTC, bit, value);
}