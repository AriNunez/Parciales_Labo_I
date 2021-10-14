/*
 * ePedido.c
 *
 *  Created on: 9 oct. 2021
 *      Author: user
 */

#include "ePedido.h"


									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

/// \brief Inicializa el campo isEmpty todas las posiciones de un vector del tipo ePedido en LIBRE (1).
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
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

/// \brief Recorre un vector del tipo ePedido y busca el primer espacio LIBRE del vector.
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna el valor del indice el cual representa un espacio LIBRE del vector(>=0 EXITO) y -1 (ERROR) en caso de no encontrar espacio LIBRE.
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

/// \brief Recorre un vector del tipo ePedido buscando coincidencia entre el id buscado y los id del vector, si encuentra coincidencia devuelve el indice que representa la posicion donde se encuentra en el vector
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \param id Dato del tipo int que representa el id buscado.
/// \return Retorna el valor del indice que representa la posicion en el vector del id buscado(>=0 EXITO) y -1 (ERROR) en caso de no encontrar el id buscado.
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

/// \brief Recibe un elemento del tipo ePedido e imprime los datos que contiene.
/// \param elemento Dato del tipo ePedido.
void ePedido_MostrarUno(ePedido elemento)
{
	printf("|%-15d|%-30.2f|%-15.2f|%-15.2f|%-15.2f|%-15s|%-15d|\n",elemento.idPedido,elemento.cantidadKilosTotales,elemento.HPPE,elemento.LDPE,elemento.PP,elemento.estado,elemento.idClientes);
}

/// \brief Recibe un vector del tipo ePedido, lo recorre e imprime los datos que corresponden a cada posicion del vector si el campo isEmpty se encuentra en OCUPADO (0).
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de poder imprimir 1 o mas elementos del vector y 0 (ERROR) en caso de no poder imprimir ningun elemento.
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

/// \brief Recibe un vector del tipo ePedido, lo recorre e imprime los datos que corresponden a cada posicion del vector si el campo estado se encuentra en PENDIENTE.
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de poder imprimir 1 o mas elementos del vector y 0 (ERROR) en caso de no poder imprimir ningun elemento.
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

//---ABM---//

