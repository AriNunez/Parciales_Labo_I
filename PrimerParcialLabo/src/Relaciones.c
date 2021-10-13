/*
 * Relaciones.c
 *
 *  Created on: 11 oct. 2021
 *      Author: user
 */

#include "Relaciones.h"

int Relaciones_BajaDeClienteConPedidos(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos)
{
	int retorno;
	int i;
	int idBaja;

	retorno = 0;

	if(eClientes_Baja(vectorClientes, tamClientes,&idBaja)==1)
	{
		for(i=0;i<tamPedidos;i++)
		{
			if((strcmp(vectorPedidos[i].estado,"COMPLETADO")==0 || strcmp(vectorPedidos[i].estado,"PENDIENTE")==0) && vectorPedidos[i].isEmpty == OCUPADO && vectorPedidos[i].idClientes == idBaja)
			{
				vectorPedidos[i].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Relaciones_ImprimirClientesConPedidosPendientes(eClientes vectorClientes[],int tamClientes,ePedido vectorPedidos[],int tamPedidos)
{
	int retorno;
	int i;
	int cantidadPedidos;

	retorno = 0;

	if(vectorClientes != NULL && tamClientes > 0 && vectorPedidos != NULL && tamPedidos > 0)
	{
		puts("\n\t>>Listado Clientes con Pedidos Pendientes");
		printf("\n\n|%-15s|%-35s|%-15s|%-35s|%-35s|\n\n","ID CLIENTE","NOMBRE DE LA EMPRESA","CUIT","DIRECCION","LOCALIDAD");
		for(i=0;i<tamClientes;i++)
		{
			if(vectorClientes[i].isEmpty == OCUPADO)
			{
				cantidadPedidos = Relaciones_CalcularPedidosPendientesPorCliente(vectorClientes[i], vectorPedidos, tamPedidos);
				eClientes_MostrarUno(vectorClientes[i]);
				printf("\n\tCANTIDAD DE PEDIDOS PENDIENTES: %d\n\n\n",cantidadPedidos);
				retorno = 1;
			}
		}




		/*puts("\n\t>>Listado Clientes con Pedidos Pendientes");
		for(i=0;i<tamClientes;i++)
		{
			if(vectorClientes[i].isEmpty == OCUPADO)
			{
				printf("\n\n|%-15s|%-35s|%-15s|%-35s|%-35s|\n\n","ID CLIENTE","NOMBRE DE LA EMPRESA","CUIT","DIRECCION","LOCALIDAD");
				eClientes_MostrarUno(vectorClientes[i]);
				printf("\n\t\t");
				printf("|%-15s|%-30s|%-15s|%-15s|%-15s|%-15s|%-15s|\n\n","ID PEDIDO","TOTAL A RECOLECTAR EN KG","HDPE","LDPE","PP","ESTADO","ID CLIENTE");

				for(j=0;j<tamPedidos;j++)
				{
					if(vectorPedidos[j].isEmpty == OCUPADO && strcmp(vectorPedidos[j].estado,"PENDIENTE")==0 && vectorClientes[i].idClientes == vectorPedidos[j].idClientes)
					{
						printf("\t\t");
						ePedido_MostrarUno(vectorPedidos[j]);
						retorno = 1;
					}
				}
			}
		}*/
	}

	return retorno;
}

int Relaciones_CalcularPedidosPendientesPorCliente(eClientes cliente,ePedido vectorPedidos[],int tamPedidos)
{
	int cantidadPedidos;
	int i;

	cantidadPedidos = 0;

	if(vectorPedidos != NULL && tamPedidos > 0)
	{
		for(i=0;i<tamPedidos;i++)
		{
			if(vectorPedidos[i].isEmpty == OCUPADO && strcmp(vectorPedidos[i].estado,"PENDIENTE")==0 && vectorPedidos[i].idClientes == cliente.idClientes)
			{
				cantidadPedidos++;
			}
		}
	}

	return cantidadPedidos;
}


int Relaciones_ImprimirPedidosPendientes(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	int i;
	int index;

	retorno = 0;

	if(vectorClientes != NULL && tamClientes > 0 && vectorPedidos != NULL && tamPedidos > 0)
	{
		puts("\n\t>>Listado Pedidos Pendientes");
		printf("|%-15s|%-35s|%-30s|\n\n","CUIT","DIRECCION","TOTAL A RECOLECTAR EN KG");
		for(i=0;i<tamPedidos;i++)
		{
			if(vectorPedidos[i].isEmpty == OCUPADO && strcmp(vectorPedidos[i].estado,"PENDIENTE")==0)
			{
				index = eClientes_BuscarPorID(vectorClientes, tamClientes, vectorPedidos[i].idClientes);
				printf("|%-15s|%-35s|%-30d|\n",vectorClientes[index].cuit,vectorClientes[index].direccion,vectorPedidos[i].cantidadKilosTotales);
			}
		}
	}

	return retorno;
}

int Relaciones_ImprimirPedidosProcesados(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	int i;
	int index;

	retorno = 0;

	if(vectorClientes != NULL && tamClientes > 0 && vectorPedidos != NULL && tamPedidos > 0)
	{
		puts("\n\t>>Listado Pedidos Procesados");
		printf("|%-15s|%-35s|%-15s|%-15s|%-15s|\n\n","CUIT","DIRECCION","HDPE EN KG","LDPE EN KG","PP EN KG");
		for(i=0;i<tamPedidos;i++)
		{
			if(vectorPedidos[i].isEmpty == OCUPADO && strcmp(vectorPedidos[i].estado,"COMPLETADO")==0)
			{
				index = eClientes_BuscarPorID(vectorClientes, tamClientes, vectorPedidos[i].idClientes);
				printf("|%-15s|%-35s|%-15d|%-15d|%-15d|\n",vectorClientes[index].cuit,vectorClientes[index].direccion,vectorPedidos[i].HPPE,vectorPedidos[i].LDPE,vectorPedidos[i].PP);
			}
		}
	}

	return retorno;
}

int Relaciones_InformarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	int cantidadPedidos;

	retorno = 0;

	if(vectorPedidos != NULL && tamPedidos > 0 && vectorClientes != NULL && tamClientes > 0)
	{
		if(Relaciones_FiltrarPedidosPendientesPorLocalidad(vectorPedidos, tamPedidos, vectorClientes, tamClientes, &cantidadPedidos)==1)
		{
			printf("\nCANTIDAD DE PEDIDOS PENDIENTES EN ESA LOCALIDAD: %d\n",cantidadPedidos);
			retorno = 1;
		}
		else
		{
			printf("\nNO SE ENCONTRARON PEDIDOS PENDIENTES EN ESA LOCALIDAD\n");
		}
	}
	return retorno;
}


int Relaciones_FiltrarPedidosPendientesPorLocalidad(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,int* cantidadPendientes)
{
	int retorno;
	int i;
	int j;
	char bufferLocalidad[TAM_CADENACHAR];
	int contadorPendientes;

	retorno = 0;
	contadorPendientes = 0;


	if(vectorPedidos != NULL && tamPedidos > 0 && vectorClientes != NULL && tamClientes > 0)
	{
		if(utn_getTexto(bufferLocalidad, "\nIngrese una localidad: \n", "\n¡ERROR!\n", TAM_CADENACHAR, 3)==0)
		{
			for(i=0;i<tamPedidos;i++)
			{
				if(strcmp(vectorPedidos[i].estado,"PENDIENTE")==0 && vectorPedidos[i].isEmpty == OCUPADO)
				{
					for(j=0;j<tamClientes;j++)
					{
						if(vectorClientes[j].idClientes == vectorPedidos[i].idClientes && vectorClientes[j].isEmpty == OCUPADO && stricmp(bufferLocalidad,vectorClientes[j].localidad)==0)
						{
							contadorPendientes++;
						}
					}
				}
			}
		}

		if(contadorPendientes > 0)
		{
			retorno = 1;
			*cantidadPendientes = contadorPendientes;
		}
	}

	return retorno;
}

int Relaciones_InformarPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	float promedio;

	retorno = 0;

	if(vectorPedidos != NULL && tamPedidos > 0 && vectorClientes != NULL && tamClientes > 0)
	{
		if(Relaciones_CalcularPromedioPP(vectorPedidos, tamPedidos, vectorClientes, tamClientes, &promedio)==1)
		{
			printf("\nEL PROMEDIO DE KILOS DE POLIPROPILENO RECICLADO POR CLIENTE ES: %.2f\n",promedio);
		}
		else
		{
			printf("\n¡ATENCION! NO ES POSIBLE INFORMAR PROMEDIO PORQUE NO HAY PEDIDOS PROCESADOS\n");
		}
	}


	return retorno;
}


int Relaciones_CalcularPromedioPP(ePedido vectorPedidos[],int tamPedidos,eClientes vectorClientes[],int tamClientes,float* promedio)
{
	int retorno;
	int cantidadClientes;
	int acumuladorPP;
	int i;

	retorno = 0;
	cantidadClientes = eClientes_CalcularCantidadDeClientesEnAlta(vectorClientes, tamClientes);
	acumuladorPP = 0;

	if(vectorPedidos != NULL && tamPedidos > 0 && vectorClientes != NULL && tamClientes > 0)
	{
		if(cantidadClientes > 0)
		{
			for(i=0;i<tamPedidos;i++)
			{
				if(vectorPedidos[i].isEmpty == OCUPADO && strcmp(vectorPedidos[i].estado,"COMPLETADO")==0)
				{
					acumuladorPP = acumuladorPP + vectorPedidos[i].PP;
					retorno = 1;
				}
			}
			*promedio = (float)acumuladorPP / cantidadClientes;
		}
		else
		{
			printf("\nNO ES POSIBLE CALCULAR EL PROMEDIO SI NO EXISTEN CLIENTES EN ALTA\n");
		}
	}

	return retorno;
}
