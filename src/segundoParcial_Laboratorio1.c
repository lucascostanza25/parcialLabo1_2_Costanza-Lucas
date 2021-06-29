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
	int menuGuardado;
	int opcionGuardado;
	LinkedList* listaLibros=ll_newLinkedList();
	LinkedList* listaLibrosBackUp;

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
				"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 6, 2);
		system("cls");
		switch(menu)
		{
			case 1:
				if(!controller_loadFromText("../Datos.csv", listaLibros))
				{
					listaLibrosBackUp=ll_clone(listaLibros);
					controller_saveAsText("../Datos_backup.csv", listaLibrosBackUp);
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
						listaLibrosBackUp=ll_clone(listaLibros);
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
								if(controller_ListLibro(listaLibros)!=-1)
								{
									printf("Lista de libros original con descuento en el sistema!\n");
									system("pause");
								}
							break;

							case 2:
								if(controller_sortLibro(listaLibrosBackUp)!=-1)
								{
									controller_ListLibro(listaLibrosBackUp);
									printf("Lista de libros ordenados de manera ascendente en el sistema!\n");
									system("pause");
								}
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
						listaLibrosBackUp=ll_clone(listaLibros);
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
					do
					{
						utn_getNumero(&menuGuardado, "-- GUARDAR --\n"
							"\n1.Lista original\n"
							"2.Lista backup\n"
							"3.Lista mapeada\n"
							"\n0.Volver al menu principal\n"
							"\nSeleccione una opcion: ", "", 0, 3, 2);
						system("cls");
						switch(menuGuardado)
						{
							case 1:
								utn_getNumero(&opcionGuardado, "Seguro que desea sobreescribir la lista original?\n"
																"\n0.Si\n"
																"1.No\n"
																"\nSeleccione una opcio: ", "", 0, 1, 2);
								system("cls");
								if(opcionGuardado==0)
								{
									if(controller_saveAsText("../Datos.csv", listaLibros)!=-1)
									{
										printf("Archivo original guardado con exito!\n");
										system("pause");
									}
									else
									{
										printf("Hubo un ERROR al guardar el archivo!\n");
										system("pause");
									}
								}
								else
								{
									printf("Se cancelo el guardado de la lista original!\n");
									system("pause");
								}
							break;

							case 2:
								utn_getNumero(&opcionGuardado, "Seguro que desea sobreescribir la lista backup?\n"
																"\n0.Si\n"
																"1.No\n"
																"\nSeleccione una opcio: ", "", 0, 1, 2);
								system("cls");
								if(opcionGuardado==0)
								{
									if(controller_saveAsText("../Datos_backup.csv", listaLibrosBackUp)!=-1)
									{
										printf("Lista backup guardada con exito!\n");
										system("pause");
									}
									else
									{
										printf("Hubo un ERROR al guardar el archivo!\n");
										system("pause");
									}
								}
								else
								{
									printf("Se cancelo el guardado de la lista original!\n");
									system("pause");
								}
							break;

							case 3:
								utn_getNumero(&opcionGuardado, "Seguro que desea sobreescribir la lista mapeada?\n"
																"\n0.Si\n"
																"1.No\n"
																"\nSeleccione una opcio: ", "", 0, 1, 2);
								system("cls");
								if(opcionGuardado==0)
								{
									if(controller_saveAsText("../mapeado.csv" , listaLibrosBackUp)!=-1)
									{
										printf("Archivo guardado con exito!\n");
										system("pause");
									}
									else
									{
										printf("Hubo un ERROR al guardar el archivo!\n");
										system("pause");
									}
								}
								else
								{
									printf("Se cancelo el guardado de la lista original!\n");
									system("pause");
								}
							break;
						}
						system("cls");
					}while(menuGuardado!=0);
				}
				else
				{
					printf("Primero cargue el archivo!\n");
					system("pause");
				}
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
