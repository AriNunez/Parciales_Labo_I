/*
 * eClientes.h
 *
 *  Created on: 9 oct. 2021
 *      Author: user
 */

#ifndef ECLIENTES_H_
#define ECLIENTES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINE---//
#define LIBRE 1
#define OCUPADO 0
#define TAM_CADENACHAR 30

//---ESTRUCTURA---//
typedef struct {
	int idClientes;
	char nombreEmpresa[TAM_CADENACHAR];
	char cuit[TAM_CADENACHAR];
	char direccion[TAM_CADENACHAR];
	char localidad[TAM_CADENACHAR];
	int isEmpty;
}eClientes;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eClientes_Inicializar(eClientes vector[],int tam);
int eClientes_ObtenerIndexLibre(eClientes vector[],int tam);
int eClientes_BuscarPorID(eClientes vector[],int tam,int id);
void eClientes_MostrarUno(eClientes elemento);
int eClientes_MostrarTodos(eClientes vector[],int tam);
int eClientes_CalcularCantidadDeClientesEnAlta(eClientes vector[],int tam);

//---ABM---//

int eClientes_CargarDatos(eClientes* elemento);
int eClientes_ModificarUno(eClientes elementoParaModificar,eClientes* elementoModificado);
int eClientes_Alta(eClientes vector[],int tam,int* idAutoincremental);
int eClientes_Baja(eClientes vectorClientes[],int tamClientes,int* idParaBaja);
int eClientes_Modificacion(eClientes vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eClientes_OrdenarClientesPorCriterioFIAscendente(eClientes vector[], int tam);
int eClientes_OrdenarClientesPorCriterioFIDescendiente(eClientes vector[], int tam);
int eClientes_OrdenarClientesPorCriterioCharAscendente(eClientes vector[], int tam);
int eClientes_OrdenarClientesPorCriterioCharDescendente(eClientes vector[], int tam);

#endif /* ECLIENTES_H_ */
