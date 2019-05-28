#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/**\brief Listar las orquestas de un lugar en particular ingresado por el usuario
 *\param eOrquesta Orquesta*
 *\param cant int
 * \return
 */
void informeA(Orquesta *eOrquesta, int cant);

/**\brief Listar los musicos de menos de 25 anios
 *\param eMusico Musico*
 *\param eOrquesta Orquesta*
 *\param eInstrumento Instrumento*
 *\param cantUno int
 *\param cantDos int
 *\param cantTres int
 * \return
 */
void informeB(Musico *eMusico,
              Instrumento *eInstrumento,
              Orquesta *eOrquesta,
              int cantUno,
              int cantDos,
              int cantTres);

/**\brief Listar las orquestas con menos de 6 musicos
 *\param eOrquesta Orquesta*
 *\param eMusico Musico*
 *\param cantUno int
 *\param cantDos int
 * \return
 */
void informeC(Orquesta *eOrquesta, Musico *eMusico, int cantUno, int cantDos);

/**\brief Listar todos los instrumentos de una orquesta determinada
 *\param eOrquesta Orquesta*
 *\param eMusico Musico*
 *\param eInstrumento Instrumento*
 *\param cantUno int
 *\param cantDos int
 *\param cantTres int
 * \return
 */
void informeD(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres);

/**\brief Listar las orquestas completas
 *\param
 *\param
 * \return
 */
void informeE(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres);

/**\brief Imprimir la orquesta con menos musicos
 *\param
 *\param
 * \return
 */
void informeF(Orquesta *eOrquesta, int cant);

/**\brief Imprimir el promedio de instrumentos por orquesta
 *\param
 *\param
 * \return
 */
void informeG(Musico *eMusico, Instrumento *eInstrumento, Orquesta *eOrquesta, int cantUno, int cantDos, int cantTres);

/**\brief Listar los musicos que no toquen instrumentos de viento, ordenado por apellido
 *\param
 *\param
 * \return
 */
void informeH(Orquesta *eOrquesta, int cant);


#endif // INFORMES_H_INCLUDED
