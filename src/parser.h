/*
 * parser.h
 *
 *  Created on: 9 jun. 2021
 *      Author: Lucas
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
