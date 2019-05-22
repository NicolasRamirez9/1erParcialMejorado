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

static int generarIdMusico(void)
{
    static int id1 = 0;
    return id1++;
}

int inicializarMusico(Musico *eMusico, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        eMusico[i].isEmpty = VACIO;
        ret = 0;
    }
    return ret;
}

int buscarElVacioMusico(Musico *eMusico, int cant, int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(eMusico[i].isEmpty == VACIO)
        {
            *indice = i;
            ret = 0;
            break;
        }
        ret = VACIO;
    }
    return ret;
}

int altaMusico(Musico *eMusico, Orquesta *eOrquesta, Instrumento *eInstrumento, int cant, int posLibre)
{
    int ret;
    int pos;
    char edadMus[50];
    int auxMus;
    char idOrq[50];
    int auxOrq;
    char idIns[50];
    int auxIns;

    if (!getName(eMusico[posLibre].nombreMusico,
                 "\n Ingrese nombre del musico: ",
                 "\n Error, vuelva a ingresar\n\n",
                 2,
                 51,
                 1))
    {
        if (!getName(eMusico[posLibre].apellidoMusico,
                     "\n Ingrese apellido del musico: ",
                     "\n Error, vuelva a ingresar\n\n",
                     2,
                     51,
                     1))
        {
            if (!getInt("\n Ingrese edad del musico: ",
                        "\n Error, vuelva a ingresar\n\n",
                        1,
                        3,
                        1,
                        edadMus))
            {
                auxMus = atoi(edadMus);
                eMusico[posLibre].edad = auxMus;

                if(!buscarIdOrquesta(eOrquesta, cant, &pos))
                {
                    printf("\n Se encontro ID de Orquesta.");

                    if(!getInt("\n Ingrese el ID de la orquesta: ",
                               "\n Error, vuelva a ingresar\n\n",
                               0,
                               20,
                               1,
                               idOrq))
                    {
                        auxOrq = atoi(idOrq);
                        eMusico[posLibre].idOrquesta = auxOrq;

                        if(!buscarIdInstrumento(eInstrumento, cant, &pos))
                        {
                            printf("\n Se encontro el ID del instrumento.");

                            if(!getInt("\n Ingrese el ID del instrumento: ",
                                       "\n Error, vuelva a ingresar\n\n",
                                       0,
                                       20,
                                       1,
                                       idIns))
                            {
                                auxIns = atoi(idIns);
                                eMusico[posLibre].idInstrumento = auxIns;
                                eMusico[posLibre].idMusico = generarIdMusico();
                                eMusico[posLibre].isEmpty = LLENO;
                                ret=0;

                            }
                        }


                    }
                }
            }
        }
    }

    else
    {
        ret = LLENO;
    }
    return ret;
}

int buscarIdMusico (Musico *eMusico, int cant, int *idEncontrado)
{
    int i;
    int retorno = VACIO;
    Musico auxMus;
    printf("\n Ingrese ID del musico: ");
    scanf("%d", &auxMus.idMusico);
    for(i=0; i< cant; i++)
    {
        if (eMusico[i].idMusico == auxMus.idMusico)
        {
            retorno = 0;
            *idEncontrado = i;
            break;
        }
    }
    return retorno;
}