/// \brief Muestra una lista de clientes y pide seleccionar uno, luego realiza la carga de datos en una variable auxiliar, despues de verificar que la carga sea correcta, devuelve los datos cargador por referencia.
/// \param elemento Puntero a un dato del tipo ePedido.
/// \param vectorClientes Vector del tipo eClientes.
/// \param tamClientes Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de que la carga haya sido correcta y 0 (ERROR) en caso de que la carga haya sido erronea.
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
			if(utn_getInt(&idClientes, "\nIngrese un ID de Cliente para asignar: \n", "¡ERROR!\n", 0, 3000000, 5)==0)
			{
				while(eClientes_BuscarPorID(vectorClientes, tamClientes, idClientes)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idClientes, "\nIngrese un ID de Cliente para asignar: \n", "¡ERROR!\n", 0, 3000000, 5);
				}
				auxiliar.idClientes = idClientes;

				if(utn_getFloat(&auxiliar.cantidadKilosTotales, "\nIngrese la cantidad de Kilos que se deberan recolectar: \n", "¡ERROR!\n", 0, 9999999, 3)==0)
				{
					strcpy(auxiliar.estado,"PENDIENTE");
					*elemento = auxiliar;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

/// \brief Recibe el elemento del vector del tipo ePedido que se quiere modificar, realiza una nueva carga de datos y en caso de ser correcta, devuelve los datos modificados por referencia.
/// \param elementoParaModificar Dato del tipo ePedido.
/// \param elementoModificado Puntero a un dato del tipo ePedido
/// \return Retorna 1 (EXITO) en caso de que la modificacion haya sido correcta y 0 (ERROR) en caso de que la modificacion haya sido erronea.
int ePedido_ModificarUno(ePedido elementoParaModificar,ePedido* elementoModificado)
{
	int retorno;
	ePedido auxiliar;

	auxiliar = elementoParaModificar;
	retorno = 0;

	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
	{
		if(strcmp(auxiliar.estado,"PENDIENTE")==0)
		{
			if(utn_getFloat(&auxiliar.cantidadKilosTotales, "\nIngrese la nueva cantidad de Kilos que se deberan recolectar: \n", "¡ERROR!\n", 0, 9999999, 3)==0)
			{
				*elementoModificado = auxiliar;
				retorno = 1;
			}
		}

	}
	return retorno;
}

/// \brief Recibe un vector del tipo ePedido y su tamanio, busca un espacio libre en el vector y realiza la carga de datos necesaria para dar el ALTA luego de verificar que sea correcta. Por ultimo, devuelve el idAutoincremental aumentado.
/// \param vectorPedidos Vector del tipo ePedido.
/// \param tamPedidos Dato de tipo int que reperesenta la cantidad de posiciones del vectorPedidos.
/// \param idAutoincremental Puntero a un dato del tipo int que representa un idAutoincremental.
/// \param vectorClientes Vector del tipo eClientes.
/// \param tamClientes Dato de tipo int que reperesenta la cantidad de posiciones del vectorClientes.
/// \return Retorna 1 (EXITO) en caso de que el ALTA haya sido correcta y 0 (ERROR) en caso de que el ALTA haya sido erronea.
int ePedido_Alta(ePedido vectorPedidos[],int tamPedidos,int* idAutoincremental,eClientes vectorClientes[],int tamClientes)
{
	int retorno;
	ePedido auxiliar;
	int index;
	int idAux;

	retorno = 0;

	if(vectorPedidos != NULL && tamPedidos > 0 && idAutoincremental != NULL && vectorClientes != NULL && tamClientes > 0)
	{
		idAux = *idAutoincremental+1;
		index = ePedido_ObtenerIndexLibre(vectorPedidos, tamPedidos);

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
	}
	return retorno;
}

/// \brief Recibe un vector del tipo ePedido y su tamanio, muestra los pedidos en ALTA y pide seleccionar uno, si se confirma se dara de baja el pedido seleccionado.
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de que la BAJA haya sido correcta y 0 (ERROR) en caso de que la BAJA haya sido erronea.
int ePedido_Baja(ePedido vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(vector != NULL && tam > 0)
	{
		if(ePedido_MostrarTodos(vector, tam) == 1)
		{
			flagMostrados = 1;
		}

		if(flagMostrados == 1)
		{
			if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 5)==0)
			{
				while(ePedido_BuscarPorID(vector, tam, idBaja)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 5);
				}
			}

			index = ePedido_BuscarPorID(vector, tam, idBaja);

			if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
			{
				vector[index].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}

/// \brief Recibe un vector del tipo ePedido y su tamanio, muestra los pedidos en ALTA y pide seleccionar uno para poder modificarlo,
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de que la MODIFICACION haya sido correcta y 0 (ERROR) en caso de que la MODIFICACION haya sido erronea.
int ePedido_Modificacion(ePedido vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	ePedido buffer;

	if(vector != NULL && tam > 0)
	{
		if(ePedido_MostrarTodos(vector, tam)==1)
		{
			flagMostrados = 1;
		}

		if(flagMostrados == 1)
		{
			if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 5)==0)
			{
				while(ePedido_BuscarPorID(vector, tam, idModificacion)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 5);
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
	}
	return retorno;
}

/// \brief Recibe un vector del tipo ePedido y su tamanio, muestra los pedidos en PENDIENTE y pide seleccionar uno para poder procesarlo,
/// \param vector Vector del tipo ePedido.
/// \param tam Dato de tipo int que reperesenta la cantidad de posiciones del vector.
/// \return Retorna 1 (EXITO) en caso de que se haya COMPLETADO el proceso y 0 (ERROR) en caso de que no se haya COMPLETADO el proceso.
int ePedido_ProcesarPedido(ePedido vector[],int tam)
{
	int retorno;
	int idParaProcesar;
	int index;
	int flagMostrados;
	char confirmacion;
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
			if(utn_getInt(&idParaProcesar, "\nIngrese un ID de pedido para procesar: \n", "¡ERROR!\n", 1, 3000000, 5)==0)
			{
				while(ePedido_BuscarPorID(vector, tam, idParaProcesar)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idParaProcesar, "\nIngrese un ID de pedido para procesar: \n", "¡ERROR!\n", 1, 3000000, 5);
				}

				index = ePedido_BuscarPorID(vector, tam, idParaProcesar);

				if(ePedido_ProcesarResiduos(vector[index], &buffer)==1)
				{
					if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
					{
						strcpy(buffer.estado,"COMPLETADO");
						vector[index] = buffer;
						retorno = 1;
					}
				}
			}
		}
	}


	return retorno;
}

/// \brief Recibe el pedido que se quiere procesar, pide los datos obtenidos al procesar los residuos y en caso de ser correctos, devuelve el pedido procesado por referencia.
/// \param elementoParaProcesar Dato del tipo ePedido.
/// \param elementoProcesado Puntero a un dato del tipo ePedido.
/// \return Retorna 1 (EXITO) en caso de que la carga del proceso haya sido correcta y 0 (ERROR) en caso de que la carga del proceso no haya sido correcta.
int ePedido_ProcesarResiduos(ePedido elementoParaProcesar,ePedido* elementoProcesado)
{
	int retorno;
	ePedido buffer;
	float numeroParaRestar;
	float limiteResto;

	retorno = 0;
	buffer = elementoParaProcesar;
	limiteResto = buffer.cantidadKilosTotales;

	if(elementoProcesado != NULL && buffer.isEmpty == OCUPADO && strcmp(buffer.estado,"PENDIENTE")==0)
	{
		printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %.2f\n",limiteResto);
		if(utn_getFloat(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIETILENO DE ALTA DENSIDAD (HDPE): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
		{
			buffer.HPPE = numeroParaRestar;
			limiteResto = limiteResto - numeroParaRestar;
			printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %.2f\n",limiteResto);
			if(utn_getFloat(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIETILENO DE BAJA DENSIDAD (LDPE): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
			{
				buffer.LDPE = numeroParaRestar;
				limiteResto = limiteResto - numeroParaRestar;
				printf("\nCANTIDAD TOTAL DE KILOS DE RESIDUOS RESTANTES: %.2f\n",limiteResto);
				if(utn_getFloat(&numeroParaRestar, "\nIngrese la cantidad recolectada de POLIPROPILENO (PP): \n", "¡ERROR!\n", 0, limiteResto, 3)==0)
				{
					buffer.PP = numeroParaRestar;
					limiteResto = limiteResto - numeroParaRestar;
					printf("\n%.2f KG FUERON DESECHADOS\n",limiteResto);
					buffer.restoDesechados = limiteResto;
					*elementoProcesado = buffer;
					retorno = 1;
				}
			}
		}
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
