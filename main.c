#define F_CPU 16000000L
#include <avr/io.h>
#include "bits.h"
#include "Semaforo.h"
#include "Disp7Seg.h"
#include "Botoes.h"
#include <util/delay.h>


void main(void){
    unsigned long counter = 0;

    displayInit();
    semaforoInit();
    buttonInit();

    while(1){
        _delay_ms(1);
        counter++;

        if((button_rising()) && (counter<=32000)){
            counter = 32000;
        }

        if(counter<=42000){
            setLight(GREEN, 1);
            setLight(RED_PD, 1);
            setLight(RED, 0);
            setLight(YELLOW,0);
            setLight(GREEN_PD,0);
            display(42 - (counter/1000));
        }else if(counter<=45000){
            setLight(GREEN, 0);
            setLight(RED_PD, 1);
            setLight(RED, 0);
            setLight(YELLOW,1);
            setLight(GREEN_PD,0);
        }else if(counter<=57000){
            setLight(GREEN, 0);
            setLight(RED_PD, 0);
            setLight(RED, 1);
            setLight(YELLOW,0);
            setLight(GREEN_PD,1);
        }else if(counter<=60000){
            setLight(GREEN_PD,0);
            setLight(RED_PD, 1);
            _delay_ms(500);
            setLight(RED_PD, 0);
            _delay_ms(500);
            setLight(RED_PD, 1);
            _delay_ms(500);
            setLight(RED_PD, 0);
            _delay_ms(500);
            setLight(RED_PD, 1);
            _delay_ms(500);
            setLight(RED_PD, 0);
            _delay_ms(500);
            counter =0;        
        }
    }

}