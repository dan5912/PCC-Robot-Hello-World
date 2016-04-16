/*
 * File:   newmain.c
 * Author: 120534
 *
 * Created on April 16, 2016, 1:21 PM
 */


#include <xc.h>
#include "lcd.h"

void main(void) {
    
    lcd4Init(16, 2); 
    lcd4WriteString("Ruth");
    lcd4SetCursor(0, 1);
    lcd4WriteString("Hello World - April 2016");
    
    return;
}
