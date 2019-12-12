

#ifndef _User_Int_H    /* Guard against multiple inclusion */
#define _User_Int_H

#include <stdio.h>
#include "time.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <xc.h>

#include "mcc_generated_files/usb/usb.h"

#endif

//Tamañoo de lista de registro de datos
#define Max_Strings         62
#define Max_Size_Strings    80


//Funciones
int Enviar_Menu(void);
int Conf_ID_Planta(int ID_Planta,char *ID_Planta_string);
int Conf_Alerta_Humedad(int Niv_Alarm);
int Msje_Error(void);
int Conf_Celular(char Nro_Cel[9]);
int Consulta_Registro(char Registro_Datos[Max_Strings][Max_Size_Strings]);
int Borrar_Registro(char Registro_Datos[Max_Strings][Max_Size_Strings]);
//int Consulta_RTC(void);
//int Conf_RTC(void);
//int Consulta_Lista_Eventos(void);
//int Agregar_Evento(void);
//int Eliminar_Evento(void);
//void Leer_Puerto_serie(char *buffer, uint8_t numBytes);