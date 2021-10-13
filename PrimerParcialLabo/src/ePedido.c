/*
 * ePedido.c
 *
 *  Created on: 9 oct. 2021
 *      Author: user
 */

#include "ePedido.h"


									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void ePedido_Inicializar(ePedido vector[],int tam)
{
	int i;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			vector[i].cantidadKilosTotales = 0;
			vector[i].HPPE = 0;
			vector[i].LDPE = 0;
			vector[i].PP = 0;
			vector[i].restoDesechados = 0;
			vector[i].isEmpty = LIBRE;
		}
	}
}

int ePedido_ObtenerIndexLibre(ePedido vector[],int tam)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int ePedido_BuscarPorID(ePedido vector[],int tam,int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idPedido == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void ePedido_MostrarUno(ePedido elemento)
{
	printf("|%-15d|%-30d|%-15d|%-15d|%-15d|%-15s|%-15d|\n",elemento.idPedido,elemento.cantidadKilosTotales,elemento.HPPE,elemento.LDPE,elemento.PP,elemento.estado,elemento.idClientes);
}

int ePedido_MostrarTodos(ePedido vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Pedidos");
	printf("|%-15s|%-30s|%-15s|%-15s|%-15s|%-15s|%-15s|\n\n","ID PEDIDO","TOTAL A RECOLECTAR EN KG","HDPE","LDPE","PP","ESTADO","ID CLIENTE"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				ePedido_MostrarUno(vector[i]);
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

//---ABM---//

int ePedido_CargarDatos(ePedido* elemento,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	ePedido auxiliar;
	int flagMostrados;
	int idClientes;

	retorno = 0;
	flagMostrados = 0;

	ePedido_Inicializar(&auxiliar, 1);

	if(elemento != NULL && vectorClientes != NULL && tamClientes > 0)
	{
		if(eClientes_MostrarTodos(vectorClientes, tamClientes)==1)
		{
			flagMostrados = 1;
		}

		if(flagMostrados == 1)
		{
			if(utn_getInt(&idClientes, "\nIngrese un ID de Cliente para asignar: \n", "¡ERROR!\n", 0, 3000000, 0)==0)
			{
				while(eClientes_BuscarPorID(vectorClientes, tamClientes, idClientes)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idClientes, "\nIngrese un ID de Cliente para asignar: \n", "¡ERROR!\n", 0, 3000000, 0);
				}
				auxiliar.idClientes = idClientes;

				if(utn_getInt(&auxiliar.cantidadKilosTotales, "\nIngrese la cantidad de Kilos que se deberan recolectar: \n", "¡ERROR!\n", 0, 9999999, 3)==0)
				{
					retorno = 1;
					strcpy(auxiliar.estado,"PENDIENTE");
					*elemento = auxiliar;
				}
			}
		}
	}

	return retorno;
}

int ePedido_ModificarUno(ePedido elementoParaModificar,ePedido* elementoModificado)
{
	int retorno;
	/*int opciones;
	ePedido auxiliar;

	auxiliar = elementoParaModificar;*/
	retorno = 0;

	/*	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
	{
		printf("\n¿Que desea modificar?\n1. TODO EL PRODUCTO\n2. SOLO UNA CARACTERISTICA\n\n");
		if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 2, 2)==0)
		{
			switch(opciones)
			{
				case 1:
					if(utn_getTexto(auxiliar.descripcion, "Ingrese la nueva descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
					{
						printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
						if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nueva nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
						{
							printf("\n\t>>Listado Tipos\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\n\n");
							if(utn_getInt(&auxiliar.tipo, "Seleccione un nuevo tipo: \n", "¡ERROR!\n", 1, 4, 2)==0)
							{
								if(utn_getFloat(&auxiliar.precio, "Ingrese el nuevo precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
							}
						}
					}
					break;

				case 2:
					printf("\n¿Que caracteristica desea modificar?\n1. DESCRIPCION\n2. NACIONALIDAD\n3. TIPO\n4. PRECIO\n\n");
					if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 4, 1)==0)
					{
						switch (opciones)
						{
							case 1:
								if(utn_getTexto(auxiliar.descripcion, "Ingrese la nueva descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 2:
								printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
								if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nueva nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 3:
								printf("\n\t>>Listado Tipos\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\n\n");
								if(utn_getInt(&auxiliar.tipo, "Seleccione un nuevo tipo: \n", "¡ERROR!\n", 1, 4, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 4:
								if(utn_getFloat(&auxiliar.precio, "Ingrese el nuevo precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
						}
					}
					break;
			}
		}
	}*/
	return retorno;
}

int ePedido_Alta(ePedido vectorPedidos[],int tamPedidos,int* idAutoincremental,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	ePedido auxiliar;
	int index;
	int idAux;

	retorno = 0;
	index = ePedido_ObtenerIndexLibre(vectorPedidos, tamPedidos);
	idAux = *idAutoincremental+1;

	if(index != -1)
	{
		if(ePedido_CargarDatos(&auxiliar,vectorClientes,tamClientes)==1)
		{
			retorno = 1;
		}

		if(retorno == 1)
		{
			auxiliar.idPedido = idAux;

			auxiliar.isEmpty = OCUPADO;

			vectorPedidos[index] = auxiliar;

			*idAutoincremental = idAux;
		}
	}
	return retorno;
}

int ePedido_Baja(ePedido vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(ePedido_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(ePedido_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = ePedido_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int ePedido_Modificacion(ePedido vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	ePedido buffer;

	if(ePedido_MostrarTodos(vector, tam)==1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(ePedido_BuscarPorID(vector, tam, idModificacion)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0);
			}

			index = ePedido_BuscarPorID(vector, tam, idModificacion);

			if(ePedido_ModificarUno(vector[index], &buffer)==1)
			{
				if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
				{
					vector[index] = buffer;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}


int ePedido_ProcesarPedido(ePedido vector[],int tam)
{
	int retorno;
	int idParaProcesar;
	int index;
	int flagMostrados;
	ePedido buffer;

	retorno = 0;
	flagMostrados = 0;

	if(vector != NULL && tam > 0)
	{
		if(ePedido_MostrarPendientes(vector, tam)==1)
		{
			flagMostrados = 1;
		}

		if(flagMostrados == 1)
		{
			if(utn_getInt(&idParaProcesar, "\nIngrese un ID de pedido para procesar: \n", "¡ERROR!\n", 1, 3000000, 1)==0)
			{
				while(ePedido_BuscarPorID(vector, tam, idParaProcesar)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idParaProcesar, "\nIngrese un ID de pedido para procesar: \n", "¡ERROR!\n", 1, 3000000, 0);
				}

				index = ePedido_BuscarPorID(vector, tam, idParaProcesar);

				if(ePedido_ProcesarResiduos(vector[index], &buffer)==1)
				{
					strcpy(buffer.estado,"COMPLETADO");
					vector[index] = buffer;
					retorno = 1;
				}
			}
		}
	}


	return retorno;
}

int ePedido_ProcesarResiduos(ePedido elementoParaProcesar,ePedido* elementoProcesado)
{
	int retorno;
	ePedido buffer;
	int numeroParaRestar;
	int limiteResto;

	retorno = 0;
	buffer = elementoParaProcesar;
	limiteResto = buffer.cantidadKilosTotales;

	if(elementoProcesado != NULL && buffer.isEmpty == OCUPADO && strcmp(buffer.estado,"PENDIENTE")==0)
	{
		printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %d\n",limiteResto);
		if(utn_getInt(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIETILENO DE ALTA DENSIDAD (HDPE): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
		{
			buffer.HPPE = numeroParaRestar;
			limiteResto = limiteResto - numeroParaRestar;
			printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %d\n",limiteResto);
			if(utn_getInt(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIETILENO DE BAJA DENSIDAD (LDPE): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
			{
				buffer.LDPE = numeroParaRestar;
				limiteResto = limiteResto - numeroParaRestar;
				printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %d\n",limiteResto);
				if(utn_getInt(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIPROPILENO (PP): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
				{
					buffer.PP = numeroParaRestar;
					limiteResto = limiteResto - numeroParaRestar;
					printf("\n%d KG FUERON DESECHADOS\n",limiteResto);
					buffer.restoDesechados = limiteResto;
					*elementoProcesado = buffer;
					retorno = 1;
				}
			}
		}
	}


	return retorno;
}

int ePedido_MostrarPendientes(ePedido vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Pedidos");
	printf("|%-15s|%-30s|%-15s|%-15s|%-15s|%-15s|%-15s|\n\n","ID PEDIDO","TOTAL A RECOLECTAR EN KG","HDPE","LDPE","PP","ESTADO","ID CLIENTE"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO && strcmp(vector[i].estado,"PENDIENTE")==0)
			{
				ePedido_MostrarUno(vector[i]);
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
//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int ePedido_OrdenarPedidoPorCriterioFIAscendente(ePedido vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	ePedido buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idPedido > vector[i+1].idPedido) //>>>CAMBIAR EL .idPedido EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int ePedido_OrdenarPedidoPorCriterioFIDescendiente(ePedido vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	ePedido buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idPedido < vector[i+1].idPedido) //>>>CAMBIAR EL .idPedido EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int ePedido_OrdenarPedidoPorCriterioCharAscendente(ePedido vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	//ePedido buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				/*if(strcmp(vector[i].idPedido,vector[i+1].idPedido)>0) //>>>CAMBIAR EL .idPedido EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}*/
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int ePedido_OrdenarPedidoPorCriterioCharDescendente(ePedido vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	//ePedido buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				/*if(strcmp(vector[i].idPedido,vector[i+1].idPedido)<0) //>>>CAMBIAR EL .idPedido EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}*/
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int ePedido_ListadoPedidoCriterios(ePedido vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Pedido");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				ePedido_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}
