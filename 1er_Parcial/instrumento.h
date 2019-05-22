#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int idInstrumento;
    int isEmpty;
    char nombreInstrumento[51];
    int tipoInstrumento;

}Instrumento;

/**\brief recorre array
 *\param eInstrumento Instrumento*
 *\param cant int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int inicializarInstrumento(Instrumento *eInstrumento, int cant);

/**\brief recorre array
 *\param eIntrumento Instrumento*
 *\param cant int
 *\param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarElVacioInstrumento(Instrumento *eInstrumento, int cant, int *indice);

/**\brief ingreso de los campos
 *\param eInstrumento Instrumento*
 *\param cant int
 *\param posLibre int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int altaInstrumento(Instrumento *eInstrumento, int cant, int posLibre);

/**\brief ingresa un id
 *\param eInstrumento Instrumento*
 *\param cant int
 *\param idEncontrado int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int buscarIdInstrumento(Instrumento *eInstrumento, int cant, int *idEncontrado);

/**\brief recorre array de instrumentos
 *\param eInstrumento Instrumento*
 *\param cant int
 * \return void
 */
int imprimirInstrumentos(Instrumento *eInstrumento,int cant);


#endif // INSTRUMENTO_H_INCLUDED
