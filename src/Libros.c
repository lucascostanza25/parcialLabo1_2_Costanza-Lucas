/*
 * Libros.c
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libros.h"
#include "Controller.h"
#include "LinkedList.h"
#include "UTN.h"

eLibro* new_libro()
{
	eLibro* this=NULL;
	this=(eLibro*)malloc(sizeof(eLibro));

	if(this!=NULL)
	{
		this->id=0;
		strcpy(this->titulo, " ");
		strcpy(this->autor, " ");
		this->precio=0;
		strcpy(this->editorial, " ");
	}

	return this;
}

eLibro* newParametros_libro(char* idLibro, char* tituloLibro, char* autorLibro, char* precioLibro, char* editorialLibro)
{
	eLibro* auxLibro=new_libro();

	if(idLibro!=NULL && tituloLibro!=NULL && autorLibro!=NULL && precioLibro!=NULL && editorialLibro!=NULL)
	{
		auxLibro->id=atoi(idLibro);
		strcpy(auxLibro->titulo, tituloLibro);
		strcpy(auxLibro->autor, autorLibro);
		auxLibro->precio=atoi(precioLibro);
		strcpy(auxLibro->editorial, editorialLibro);
	}

	return auxLibro;
}

void delete_libro(eLibro* auxLibro)
{
	if(auxLibro!=NULL)
	{
		free(auxLibro);
	}
}

int setId_libro(eLibro* this, int idLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id=idLibro;
		retorno=0;
	}

	return retorno;
}

int getId_libro(eLibro* this,int* idLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*idLibro=this->id;
		retorno=0;
	}

	return retorno;
}

int setTitulo_libro(eLibro* this, char* tituloLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->titulo, tituloLibro);
		retorno=0;
	}

	return retorno;
}

int getTitulo_libro(eLibro* this, char* tituloLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(tituloLibro, this->titulo);
		retorno=0;
	}

	return retorno;
}

int setAutor_libro(eLibro* this, char* autorLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->autor, autorLibro);
		retorno=0;
	}

	return retorno;
}

int getAutor_libro(eLibro* this, char* autorLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(autorLibro, this->autor);
		retorno=0;
	}

	return retorno;
}

int setPrecio_libro(eLibro* this, float precioLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->precio=precioLibro;
		retorno=0;
	}

	return retorno;
}

int getPrecio_libro(eLibro* this, float* precioLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*precioLibro=this->precio;
		retorno=0;
	}

	return retorno;
}

int setEditorial_libro(eLibro* this, char* editorialLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->editorial, editorialLibro);
		retorno=0;
	}

	return retorno;
}

int getEditorial_libro(eLibro* this, char* editorialLibro)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(editorialLibro, this->editorial);
		retorno=0;
	}

	return retorno;
}

int imprimirUn_libro(eLibro* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		printf("-> ID: %d | Titulo: %s | Autor: %s | Precio: %.2f | Editorial: %s", this->id, this->titulo, this->autor, this->precio, this->editorial);
	}

	return retorno;
}

int buscarId_libro(LinkedList* listaLibros, int idBuscado)
{
	int index;
	int i;
	eLibro* auxLibro;

	if(listaLibros!=NULL)
	{
		for(i=0; i<ll_len(listaLibros); i++)
		{
			auxLibro=(eLibro*)ll_get(listaLibros, i);
			if(auxLibro->id==idBuscado)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

int idAutomatico_libro(LinkedList* listaLibros, int* idAutomatico)
{
	int retorno=-1;
	eLibro* auxLibro;

	if(listaLibros!=NULL)
	{
		if(ll_len(listaLibros)>0)
		{
			auxLibro=ll_get(listaLibros, ll_len(listaLibros)-1);
			*idAutomatico=auxLibro->id+1;
			retorno=0;
		}
	}

	return retorno;
}

int sortAutor_libro(void* libroUno, void* libroDos)
{
	int retorno=-1;
	eLibro* auxLibroUno=(eLibro*)libroUno;
	eLibro* auxLibroDos=(eLibro*)libroDos;

	if(libroUno!=NULL && libroDos!=NULL)
	{
		if(strcmp(auxLibroUno->autor, auxLibroDos->autor)<0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int sortId_libro(void* libroUno, void* libroDos)
{
	int retorno=-1;
	eLibro* auxLibroUno=(eLibro*)libroUno;
	eLibro* auxLibroDos=(eLibro*)libroDos;

	if(libroUno!=NULL && libroDos!=NULL)
	{
		if(auxLibroUno->id > auxLibroDos->id)
		{
			retorno=0;
		}
	}

	return retorno;
}

void* descuento_libro(void* libro)
{
	eLibro* auxDescuento=(eLibro*)libro;
	char auxEditorial[100];
	float auxPrecioLibro;
	float precioFinal;
	float descuento;
	getPrecio_libro(auxDescuento, &auxPrecioLibro);
	getEditorial_libro(auxDescuento, auxEditorial);

	if(libro!=NULL)
	{
		if(strcmp(auxEditorial, "Planeta")==0)
		{
			if(auxPrecioLibro>=300)
			{
				descuento=auxPrecioLibro*20/100;
				precioFinal=auxPrecioLibro-descuento;
				setPrecio_libro(auxDescuento, precioFinal);
			}
		}
		else if(strcmp(auxEditorial, "SIGLO XXI EDITORES")==0)
		{
			if(auxPrecioLibro<=200)
			{
				descuento=auxPrecioLibro*10/100;
				precioFinal=auxPrecioLibro-descuento;
				setPrecio_libro(auxDescuento, precioFinal);
			}
		}
	}

	return libro;
}
