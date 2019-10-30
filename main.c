
#include <stdio.h>
#include <stdint.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h" 
#include "mcc_generated_files/tmr2.h"
#include  "mcc_generated_files/usb/usb.h"


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        if( BOTON1_GetValue() == 1) {
            LEDB_SetHigh();
            count1 = 0;
        }
        if( count1 == 10) {
            LEDB_SetLow();
        }
       if( BOTON2_GetValue() == 1) {
            LEDA_SetHigh();
            count2 = 0;
        }
        if( count2 == 10) {
            LEDA_SetLow();
            
        }
        
 //*****************************__USB__*****************************************
 //_____________________________________________________________________________
        
        uint8_t numBytes;
        uint8_t buffer[64];
        
        USBDeviceTasks(); //Takes care of enumeration and other USB events
            if((USBGetDeviceState() != CONFIGURED_STATE) ||
               (USBIsDeviceSuspended() == true))
            {
                continue;   //go back to the top of the while loop
            }
            else
            {
                int i;
                for(i = 0;i < 64;i++)
                {
                buffer[i] = 0;
                }
                numBytes = getsUSBUSART(buffer,sizeof(buffer)); //until the buffer is free.
                if(numBytes > 0)
                {
                
                 putsUSBUSART(buffer);
                   
                }
            }
        CDCTxService();
    }
    
    return 1; 
}

