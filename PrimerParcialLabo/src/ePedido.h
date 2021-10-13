/*
 * ePedido.h
 *
 *  Created on: 9 oct. 2021
 *      Author: user
 */

#ifndef EPEDIDO_H_
#define EPEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eClientes.h"
#include "utn.h"

//---DEFINE---//
#define LIBRE 1
#define OCUPADO 0

//---ESTRUCTURA---//
typedef struct {
	int idPedido;
	int cantidadKilosTotales;
	int HPPE;
	int LDPE;
	int PP;
	int restoDesechados;
	char estado[10];
	int isEmpty;
	int idClientes;
}ePedido;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void ePedido_Inicializar(ePedido vector[],int tam);
int ePedido_ObtenerIndexLibre(ePedido vector[],int tam);
int ePedido_BuscarPorID(ePedido vector[],int tam,int id);
void ePedido_MostrarUno(ePedido elemento);
int ePedido_MostrarTodos(ePedido vector[],int tam);

//---ABM---//

int ePedido_CargarDatos(ePedido* elemento,eClientes vectorClientes[],int tamClientes);
int ePedido_ModificarUno(ePedido elementoParaModificar,ePedido* elementoModificado);
int ePedido_Alta(ePedido vectorPedidos[],int tamPedidos,int* idAutoincremental,eClientes vectorClientes[],int tamClientes);
int ePedido_Baja(ePedido vector[],int tam);
int ePedido_Modificacion(ePedido vector[],int tam);
int ePedido_ProcesarPedido(ePedido vector[],int tam);
int ePedido_ProcesarResiduos(ePedido elementoParaProcesar,ePedido* elementoProcesado);
int ePedido_MostrarPendientes(ePedido vector[],int tam);
//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int ePedido_OrdenarPedidoPorCriterioFIAscendente(ePedido vector[], int tam);
int ePedido_OrdenarPedidoPorCriterioFIDescendiente(ePedido vector[], int tam);
int ePedido_OrdenarPedidoPorCriterioCharAscendente(ePedido vector[], int tam);
int ePedido_OrdenarPedidoPorCriterioCharDescendente(ePedido vector[], int tam);

#endif /* EPEDIDO_H_ */
