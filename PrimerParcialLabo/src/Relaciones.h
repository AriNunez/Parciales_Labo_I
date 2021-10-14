/*
 * Relaciones.h
 *
 *  Created on: 11 oct. 2021
 *      Author: user
 */

#ifndef RELACIONES_H_
#define RELACIONES_H_

#include "ePedido.h"

//3)
int Relaciones_BajaDeClienteConPedidos(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos);

//6)
int Relaciones_ImprimirClientesConPedidosPendientes(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos);
int Relaciones_CalcularPedidosPendientesPorCliente(eClientes cliente,ePedido vectorPedidos[],int tamPedidos);

//7)
int Relaciones_ImprimirPedidosPendientes(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);

//8)
int Relaciones_ImprimirPedidosProcesados(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);

//9)
//int Relaciones_InformarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);
int Relaciones_InformarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,eLocalidad vectorLocalidad[],int tamLocalidad);
//int Relaciones_FiltrarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,int* cantidadPendientes);
int Relaciones_FiltrarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,int* cantidadPendientes,eLocalidad vectorLocalidad[],int tamLocalidad);
//10)
int Relaciones_InformarPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);
int Relaciones_CalcularPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,float* promedio);



int Relaciones_InformarClientesConMasPedidosPendientes(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes);

#endif /* RELACIONES_H_ */
