#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1DIR |= BIT0 ; // PIN1.0 Configured as OUTPUT
    while(1)
    {
        P1OUT ^= BIT0 ; // PIN1.0 = 1
        __delay_cycles(1000000);
    }
	return 0;
}
