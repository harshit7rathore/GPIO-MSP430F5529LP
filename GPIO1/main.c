#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//int flag = 0 ;
	P4DIR |= BIT7 ;
    P4OUT &= BIT7 ;
	P1DIR &= BIT1 ;
	P1REN |= BIT1 ;
	P1OUT |= BIT1 ;
    P1DIR |= BIT0 ;
	P2DIR &= ~BIT1 ;
    P2REN |= BIT1 ;
    P2OUT |= BIT1 ;
    while(1)
    {
        if(P2IN&BIT1)
        {
            P1OUT |= BIT0 ;
        }
        if(P1IN&BIT1)
        {
            P4OUT |= BIT7 ;
        }
        P1OUT &= ~BIT0 ;
        P4OUT &= ~BIT7 ;
    }
	return 0;
}
