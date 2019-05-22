#include <stdio.h>
///#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
#include "validaciones.h"
#define VACIO -1
#define LLENO 1

int getString(char *msg, char *msgError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno = VACIO;
    char bufferStr[400];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
            fflush(stdin);///            __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr) >= minimo && strlen(bufferStr) < maximo)
            {
                strncpy(resultado, bufferStr, maximo);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", msgError);
            }
            reintentos --;
        }
        while(reintentos > 0);
    }
    return retorno;
}
int isValidName(char *cadena)
{
    int retorno = LLENO;
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getName(char *resultado, char *msg, char *msgError, int minimo, int maximo, int reintentos)
{
    int retorno = VACIO;
    char bufferStr[4000];
    while(retorno == VACIO)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,
                          msgError,
                          minimo,
                          maximo,
                          reintentos,
                          bufferStr))
            {
                if(isValidName(bufferStr))
                {
                    strncpy(resultado, bufferStr, maximo);
                    retorno = 0;
                    break;
                }
                else
                {

                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}

int isValidint(char* cadena)
{
    int retorno = LLENO;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
   char bufferStr[20];
    int retorno = VACIO;
    while(retorno == VACIO && reintentos > 0)
    {
        if(!getString(mensaje,
                      mensajeError,
                      minimo,
                      maximo,
                      reintentos,
                      bufferStr)&&(resultado!=NULL)&&(isValidint(bufferStr)))
        {
            strncpy(resultado, bufferStr, sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf("%s", mensajeError);
            retorno=VACIO;
        }
    }
    return retorno;
}

int isValidDireccion(char *cadena)
{
    int retorno = LLENO;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getDireccion(char *resultado, char *msg, char *msgError, int minimo, int maximo, int reintentos)
{
    int retorno = VACIO;
    char bufferStr[4000];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,
                      msgError,
                      minimo,
                      maximo,
                      reintentos,
                      bufferStr))
        {
            if(isValidDireccion(bufferStr))
            {
                strncpy(resultado, bufferStr, maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}
