

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

//Estados de led
#define LedBOn               1
#define LedBOff              0


#include "mcc_generated_files/pin_manager.h"
#include "utils.h"
#include <string.h>
#endif

void Comando_Luz_Roja(char *Razon, char *ID_Planta_string, char *Posicion_GPS,char *Nro_Celular);
void Comando_Luz_Amarilla(void);
void Comando_Luz_Verde(void);
