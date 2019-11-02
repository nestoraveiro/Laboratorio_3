#include <stdint.h>
#include <xc.h>
#ifndef _UTILS_H
#define _UTILS_H


typedef struct 
{
    uint32_t            startValue;
    UT_TMR_DELAY_STATE  state;
} ut_tmrDelay_t;
  
    
typedef enum
{
            UT_TMR_DELAY_INIT,
            UT_TMR_DELAY_WAIT
}UT_TMR_DELAY_STATE;

bool UT_delayDs(ut_tmrDelay_t* p_timer, uint32_t p_ds);

#endif