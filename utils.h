

#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include "time.h"
#include <stdbool.h>
#include <stdint.h>

#endif


typedef enum
{
    UT_TMR_DELAY_INIT,
    UT_TMR_DELAY_WAIT        
}UT_TMR_DELAY_STATE;

typedef struct
{
    uint32_t startValue;
    UT_TMR_DELAY_STATE state;
}ut_tmrDelay_t;


bool UT_delayDs(ut_tmrDelay_t *p_timer, uint32_t p_ds);