#include <stdio.h>
///#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "validaciones.h"
#define VACIO -1
#define LLENO 1

static int generarIdOrquesta(void)
{
    static int id1 = 0;
    return id1++;
}

int inicializarOrquesta(Orquesta *eOrquesta, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        eOrquesta[i].isEmpty = VACIO;
        ret = 0;
    }
    return ret;
}

int buscarElVacioOrquesta(Orquesta *eOrquesta, int cant, int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(eOrquesta[i].isEmpty == VACIO)
        {
            *indice = i;
            ret = 0;
            break;
        }
        ret = VACIO;
    }
    return ret;
}

int altaOrquesta(Orquesta *eOrquesta, int cant, int posLibre)
{
    int ret;
    char tipoOrq[50];
    int auxOrq;

    if (!getName(eOrquesta[posLibre].nombreOrquesta,
                 "\n Ingrese nombre de la orquesta: ",
                 "\n Error, vuelva a ingresar\n\n",
                 2,
                 51,
                 1))
    {
        if (!getDireccion(eOrquesta[posLibre].lugar,
                          "\n Ingrese lugar de la orquesta: ",
                          "\n Error, vuelva a ingresar\n\n",
                          2,
                          51,
                          1))
        {
            if (!getInt("\n Ingrese tipo de orquesta(1.SINFONICA 2.FILAMORNICA 3.CAMARA.): ",
                        "\n Error, vuelva a ingresar\n\n",
                        1,
                        3,
                        1,
                        tipoOrq))
            {
                auxOrq = atoi(tipoOrq);
                eOrquesta[posLibre].tipoOrquesta = auxOrq;
                eOrquesta[posLibre].idOrquesta = generarIdOrquesta();
                printf("\n El ID de la orquesta es: %d", eOrquesta[posLibre].idOrquesta);
                eOrquesta[posLibre].isEmpty = LLENO;
                ret = 0;
            }
        }
    }
    else
    {
        ret = LLENO;
    }
    return ret;
}

int buscarIdOrquesta(Orquesta *eOrquesta, int cant, int *idEncontrado)
{
    int i;
    int retorno = VACIO;
    Orquesta auxOrq;
    printf("\n Ingrese id de la orquesta que buscar: ");
    scanf("%d", &auxOrq.idOrquesta);
    for(i=0; i<cant; i++)
    {
        if (eOrquesta[i].idOrquesta == auxOrq.idOrquesta)
        {
            retorno = 0;
            *idEncontrado = i;
            break;
        }
    }
    return retorno;
}

void imprimirOrquestas(Orquesta *eOrquesta, int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(eOrquesta[i].isEmpty != VACIO)
        {
            printf("\n Nombre de la orquesta:%s", eOrquesta[i].nombreOrquesta);
            printf("\n Lugar de la orquesta:%s", eOrquesta[i].lugar);
            printf("\n Tipo de orquesta:%d \n", eOrquesta[i].tipoOrquesta);
        }
    }
}
