/*
 * utn.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------PROTOTIPOS DE FUNCIONES STATIC--------------------
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets (char* cadena, int longitud);
static int getFloat(float* pResultado);
static int esNumericaConDecimal(char* cadena);
static int getString(char* pResultado,int limite);
static int getName(char* pResultado,int limite);
static int isValidName(char* nombre);

//--------------------INTEGER--------------------

/// \brief Solicita un numero entero al usuario que lee por stdin, solo admite numeros enteros que se encuentren entre el minimo y maximo.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido
/// \param mensaje mensaje Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje al usuario.
/// \param mensajeError Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje de error al usuario.
/// \param minimo Define el numero entero minimo aceptado.
/// \param maximo Define el numero entero maximo aceptado.
/// \param reintentos Define el numero de reintentos que se le brindara al usuario.
/// \return Retorna 0 (EXITO) si se obtiene el numero entero y -1/-2 (ERROR) si no pudo.
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}

/// \brief Solicita un numero entero al usuario que lee por stdin, admite cualquier numero entero.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido
/// \param mensaje Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje al usuario.
/// \param mensajeError Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje de error al usuario.
/// \param reintentos Define el numero de reintentos que se le brindara al usuario.
/// \return Retorna 0 (EXITO) si se obtiene el numero entero y -1/-2 (ERROR) si no pudo.
int utn_getIntSinLimite(int* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}

/// \brief Verifica si la cadena ingresada es numerica.
/// \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
static int getInt(int* pResultado)
{
	int retorno = -1;//int utn_getString(char* pResultado,char* mensaje,char* mensajeError,int reintento)
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);//convierte un string en caso de ser posible en un numero int
		}
	}
	return retorno;
}

/// \brief Verifica si la cadena ingresada es numerica.
/// \param cadena Cadena de caracteres a ser analizada.
/// \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es.
static int esNumerica(char* cadena)//trata de verificar si cada caracter es un numero falso 0 y verdadero 1
{
	int retorno = 1;
	int i;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

//--------------------FLOAT--------------------

/// \brief  Solicita un numero real al usuario que lee por stdin, solo admite numeros reales que se encuentren entre el minimo y maximo.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \param mensaje Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje al usuario.
/// \param mensajeError Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje de error al usuario.
/// \param minimo Define el numero entero minimo aceptado.
/// \param maximo Define el numero entero maximo aceptado.
/// \param reintentos Define el numero de reintentos que se le brindara al usuario.
/// \return Retorna 0 (EXITO) si se obtiene el numero entero y -1/-2 (ERROR) si no pudo.
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}

/// \brief Solicita un numero real al usuario que lee por stdin, admite cualquier numero real.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \param mensaje Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje al usuario.
/// \param mensajeError Cadena de caracteres ingresada por parametro, la cual mostrara un mensaje de error al usuario.
/// \param reintentos Define el numero de reintentos que se le brindara al usuario.
/// \return Retorna 0 (EXITO) si se obtiene el numero entero y -1/-2 (ERROR) si no pudo.
int utn_getFloatSinLimite(float* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}

/// \brief Verifica si la cadena ingresada es numerica con decimal.
/// \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumericaConDecimal(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);//convierte un string en caso de ser posible en un numero int
		}
	}
	return retorno;
}

/// \brief Verifica si la cadena ingresada es numerica con decimal.
/// \param cadena Cadena de caracteres a ser analizada.
/// \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es.
static int esNumericaConDecimal(char* cadena)//trata de verificar si cada caracter es un numero falso 0 y verdadero 1
{
	int retorno = 1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}

		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = 0;
			}
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			i++;
		}
		if(contadorPuntos > 1)
		{
			retorno = 0;
		}
	}
	return retorno;
}


//--------------------CHAR--------------------
/*
 * \brief Solicita una letra al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \param reintentos Es el numero de reintentos para poder ingresar un dato valido
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}
int utn_getCharParaContinuar(char* pResultado,char* mensaje,char* mensajeError,char primeraOpcionValida,char segundaOpcionValida,int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && primeraOpcionValida != segundaOpcionValida && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);
			fflush(stdin);

			if(bufferChar == primeraOpcionValida || bufferChar == segundaOpcionValida)
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}


//--------------------STRING--------------------
/*
 * \brief Solicita un texto al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param limite Es el limite de tamanio del texto a ingresar
 * \param reintentos Es el numero de reintentos para poder ingresar un dato valido
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getTexto(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos)
{
	int retorno = -1;
	char bufferString[limite];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getString(bufferString,limite) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * \brief Verifica si la cadena ingresada es un texto.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param limite Es el limite de tamanio del texto a ingresar
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getString(char* pResultado,int limite)
{
	int retorno = -1;
	char buffer[limite];

		if(pResultado != NULL)
		{
			if(myGets(buffer,sizeof(buffer))==0)
			{
				strncpy(pResultado,buffer,limite);
				retorno = 0;
			}
		}
		return retorno;
}
/*
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param limite Es el limite de tamanio del texto a ingresar
 * \param reintentos Es el numero de reintentos para poder ingresar un dato valido
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getName(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos)
{
	int retorno = -1;
	char bufferString[limite];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getName(bufferString,limite) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * \brief Verifica si la cadena ingresada es un nombre.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param limite Es el limite de tamanio del texto a ingresar
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getName(char* pResultado,int limite)
{
	int retorno = -1;
	char buffer[limite];

		if(pResultado != NULL)
		{
			if(myGets(buffer,sizeof(buffer))==0 && isValidName(buffer))
			{
				strncpy(pResultado,buffer,limite);
				retorno = 0;
			}
		}
		return retorno;
}

/*
 * \brief Verifica si la cadena ingresada es un nombre.
 * \param nombre Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es un nombre y 0 (falso) si no lo es
 */
