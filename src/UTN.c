/*
 * UTN.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

int myGets(char* pCadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(pCadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1]='\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(pCadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numeroIngresado;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &numeroIngresado);
			if(numeroIngresado>=minimo && numeroIngresado<=maximo)
			{
				*pResultado=numeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

float utn_getFlotante(float* pResultadoFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float numeroIngresado;

	if(pResultadoFlotante!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &numeroIngresado);
			if(numeroIngresado>=minimo && numeroIngresado<=maximo)
			{
				*pResultadoFlotante=numeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultadoChar, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno=-1;
	char caracterIngresado;

	if(pResultadoChar!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%c", &caracterIngresado);
			if(caracterIngresado>=minimo && caracterIngresado<=maximo)
			{
				*pResultadoChar=caracterIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

	return retorno;
}

int getString(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && strnlen(buffer, sizeof(buffer))<longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno=0;
		}
	}

	return retorno;
}

int esString(char* cadena, int longitud)
{
	int i;
	int retorno = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ' && cadena[i] != '.' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char* pResultado, char mensaje[], char mensajeError[], int longitud, int reintentos)
{
	char bufferString[4096];
	int retorno=-1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getString(bufferString, sizeof(bufferString)) ==0  && esString(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString))<longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno=0;
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}


