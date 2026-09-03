/***************************************
*		Pontificia Universidad Javeriana *
* Autor: Pablo Samuel Leon Hernandez	*
* Profesor: John Jairo Corredor Franco *
* Fecha: 3/09/2026							*
* Materia: sistemas operativos			*
*													*
* Tema: Laboratoria de memoria			*
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

#define CAPACIDAD_INICIAL 4

//Funcion para creacion e inicio del vector
void iniVector(vectorDin *V){
	V->capacidad = CAPACIDAD_INICIAL;
	V->totalElementos = 0;
	V->elemento = malloc(sizeof(void *)*V->capacidad);
}

//Funcion para la redimension del vector
/*static void resizeVector(vectorDin *V, int capacidad){
	printf("Redimension: %d a %d \n", V->capacidad, capacidad);
	void **elemento = realloc(V->elemento, sizeof(void *)*capacidad);
	if(elemento){
		V->elemento = elemento;
		V->capacidad = capacidad;
	}
}*/

//Funcion para obtener el indice de un elemento dentro del vector
void *getVector(vectorDin *V, int indice){
	if(indice>=0 && indice < V->totalElementos)
		return V->elemento[indice];
	return NULL;
}

//Funcion para redimensionar vectores
void addVector(vectorDin *V, void *elemento){
	if(V->capacidad == V->totalElementos)
		resizeVector(V, V->capacidad*2);
	V->elemento[V->totalElementos++] = elemento;
}

//Funcion para obtener el total de elementos
int totalVector(vectorDin *V){
	return V->totalElementos;
}

//Funcion para borrar un elemento
void borrarVector(vectorDin *V, int indice){
	if(indice < 0 || indice >= V->totalElementos)
		return;
	V->elemento[indice] = NULL;

	for(int i=indice; i < V->totalElementos-1; i++){
		V->elemento[i] = V->elemento[i+1];
		V->elemento[i+1] = NULL;
	}
	V->totalElementos--;
	if(V->totalElementos > 0 && V->totalElementos == V->capacidad/4)
		resizeVector(V, V->capacidad/2);
}

//Funcion para ubicar un elemento en el indice
void setVector(vectorDin *V, int indice, void *elemento){
	if(indice >= 0 && indice < V->totalElementos)
		V->elemento[indice]=elemento;
}

//Funcion para liberar memoria reservada
void liberarVector(vectorDin *V){
	free(V->elemento);
}
