#include "User_Int.h"

uint8_t Mje_env=0;//índice de msjes enviados de menú
uint8_t i_ex_ID=0;//índice de ejecución de configuración ID
uint8_t i_ex_AL=0;//índice de ejecución de configuración Alarma
uint8_t i_ex_Cel=0;//índice de ejecución de configuración de celular
uint8_t i_Registro=1;//índice de lista de registro 

//struct tm *Read_RTC;// estructura para recepción de lectura de RTC

/*
//Sección para configuración de RTC desde USB, no es necesario, se considera para futuras mejoras

Read_RTC->tm_min=0;
Read_RTC->tm_hour=0;
Read_RTC->tm_mday=10;
Read_RTC->tm_mon=1;
Read_RTC->tm_year=1900;
Read_RTC->tm_wday=2;
Read_RTC->tm_yday=2;
Read_RTC->tm_isdst=1;
*/

// Fecha y Hora leídos
char Year_Read[8];
char Month_Read[8];
char Day_Read[8];
char Hour_Read[8];
char Min_Read[8];
char Sec_Read[8];
char Barra[1]="/";
char Fecha_Read[64]="\n Fecha actual:";
char Tiempo_Read[16]="\n Hora actual:";
char Cambio_Linea[4]="\n\n";
char *Fecha_Hora_RTC_Read;

//Textos para manú
    char msj1[]="\n________________________________________________________________\n";
    char msj2[]="Menu principal de configuración sistema de riego.\n\n";
    char msj3[]="Digite el numero de la tarea que desea realizar y presione enter:\n\n";
    char msj4[]="1-Configurar ID Planta.\n";
    char msj5[]="2-Configurar Alertas de humedad.\n";
    char msj6[]="3-Configurar celular de contacto.\n";
    char msj7[]="4-Consultar lista de registros.\n";
    char msj8[]="5-Borrar lista de registros.\n";
    
    //char msj7[]="4-Fijar hora RTC.\n";
    //char msj8[]="5-Consultar hora RTC.\n";
    //char msj9[]="6-Consultar lista de eventos.\n";
    //char msj10[]="7-Agregar evento.\n";
    //char msj11[]="8-Quitar evento.\n";
    char msj9[]="_________________________________________________________________\n";


int Enviar_Menu(void)
{
    uint8_t numBytes;
    uint8_t buffer[64];
    //static int Mje_env=0;
    
    
 switch(Mje_env)
    {   
    case (0):
        numBytes = getsUSBUSART(buffer,sizeof(buffer)); //until the buffer is free.                                        
        if((USBUSARTIsTxTrfReady())&&(numBytes > 0)) 
        {
            putsUSBUSART(msj1);                                                                    
            Mje_env=1;
        }
    break;
    case (1):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj2);                           
            Mje_env=2;
        }
    break;
    case (2):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj3);                                                                    
            Mje_env=3;
        }
    break;
    case (3):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj4);                           
            Mje_env=4;
        }
    break;
    case (4):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj5);                                                                    
            Mje_env=5;
        }
    break;
    case (5):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj6);                           
            Mje_env=6;
        }
    break;
    case (6):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj7);                                                                    
            Mje_env=7;
        }
    break;
    case (7):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj8);                           
            Mje_env=8;
        }
    break;
    case (8):
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(msj9);                                                                    
            Mje_env=0;
            return 1;
        }
    break;
    }
 return 0;   
}
int Msje_Error(void)
{
    char Msje_Error[64]="\nEl número ingresado es incorrecto \n\n";
    
    if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(Msje_Error);                                                                    
            return 1;
        }
    return 0;
}

void Leer_Puerto_serie(char *buffer, uint8_t numBytes)
{
    int i;
    for(i = 0;i < 64;i++)
    {
        buffer[i] = 0;
    } 
    numBytes = getsUSBUSART(buffer,sizeof(buffer)); //until the buffer is free.
    
}

int Conf_ID_Planta(int ID_Planta,char *ID_Planta_string)
{
    int i;
    char buffer_ID[64];
    uint8_t numBytes_ID=0;
    char mje_selec_ID[64]="\nDigite el numero ID de la planta (4 digitos):\n\n";
    char mje_confirmacion_ID[64]="\nEl ID configurado es:\t";
        
    switch(i_ex_ID)
    {
        case(0):
            if(USBUSARTIsTxTrfReady()) 
            {
                putsUSBUSART(mje_selec_ID);
                i_ex_ID=1;
            }
        break;
        case(1):
            for(i = 0;i < 64;i++)
            {
                buffer_ID[i] = 0;
            } 
            numBytes_ID = getsUSBUSART(buffer_ID,sizeof(buffer_ID));
            if (numBytes_ID>4)
            {
                return 2;
            }
            if((numBytes_ID>0)&&(USBUSARTIsTxTrfReady()))
            {
                ID_Planta_string=buffer_ID;
                ID_Planta=atoi(buffer_ID);
                strcat(mje_confirmacion_ID,buffer_ID);
                strcat(mje_confirmacion_ID,Cambio_Linea);
                putsUSBUSART(mje_confirmacion_ID);
                i_ex_ID=0;
                return 1;
            }
        break;    
    }       
    return 0;
}

