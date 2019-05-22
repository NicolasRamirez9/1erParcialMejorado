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

void informeA(Orquesta *eOrquesta, int cant)
{
    int i;
    char auxOrq[50];

    getDireccion(auxOrq,
                 "\n Ingrese lugar de las listas que desee ver: ",
                 "\n Error, vuelva a intentar.",
                 1,
                 51,
                 1);

    for(i=0; i<cant; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO && strcmp(eOrquesta[i].lugar, auxOrq) == 0)
        {
            printf("\n ID de la orquesta: %d", eOrquesta[i].idOrquesta);
            printf("\n Nombre de la orquesta: %s", eOrquesta[i].nombreOrquesta);
            printf("\n Tipo de orquesta: %d", eOrquesta[i].tipoOrquesta);
            printf("\n Lugar de la orquesta: %s \n", eOrquesta[i].lugar);
        }
    }
}

void informeB(Musico *eMusico,
              Instrumento *eInstrumento,
              Orquesta *eOrquesta,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;

    for(i=0; i<cantUno; i++)
    {
        if(eMusico[i].isEmpty == LLENO && eMusico[i].edad < 25)
        {
            printf("\n ID del musico: %d", eMusico[i].idMusico);
            printf("\n Nombre del musico: %s", eMusico[i].nombreMusico);
            printf("\n Apellido del musico: %s", eMusico[i].apellidoMusico);
            printf("\n Edad del musico: %d \n", eMusico[i].edad);

            for(j=0; j<cantDos; j++)
            {
                if(eInstrumento[j].isEmpty == LLENO && eInstrumento[j].idInstrumento == eMusico[i].idInstrumento)
                {
                    printf(" Nombre de su instrumento: %s\n", eInstrumento[j].nombreInstrumento);
                }
            }
            for(k=0; k<cantTres; k++)
            {
                if(eOrquesta[k].isEmpty == LLENO && eOrquesta[k].idOrquesta == eMusico[i].idOrquesta)
                {
                    printf("\n Lugar de la orquesta: %s \n", eOrquesta[k].lugar);
                }
            }
        }
    }
}

void informeC(Orquesta *eOrquesta, Musico *eMusico, int cantUno, int cantDos)
{
    int i;
    int j;
    int k;
    int contadorMus = 0;

    for(i=0; i<cantUno; i++)
    {
        contadorMus = 0;
        for(j=0; j<cantDos; j++)
        {
            if(eMusico[i].isEmpty == LLENO && eMusico[i].idOrquesta == eOrquesta[j].idOrquesta)
            {
                contadorMus ++;
            }
        }
        for(k=0; k<cantDos; k++)
        {
            if(contadorMus > 6)
            {
                printf("\n ID de la orquesta: %d", eOrquesta[i].idOrquesta);
                printf("\n Nombre de la orquesta: %s", eOrquesta[i].nombreOrquesta);
                printf("\n Tipo de orquesta: %d", eOrquesta[i].tipoOrquesta);
                printf("\n Lugar de la orquesta: %s \n", eOrquesta[i].lugar);
            }
        }
    }
}
