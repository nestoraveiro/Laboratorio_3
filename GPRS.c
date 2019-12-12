#include "GPRS.h"



void modem_init (void)
{
    
    int status = 0;
    status = PORTAbits.RA11;
    
    while (status == 0) {
        CNPDAbits.CNPDA0 = 1;
        CNPUAbits.CNPUA0 = 0;
        countGPRS = 0;
        while (countGPRS <= 12){
        }
        CNPDAbits.CNPDA0 = 0;
        countGPRS = 0;
        while (countGPRS <= 22){
        }
        status = PORTAbits.RA11; //Vemos si el modem se prendio (STATUS = 1)
        
    }  
}


void EnviarMensaje (char *NumCel , char *MensajeTexto)
{
    char mensajeModoTexto[]= "AT+CMGF=1\r"; // selecciono el modo texto
    char NumeroCel1[]= "AT+CMGS=\""; //numero de cel    AT+CMGS=\"099560030\"" -----    AT+CMGS="099560030"
    char NumeroCel2[]= "\"";
    char NumCelCompleto[20];
    memset(NumCelCompleto, '\0', sizeof(NumCelCompleto));
    strcpy (NumCelCompleto , NumeroCel1);
    strcat (NumCelCompleto , NumCel);
    strcat(NumCelCompleto , NumeroCel2);

    if (UART1_IsTxReady())
    {
        UART1_WriteBuffer(mensajeModoTexto , strlen(mensajeModoTexto));
    }
    countGPRS = 0;
    while (countGPRS < 1) 
    {            
    }            
    if (UART1_IsTxReady())
    {
        UART1_WriteBuffer(NumCelCompleto , strlen (NumCelCompleto));
    }
    countGPRS = 0;
    while(countGPRS < 2)
    {                
    }            
    if (UART1_IsTxReady())
    {
        UART1_Write(0x0D);
    }
    countGPRS = 0;
    while(countGPRS < 1)
    {                
    }            
    if (UART1_IsTxReady())
    {
        UART1_WriteBuffer(MensajeTexto , strlen(MensajeTexto));
    }
    countGPRS = 0;
    while(countGPRS < 1)
    {                
    }          
    if (UART1_IsTxReady())
    {
        UART1_Write(0x1A);
    }
                                
}