
#include "utils.h"

/*La función Delay es de tipo reentrante, recibe un puntero a una estructura donde recibe el comando de inicio de 
conteo mediante UT_TMR_DELAY_INIT y guarda en la misma, el estado UT_TMR_DELAY_WAIT en caso de haber iniciado el 
conteo además del valor inicial del contador para comparar cada vez que se realiza la interrupción (cada 100ms) si 
ha ocurrido el tiempo de retardo deseado. Una vez transcurrido el delay, la función devuelve True.  
*/

bool UT_delayDs(ut_tmrDelay_t *p_timer, uint32_t p_ds)
{
	switch(p_timer->state)
	{
		case(UT_TMR_DELAY_INIT):
			p_timer->startValue=TMR2_SoftwareCounterGet();
			p_timer->state=UT_TMR_DELAY_WAIT;
			break;
		case(UT_TMR_DELAY_WAIT):
			if(TMR2_SoftwareCounterGet()>=((p_timer->startValue)+p_ds))
			{
				p_timer->state=UT_TMR_DELAY_INIT;
				return true;
			}
			break;
	}
	return false;
}




