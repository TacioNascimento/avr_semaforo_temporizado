#include "disp7seg.h"
#include "teclas.h"

void main(void) 
{
    char i = 0;
    disp7seg_init();
    teclas_init();
    while( 1 )
    {
        if( b0_rising_edge() )
        {
            i = i<99 ? i+1 : i;
        }

        if( b1_falling_edge() )
        {
            i = i>0 ? i-1 : i;
        }

        disp7seg( i );
    }
}