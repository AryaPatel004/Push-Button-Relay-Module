//#include "stm8s.h"
#include <iostm8s003.h>

main() {
	CLK_CKDIVR = 0x00; //set clock 16MHZ
  CLK_PCKENR1 = 0xFF; //Enable peripherals
	UART1_BRR2 = 0x03;
	UART1_BRR1 = 0x68; //9600 baud 
	UART1_CR3 &= ~((1<<4) | (1<<5)); //1 STOP BIT
	UART1_CR2 |= (1<<2) | (1<<3); //1 STOP BIT
	
	UART1_DR = 'A';
	while(UART1_SR &(1<<6));
	
    while(1);
}








