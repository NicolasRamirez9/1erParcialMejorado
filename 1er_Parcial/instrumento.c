#include <stdio.h>
///#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "validaciones.h"
#include "menu.h"
#define VACIO -1
#define LLENO 1

static int generarIdInstrumento(void)
{
    static int id1 = 0;
    return id1++;
}

int inicializarInstrumento(Instrumento *eInstrumento, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        eInstrumento[i].isEmpty = VACIO;
        ret = 0;
    }
    return ret;
}

int buscarElVacioInstrumento(Instrumento *eInstrumento, int cant, int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(eInstrumento[i].isEmpty == VACIO)
        {
            *indice = i;
            ret = 0;
            break;
        }
        ret = VACIO;
    }
    return ret;
}

int altaInstrumento(Instrumento *eInstrumento, int cant, int posLibre)
{
    int ret;
    char tipoIns[50];
    int auxIns;

    if (!getName(eInstrumento[posLibre].nombreInstrumento,
                 "\n Ingrese nombre del instrumento: ",
                 "\n Error, vuelva a ingresar\n\n",
                 3,
                 51,
                 1))
    {
        if (!getInt("\n Ingrese tipo de instrumento(1.CUERDAS 2.VIENTO-MADERA 3.VIENTO-METAL 4.PERCUSION.): ",
                    "\n Error, vuelva a ingresar\n\n",
                    1,
                    3,
                    1,
                    tipoIns))
        {
            auxIns = atoi(tipoIns);
            eInstrumento[posLibre].tipoInstrumento = auxIns;
            eInstrumento[posLibre].idInstrumento = generarIdInstrumento();
            printf("\n El ID del instrumento es: %d", eInstrumento[posLibre].idInstrumento);
            eInstrumento[posLibre].isEmpty = LLENO;
            ret = 0;
        }
    }
    else
    {
        ret = LLENO;
    }
    return ret;
}

int buscarIdInstrumento(Instrumento *eInstrumento, int cant, int *idEncontrado)
{
    int i;
    int retorno = VACIO;
    Instrumento auxIns;
    printf("\n Ingrese id del instrumento: ");
    scanf("%d", &auxIns.idInstrumento);
    for(i=0; i<cant; i++)
    {
        if (eInstrumento[i].idInstrumento == auxIns.idInstrumento)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}

int imprimirInstrumentos(Instrumento *eInstrumento,int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(eInstrumento[i].isEmpty != VACIO)
        {
            if(eInstrumento[i].tipoInstrumento == 1)
            {
                printf("\n Nombre del instrumento:%s", eInstrumento[i].nombreInstrumento);
                printf("\n Cuerdas:%d", eInstrumento[i].tipoInstrumento);
                printf("\n ID del instrumento:%d \n", eInstrumento[i].idInstrumento);
            }
            if(eInstrumento[i].tipoInstrumento == 2)
            {
                printf("\n Nombre del instrumento:%s", eInstrumento[i].nombreInstrumento);
                printf("\n Viento-madera:%d", eInstrumento[i].tipoInstrumento);
                printf("\n ID del instrumento:%d \n", eInstrumento[i].idInstrumento);
            }
            if(eInstrumento[i].tipoInstrumento == 3)
            {
                printf("\n Nombre del instrumento:%s", eInstrumento[i].nombreInstrumento);
                printf("\n Viento-metal:%d", eInstrumento[i].tipoInstrumento);
                printf("\n ID del instrumento:%d \n", eInstrumento[i].idInstrumento);
            }
            if(eInstrumento[i].tipoInstrumento == 4)
            {
                printf("\n Nombre del instrumento:%s", eInstrumento[i].nombreInstrumento);
                printf("\n Percusion:%d", eInstrumento[i].tipoInstrumento);
                printf("\n ID del instrumento:%d \n", eInstrumento[i].idInstrumento);
            }
            else
            {
                printf("\n Ingrese una opcion correcta. \n");
            }
        }
    }
}
