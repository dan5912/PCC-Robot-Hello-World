/*******************************************
 
 * Author: Daniel Hill
 * Copyright: Free to use and distribute in any way
 *              shape or form -- if modified, 
 *                  remove this notice
 
 ********************************************/


#ifndef __LCD__LIB__H

    #define __LCD__LIB__H


    #include <xc.h>                         //PIC hardware mapping

    #define RS PORTAbits.RD4
    #define RW PORTAbits.RD5
    #define EN PORTAbits.RD6
    #define D7 PORTCbits.RC4
    #define D6 PORTCbits.RC5
    #define D5 PORTCbits.RC6
    #define D4 PORTCbits.RC7

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