/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/
#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <stdio.h>
#include <stdlib.h>
//#include <proc/p32mx460f512l.h>
#include <sys/attribs.h>
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/
int i;
/* i.e. uint32_t <variable_name>; */
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void SetUpLEDPort(void){
    TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    PORTBbits.RB10 = 0;
    PORTBbits.RB11 = 0;
    PORTBbits.RB12 = 0;
    PORTBbits.RB13 = 0;
}


void SimpleCounterDelay(int CountLimit){
    int x;
    for (x = 0; x < CountLimit; x++){
    }  
}


void TurnOnLED(int LedNum){
 
    switch(LedNum){
        case 1:
            PORTBSET = 1 << 10;
            break;
        case 2: 
            PORTBSET = 1 << 11;
            break;
        case 3:
            PORTBSET = 1 << 12;
            break;
        case 4:
            PORTBSET = 1 << 13;   
            break;
    }            
}

void TurnOffLED(int LedNum){
    switch(LedNum){
        case 1:
            PORTBCLR = 1 << 10;
            break;
        case 2: 
            PORTBCLR = 1 << 11;
            break;
        case 3:
            PORTBCLR = 1 << 12;
            break;
        case 4:
            PORTBCLR = 1 << 13;  
            break;
    }            
}
    
int32_t main(void)
{
#ifndef PIC32_STARTER_KIT
    /*The JTAG is on by default on POR.  A PIC32 Starter Kit uses the JTAG, but
    for other debug tool use, like ICD 3 and Real ICE, the JTAG should be off
    to free up the JTAG I/O */
    DDPCONbits.JTAGEN = 0;
#endif
    SetUpLEDPort();
    while(1){
        SimpleCounterDelay(10000);
        TurnOnLED(4);
        SimpleCounterDelay(10000);
        TurnOnLED(3);
        SimpleCounterDelay(10000);
        TurnOnLED(2);
        SimpleCounterDelay(10000);
        TurnOnLED(1);
        SimpleCounterDelay(10000);
        TurnOffLED(4);
        SimpleCounterDelay(10000);
        TurnOffLED(3);
        SimpleCounterDelay(10000);
        TurnOffLED(2);
        SimpleCounterDelay(10000);
        TurnOffLED(1);
        SimpleCounterDelay(10000);
    }
   
}
