/*
 * utn.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Lucas
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Se le pide un numero al usuario y en caso de que cumpla las condiciones devuelve el resultado.
 *
 * \param pResultado / Puntero al espacio de memoria donde se escribira el resultado dado.
 * \param mensaje / Mensaje mostrado al usuario para que pueda ingresar el numero.
 * \param mensajeError / Mensaje mostrado al usuario si dio error al ingresar el numero.
 * \param minimo / Numero minimo aceptado.
 * \param maximo / Numero maximo aceptado.
 * \param reintentos / Cantidad de reintentos que tiene el usuario para ingresar el numero.
 * \return Retorna 0 si se cumplio las condiciones y se obtuvo el numero o -1 si dio error.
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Se le pide un numero flotante al usuario y en caso de que cumpla las condiciones devuelve el resultado.
 *
 * \param pResultadoFlotante / Puntero al espacio de memoria donde se escribira el resultado dado.
 * \param mensaje / Mensaje mostrado al usuario para que pueda ingresar el numero.
 * \param mensajeError / Mensaje mostrado al usuario si dio error al ingresar el numero.
 * \param minimo / Numero minimo aceptado.
 * \param maximo / Numero maximo aceptado.
 * \param reintentos / Cantidad de reintentos que tiene el usuario para ingresar el numero.
 * \return Retorna 0 si se cumplio las condiciones y se obtuvo el numero o -1 si dio error.
 */
float utn_getFlotante(float* pResultadoFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief
 *
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/**
 * \brief Se le pide una cadena de caracteres al usuario.
 *
 * \param pResultado / Puntero al espacio de memoria donde se escribira el resultado luego de haber sido aprobado.
 * \param mensaje / Mensaje mostrado al usuario para que ingrese la cadena de caracteres.
 * \param mensajeError / Mensaje de error mostrado al usuario si no se cumplen las condiciones dadas.
 * \param longitud / Longitud maxima de la cadena de caracteres.
 * \param reintentos / Cantidad de reintentos que tiene el usuario para poder ingresar la cadena.
 * \return Retorna 0 si se cumplio las condiciones -1 si dio error.
 */
int utn_getString(char* pResultado, char mensaje[], char mensajeError[], int longitud, int reintentos);

/**
 * \brief Verifica y valida si la cadena ingresada es de tipo String.
 *
 * \param cadena / Direccion de memoria con la cadena a analizar.
 * \param longitud / Longitud de la cadena previamente pasada.
 * \return Retorna 0 si se cumplio las condiciones -1 si dio error.
 */
int esString(char* cadena, int longitud);

/**
 * \brief Lee stdin hasta que se encuentra con un '\n'.
 *
 * \param pCadena / Puntero al espacio de memoria donde se escribira la cadena obtenida.
 * \param longitud / Longitud disponible para el tamaño de la cadena.
 * \return Retorna 0 si se cumplio las condiciones -1 si dio error.
 */
int myGets(char* pCadena, int longitud);

#endif /* UTN_H_ */
