#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "instrumento.h"

typedef struct
{
    int idMusico;
    int isEmpty;
    char nombreMusico[51];
    char apellidoMusico[51];
    int edad;
    int idOrquesta;
    int idInstrumento;

}Musico;

/**\brief recorre array
 *\param eMusico Musico*
 *\param cant int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int inicializarMusico(Musico *eMusico, int cant);

/**\brief recorre array
 *\param eMusico Musico*
 *\param cant int
 *\param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarElVacioMusico(Musico *eMusico, int cant, int *indice);

/**\brief ingreso de los campos
 *\param eMusico Musico*
 *\param eOrquesta Orquesta*
 *\param eInstrumento Instrumento*
 *\param cant int
 *\param posLibre int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int altaMusico(Musico *eMusico, Orquesta *eOrquesta, Instrumento *eInstrumento, int cant, int posLibre);

/**\brief ingresa un id
 *\param eMusico Musico*
 *\param cant int
 *\param idEncontrado int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarIdMusico (Musico *eMusico, int cant, int *idEncontrado);

/**\brief se ingresa id para modificar los campos
 *\param eMusico Musico*
 *\param eOrquesta Orquesta*
 *\param cant int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int modificarMusico(Musico *eMusico, Orquesta *eOrquesta, int cant);

/**\brief se ingresa id para dar de baja a un musico
 *\param eMusico Musico*
 *\param cant int
 * \return int Return (0) if Ok
 */
int bajaMusico(Musico *eMusico, int cant);

/**\brief se ingresa id para dar de baja a la orquesta y sus musicos
 *\param eOrquesta Orquesta*
 *\param eMusico Musico*
 *\param cantUno int
 *\param cantDos int
 * \return int Return (0) if Ok
 */
int bajaOrquesta(Orquesta *eOrquesta, Musico *eMusico, int cantUno, int cantDos);

/**\brief recorre el array de musicos
 *\param eMusico Musico*
 *\param eInstrumento Instrumento*
 *\param cantUno int
 *\param cantDos int
 * \return void
 */
void imprimirMusico(Musico *eMusico, Instrumento *eInstrumento,int cantUno, int cantDos);

#endif // MUSICO_H_INCLUDED
