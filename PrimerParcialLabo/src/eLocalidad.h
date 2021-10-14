/*
 * eLocalidad.h
 *
 *  Created on: 14 oct. 2021
 *      Author: user
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define TAM_CADENACHAR 30

//---ESTRUCTURA---//
typedef struct {
	int idLocalidad;
	char descripcion[TAM_CADENACHAR];
	int isEmpty;
}eLocalidad;

void eLocalidad_MostrarUno(eLocalidad elemento);
int eLocalidad_MostrarTodos(eLocalidad vector[],int tam);

#endif /* ELOCALIDAD_H_ */
