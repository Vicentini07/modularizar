/*
 * File:   main.c
 * Author: 19180051
 *
 * Created on 12 de Março de 2020, 08:30
 */


#include <xc.h>
#include "CONFIG.h"

#define LED0        PORTDbits.RD0 
#define LED1        PORTDbits.RD1 
#define DIR_LED0    TRISDbits.TRISD0 
#define DIR_LED1    TRISDbits.TRISD1 
#define S0          PORTDbits.RD3
#define S1          PORTDbits.RD2
#define DIR_S0      TRISDbits.TRISD3
#define DIR_S1      TRISDbits.TRISD2

#define DIR_ENTRADA 1
#define DIR_SAIDA   0

void main(void) 
{
    LED0 = 0;
    LED1 = 1;
    DIR_LED0 = DIR_SAIDA;
    DIR_LED1 = DIR_SAIDA;
    DIR_S0 = DIR_ENTRADA;
    DIR_S1 = DIR_ENTRADA;

    while( 1 )
    {
        LED0 = !LED0;
        LED1 = !LED1;
        
        if( S0 && S1 )
            __delay_ms( 100 );
        else
        {
            if( S0 || S1 )
                __delay_ms( 250 );
            else
                __delay_ms( 500 );
        }    
    }        
    return;
}