#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR = 0x01 ; // PIN1.0 Configured as OUTPUT
	while(1)
	{
	    P1OUT = 0x01 ; // PIN1.0 = 1
	    __delay_cycles(2000000);
	    P1OUT = 0x00 ;
        __delay_cycles(1000000);
	}
	return 0;
}