int Conf_Alerta_Humedad(int Niv_Alarm)
{
    int i;
    char buffer_AL[64];
    uint8_t numBytes_AL=0;
    char mje_selec_AL[64]="\nDigite el nivel de alarma deseado:1-Bajo, 2-Medio, 3-Alto:\n\n";
    char mje_confirmacion_AL[64]="\nEl nivel de alarma configurado es:\t";
    char Cambio_Linea[4]="\n\n";
    
    switch(i_ex_AL)
    {
        case(0):
            if(USBUSARTIsTxTrfReady()) 
            {
                putsUSBUSART(mje_selec_AL);
                i_ex_AL=1;
            }
        break;
        case(1):
            for(i = 0;i < 64;i++)
            {
                buffer_AL[i] = 0;
            } 
            numBytes_AL = getsUSBUSART(buffer_AL,sizeof(buffer_AL));
            if((numBytes_AL>0)&&(USBUSARTIsTxTrfReady()))
            {
                Niv_Alarm=atoi(buffer_AL);
                if((Niv_Alarm>3)||(Niv_Alarm==0))
                {
                    i_ex_AL=0;
                    return 2;
                }
                strcat(mje_confirmacion_AL,buffer_AL);
                strcat(mje_confirmacion_AL,Cambio_Linea);
                putsUSBUSART(mje_confirmacion_AL);
                i_ex_AL=0;
                return 1;
            }
        break;    
    }       
    return 0;
}
 

  
int Conf_Celular(char Nro_Cel[9])
{
    int i;
    char buffer_Cel[64];
    uint8_t numBytes_Cel=0;
    char mje_selec_Cel[64]="\nDigite el Nro. de celular sin espacios ni guiones.\n\n";
    char mje_confirmacion_Cel[64]="\nEl Nro. de celular configurado es:\t";
    char Cambio_Linea[4]="\n\n";
    
    switch(i_ex_Cel)
    {
        case(0):
            if(USBUSARTIsTxTrfReady()) 
            {
                putsUSBUSART(mje_selec_Cel);
                i_ex_Cel=1;
            }
        break;
        case(1):
            for(i = 0;i < 64;i++)
            {
                buffer_Cel[i] = 0;
            } 
            numBytes_Cel = getsUSBUSART(buffer_Cel,sizeof(buffer_Cel));
            if((numBytes_Cel>0)&&(USBUSARTIsTxTrfReady()))
            { 
                if((numBytes_Cel >9)||(buffer_Cel[0]!='0')||(buffer_Cel[1]!='9'))
                {
                    i_ex_Cel=0;
                    return 2;
                }
               
                Nro_Cel=buffer_Cel;
                
                strcat(mje_confirmacion_Cel,Nro_Cel);
                strcat(mje_confirmacion_Cel,Cambio_Linea);
                putsUSBUSART(mje_confirmacion_Cel);
                i_ex_Cel=0;
                return 1;
            }
        break;    
    }       
    return 0;
}

int Consulta_Registro(char Registro_Datos[Max_Strings][Max_Size_Strings])
{
    if (i_Registro>sizeof(Registro_Datos))
    {
        i_Registro=1;
        return 1;
    }    
    while(i_Registro<=sizeof(Registro_Datos))
    {                                         
        if(USBUSARTIsTxTrfReady()) 
        {
            putsUSBUSART(Registro_Datos[i_Registro]);                                                                    
            i_Registro++;            
        }
    break;
    }
    return 0;
}


int Borrar_Registro(char Registro_Datos[Max_Strings][Max_Size_Strings])
{
    memset(Registro_Datos,0,sizeof(Registro_Datos));
    return 1;
}







/*
int Consulta_RTC(void)
{
    RTCC_TimeGet(Read_RTC);
    //Fecha_Hora_RTC_Read=asctime(&Read_RTC);
    //strcat(Fecha_Hora_RTC_Read,Cambio_Linea);
    if(USBUSARTIsTxTrfReady()) 
    {
        //putsUSBUSART(asctime(&Read_RTC));
        return 1;
    }
    return 0;
}
*/
/*
int Conf_RTC(void)
{
   if(USBUSARTIsTxTrfReady()) 
    {
        //putsUSBUSART(asctime(&Read_RTC));
        return 1;
    }
    return 0;
}

int Consulta_Lista_Eventos(void)
{
     if(USBUSARTIsTxTrfReady()) 
    {
        //putsUSBUSART(asctime(&Read_RTC));
        return 1;
    }
    return 0;
}

int Agregar_Evento(void)
{
     if(USBUSARTIsTxTrfReady()) 
    {
        //putsUSBUSART(asctime(&Read_RTC));
        return 1;
    }
    return 0;
}

int Eliminar_Evento(void)
{
       if(USBUSARTIsTxTrfReady()) 
    {
        //putsUSBUSART(asctime(&Read_RTC));
        return 1;
    }
    return 0;
}

*/