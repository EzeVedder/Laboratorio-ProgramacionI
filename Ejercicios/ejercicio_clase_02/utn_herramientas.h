#ifndef UTN_HERRAMIENTAS_H_INCLUDED
#define UTN_HERRAMIENTAS_H_INCLUDED

/** \brief Funcion que pide un numero de tipo int al usuario.
 *
 * \param pNumero int* puntero a int del numero.
 * \param msg char* mensaje mostrado al usuario.
 * \param msgError char* mensaje de error si el usuario no ingresa un entero.
 * \return int retorna 0 si esta ok -1 si esta mal.
 *
 */
int utn_getInt(int *pNumero,char *msg,char *msgError);




#endif // UTN_HERRAMIENTAS_H_INCLUDED
