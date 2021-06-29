/*
 ============================================================================
 Name        : segundoParcial_Laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "UTN.h"
#include "Controller.h"
#include "Libros.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu=0;
	int flagArchivo=0;
	int menuInforme;
	LinkedList* listaLibros=ll_newLinkedList();

	do
	{
		utn_getNumero(&menu, "Parcial Nro 2 - Laboratorio\n\n"
				"1.Cargar archivo de libros\n"
				"2.Dar de alta nuevo libro\n"
				"3.Modificar libro\n"
				"4.Informar\n"
				"5.Dar de baja libro\n"
				"6.Guardar\n"
				"0.Salir\n"
				"\nSeleccione una opcion: ", "Erro, opcion incorrecta\n", 0, 6, 2);
		system("cls");
		switch(menu)
		{
			case 1:
				if(!controller_loadFromText("../Datos.csv", listaLibros))
				{
					printf("Archivo cargado con exito!\n");
					flagArchivo=1;
				}
				else
				{
					printf("No se pudo cargar el archivo!\n");
				}
				system("pause");
			break;

			case 2:
				if(flagArchivo==1)
				{
					if(controller_addLibro(listaLibros)!=-1)
					{
						printf("Libro cargado con exito!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo!\n");
				}
				system("pause");
			break;

			case 3:
				if(flagArchivo==1)
				{
					if(controller_editLibro(listaLibros)!=-1)
					{
						printf("Libro modificado con exito!\n");
					}
					else
					{
						printf("Se cancelo la modificacion del libro!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo!\n");
				}
				system("pause");
			break;

			case 4:
				if(flagArchivo==1)
				{
					do
					{
						utn_getNumero(&menuInforme, "-- INFORME --\n"
								"\n1.Lista de libros original con descuento\n"
								"2.Lista de libros ordenados por autores\n"
								"\n0.Voler al menu principal\n"
								"\nSeleccione una opcion: ", "", 0, 2, 2);
						system("cls");
						switch(menuInforme)
						{
							case 1:
								//controller_librosDefault(listaLibros);
								if(controller_ListLibro(listaLibros)!=-1)
								{
									printf("Lista de libros original con descuento en el sistema!\n");
									system("pause");
								}
							break;

							case 2:
								if(controller_sortLibro(listaLibros)!=-1)
								{
									controller_ListLibro(listaLibros);
									printf("Lista de libros ordenados de manera ascendente en el sistema!\n");
									system("pause");
								}
								controller_librosDefault(listaLibros);
							break;
						}
						system("cls");
					}while(menuInforme!=0);
				}
				else
				{
					printf("Primero cargue el archivo!\n");
					system("pause");
				}
			break;

			case 5:
				if(flagArchivo==1)
				{
					if(controller_removeLibro(listaLibros)!=-1)
					{
						printf("Libro dado de baja con exito!\n");
					}
					else
					{
						printf("Se cancelo la baja del libro!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo!\n");
				}
				system("pause");
			break;

			case 6:
				if(flagArchivo==1)
				{
					if(controller_saveAsText("../mapeado.csv" , listaLibros)!=-1)
					{
						printf("Archivo guardado con exito!\n");
					}
					else
					{
						printf("No se pudo guardar el archivo!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo!\n");
				}
				system("pause");
			break;

			case 0:
				utn_getNumero(&menu, "Desea salir del programa?\n"
						"ATENCION! Todos los progresos no guardados se perderan\n"
						"\n0.Si\n"
						"1.No\n"
						"\nSeleccione una opcion: ", "Error, opcion incorrecta", 0, 1, 2);
			break;
		}
		system("cls");
	}while(menu!=0);

	return EXIT_SUCCESS;
}
