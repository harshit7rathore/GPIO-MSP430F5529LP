#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P2DIR &= ~BIT1 ;
	P2REN |= BIT1 ;
	P2OUT |= BIT1 ;

	P1DIR |= BIT0 ;
	P1OUT &= ~BIT0 ;

	//Configuring Port Interupts

	P2IE |= BIT1 ;
	P2IES |= BIT1 ;
	P2IFG &= ~BIT1 ;

	__bis_SR_register(GIE+LPM4_bits) ;

	//while(1)
}

#pragma vector = PORT2_VECTOR
__interrupt void p2isr()
{
    P2IFG &= ~BIT1;
    P2IES ^= BIT1;
    P1OUT ^= BIT0;
}

