/*******************************************
 
 * Author: Daniel Hill
 * Copyright: Free to use and distribute in any way
 *              shape or form -- if modified, 
 *                  remove this notice
 
 ********************************************/


#include "lcd.h"

void lcd4WaitBusy();
void lcd4SendCommand(unsigned char data);
void lcd4_8SendCommand(unsigned char data);
void lcd4MoveCursor(unsigned char spaces, unsigned char dir);	// direction - Right = 1, Left = 0;
unsigned char LCD4_disp_width = 0;
unsigned char LCD4_disp_height = 0;


void lcd4SendCommand(unsigned char data)
{
// Sends lcd command
    
	RS = 0; 				// Command Byte
	RW = 0;					// Writing data
    
	D7 = (data >> 7) & 0x1;		// Write data to lines
	D6 = (data >> 6) & 0x1;
	D5 = (data >> 5) & 0x1;
	D4 = (data >> 4) & 0x1;
    EN = 1;
	__delay_us(5);	
	EN = 0;
	__delay_us(5);
    
    
    
	D7 = (data >> 3) & 0x1;		// Write data to lines
	D6 = (data >> 2) & 0x1;
	D5 = (data >> 1) & 0x1;
	D4 = (data) & 0x1;
    EN = 1;
	__delay_us(5);
    EN = 0;
	__delay_us(5);
    
}
void lcd4_8SendCommand(unsigned char data)
{
// Sends 4 bit lcd command in 8 bit mode
    
	RS = 0; 				// Command Byte
	RW = 0;					// Writing data
    EN = 1;					// Clock out the data
	__delay_us(5);
	D7 = (data >> 3) & 0x1;		// Write data to lines
	D6 = (data >> 2) & 0x1;
	D5 = (data >> 1) & 0x1;
	D4 = (data) & 0x1;
    __delay_us(1);
    
	EN = 0;
	__delay_us(5);
}



void lcd4WaitBusy()
{
	int r = 0;
    D7 = 0;
    D7DIR = 1;
    RS = 0;
	RW = 1;
    __delay_us(1);
	while(r == 0)
	{
        EN = 1;
		__delay_us(2);
        EN = 0;
		__delay_us(2);
		if(D7 == 0)
		{
			r = 1;
		}
        
		EN = 1;
		__delay_us(2);
		EN = 0;
		__delay_us(2);
	}
    
    D7DIR = 0;
    //__delay_ms(10);
}

void lcd4Clear()
{
	lcd4WaitBusy();
	lcd4SendCommand(0x01);
}

void lcd4Home()
{
	lcd4WaitBusy();
	lcd4SendCommand(0x3);
}

void lcd4Init(unsigned char x, unsigned char y) // Display dimensions
{
    LCD4_disp_height = y;
    LCD4_disp_width = x;
    
    __delay_ms(100);
    // 8 bit mode commands
    EN = 1;
    RS = 0;
    RW = 0;
    LATC = 3;
    __delay_us(5);
    EN = 0;
    __delay_ms(25);
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_ms(25);
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_ms(25);
    EN = 1;
    LATC = 2;
    __delay_us(5);
    EN = 0;
    
    
    __delay_ms(25);
    lcd4SendCommand(0x28);
    
    lcd4WaitBusy();
    lcd4SendCommand(0x08);
    
    lcd4WaitBusy();
    lcd4SendCommand(0x0F);
    
    lcd4WaitBusy();
    lcd4SendCommand(0x06);
    
    lcd4WaitBusy();
    lcd4SendCommand(0x01);
    
    lcd4WaitBusy();
    lcd4SendCommand(0x02);
    
    
    
   
	
}

void lcd4SendChar(char data)
{

	lcd4WaitBusy();				
	RS = 1;
    RW = 0;
    
    LATC = data>>4;
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_us(5);
    
    
    LATC = data;
    EN = 1;
    __delay_us(5);
    EN = 0;
    RW = 1;
    __delay_us(5);
}

void lcd4WriteString(char *strng)
{
	int i = 0;
	while(*(strng + i) != '\0')
	{
		lcd4SendChar(*(strng + i++));
	}
}

void lcd4MoveCursor(unsigned char spaces, unsigned char dir)	// direction - Right = 1, Left = 0;
{
	while (spaces-- > 0)
	{
		lcd4WaitBusy();
		lcd4SendCommand(0x10 | (dir << 2));		// Shift cursor in the selected direction 1 space until spaces = 0;
	}
}

void lcd4SetCursor(unsigned char x, unsigned char y)
{
    if(x < LCD4_disp_width && y < LCD4_disp_height){
        unsigned char shiftDistance = x + y*40;
        lcd4WaitBusy();
        lcd4SendCommand(0x80 | (shiftDistance));
    }
    
}

