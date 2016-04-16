/*
 * File:   main.c
 * Author: 123709
 *
 * Created on April 16, 2016, 12:50 PM
 */


#include <xc.h>

void main(void) 
{
    TRISBbits.RB7 = 1;
    WPUBbits.WPUB7 = 1;
    while(!PORTBbits.RB7)
    {
        continue;
    }
    
    //Kyle's LCD code goes here
    
    while(1)
    {
        
    }
    
    return;
}