static int isValidName(char* nombre)
{
	int retorno = 0;
	int i = 0;

	if(nombre != NULL && strlen(nombre) > 0)
	{
		if(nombre[0] >= 'A' && nombre[0] <= 'Z')
		{
			i = 1;
			retorno = 1;
		}

		while(nombre[i] != '\0')
		{
			if(nombre[i] < 'a' || nombre[i] > 'z')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

//---------------------------PRUEBAS CUIT----------------------
static int getCuitCuil(char* pResultado,int limite);
static int isValidCuitCuil(char* CuitCuil);

int utn_getCuitCuil(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos)
{
	int retorno = -1;
	char bufferString[limite];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getCuitCuil(bufferString,limite) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}
	return retorno;
}

static int getCuitCuil(char* pResultado,int limite)
{
	int retorno = -1;
	char buffer[limite];

		if(pResultado != NULL)
		{
			if(myGets(buffer,sizeof(buffer))==0 && isValidCuitCuil(buffer))
			{
				strncpy(pResultado,buffer,limite);
				retorno = 0;
			}
		}
		return retorno;
}

static int isValidCuitCuil(char* CuitCuil)
{
	int retorno = 0;
	int i = 0;

	if(CuitCuil != NULL && strlen(CuitCuil) > 0)
	{

		if(strlen(CuitCuil)==11)
		{
			retorno = 1;
			while(CuitCuil[i] != '\0')
			{
				if(CuitCuil[i] < '0' || CuitCuil[i] > '9')
				{
					retorno = 0;
					break;
				}
				i++;
			}
		}
	}
	return retorno;
}

//-------------------PRUEBA TELEFONO-----------
static int getTelefono(char* pResultado,int limite);
static int isValidTelefono(char* telefono);

int utn_getTelefono(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos)
{
	int retorno = -1;
	char bufferString[limite];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getTelefono(bufferString,limite) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}
	return retorno;
}

static int getTelefono(char* pResultado,int limite)
{
	int retorno = -1;
	char buffer[limite];

		if(pResultado != NULL)
		{
			if(myGets(buffer,sizeof(buffer))==0 && isValidTelefono(buffer))
			{
				strncpy(pResultado,buffer,limite);
				retorno = 0;
			}
		}
		return retorno;
}

static int isValidTelefono(char* telefono)
{
	int retorno = 0;
	int i = 0;

	if(telefono != NULL && strlen(telefono) > 0)
	{

		if(strlen(telefono)==8)
		{
			retorno = 1;
			while(telefono[i] != '\0')
			{
				if(telefono[i] < '0' || telefono[i] > '9')
				{
					retorno = 0;
					break;
				}
				i++;
			}
		}
	}
	return retorno;
}
//-----------------FUNCION PRINCIPAL-----------------------

/// \brief Lee un stdin (lo que lee por consola) hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
/// \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida.
/// \param longitud Define el tamaño de cadena.
/// \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
static int myGets (char* cadena, int longitud)//verifica que no se desborde y remplaza el scanf
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin) == cadena)//file gets, lee un archivo, longitud me da el limte y cadena el espacio donde lo voy a guardar
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}

	return -1;
}
