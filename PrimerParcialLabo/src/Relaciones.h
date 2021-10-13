/*
 * Relaciones.h
 *
 *  Created on: 11 oct. 2021
 *      Author: user
 */

#ifndef RELACIONES_H_
#define RELACIONES_H_

#include "ePedido.h"

int Relaciones_BajaDeClienteConPedidos(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos);

int Relaciones_ImprimirClientesConPedidosPendientes(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos);
int Relaciones_CalcularPedidosPendientesPorCliente(eClientes cliente,ePedido vectorPedidos[],int tamPedidos);

int Relaciones_ImprimirPedidosPendientes(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);

int Relaciones_ImprimirPedidosProcesados(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);

int Relaciones_InformarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);
int Relaciones_FiltrarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,int* cantidadPendientes);

int Relaciones_InformarPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);
int Relaciones_CalcularPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,float* promedio);

#endif /* RELACIONES_H_ */
