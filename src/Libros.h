/*
 * Libros.h
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char titulo[120];
	char autor[100];
	float precio;
	char editorial[100];
}eLibro;

eLibro* new_libro();

eLibro* newParametros_libro(char* idLibro, char* tituloLibro, char* autorLibro, char* precioLibro, char* editorialLibro);

void delete_libro();

int add_libro(LinkedList* listaLibros);

int setId_libro(eLibro* this, int idLibro);

int getId_libro(eLibro* this,int* idLibro);

int setTitulo_libro(eLibro* this, char* tituloLibro);

int getTitulo_libro(eLibro* this, char* tituloLibro);

int setAutor_libro(eLibro* this, char* autorLibro);

int getAutor_libro(eLibro* this, char* autorLibro);

int setPrecio_libro(eLibro* this, float precioLibro);

int getPrecio_libro(eLibro* this, float* precioLibro);

int setEditorial_libro(eLibro* this, char* editorialLibro);

int getEditorial_libro(eLibro* this, char* editorialLibro);

int imprimirUn_libro(eLibro* this);

int buscarId_libro(LinkedList* listaLibros, int idBuscado);

int idAutomatico_libro(LinkedList* listaLibros, int* idAutomatico);

int sortAutor_libro(void* libroUno, void* libroDos);

int sortId_libro(void* libroUno, void* libroDos);

void* descuento_libro(void* libro);

#endif /* LIBROS_H_ */
