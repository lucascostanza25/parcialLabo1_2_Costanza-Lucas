/*
 * Controller.h
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* listaLibros);

int controller_loadFromBinary(char* path , LinkedList* listaLibros);

int controller_addLibro(LinkedList* listaLibros);

int controller_editLibro(LinkedList* listaLibros);

int controller_removeLibro(LinkedList* listaLibros);

int controller_ListLibro(LinkedList* listaLibros);

int controller_sortLibro(LinkedList* listaLibros);

int controller_librosDefault(LinkedList* listaLibros);

int controller_saveAsText(char* path , LinkedList* listaLibros);

int controller_saveAsBinary(char* path , LinkedList* listaLibros);


#endif /* CONTROLLER_H_ */
