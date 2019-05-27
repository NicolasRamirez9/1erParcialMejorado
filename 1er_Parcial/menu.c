#include <stdio.h>
///#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "validaciones.h"
#include "informes.h"
#define ORQUESTA 50
#define MUSICOS 1000
#define INSTRUMENTO 20
#define LLENO 1
#define VACIO -1

int funcionMenu(void)
{
    int opcion;
    char seguir;
    int posLibreOrquesta;
    int posLibreMusico;
    int posLibreInstrumento;
    int flagUno = 0;
    int flagDos = 0;
    int flagTres = 0;
    int report;

    Orquesta eOrquesta[ORQUESTA];
    Musico eMusico[MUSICOS];
    Instrumento eInstrumento[INSTRUMENTO];

    inicializarOrquesta(eOrquesta, ORQUESTA);
    inicializarMusico(eMusico, MUSICOS);
    inicializarInstrumento(eInstrumento, INSTRUMENTO);


    //**********************************************
    strcpy(eOrquesta[0].nombreOrquesta, "Orquesta1");
    strcpy(eOrquesta[0].lugar, "Lugar1");
    eOrquesta[0].idOrquesta = 1;
    eOrquesta[0].isEmpty = LLENO;
    eOrquesta[0].tipoOrquesta = 1;

    strcpy(eOrquesta[1].nombreOrquesta, "Orquesta2");
    strcpy(eOrquesta[1].lugar, "Lugar1");
    eOrquesta[1].idOrquesta = 2;
    eOrquesta[1].isEmpty = LLENO;
    eOrquesta[1].tipoOrquesta = 2;

    strcpy(eOrquesta[3].nombreOrquesta, "Orquesta3");
    strcpy(eOrquesta[3].lugar, "Lugar2");
    eOrquesta[3].idOrquesta = 3;
    eOrquesta[3].isEmpty = LLENO;
    eOrquesta[3].tipoOrquesta = 3;

    strcpy(eOrquesta[4].nombreOrquesta, "Orquesta4");
    strcpy(eOrquesta[4].lugar, "Lugar3");
    eOrquesta[4].idOrquesta = 4;
    eOrquesta[4].isEmpty = LLENO;
    eOrquesta[4].tipoOrquesta = 2;

//*************************************************************
    strcpy(eMusico[0].nombreMusico, "Mus1");
    strcpy(eMusico[0].apellidoMusico, "Amus1");
    eMusico[0].idMusico = 1;
    eOrquesta[0].idOrquesta = 1;
    eMusico[0].edad = 30;
    eMusico[0].isEmpty = LLENO;
    eMusico[0].idInstrumento = 2;

    strcpy(eMusico[1].nombreMusico, "Mus2");
    strcpy(eMusico[1].apellidoMusico, "Amus2");
    eMusico[1].idMusico = 2;
    eOrquesta[1].idOrquesta = 2;
    eInstrumento[1].idInstrumento = 5;
    eMusico[1].edad = 20;
    eMusico[1].isEmpty = LLENO;

    strcpy(eMusico[2].nombreMusico, "Mus3");
    strcpy(eMusico[2].apellidoMusico, "Amus3");
    eMusico[2].idMusico = 3;
    eOrquesta[2].idOrquesta = 4;
    eInstrumento[2].idInstrumento = 2;
    eMusico[2].edad = 25;
    eMusico[2].isEmpty = LLENO;
    eMusico[2].idInstrumento = 0;

    strcpy(eMusico[3].nombreMusico, "Mus4");
    strcpy(eMusico[3].apellidoMusico, "Amus4");
    eMusico[3].idMusico = 4;
    eOrquesta[3].idOrquesta = 4;
    eInstrumento[3].idInstrumento = 1;
    eMusico[3].edad = 27;
    eMusico[3].isEmpty = LLENO;

    strcpy(eMusico[4].nombreMusico, "Mus5");
    strcpy(eMusico[4].apellidoMusico, "Amus5");
    eMusico[4].idMusico = 5;
    eOrquesta[4].idOrquesta = 1;
    eMusico[4].edad = 22;
    eMusico[4].isEmpty = LLENO;
    eMusico[4].idInstrumento = 3;

    strcpy(eMusico[5].nombreMusico, "Mus6");
    strcpy(eMusico[5].apellidoMusico, "Amus6");
    eMusico[5].idMusico = 6;
    eOrquesta[5].idOrquesta = 3;
    eInstrumento[5].idInstrumento = 4;
    eMusico[5].edad = 35;
    eMusico[5].isEmpty = LLENO;

//*****************************************************************************************

    strcpy(eInstrumento[0].nombreInstrumento, "Inst1");
    eInstrumento[0].tipoInstrumento = 1;
    eInstrumento[0].idInstrumento = 1;
    eInstrumento[0].isEmpty = LLENO;

    strcpy(eInstrumento[1].nombreInstrumento, "Inst2");
    eInstrumento[1].tipoInstrumento = 2;
    eInstrumento[1].idInstrumento = 2;
    eInstrumento[1].isEmpty = LLENO;

    strcpy(eInstrumento[2].nombreInstrumento, "Inst3");
    eInstrumento[2].tipoInstrumento = 2;
    eInstrumento[2].idInstrumento = 3;
    eInstrumento[2].isEmpty = LLENO;

    strcpy(eInstrumento[3].nombreInstrumento, "Inst4");
    eInstrumento[3].tipoInstrumento = 3;
    eInstrumento[3].idInstrumento = 4;
    eInstrumento[3].isEmpty = LLENO;

    strcpy(eInstrumento[4].nombreInstrumento, "Inst5");
    eInstrumento[4].tipoInstrumento = 4;
    eInstrumento[4].idInstrumento = 6;
    eInstrumento[4].isEmpty = LLENO;
    //**********************************************
    do
    {
        printf(" ***********************************************************   \n");

        printf("\n *                    ORQUESTA                             * \n");

        printf("\n *           1.ALTA   2.BAJA   3.IMPRIMIR                  * \n");

        printf("\n *********************************************************** \n");

        printf("\n *                    MUSICOS                              * \n");

        printf("\n *  4.ALTA     5.MODIFICACION    6.BAJA     7.IMPRIMIR     * \n");

        printf("\n *********************************************************** \n");

        printf("\n *                  INSTRUMENTOS                           * \n");

        printf("\n *           8. ALTA            9.IMPRIMIR                 * \n");

        printf("\n *********************************************************** \n");

        printf("\n *                   10.INFORMES                           * \n");

        printf("\n *********************************************************** \n");

        printf("\n Elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");///system("clear");

        switch(opcion)
        {
        case 1:
            if(!buscarElVacioOrquesta(eOrquesta, ORQUESTA, &posLibreOrquesta))
            {
                flagUno = LLENO;
                switch(altaOrquesta(eOrquesta, ORQUESTA, posLibreOrquesta))
                {
                case 0:
                    printf("\n Dato ingresado correctamente.\n\n");
                    break;

                case 1:
                    printf("\n Dato ingresado incorrectamente.\n\n");
                    break;
                }
            }
            else
            {
                printf("\n Lleno.");
            }
            break;

        case 2:
            if(flagUno == 0)
            {
                printf("\n No hay datos para dar de baja, se debe cargar la orquesta primero. \n");
            }
            else
            {
                bajaOrquesta(eOrquesta, eMusico, ORQUESTA, MUSICOS);
            }
            break;

        case 3:
            if(flagUno == 0)
            {
                printf("\n No hay datos para modificar, se debe cargar la orquesta primero. \n");
            }
            else
            {
                imprimirOrquestas(eOrquesta, ORQUESTA);
            }
            break;

        case 4:
            if(flagDos != 0 && flagUno != 0)
            {
                if(!buscarElVacioMusico(eMusico, MUSICOS, &posLibreMusico))
                {
                    flagTres = LLENO;
                    switch(altaMusico(eMusico, eOrquesta, eInstrumento, MUSICOS, posLibreMusico))
                    {
                        case 0:
                            printf("\n Dato ingresado correctamente.\n\n");
                            break;

                        case 1:
                            printf("\n Dato ingresado incorrectamente.\n\n");
                            break;
                    }
                }
                else
                {
                    printf("\n Lleno.");
                }
            }
            else
            {
                printf("\n Primero se debe ingresar la orquesta y instrumento. \n");
            }
            break;

        case 5:
            if(flagTres == 0)
            {
                printf("\n No hay datos para modificar, se debe cargar el musico primero. \n");
            }
            else
            {
                modificarMusico(eMusico, eOrquesta, MUSICOS);
            }
            break;

        case 6:
            if(flagTres == 0)
            {
                printf("\n No hay datos para dar de baja, se debe cargar el musico primero. \n");
            }
            else
            {
                bajaMusico(eMusico, MUSICOS);
            }
            break;

    inicializarOrquesta(eOrquesta, ORQUESTA);
        case 7:
            if(flagTres == 0)
            {
                printf("\n No hay datos para imprimir por pantalla, se debe cargar el musico primero. \n");
            }
            else
            {
                imprimirMusico(eMusico, eInstrumento, MUSICOS, INSTRUMENTO);
            }
            break;

        case 8:
            if(!buscarElVacioInstrumento(eInstrumento, INSTRUMENTO, &posLibreInstrumento))
            {
                flagDos = LLENO;
                switch(altaInstrumento(eInstrumento, INSTRUMENTO, posLibreInstrumento))
                {
                case 0:
                    printf("\n Dato ingresado correctamente.\n\n");
                    break;

                case 1:
                    printf("\n Dato ingresado incorrectamente.\n\n");
                    break;
                }
            }
            else
            {
                printf("\n Lleno.");
            }
            break;

        case 9:
            if(flagDos == 0)
            {
                printf("\n No hay datos para imprimir por pantalla, se debe cargar el instrumento primero. \n");
            }
            else
            {
                imprimirInstrumentos(eInstrumento, INSTRUMENTO);
            }
            break;

        case 10:
//            if(flagUno == 0 && flagDos == 0 && flagTres == 0)
//            {
//                printf("\n No hay datos que informar, se debe cargar al empleado primero. \n");
//            }
//            else
                {
                    printf("\n *-----------------------------------------------------* \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   1. Lista orquestas de un lugar en particular.     * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   2. Lista de musico menores de 25 años.            * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   3. Lista de las orquestas con menos de 6 musicos. * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   4. Lista de todos los instrumentos de una         * \n");

                    printf("\n *      orquesta determinada.                          * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   5. Lista de orquestas completas.                  * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   6. Orquesta con menos musicos.                    * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   7. Promedio de instrumentos por orquesta.         * \n");

                    printf("\n *                                                     * \n");

                    printf("\n *   8. Musicos que no tocan instrumentos de viento.   * \n");

                    printf("\n *-----------------------------------------------------* \n");

                    printf("\n Elija una opcion: ");
                    scanf("%d", &report);

                    switch(report)
                    {
                    case 1:
                        informeA(eOrquesta, ORQUESTA);
                        break;

                    case 2:
                        informeB(eMusico, eInstrumento, eOrquesta, MUSICOS, INSTRUMENTO, ORQUESTA);
                        break;

                    case 3:
                        informeC(eOrquesta, eMusico, ORQUESTA, MUSICOS);
                        break;

                    case 4:
                        informeD(eOrquesta, eInstrumento, eMusico, ORQUESTA, INSTRUMENTO, MUSICOS);
                        break;

          //          case 5:
            //            break;

              //      case 6:
                //        break;

                  //  case 7:
                    //    break;

               //     case 8:
                 //       break;

                    }
                }
                break;

        }
        printf("\n Quiere volver al menu?\n s/para continuar n/para salir: ");
        scanf("%s", &seguir);
        system("cls");///system("clear");
    }
    while(seguir =='s');
    return 0;
}
