/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC32MM0256GPM064
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.20
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA13, high using LATA13.

  @Description
    Sets the GPIO pin, RA13, high using LATA13.

  @Preconditions
    The RA13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA13 high (1)
    BOTON1_SetHigh();
    </code>

*/
#define BOTON1_SetHigh()          ( LATASET = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RA13, low using LATA13.

  @Description
    Sets the GPIO pin, RA13, low using LATA13.

  @Preconditions
    The RA13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA13 low (0)
    BOTON1_SetLow();
    </code>

*/
#define BOTON1_SetLow()           ( LATACLR = (1 << 13) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA13, low or high using LATA13.

  @Preconditions
    The RA13 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA13 to low.
    BOTON1_SetValue(false);
    </code>

*/
inline static void BOTON1_SetValue(bool value)
{
  if(value)
  {
    BOTON1_SetHigh();
  }
  else
  {
    BOTON1_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA13, using LATA13.

  @Description
    Toggles the GPIO pin, RA13, using LATA13.

  @Preconditions
    The RA13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA13
    BOTON1_Toggle();
    </code>

*/
#define BOTON1_Toggle()           ( LATAINV = (1 << 13) )
/**
  @Summary
    Reads the value of the GPIO pin, RA13.

  @Description
    Reads the value of the GPIO pin, RA13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA13
    postValue = BOTON1_GetValue();
    </code>

*/
#define BOTON1_GetValue()         PORTAbits.RA13
/**
  @Summary
    Configures the GPIO pin, RA13, as an input.

  @Description
    Configures the GPIO pin, RA13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA13 as an input
    BOTON1_SetDigitalInput();
    </code>

*/
#define BOTON1_SetDigitalInput()   ( TRISASET = (1 << 13) )
/**
  @Summary
    Configures the GPIO pin, RA13, as an output.

  @Description
    Configures the GPIO pin, RA13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA13 as an output
    BOTON1_SetDigitalOutput();
    </code>

*/
#define BOTON1_SetDigitalOutput()   ( TRISACLR = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    LEDA_SetHigh();
    </code>

*/
#define LEDA_SetHigh()          ( LATASET = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    LEDA_SetLow();
    </code>

*/
#define LEDA_SetLow()           ( LATACLR = (1 << 7) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA7, low or high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA7 to low.
    LEDA_SetValue(false);
    </code>

*/
inline static void LEDA_SetValue(bool value)
{
  if(value)
  {
    LEDA_SetHigh();
  }
  else
  {
    LEDA_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    LEDA_Toggle();
    </code>

*/
#define LEDA_Toggle()           ( LATAINV = (1 << 7) )
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = LEDA_GetValue();
    </code>

*/
#define LEDA_GetValue()         PORTAbits.RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    LEDA_SetDigitalInput();
    </code>

*/
#define LEDA_SetDigitalInput()   ( TRISASET = (1 << 7) )
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    LEDA_SetDigitalOutput();
    </code>

*/
#define LEDA_SetDigitalOutput()   ( TRISACLR = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RB14, high using LATB14.

  @Description
    Sets the GPIO pin, RB14, high using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 high (1)
    LEDB_SetHigh();
    </code>

*/
#define LEDB_SetHigh()          ( LATBSET = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RB14, low using LATB14.

  @Description
    Sets the GPIO pin, RB14, low using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 low (0)
    LEDB_SetLow();
    </code>

*/
#define LEDB_SetLow()           ( LATBCLR = (1 << 14) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB14, low or high using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB14 to low.
    LEDB_SetValue(false);
    </code>

*/
inline static void LEDB_SetValue(bool value)
{
  if(value)
  {
    LEDB_SetHigh();
  }
  else
  {
    LEDB_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB14, using LATB14.

  @Description
    Toggles the GPIO pin, RB14, using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB14
    LEDB_Toggle();
    </code>

*/
#define LEDB_Toggle()           ( LATBINV = (1 << 14) )
/**
  @Summary
    Reads the value of the GPIO pin, RB14.

  @Description
    Reads the value of the GPIO pin, RB14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB14
    postValue = LEDB_GetValue();
    </code>

*/
#define LEDB_GetValue()         PORTBbits.RB14
/**
  @Summary
    Configures the GPIO pin, RB14, as an input.

  @Description
    Configures the GPIO pin, RB14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an input
    LEDB_SetDigitalInput();
    </code>

*/
#define LEDB_SetDigitalInput()   ( TRISBSET = (1 << 14) )
/**
  @Summary
    Configures the GPIO pin, RB14, as an output.

  @Description
    Configures the GPIO pin, RB14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an output
    LEDB_SetDigitalOutput();
    </code>

*/
#define LEDB_SetDigitalOutput()   ( TRISBCLR = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RB15, high using LATB15.

  @Description
    Sets the GPIO pin, RB15, high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 high (1)
    BOTON2_SetHigh();
    </code>

*/
#define BOTON2_SetHigh()          ( LATBSET = (1 << 15) )
/**
  @Summary
    Sets the GPIO pin, RB15, low using LATB15.

  @Description
    Sets the GPIO pin, RB15, low using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 low (0)
    BOTON2_SetLow();
    </code>

*/
#define BOTON2_SetLow()           ( LATBCLR = (1 << 15) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB15, low or high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB15 to low.
    BOTON2_SetValue(false);
    </code>

*/
inline static void BOTON2_SetValue(bool value)
{
  if(value)
  {
    BOTON2_SetHigh();
  }
  else
  {
    BOTON2_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB15, using LATB15.

  @Description
    Toggles the GPIO pin, RB15, using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB15
    BOTON2_Toggle();
    </code>

*/
#define BOTON2_Toggle()           ( LATBINV = (1 << 15) )
/**
  @Summary
    Reads the value of the GPIO pin, RB15.

  @Description
    Reads the value of the GPIO pin, RB15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB15
    postValue = BOTON2_GetValue();
    </code>

*/
#define BOTON2_GetValue()         PORTBbits.RB15
/**
  @Summary
    Configures the GPIO pin, RB15, as an input.

  @Description
    Configures the GPIO pin, RB15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an input
    BOTON2_SetDigitalInput();
    </code>

*/
#define BOTON2_SetDigitalInput()   ( TRISBSET = (1 << 15) )
/**
  @Summary
    Configures the GPIO pin, RB15, as an output.

  @Description
    Configures the GPIO pin, RB15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an output
    BOTON2_SetDigitalOutput();
    </code>

*/
#define BOTON2_SetDigitalOutput()   ( TRISBCLR = (1 << 15) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0256GPM064
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

#endif
