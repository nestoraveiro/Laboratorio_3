#include "Ejecución_Eventos.h"
#define SizeText 80 

int EstadoLedB=0;
char MensajeTexto[SizeText];


ut_tmrDelay_t ledB;
uint8_t i_mje=0;


void Comando_Luz_Roja(char *Razon, char *ID_Planta_string, char *Posicion_GPS,char *Nro_Celular)
{
     
    if (i_mje==0)
    { 
        memset(MensajeTexto,0,SizeText);
        strcat(MensajeTexto,ID_Planta_string);
        strcat(MensajeTexto,Razon);
        strcat(MensajeTexto,Posicion_GPS);
        
        EnviarMensaje (Nro_Celular , MensajeTexto);
        i_mje=1;
    }
    switch(EstadoLedB)
    {    
        case(LedBOff):
                        
            LEDB_SetLow();
            if(UT_delayDs(&ledB,4)==true)
            {
                LEDB_SetHigh();
                EstadoLedB=LedBOn;
            }
        break;
                        
        case(LedBOn):
            if(UT_delayDs(&ledB,4)==true)
            {
                LEDB_SetLow();
                EstadoLedB=LedBOff;
            }
        break;
    }  
}

void Comando_Luz_Amarilla(void)
{
    i_mje=0;
    switch(EstadoLedB)
    {    
        case(LedBOff):
                        
            LEDB_SetLow();
            if(UT_delayDs(&ledB,10)==true)
            {
                LEDB_SetHigh();
                EstadoLedB=LedBOn;
            }
        break;
                        
        case(LedBOn):
            if(UT_delayDs(&ledB,10)==true)
            {
                LEDB_SetLow();
                EstadoLedB=LedBOff;
            }
        break;
    }  
}

void Comando_Luz_Verde(void)
{
    i_mje=0;
    LEDB_SetHigh();
}
