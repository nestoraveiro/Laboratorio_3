
#include "rtcc.h"
#include "system.h"


static bool rtccTimeInitialized;
static bool RTCCTimeInitialized(void);
static uint8_t ConvertHexToBCD(uint8_t hexvalue);
static uint8_t ConvertBCDToHex(uint8_t bcdvalue);


void RTCC_Initialize(void)
{
  
   SYSTEM_RegUnlock();
   RTCCON1CLR = (1 << _RTCCON1_WRLOCK_POSITION);
   RTCCON1CLR = (1 << _RTCCON1_ON_POSITION);
     
   if(!RTCCTimeInitialized())
   {
       // set 2019-10-31 18-17-45
       RTCDATE = 0x19103104; // Year/Month/Date/Wday
       RTCTIME = 0x18174500; //  hours/minutes/seconds
       
   }
       // ON enabled; OUTSEL Alarm Event; WRLOCK disabled; AMASK Every Half Second; ALMRPT 0; RTCOE disabled; CHIME disabled; ALRMEN disabled; 
       RTCCON1 = 0x8000;
   
       // DIV 0; CLKSEL SOSC; FDIV 0; 
       RTCCON2 = 0x00;

   // Enable RTCC 
   RTCCON1SET = (1 << _RTCCON1_ON_POSITION);
   RTCCON1SET = (1 << _RTCCON1_WRLOCK_POSITION);
   SYSTEM_RegLock();

}

bool RTCC_TimeGet(struct tm *currentTime)
{
    uint32_t register_value;
    if(RTCSTATbits.SYNC){
        return false;
    }
     
    register_value = RTCDATE;
    currentTime->tm_year = ConvertBCDToHex((register_value & 0xFF000000) >> 24);
    currentTime->tm_mon = ConvertBCDToHex((register_value & 0xFF0000) >> 16);
    currentTime->tm_mday = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_wday = ConvertBCDToHex(register_value & 0xF);
    
    register_value = RTCTIME;
    currentTime->tm_hour = ConvertBCDToHex((register_value & 0xFF000000) >> 24);
    currentTime->tm_min = ConvertBCDToHex((register_value & 0xFF0000) >> 16);
    currentTime->tm_sec = ConvertBCDToHex((register_value & 0xFF00) >> 8);

    return true;
}

void RTCC_TimeSet(struct tm *initialTime)
{
   SYSTEM_RegUnlock();
   RTCCON1CLR = (1 << _RTCCON1_WRLOCK_POSITION);
   RTCCON1CLR = (1 << _RTCCON1_ON_POSITION);
  

   // set RTCC initial time
   RTCDATE = (ConvertHexToBCD(initialTime->tm_year) << 24) | (ConvertHexToBCD(initialTime->tm_mon) << 16 ) | (ConvertHexToBCD(initialTime->tm_mday) << 8) | ConvertHexToBCD(initialTime->tm_wday) ; // YEAR/MONTH-1/DAY-1/WEEKDAY
   RTCTIME = (ConvertHexToBCD(initialTime->tm_hour) << 24) | (ConvertHexToBCD(initialTime->tm_min) << 16 ) | (ConvertHexToBCD(initialTime->tm_sec) << 8) ; // HOURS/MINUTES/SECOND
          
   // Enable RTCC 
   RTCCON1SET = (1 << _RTCCON1_ON_POSITION);
    
    // SET WRLOCK
   RTCCON1SET = (1 << _RTCCON1_WRLOCK_POSITION);
   SYSTEM_RegLock();

}

bool RTCC_BCDTimeGet(bcdTime_t *currentTime)
{
    uint32_t register_value;
    if(RTCSTATbits.SYNC){
        return false;
    }
    
    register_value = RTCDATE;
    currentTime->tm_year = (register_value & 0xFF000000) >> 24;
    currentTime->tm_mon = (register_value & 0xFF0000) >> 16;
    currentTime->tm_mday = (register_value & 0xFF00) >> 8;
    currentTime->tm_wday = (register_value & 0xF);
    
    register_value = RTCTIME;
    currentTime->tm_hour = (register_value & 0xFF000000) >> 24;
    currentTime->tm_min = (register_value & 0xFF0000) >> 16;
    currentTime->tm_sec = (register_value & 0xFF00) >> 8;
    
    return true;
}

void RTCC_BCDTimeSet(bcdTime_t *initialTime)
{
   SYSTEM_RegUnlock();
   RTCCON1CLR = (1 << _RTCCON1_WRLOCK_POSITION);
   RTCCON1CLR = (1 << _RTCCON1_ON_POSITION);

   // set RTCC initial time
   RTCDATE = (initialTime->tm_year << 24) | (initialTime->tm_mon << 16 ) | (initialTime->tm_mday << 8) | (initialTime->tm_wday) ; // YEAR/MONTH-1/DAY-1/WEEKDAY
   RTCTIME = (initialTime->tm_hour << 24) | (initialTime->tm_min << 16 ) | (initialTime->tm_sec << 8) ; // HOURS/MINUTES/SECOND
              
   // Enable RTCC  
   RTCCON1SET = (1 << _RTCCON1_ON_POSITION);
   
   // SET WRLOCK 
   RTCCON1SET = (1 << _RTCCON1_WRLOCK_POSITION);
   SYSTEM_RegLock();

}

/**
 This function implements RTCC_TimeReset.This function is used to
 used by application to reset the RTCC value and reinitialize RTCC value.
*/
void RTCC_TimeReset(bool reset)
{
    rtccTimeInitialized = reset;
}

static bool RTCCTimeInitialized(void)
{
    return(rtccTimeInitialized);
}

static uint8_t ConvertHexToBCD(uint8_t hexvalue)
{
    uint8_t bcdvalue;
    bcdvalue = (hexvalue / 10) << 4;
    bcdvalue = bcdvalue | (hexvalue % 10);
    return (bcdvalue);
}

static uint8_t ConvertBCDToHex(uint8_t bcdvalue)
{
    uint8_t hexvalue;
    hexvalue = (((bcdvalue & 0xF0) >> 4)* 10) + (bcdvalue & 0x0F);
    return hexvalue;
}

void __attribute__ ((weak)) RTCC_CallBack(void)
{
    // Add your custom callback code here
}

/* Function:
    bool RTCC_Task(void)

  Summary:
    Status function which returns the RTCC interrupt flag status

  Description:
    This is the status function for the RTCC peripheral. 
*/
bool RTCC_Task(void)
{
    bool status;
    status = IFS1bits.RTCCIF;
    if( IFS1bits.RTCCIF)
    {
		// RTCC callback function 
		RTCC_CallBack();
        
		IFS1CLR= 1 << _IFS1_RTCCIF_POSITION;
    }
    return status;
}
/**
 End of File
*/
