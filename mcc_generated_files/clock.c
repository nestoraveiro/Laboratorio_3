
#include "xc.h"
#include "stdint.h"
#include "clock.h"
#include "system.h"

void CLOCK_Initialize(void)
{
    SYSTEM_RegUnlock();
    // ORPOL disabled; SIDL disabled; SRC SOSC; TUN Center frequency; POL disabled; ON disabled; 
    OSCTUN = 0x00;
    // PLLODIV 1:4; PLLMULT 12x; PLLICLK POSC; 
    SPLLCON = 0x2050000;
    // SBOREN disabled; VREGS disabled; RETEN disabled; 
    PWRCON = 0x00;
    // configure REFO to request POSC :POSC Errata workaround
    REFO1CON = 0x9002;
    // delay for 9 ms :POSC Errata workaround
    unsigned int start = __builtin_mfc0(_CP0_COUNT, _CP0_COUNT_SELECT);
    while((__builtin_mfc0(_CP0_COUNT, _CP0_COUNT_SELECT)) - start < (unsigned int)(0.009*8000000/2));
    //Clear NOSC,CLKLOCK and OSWEN bits :POSC Errata workaround
    OSCCONCLR = _OSCCON_NOSC_MASK | _OSCCON_CLKLOCK_MASK | _OSCCON_OSWEN_MASK;
    // CF No Clock Failure; FRCDIV FRC/1; SLPEN Device will enter Idle mode when a WAIT instruction is issued; NOSC SPLL; SOSCEN disabled; CLKLOCK Clock and PLL selections are not locked and may be modified; OSWEN Switch is Complete; 
    OSCCON = (0x100 | _OSCCON_OSWEN_MASK);
    SYSTEM_RegLock();
    // Wait for Clock switch to occur 
    while(OSCCONbits.OSWEN == 1); 
    while(CLKSTATbits.SPLLRDY != 1);
    REFO1CONCLR = 0x9002;
    // ON disabled; DIVSWEN disabled; RSLP disabled; ROSEL SYSCLK; OE disabled; SIDL disabled; RODIV 0; 
    REFO1CON = 0x00;
    // ROTRIM 0; 
    REFO1TRIM = 0x00;
}
