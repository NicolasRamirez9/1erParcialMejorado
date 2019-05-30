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
        for(j=0; j<cantDos; j++)
        {
            if(eOrquesta[i].isEmpty == LLENO && eOrquesta[i].idOrquesta == eMusico[j].idOrquesta)
            {
                contadorMus ++;
            }
        }
    }
    for(k=0; k<cantUno; k++)
    {
        if(contadorMus < 6 && eOrquesta[k].isEmpty == LLENO)
        {
            printf("\n ID de la orquesta: %d", eOrquesta[k].idOrquesta);
            printf("\n Nombre de la orquesta: %s", eOrquesta[k].nombreOrquesta);
            printf("\n Tipo de orquesta: %d", eOrquesta[k].tipoOrquesta);
            printf("\n Lugar de la orquesta: %s \n", eOrquesta[k].lugar);
        }
    }
}
void informeD(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;
    char idOrq[50];
    int auxId;

    getInt("\n Ingrese ID de la orquesta a la que quiere listar sus instrumentos: ",
           "\n Error, vuelva a intentar.",
           0,
           20,
           1,
           idOrq);
    auxId = atoi(idOrq);

    for(i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO &&
           auxId == eOrquesta[i].idOrquesta)
        {
            for(j=0; j<cantDos; j++)
            {
                if(eMusico[j].isEmpty == LLENO &&
                   eMusico[j].idOrquesta == eOrquesta[i].idOrquesta)
                {
                    printf("\n Nombre del musico que toca el instrumento: %s", eMusico[j].nombreMusico);

                    for(k=0; k<cantTres; k++)
                    {
                        if (eInstrumento[k].isEmpty == LLENO &&
                            eMusico[j].idInstrumento == eInstrumento[k].idInstrumento)
                        {
                            printf("\n Nombre del instrumento: %s", eInstrumento[k].nombreInstrumento);
                            printf("\n Tipo de instrumento: %d", eInstrumento[k].tipoInstrumento);
                        }
                    }
                }
            }
        }
    }
}

void informeE(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;
    int z;
    int contadorDeCuerdas = 0;
    int contadorDeViento = 0;
    int contadorDePercusion = 0;

    for (i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO)
        {
            for (j=0; j<cantDos; j++)
            {
                if(eMusico[j].isEmpty == LLENO && eMusico[j].idOrquesta == eOrquesta[i].idOrquesta)
                {
                    for (k=0; k<cantTres; k++)
                    {
                        if(eInstrumento[k].isEmpty == LLENO && eInstrumento[k].idInstrumento == eMusico[j].idInstrumento)
                        {
                            if(eInstrumento[k].tipoInstrumento == 1)
                            {
                                contadorDeCuerdas ++;
                            }
                            if(eInstrumento[k].tipoInstrumento == 2 || eInstrumento[k].tipoInstrumento == 3)
                            {
                                contadorDeViento ++;
                            }
                            if(eInstrumento[k].tipoInstrumento == 4)
                            {
                                contadorDePercusion ++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(z=0; z<cantUno; z++)
    {
        if(contadorDeCuerdas >= 4 && contadorDeViento >= 4 && contadorDePercusion >= 1)
        {
            printf("ID de la orquesta: %d", eOrquesta[z].idOrquesta);
            printf("Nombre de orquesta: %s", eOrquesta[z].nombreOrquesta);
            printf("Lugar de la orquesta: %s", eOrquesta[z].lugar);
            printf("Tipo de orquesta: %d", eOrquesta[z].tipoOrquesta);
            break;
        }
    }
}

void informeG(Musico *eMusico, Instrumento *eInstrumento, Orquesta *eOrquesta, int cantUno, int cantDos, int cantTres)
{
    int i;
    int j;
    int k;
    float contadorInstrumento = 0;
    int contadorOrquesta = 0;
    float promedio;

    for(i=0; i<cantUno; i++)
    {
        if(eMusico[i].isEmpty == LLENO)
        {
            for(j=0; j<cantDos; j++)
            {
                if(eInstrumento[j].isEmpty == LLENO && eMusico[i].idInstrumento == eInstrumento[j].idInstrumento)
                {
                    contadorInstrumento ++;
                }
            }
        }
    }
    for(k=0; k<cantTres; k++)
    {
        if(eOrquesta[k].isEmpty == LLENO)
        {
            contadorOrquesta ++;
        }
    }
    promedio = contadorInstrumento / contadorOrquesta;
    printf("El promedio de instrumentos por orquesta es: %.2f", promedio);
}

