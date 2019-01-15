/******************************************************************************/
/*  Made by Golub M. & Serhiienko A.  DK-62                                   */
/******************************************************************************/
#include <stdint.h>                               
#include <stdbool.h>
#include <xc.h> 
#include "UART.h"
#include "init.h"  
#include "config.h"  

static char uart_data[BUFFER];

//interrupt handlers 
void __ISR(_CHANGE_NOTICE_A_VECTOR, IPL2SOFT) ISR_PortA_Change(void) {
    
        if (PORTAbits.RA5 == 1){   // Switch is pressed
           UART4_puts("RESET pressed\r\n");
		LATAbits.LATA9 = 0;
		LATAbits.LATA2 = 0;
	}
	if (PORTAbits.RA5 == 0){  // Switch is pressed
           UART4_puts("RESET unpressed\r\n");
		LATAbits.LATA9 = 1;
	}
	IFS3bits.CNAIF = 0;
}
/*
void __ISR(_CHANGE_NOTICE_D_VECTOR, IPL3SOFT) ISR_PortD_Change(void) {
        if (PORTDbits.RD5 == 1)   // Switch is pressed
           UART4_puts("Button 2 pressed\r\n");
    // Reset interrupt flag
	IFS3bits.CNDIF = 0;
}*/

void __ISR(_CHANGE_NOTICE_F_VECTOR, IPL4SOFT) ISR_PortF_Change(void) {
        if (PORTFbits.RF1 == 1){  // Switch is pressed
           UART4_puts("Button 3 pressed\r\n");
		LATAbits.LATA2 = 1;
	}
	if (PORTFbits.RF1 == 0){  // Switch is pressed
           UART4_puts("Button 3 unpressed\r\n");
		LATAbits.LATA2 = 0;
	}
    // Reset interrupt flag
	IFS3bits.CNFIF = 0;
}

void main(void)
{
	init_bits();
	CN_interrupts();
	UART4_init();
   	while(1){
				
	}

}
