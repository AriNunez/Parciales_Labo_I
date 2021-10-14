/*
 * eLocalidad.c
 *
 *  Created on: 14 oct. 2021
 *      Author: user
 */

#include "eLocalidad.h"

void eLocalidad_MostrarUno(eLocalidad elemento)
{
	printf("|%-15d|%-35s|\n",elemento.idLocalidad,elemento.descripcion);
}

int eLocalidad_MostrarTodos(eLocalidad vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Localidad");
	printf("|%-15s|%-35s|\n\n","ID LOCALIDAD","DESCRIPCION"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eLocalidad_MostrarUno(vector[i]);
				cantidad++;
			}
		}
	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}
