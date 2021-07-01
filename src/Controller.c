/*
 * Controller.c
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "UTN.h"

int controller_loadFromText(char* path , LinkedList* listaLibros)
{
	int retorno=-1;
	FILE* pArchivo=fopen(path, "r");

	if(path!=NULL && listaLibros!=NULL)
	{
		if(pArchivo!=NULL)
		{
			parser_LibroFromText(pArchivo, listaLibros);
			retorno=0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
/*
int controller_loadFromBinary(char* path , LinkedList* listaLibros)
{
	int retorno=-1;
	FILE* pArchivo=fopen(path, "rb");

	if(path!=NULL && listaLibros!=NULL)
	{
		if(pArchivo!=NULL)
		{
			parser_EmployeeFromBinary(pArchivo, listaLibros);
			retorno=0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
*/
int controller_addLibro(LinkedList* listaLibros)
{
	int retorno=-1;
	int auxId;
	char auxTitulo[120];
	char auxAutor[100];
	float auxPrecio;
	char auxEditorial[100];
	eLibro* nuevoLibro;

	if(listaLibros!=NULL)
	{
		nuevoLibro=new_libro();
		idAutomatico_libro(listaLibros, &auxId);
		utn_getString(auxTitulo, "Ingrese el titulo del libro: ", "Error, se excedio de los caracteres permitidos!\n", 120, 2);
		utn_getString(auxAutor, "Ingrese el nombre del autor: ", "Error, se excedio de los caracteres permitidos!\n", 100, 2);
		utn_getFlotante(&auxPrecio, "Ingrese el precio del libro (de $1 a $5000): ", "Error, precio fuera de rango!\n", 1, 5000, 2);
		utn_getString(auxEditorial, "Ingrese el nombre de la editorial: ", "Error, se excedio de los caracteres permitidos!\n", 100, 2);

		setId_libro(nuevoLibro, auxId);
		setTitulo_libro(nuevoLibro, auxTitulo);
		setAutor_libro(nuevoLibro, auxAutor);
		setPrecio_libro(nuevoLibro, auxPrecio);
		setEditorial_libro(nuevoLibro, auxEditorial);

		ll_add(listaLibros, nuevoLibro);

		retorno=0;
	}

	return retorno;
}

int controller_editLibro(LinkedList* listaLibros)
{
	int retorno=-1;
	int menuModificacion;
	int indexId;
	int idIngresado;
	char nuevoTitulo[120];
	char nuevoAutor[100];
	char nuevoEditorial[100];
	float nuevoPrecio;
	eLibro* libroEditado;

	if(listaLibros!=NULL)
	{
		do
		{
			printf("-- EDITAR --\n"
					"Lista de libros disponibles para editar\n");
			controller_ListLibro(listaLibros);
			utn_getNumero(&idIngresado, "Ingrese el ID del libro a editar: ", "", 1, ll_len(listaLibros), 2);
			indexId=buscarId_libro(listaLibros, idIngresado);
			system("cls");
			if(indexId!=-1)
			{
				libroEditado=(eLibro*)ll_get(listaLibros, idIngresado);
				printf("Libro seleccionado\n");
				imprimirUn_libro(libroEditado);
				printf("\nSeleccione que desea editar\n"
						"1.Titulo\n"
						"2.Autor\n"
						"3.Precio\n"
						"4.Editorial\n"
						"0.Volver al menu principal\n");
				utn_getNumero(&menuModificacion, "\nSeleccione una opcion: ", "Error, opcion invalida\n", 0, 4, 4);
				system("cls");
				switch(menuModificacion)
				{
					case 1:
						utn_getString(nuevoTitulo, "Ingrese el nuevo titulo del libro: ", "Error, se excedio de los caracteres permitidos\n", 120, 2);
						setTitulo_libro(libroEditado, nuevoTitulo);
						retorno=0;
					break;

					case 2:
						utn_getString(nuevoAutor, "Ingrese el nuevo autor del libro: ", "Error, se excedio de los caracteres permitidos\n", 100, 2);
						setAutor_libro(libroEditado, nuevoAutor);
						retorno=0;
					break;

					case 3:
						utn_getFlotante(&nuevoPrecio, "Ingrese el nuevo precio del libro (de $1 a $5000): ", "Error, precio fuera de rango\n", 1, 5000, 2);
						setPrecio_libro(libroEditado, nuevoPrecio);
						retorno=0;
					break;

					case 4:
						utn_getString(nuevoEditorial, "Ingrese la nueva editorial del libro: ", "Error, se excedio de los caracteres permitidos\n", 100, 2);
						setEditorial_libro(libroEditado, nuevoEditorial);
						retorno=0;
					break;

					case 0:
						utn_getNumero(&menuModificacion, "Desea volver al menu principal?\n\n0.Si\n1.No\n\nSeleccione una opcion: ", "", 0, 1, 2);
					break;
				}
			}
			system("cls");
		}while(menuModificacion!=0);
	}


	return retorno;
}

