/*******************************************
 
 * Author: Daniel Hill
 * Copyright: Free to use and distribute in any way
 *              shape or form -- if modified, 
 *                  remove this notice
 
 ********************************************/


#ifndef __LCD__LIB__H

    #define __LCD__LIB__H


    #include <xc.h>                         //PIC hardware mapping

    #define RS PORTAbits.RA0
    #define RW PORTAbits.RA1
    #define EN PORTAbits.RA2
    #define D7 PORTCbits.RC3
    #define D6 PORTCbits.RC2
    #define D5 PORTCbits.RC1
    #define D4 PORTCbits.RC0

    #define D7DIR TRISCbits.TRISC3

    #ifndef _XTAL_FREQ
        #define _XTAL_FREQ 500000   // Oscillator frequency for delays (critical for initilization delays)
    #endif



    void lcd4Home();                                                // sends the cursor to 0,0
    void lcd4Init(unsigned char width, unsigned char height);       // Lines wide, Lines high
    void lcd4SendChar(char data);                                   // sends one data character to the screen
    void lcd4WriteString(char *strng);                              // sends a string of characters to the screen
    void lcd4SetCursor(unsigned char x, unsigned char y);           // Moves the cursor to a position (0,0) is the origin
#endif