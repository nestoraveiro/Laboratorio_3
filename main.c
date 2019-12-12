
#include <stdio.h>
#include <stdint.h>
//#include <stdlib.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h" 
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/adc1.h"
#include "utils.h"
#include "User_Int.h"
#include "GPRS.h"


//Estados de led
#define LedOn               1
#define LedOff              0

//Razones de alarma nivel 1
char FaltaAgua[20]= "Falta de Agua";
char ExcesoAgua[20]= "Exceso de Agua";
char Posicion_GPS[50]= "link devuelto por funcion gps";

//Tareas
void Task1_Interfaz_Usuario(void);
void Task2_Ejecucion_Eventos(void);
void Task3_Control_LedA(void);
void Task4_Registro_Datos(void);

//Variables globales

int ID_Planta=0;// hasta 4 dígitos
char ID_Planta_string[4];
int Nivel_Alarma=1;//1-alta, 2-media, 3-baja
char Nro_Celular[9];// String de 9 char


char Registro_Datos[Max_Strings][Max_Size_Strings];// Registro de 62 strings de 80 char c/u

int Menu=0;
int EstadoLed=0;   
int Seleccion=0;
int i;
int i_AL;
int i_ID;
int i_Cel;
int i_reg_consulta;


uint8_t Umbral_AL_Roja_Alta=40;
uint8_t Umbral_AL_Roja_Baja=5;
uint8_t Umbral_AL_Amarilla_Alta=20;
uint8_t Umbral_AL_Amarilla_Baja=10;

// Variable de entrada analógica
uint8_t Hum_Cb=0;
    
uint8_t numBytes;
uint8_t buffer[64];
uint8_t Dato_Recibido[64];
    
ut_tmrDelay_t ledA;
ut_tmrDelay_t Temp_Muestra_Hum;