int controller_removeLibro(LinkedList* listaLibros)
{
	int retorno=-1;
	int idIngresado;
	int indexId;
	int menuBorrado;
	eLibro* auxLibro;

	if(listaLibros!=NULL)
	{
		printf("-- DAR DE BAJA --\n"
				"Lista de libros disponibles para dar de baja\n");
		controller_ListLibro(listaLibros);
		utn_getNumero(&idIngresado, "Ingrese el ID del libro a dar de baja: ", "", 1, ll_len(listaLibros), 4);
		indexId=buscarId_libro(listaLibros, idIngresado);
		system("cls");
		if(indexId!=-1)
		{
			printf("Libro selecionado para dar de baja\n\n");
			auxLibro=(eLibro*)ll_get(listaLibros, idIngresado);
			imprimirUn_libro(auxLibro);
			utn_getNumero(&menuBorrado, "\n\nDesea dar de baja el libro selecionado?\n\n1.Si\n0.No\n\nSeleccione una opcion: ", "", 0, 1, 2);
			system("cls");
			if(menuBorrado==1)
			{
				if(ll_remove(listaLibros, indexId)!=-1)
				{
					retorno=0;
				}
			}
		}
	}


	return retorno;
}

int controller_ListLibro(LinkedList* listaLibros)
{
	int retorno=-1;
	int i;
	int auxId;
	char auxTitulo[120];
	char auxAutor[100];
	float auxPrecio;
	char auxEditorial[100];
	eLibro* auxLibro;

	if(listaLibros!=NULL)
	{
		ll_map(listaLibros, descuento_libro);
		printf("ID  | TITULO                                            | AUTOR            | PRECIO    | EDITORIAL \n");

		for(i=0; i<ll_len(listaLibros); i++)
		{
			auxLibro=ll_get(listaLibros, i);
			getId_libro(auxLibro, &auxId);
			getTitulo_libro(auxLibro, auxTitulo);
			getAutor_libro(auxLibro, auxAutor);
			getPrecio_libro(auxLibro, &auxPrecio);
			getEditorial_libro(auxLibro, auxEditorial);

			printf("%-5d %-50s %-18s %-12.2f %-18s\n", auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial);
		}
		retorno=0;
	}

	return retorno;
}

int controller_sortLibro(LinkedList* listaLibros)
{
	int retorno=-1;

	if(listaLibros!=NULL)
	{
		ll_sort(listaLibros, sortAutor_libro, 0);
		retorno=0;
	}

	return retorno;
}

int controller_librosDefault(LinkedList* listaLibros)
{
	int retorno=-1;

	if(listaLibros!=NULL)
	{
		ll_sort(listaLibros, sortId_libro, 1);
		retorno=0;
	}

	return retorno;
}

int controller_saveAsText(char* path , LinkedList* listaLibros)
{
	int retorno=-1;
	int i;
	FILE* pArchivo;
	eLibro* libroGuardado;

	if(listaLibros!=NULL && path!=NULL)
	{
		pArchivo=fopen(path, "w");
		if(pArchivo!=NULL)
		{
			//ll_map(listaLibros, descuento_libro);
			//fprintf(pArchivo, "id,titulo,autor,precio,editorialId\n");
			for(i=0; i<ll_len(listaLibros); i++)
			{
				libroGuardado=(eLibro*)ll_get(listaLibros, i);
				fprintf(pArchivo, "%d, %s, %s, %f, %s\n", libroGuardado->id, libroGuardado->titulo, libroGuardado->autor, libroGuardado->precio, libroGuardado->editorial);
				retorno=0;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}
