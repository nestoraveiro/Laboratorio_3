#include "utils.h"
#include <stdbool.h>

bool UT_delayDs(ut_tmrDelay_t* p_timer, uint32_t p_ds)
//{
//	switch(p_timer->state)
//	{
//		case(p_timer->state):
//			p_timer->startValue=TMR2_getsoftwarecounter();
//			p_timer->state=UT_TMR_Delay_wait;
//			break;
//		case(UT_TMR_Delay_wait):
//			if(TMR2_getsoftwarecounter()>=(startValue+p_ds))
//			{
//				p_timer->state=UT_TMR_Delay_init;
//				return true;
//			}
//			break;
//	}
//	return false;
//}
