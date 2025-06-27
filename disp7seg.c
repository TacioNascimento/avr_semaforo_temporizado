#include <avr/io.h>
#include "bits.h"

#define DISP_UNI_ON SETBIT(PORTB, 0, 1)
#define DISP_UNI_OFF SETBIT(PORTB, 0, 0)
#define DISP_DEZ_ON SETBIT(PORTB, 1, 1)
#define DISP_DEZ_OFF SETBIT(PORTB, 1, 0)

#define DIGITS_SIZE 16

unsigned char disp_scan = 0;

char digits[DIGITS_SIZE]={ 0X3F, 0X06, 0X5B, 0X4F, 
                            0X66, 0X6D, 0X7D, 0X07, 
                            0X7F, 0X6F, 0X77, 0X7C, 
                            0X39, 0X5E, 0X79, 0X71 };

void displayInit(){
    DDRD = 0XFF;        // Define registrador do display para SAÍDA
    PORTD = 0XFF;       // Define estado para DESLIGADO
    SETBIT(DDRB, 0, 1); // Define porta 0 do registrador de ativação do display para saída
}

void display(unsigned char d){
    if(disp_scan==0){
        DISP_DEZ_OFF;
        PORTD = digits[d%10];
        DISP_UNI_ON;
    }else if(disp_scan==1){
        DISP_UNI_OFF;
        PORTD = digits[(d/10)%10];
        DISP_DEZ_ON;
    }
    disp_scan = ++disp_scan % 2;
}