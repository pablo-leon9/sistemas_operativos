/******************************************
*		Pontificia Universidad Javeriana		*
* Autor: Pablo Samuel Leon Hernandez		*
* Profesor: John Jairo Corredor Franco		*
* Fecha: 3/09/2026								*
* Materia: Sistemas Operativos				*
******************************************/
#ifndef __MODULO_H__
#define __MODULO_H__

//se crea una estructura de datos para manipulacion de Vectores
typedef struct vectorDin{
	int capacidad;
	int totalElementos;
	void **elemento;
}vectorDin;

//Funcion para creacion e inicio del vector
void iniVector(vectorDin *V);

//Funcion para la redimension del vector
static void resizeVector(vectorDin *V, int capacidad){
	printf("Redimension: %d a %d \n", V->capacidad, capacidad);
	void **elemento = realloc(V->elemento, sizeof(void *)*capacidad);
	if(elemento){
		V->elemento = elemento;
		V->capacidad = capacidad;
	}
}

//Funcion para obtener el indice de un elemento dentro del vector
void *getVector(vectorDin *V, int indice);

//Funcion para redimensionar vector
void addVector(vectorDin *V, void *elemento);

//funcion para obtener el total de elementos
int totalVector(vectorDin *V);

//funcion para borrar un elemento
void borrarVector(vectorDin *V, int indice);

//funcion para ubicar un elemento en el indice
void setVector(vectorDin *V, int indice, void *elemento);

//Funcion para liberar memoria reservada
void liberarVector(vectorDin *V);

#endif
