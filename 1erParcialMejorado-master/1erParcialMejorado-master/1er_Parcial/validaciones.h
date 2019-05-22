#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/**\brief toma por teclado lo que ingrese el usuario
 *\param msg char*
 *\param msgError char*
 *\param minimo int
 *\param maximo int
 *\param reintentos int
 *\param resultado char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getString(char *msg, char *msgError, int minimo, int maximo, int reintentos, char *resultado);

/**\brief valida que sea letra
 *\param cadena char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int isValidName(char *cadena);

/**\brief valida
 *\param resultado char*
 *\param msg char*
 *\param msgError char*
 *\param minimo int
 *\param maximo int
 *\param reintentos int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getName(char *resultado, char *msg, char *msgError, int minimo, int maximo, int reintentos);

/**\brief valida que sea numero
 *\param cadena char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int isValidint(char* cadena);

/**\brief valida
 *\param mensaje char*
 *\param mensajeError char*
 *\param minimo int
 *\param maximo int
 *\param reintentos int
 *\param resultado char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);

/**\brief valida que sea un numero y letra
 *\param cadena char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int isValidDireccion(char *cadena);

/**\brief valida
 *\param resultado char*
 *\param msg char*
 *\param msgError char*
 *\param minimo int
 *\param maximo int
 *\param reintentos int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getDireccion(char *resultado, char *msg, char *msgError, int minimo, int maximo, int reintentos);

#endif // VALIDACIONES_H_INCLUDED
