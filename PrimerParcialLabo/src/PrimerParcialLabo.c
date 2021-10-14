/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Relaciones.h"

#define QTY_CLIENTES 3
#define QTY_PEDIDOS 5
#define QTY_LOCALIDADES 2

int main(void)
{
	setbuf(stdout,NULL);

	eClientes clientes[QTY_CLIENTES];//={{1,"TOYOTA S.A.","38124567890","AVENIDA MITRE 555","AVELLANEDA",OCUPADO},{2,"FORD S.A.","38126539870","AVENIDA LIBERTADOR 666","CABA",OCUPADO},{3,"INODOROS VOLADORES S.A.","38147531590","9 DE JULIO 1200","LANUS",OCUPADO}};
	ePedido pedidos[QTY_PEDIDOS];//={{1001,1200,0,0,0,0,"PENDIENTE",OCUPADO,1},{1002,2000,0,0,0,0,"PENDIENTE",OCUPADO,3},{1003,350,0,0,0,0,"PENDIENTE",OCUPADO,2},{1004,500,0,0,0,0,"PENDIENTE",OCUPADO,1},{1005,120,0,0,0,0,"PENDIENTE",OCUPADO,1}};
	eLocalidad localidades[QTY_LOCALIDADES]={{201,"AVELLANEDA",OCUPADO},{202,"CABA",OCUPADO}};
	int opciones;
	int idClientes;
	int idPedidos;
	//int idLocalidad;
	int retornoAlta;
	int flagAltaClientes;

	idClientes = 0;
	idPedidos = 1000;
	//idLocalidad = 200;
	flagAltaClientes = 0;

	eClientes_Inicializar(clientes, QTY_CLIENTES);
	ePedido_Inicializar(pedidos, QTY_PEDIDOS);



	do
	{
		puts("\n1. ALTA DE CLIENTE\n2. MODIFICAR DATOS DE CLIENTE\n3. BAJA DE CLIENTE\n4. CREAR PEDIDO DE RECOLECCION\n5. PROCESAR RESIDUOS\n"
				"6. IMPRIMIR CLIENTES\n7. IMPRIMIR PEDIDOS PENDIENTES\n8. IMPRIMIR PEDIDOS PROCESADOS\n9. INFORMAR PEDIDOS PENDIENTES POR LOCALIDAD SELECCIONADA\n"
				"10. INFORMAR PROMEDIO POR CLIENTE DE POLIPROPILENO RECICLADO\n11. CLIENTE CON MAS PEDIDOS PENDIENTES\n0. SALIR\n");
		if(utn_getInt(&opciones, "Ingrese una opcion: ", "\n¡ERROR!\n", 0, 11, 3)==0)
		{
			switch(opciones)
			{
				case 1:
					retornoAlta = eClientes_Alta(clientes, QTY_CLIENTES, &idClientes,localidades,QTY_LOCALIDADES);
					if(retornoAlta==1)
					{
						printf("\nCliente DADO DE ALTA EXITOSAMENTE con ID %d\n",idClientes);
						flagAltaClientes = 1;
					}
					else
					{
						if(retornoAlta==0)
						{
							printf("\n¡ERROR! NO HAY MAS ESPACIO PARA ALMACENAR Cliente\n");
						}
						else
						{
							printf("\n¡ERROR EN LA CARGA DE DATOS DE Cliente!\n");
						}
					}
					break;

				case 2:
					if(eClientes_Modificacion(clientes, QTY_CLIENTES)==1)
					{
						printf("\nMODIFICACION DE Cliente EXITOSA\n");
						eClientes_MostrarTodos(clientes, QTY_CLIENTES);
					}
					else
					{
						printf("\nMODIFICACION DE Cliente CANCELADA\n");
					}
					break;

				case 3:
					if(Relaciones_BajaDeClienteConPedidos(clientes, QTY_CLIENTES, pedidos, QTY_PEDIDOS)==1)
					{
						printf("\nBAJA DE Cliente EXITOSA\n");
						if(eClientes_MostrarTodos(clientes, QTY_CLIENTES)==0)
						{
							flagAltaClientes = 0;
						}
					}
					else
					{
						printf("\nBAJA DE Cliente CANCELADA\n");
					}
					break;

				case 4:
					if(flagAltaClientes == 1)
					{
						if(ePedido_Alta(pedidos, QTY_PEDIDOS, &idPedidos, clientes, QTY_CLIENTES)==1)
						{
							printf("\nCREACION DE Pedido DE RECOLECCION EXITOSA\n");
						}
						else
						{
							printf("\nCREACION DE Pedido DE RECOLECCION CANCELADA\n");
						}
					}
					else
					{
						printf("\n¡ATENCION! PRIMERO SE DEBEN DAR DE ALTA Clientes\n");
					}
					break;

				case 5:
					if(ePedido_ProcesarPedido(pedidos, QTY_PEDIDOS)==1)
					{
						printf("\nPROCESAMIENTO DE RESIDUOS EXITOSO\n");
					}
					else
					{
						printf("\nPROCESAMIENTO DE RESIDUOS CANCELADA\n");
					}
					break;

				case 6:
					Relaciones_ImprimirClientesConPedidosPendientes(clientes, QTY_CLIENTES, pedidos, QTY_PEDIDOS);
					break;

				case 7:
					Relaciones_ImprimirPedidosPendientes(pedidos, QTY_PEDIDOS, clientes, QTY_CLIENTES);
					break;

				case 8:
					Relaciones_ImprimirPedidosProcesados(pedidos, QTY_PEDIDOS, clientes, QTY_CLIENTES);
					break;

				case 9:
					Relaciones_InformarPedidosPendientesPorLocalidad(pedidos, QTY_PEDIDOS, clientes, QTY_CLIENTES,localidades,QTY_LOCALIDADES);
					break;

				case 10:
					Relaciones_InformarPromedioPP(pedidos, QTY_PEDIDOS, clientes, QTY_CLIENTES);
					break;

				case 11:
					Relaciones_InformarClientesConMasPedidosPendientes(pedidos, QTY_PEDIDOS, clientes, QTY_CLIENTES);
					break;
				case 0:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;
			}
		}



	}while(opciones != 0);


	return EXIT_SUCCESS;
}
