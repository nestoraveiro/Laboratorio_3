

#ifndef _RTCC_H
#define _RTCC_H


#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

typedef struct tm bcdTime_t;


/**
  @Summary
    Initializes and enables RTCC peripheral

  @Description
    This function sets a time in the RTCC and enables 
    RTCC for operation. It will also configure the Alarm settings.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Example
    <code>
    struct tm currentTime;

    RTCC_Initialize();

    while(!RTCC_TimeGet(&currentTime))
    {
        // Do something
    }
    </code>
*/

void RTCC_Initialize(void);


bool RTCC_TimeGet(struct tm *currentTime);


void RTCC_TimeSet(struct tm *initialTime);


bool RTCC_BCDTimeGet(bcdTime_t *currentTime);


void RTCC_BCDTimeSet(bcdTime_t *initialTime);


void RTCC_TimeReset(bool reset);


void RTCC_CallBack(void);

bool RTCC_Task(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _RTCC_H

