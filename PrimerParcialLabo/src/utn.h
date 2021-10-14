/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getIntSinLimite(int* pResultado,char* mensaje,char* mensajeError,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getFloatSinLimite(float* pResultado,char* mensaje,char* mensajeError,int reintentos);

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int utn_getCharParaContinuar(char* pResultado,char* mensaje,char* mensajeError,char primeraOpcionValida,char segundaOpcionValida,int reintentos);

int utn_getTexto(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos);

int utn_getName(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos);

int utn_getCuitCuil(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos);

int utn_getTelefono(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos);

int utn_getDireccion(char* pResultado,char* mensaje,char* mensajeError,int limite,int reintentos);

#endif /* UTN_H_ */