int main(void)
{
    // initialize the device
    SYSTEM_Initialize();         
    
    while (1)
    {
        Task1_Interfaz_Usuario();
        Task2_Ejecucion_Eventos();
        Task3_Control_LedA();
        Task4_Registro_Datos();      
    }
    return 0;
}
    
          
//************** MÁQUINA EN TAREA DE INTERFÁZ DE USUARIO*****************************************
//***********************************************************************************************            
           
 void Task1_Interfaz_Usuario(void)
 {
    if((USBGetDeviceState() != CONFIGURED_STATE)||(USBIsDeviceSuspended() == true))
    {                 
        return;     
    }
    else
    {
                    
        switch(Menu)
        {
            case(0):// Envía menú en primer contacto
                Menu=Enviar_Menu();
            break;
            case(1):// Comienza el diálogo
                            
                switch(Seleccion)
                {
                    case(0):// Observa puerto si se ha seleccionado una opción de configuracion
                        for(i = 0;i < 64;i++)
                        {
                           buffer[i] = 0;
                        } 
                        numBytes = getsUSBUSART(buffer,sizeof(buffer));
                        if(numBytes>0)
                        {                                       
                            Seleccion=atoi(buffer);
                            if((Seleccion>5)||(Seleccion==0))
                            {    
                                Seleccion=6; 
                            }
                            numBytes =0;
                        }
                    break;
                    case(1)://Selección de configuración de identificador de planta
                        i_ID=Conf_ID_Planta(ID_Planta,ID_Planta_string);
                        if(i_ID==1)
                        {
                            Menu=0;
                            Seleccion=0;
                        }
                        else if(i_ID==2)Seleccion=9;
                    break;
                    case(2):// Selección de configuración de nivel de alarma
                        i_AL=Conf_Alerta_Humedad(Nivel_Alarma);
                        if(i_AL==1)
                        {
                            Menu=0;
                            Seleccion=0; 
                        }
                        else if(i_AL==2)Seleccion=9;
                    break;
                    case(3)://Selección de configuración de celular de contacto
                        i_Cel=Conf_Celular(Nro_Celular);
                        if(i_Cel==1)
                        {
                            Menu=0;
                            Seleccion=0;
                        }
                        else if(i_Cel==2)Seleccion=9;
                    break;
                    case(4)://Consulta de registro guardado
                        i_reg_consulta=Consulta_Registro(Registro_Datos);
                        if(i_reg_consulta==1)
                        {
                            Menu=0;
                            Seleccion=0;
                        }   
                    break;
                    case(5):// Borrado de registro
                                    
                        Borrar_Registro(Registro_Datos);
                        Menu=0;
                        Seleccion=0;
                                    
                    break;
                    case(6):
                        if(Msje_Error())
                        {
                            Menu=0;
                            Seleccion=0;
                        }
                    break;
                               
                }                                  
                           
            break;    
        }        
    }
    CDCTxService();                 
} 
//************** MÁQUINA EN TAREA DE EVALUACIÓN Y EJECUCIÓN DE EVENTOS**************************
//*********************************************************************************************** 
void Task2_Ejecucion_Eventos(void)
{
    int conversion;
    int i;
    
    if(UT_delayDs(&Temp_Muestra_Hum,50)==true)
    {
        ADC1_ChannelSelect(ADC1_POTENCIOMETRO);
        ADC1_Start();
    
        for(i=0;i <1000;i++)
        {
        }
        ADC1_Stop();
        if(!ADC1_IsConversionComplete())
        {
        return;   
        }
    
        conversion = ADC1_ConversionResultGet();
        Hum_Cb=(int)(conversion*0.06);

        if(Nivel_Alarma==1)
        {
            Umbral_AL_Roja_Alta=35;
            Umbral_AL_Roja_Baja=10;
            Umbral_AL_Amarilla_Alta=20;
            Umbral_AL_Amarilla_Baja=18;
        }
        if(Nivel_Alarma==2)
        {
            Umbral_AL_Roja_Alta=40;
            Umbral_AL_Roja_Baja=5;
            Umbral_AL_Amarilla_Alta=20;
            Umbral_AL_Amarilla_Baja=10;
        }
        if(Nivel_Alarma==3)
        {
            Umbral_AL_Roja_Alta=45;
            Umbral_AL_Roja_Baja=3;
            Umbral_AL_Amarilla_Alta=27;
            Umbral_AL_Amarilla_Baja=8;
        } 
    }
    char MensajeTexto;
    
        
    if (Hum_Cb>Umbral_AL_Roja_Alta) Comando_Luz_Roja(ExcesoAgua,ID_Planta_string,Posicion_GPS,Nro_Celular);
    if (Hum_Cb<Umbral_AL_Roja_Baja) Comando_Luz_Roja(FaltaAgua,ID_Planta_string,Posicion_GPS,Nro_Celular);
    if (Umbral_AL_Roja_Alta>Hum_Cb)
    {
        if(Hum_Cb>Umbral_AL_Amarilla_Alta)Comando_Luz_Amarilla();
    }  
    if (Umbral_AL_Roja_Baja<Hum_Cb)
    {
        if(Hum_Cb<Umbral_AL_Amarilla_Baja)Comando_Luz_Amarilla();
    } 
    if (Umbral_AL_Amarilla_Alta>Hum_Cb)
    {
        if(Hum_Cb>Umbral_AL_Amarilla_Baja)Comando_Luz_Verde();
    }
    
}           
 
//************** MÁQUINA EN TAREA DE COMANDO DE LEDS********************************************
//***********************************************************************************************                
void Task3_Control_LedA(void)
{               
    switch(EstadoLed)
    {    
        case(LedOff):
                        
            LEDA_SetLow();
            if(UT_delayDs(&ledA,8)==true)
            {
                LEDA_SetHigh();
                EstadoLed=LedOn;
            }
        break;
                        
        case(LedOn):
            if(UT_delayDs(&ledA,4)==true)
            {
                LEDA_SetLow();
                EstadoLed=LedOff;
            }
        break;
    }
           
}

//************** MÁQUINA EN TAREA DE REGISTRO DE DATOS*******************************************
//*********************************************************************************************** 
void Task4_Registro_Datos(void)
{
                    
                
               
}       


