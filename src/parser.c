#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* listaLibros)
{
	int retorno=-1;
	char bufferDatos[5][1028];
	int cantidadDatos;
	eLibro* auxLibro;

	if(pFile!=NULL && listaLibros!=NULL)
	{
		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);

			if(cantidadDatos==5)
			{
				auxLibro=newParametros_libro(bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
				if(auxLibro!=NULL)
				{
					ll_add(listaLibros, auxLibro);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* auxEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			auxEmpleado=employee_new();
			if(fread(auxEmpleado, sizeof(Employee), 1, pFile)!=0)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				retorno=0;
			}
		}
	}

    return retorno;
}
*/