int modificarMusico(Musico *eMusico, Orquesta *eOrquesta,int cant)
{
    int aceptar;
    char mod;
    int ret = VACIO;
    int posId2;
    int i;
    int posPrueba=0;
    int pos;
    char idOrq[50];
    int auxOrq;
    char edadMus[10];
    int auxEd;

    for(i=0; i<cant; i++)
    {
        if(eMusico[i].isEmpty != VACIO)
        {
            printf("\n Nombre:%s", eMusico[i].nombreMusico);
            printf("\n Apellido:%s", eMusico[i].apellidoMusico);
            printf("\n ID del musico:%d", eMusico[i].idMusico);
        }
    }
    if(!buscarIdMusico(eMusico, cant, &posId2))
    {
        do
        {
            system("clear");
            printf("\n ***************************** \n");

            printf("\n *    1.EDAD                 * \n");

            printf("\n *                           * \n");

            printf("\n *    2.ID DE ORQUESTA       * \n");

            printf("\n ***************************** \n");

            printf("\n Ingrese el campo que desea modificar: ");
            scanf("%d", &aceptar);
            system("clear");

            switch(aceptar)
            {
            case 1:
                getInt("\n Ingrese edad del musico: ",
                       "\n Error, vuelva a intentarlo.",
                       0,
                       3,
                       1,
                       edadMus);
                auxEd = atoi(edadMus);
                eMusico[posPrueba].edad = auxEd;
                break;

            case 2:
                    if(!buscarIdOrquesta(eOrquesta, cant, &pos))
                    {
                        getInt("\n Modifique el ID de la orquesta: ",
                               "\n Error, vuelva a intentarlo.",
                               0,
                               3,
                               1,
                               idOrq);
                        auxOrq = atoi(idOrq);
                        eMusico[posPrueba].idOrquesta = auxOrq;
                    }
                break;
            }
            printf("\n Quiere modificar otro campo?\n s/para continuar n/para salir: ");
            scanf("%s", &mod);
            system("clear");
        }
        while(mod == 's');
        ret = 0;
    }
    else
    {
        printf("\n No se encontro ID de la orquesta.");
    }
    return ret;
}

int bajaMusico(Musico *eMusico,int cant)
{
    int posIdUno;
    char resp;
    int posBaja = 0;
    int i;

    for(i=0; i<cant; i++)
    {
        if(eMusico[i].isEmpty!=VACIO)
        {
            printf("\n Nombre:%s", eMusico[i].nombreMusico);
            printf("\n Apellido:%s", eMusico[i].apellidoMusico);
            printf("\n ID del musico:%d", eMusico[i].idMusico);
        }
    }
    if(!buscarIdMusico(eMusico, cant, &posIdUno))
    {
        printf("\n Esta seguro que quiere dar de baja ese id? \n s|n: ");
        scanf("%s", &resp);
        if(resp == 's')
        {
            printf("\n Se ha dado de baja esta orquesta.");
            eMusico[posBaja].isEmpty = VACIO;
        }
        else
        {
            printf("\n Vuelva al menu.");
        }
    }
    return 0;
}

int bajaOrquesta(Orquesta *eOrquesta, Musico *eMusico, int cantUno, int cantDos)
{
    int posIdUno;
    char resp;
    int posBaja = 0;
    int i;
    int j;

    for(i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty != VACIO)
        {
            printf("\n ID disponibles: %d\n", eOrquesta[i].idOrquesta);
        }
    }
    if(!buscarIdOrquesta(eOrquesta, cantUno, &posIdUno))
    {
        printf("\n Esta seguro que quiere dar de baja ese ID?: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            for(j=0; j<cantDos; j++)
            {
                if(eMusico[j].idOrquesta == eOrquesta[i].idOrquesta)
                {
                    eOrquesta[posBaja].isEmpty = VACIO;
                    eMusico[j].isEmpty = VACIO;
                }
            }
            printf("\n Se ha dado de baja esta orquesta y a los musicos que la componen. \n");
        }
        else
        {
            printf("\n Vuelva al menu.");
        }
    }
    return 0;
}

void imprimirMusico(Musico *eMusico, Instrumento *eInstrumento,int cantUno, int cantDos)
{
    int i;
    int j;
    for(i=0; i<cantUno; i++)
    {
        if(eMusico[i].isEmpty == LLENO )
        {
            for(j=0; j<cantDos; j++)
            {
                if(eInstrumento[j].isEmpty==LLENO)
                {
                    if(eMusico[i].idMusico == eInstrumento[j].idInstrumento)
                    {
                        printf("\n Nombre del musico:%s", eMusico[i].nombreMusico);
                        printf("\n Apellido del musico:%s", eMusico[i].apellidoMusico);
                        printf("\n ID del musico:%d", eMusico[i].idMusico);
                        printf("\n Nombre del instrumento:%s", eInstrumento[j].nombreInstrumento);
                        printf("\n Tipo de instrumento:%d \n", eInstrumento[j].tipoInstrumento);
                    }
                }
            }
        }
    }
}
