/*
 * eClientes.c
 *
 *  Created on: 9 oct. 2021
 *      Author: user
 */

#include "eClientes.h"




									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eClientes_Inicializar(eClientes vector[],int tam)
{
	int i;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			vector[i].isEmpty = LIBRE;
		}
	}
}

int eClientes_ObtenerIndexLibre(eClientes vector[],int tam)
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

int eClientes_BuscarPorID(eClientes vector[],int tam,int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idClientes == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eClientes_MostrarUno(eClientes elemento)
{
	printf("|%-15d|%-35s|%-15s|%-35s|%-35s|\n",elemento.idClientes,elemento.nombreEmpresa,elemento.cuit,elemento.direccion,elemento.localidad);
}

int eClientes_MostrarTodos(eClientes vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Clientes");
	printf("|%-15s|%-35s|%-15s|%-35s|%-35s|\n\n","ID CLIENTE","NOMBRE DE LA EMPRESA","CUIT","DIRECCION","LOCALIDAD"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eClientes_MostrarUno(vector[i]);
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

int eClientes_CalcularCantidadDeClientesEnAlta(eClientes vector[],int tam)
{
	int i;
	int cantidadClientes;

	cantidadClientes = 0;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				cantidadClientes++;
			}
		}
	}

	return cantidadClientes;
}

//---ABM---//

int eClientes_CargarDatos(eClientes* elemento)
{
	int retorno;
	eClientes auxiliar;

	retorno = 0;

	if(elemento != NULL)
	{
		if(utn_getTexto(auxiliar.nombreEmpresa, "\nIngrese el nombre de la empresa: \n", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
		{
			if(utn_getCuitCuil(auxiliar.cuit, "\nIngrese el CUIT de la empresa (NO SE ADMITEN '-'):", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
			{
				if(utn_getTexto(auxiliar.direccion, "\nIngrese la direccion de la empresa: \n", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
				{
					if(utn_getTexto(auxiliar.localidad, "\nIngrese la localidad donde se encuentra la empresa: \n", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
					{
						retorno = 1;
						*elemento = auxiliar;
					}
				}
			}
		}
	}
	return retorno;
}

int eClientes_ModificarUno(eClientes elementoParaModificar,eClientes* elementoModificado)
{
	int retorno;
	eClientes auxiliar;

	auxiliar = elementoParaModificar;
	retorno = 0;

	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
	{
		if(utn_getTexto(auxiliar.direccion, "\nIngrese la nueva direccion de la empresa: \n", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
		{
			if(utn_getTexto(auxiliar.localidad, "\nIngrese la nueva localidad donde se encuentra la empresa: \n", "¡ERROR!\n", TAM_CADENACHAR, 3)==0)
			{
				retorno = 1;
				*elementoModificado = auxiliar;
			}
		}
	}
	return retorno;
}

int eClientes_Alta(eClientes vector[],int tam,int* idAutoincremental)
{
	int retorno;
	eClientes auxiliar;
	int index;
	int idAux;

	retorno = 0;
	index = eClientes_ObtenerIndexLibre(vector, tam);
	idAux = *idAutoincremental+1;

	if(index != -1)
	{
		if(eClientes_CargarDatos(&auxiliar)==1)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

		if(retorno == 1)
		{
			auxiliar.idClientes = idAux;

			auxiliar.isEmpty = OCUPADO;

			vector[index] = auxiliar;

			*idAutoincremental = idAux;
		}
	}
	return retorno;
}

int eClientes_Baja(eClientes vectorClientes[],int tamClientes,int* idParaBaja)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eClientes_MostrarTodos(vectorClientes, tamClientes) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "\nIngrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eClientes_BuscarPorID(vectorClientes, tamClientes, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "\nIngrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eClientes_BuscarPorID(vectorClientes, tamClientes, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "\n¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vectorClientes[index].isEmpty = LIBRE;
			retorno = 1;
			*idParaBaja = idBaja;
		}
	}
	return retorno;
}

int eClientes_Modificacion(eClientes vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	eClientes buffer;

	if(eClientes_MostrarTodos(vector, tam)==1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eClientes_BuscarPorID(vector, tam, idModificacion)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0);
			}

			index = eClientes_BuscarPorID(vector, tam, idModificacion);

			if(eClientes_ModificarUno(vector[index], &buffer)==1)
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

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int eClientes_OrdenarClientesPorCriterioFIAscendente(eClientes vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eClientes buffer;
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
 				if(vector[i].idClientes > vector[i+1].idClientes) //>>>CAMBIAR EL .idClientes EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eClientes_OrdenarClientesPorCriterioFIDescendiente(eClientes vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eClientes buffer;
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
 				if(vector[i].idClientes < vector[i+1].idClientes) //>>>CAMBIAR EL .idClientes EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eClientes_OrdenarClientesPorCriterioCharAscendente(eClientes vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	//eClientes buffer;
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
 				/*if(strcmp(vector[i].idClientes,vector[i+1].idClientes)>0) //>>>CAMBIAR EL .idClientes EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eClientes_OrdenarClientesPorCriterioCharDescendente(eClientes vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	//eClientes buffer;
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
 				/*if(strcmp(vector[i].idClientes,vector[i+1].idClientes)<0) //>>>CAMBIAR EL .idClientes EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eClientes_ListadoClientesCriterios(eClientes vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Clientes");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				eClientes_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}
