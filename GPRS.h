#include <stdbool.h>
#include "mcc_generated_files/tmr2.h"
#include <proc/p32mm0256gpm064.h>
#include <string.h>



//---------------------- Declaro la funcion que creamos para enviar menajes de texto -------------------
//--------------------------------------------------------------------------------------------------------
void EnviarMensaje (char *NumCel , char *MensajeTexto);
void modem_init (void);
