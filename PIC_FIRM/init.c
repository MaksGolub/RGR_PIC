#include "init.h"
#ifdef __XC32
    #include <xc.h>      
#endif
void init_bits(void){
	
	ANSELAbits.ANSA9 = 0;
	ANSELAbits.ANSA5 = 0;
	

	LATAbits.LATA2 = 0;
	LATAbits.LATA9 = 1;
   
  
	
	
    // Set directions to input
	TRISAbits.TRISA2 = 0;
	TRISAbits.TRISA9 = 0;
	TRISAbits.TRISA3 = 1;
	TRISAbits.TRISA5 = 1;
	
}

void CN_interrupts(){
    // Configure peripheral to generate interrupts
    // Enable change notification interrupt in CN
	CNENAbits.CNIEA5 = 1;
	//CNENAbits.CNIEA3 = 1;
	//CNENDbits.CNIED5 = 1;
	CNENFbits.CNIEF1 = 1;
    // Configure Interrupt Controller
    // Enable change notification  interrupts
	IEC3bits.CNAIE = 1;
	//IEC3bits.CNDIE = 1;
	IEC3bits.CNFIE = 1;
    // Set priority
	IPC29bits.CNAIP = 2;
	//IPC30bits.CNDIP = 3;
	IPC30bits.CNFIP = 3;
    // Clear interrupt Flag
	IFS3bits.CNAIF = 0;
	//IFS3bits.CNDIF = 0;
	IFS3bits.CNFIF = 0;
    //  Set Interrupt Controller for multi-vector mode
	INTCONSET = _INTCON_MVEC_MASK;
    //  Globally enable interrupts
	__builtin_enable_interrupts();
    //  Enable peripheral
    	CNCONAbits.ON = 1;
	//CNCONDbits.ON = 1;	
	CNCONFbits.ON = 1;
  
}