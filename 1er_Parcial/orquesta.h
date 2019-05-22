#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta;
    int isEmpty;
    char nombreOrquesta[51];
    char lugar[51];
    int tipoOrquesta;

}Orquesta;

/**\brief recorre array
 *\param eOrquesta Orquesta*
 *\param cant int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int inicializarOrquesta(Orquesta *eOrquesta, int cant);

/**\brief recorre array
 *\param eOrquesta Orquesta*
 *\param cant int
 *\param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarElVacioOrquesta(Orquesta *eOrquesta, int cant, int *indice);

/**\brief ingreso de los campos
 *\param eOrquesta Orquesta*
 *\param cant int
 *\param posLibre int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int altaOrquesta(Orquesta *eOrquesta, int cant, int posLibre);

/**\brief ingresa un id
 *\param eOrquesta Orquesta*
 *\param cant int
 *\param idEncontrado int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarIdOrquesta(Orquesta *eOrquesta, int cant, int *idEncontrado);

/**\brief recorre array de orquestas
 *\param eOrquesta Orquesta*
 *\param cant int
 * \return void
 */
void imprimirOrquestas(Orquesta *eOrquesta, int cant);

#endif // ORQUESTA_H_INCLUDED
