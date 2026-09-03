/***************************************************
*			Pontificia Universidad Javeriana				*
* Autor: Pablo Samuel Leon Hernandez					*
* Profesor: John Jairo Corredor Franco					*
* Fecha: 2/09/2026											*
* Materia: Sistemas Operativos							*
*																	*
* Tema: Laboratiorio de memoria							*
*																	*
***************************************************/
#include<stdio.h>
#include<stdlib.h>
//#include
#include"modulo.h"

/*
static void resizeVector(vectorDin *V, int capacidad){
	printf("Redimension: %d a %d \n", V->capacidad, capacidad);
	void **elemento = realloc(V->elemento, sizeof(void *)*capacidad);
	if(elemento){
		V->elemento = elemento;
		V->capacidad = capacidad;
	}
}
*/
int main(){
    /*Creación de vector para edición*/
    vectorDin editor;
    /*inicio del vector*/
    iniVector(&editor);

    /*aumento del tamaño del vecot*/
    resizeVector(&editor, 8);

    /*agregar una palabra al vector en el indice 0*/
    addVector(&editor, "Hola");
    /* Se agrega en la posición 1, el vector con la palabra Profesional */
    addVector(&editor, " Profesional");
    /*agrega una palabra al vector en el indice 2*/
    addVector(&editor, " en");
    /*agrega una palabra al vector en el indice 3*/
	 addVector(&editor, " Formacion");

    /*se imprime los elementos del vector*/
    for(int i=0; i< totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n\n");

    /*se borra el elemento en posicion 1 y 2*/
    borrarVector(&editor, 1);
	 borrarVector(&editor, 2);

    /*Se agrega en la posición 1, el vector con la palabra Excelente*/
    setVector(&editor, 1, " Mundo");

    /*se imprime los elementos del vector*/
    for(int i=0; i< totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n\n");


	 /*se libera memoria*/
    liberarVector(&editor);

    /*se retorna 0 cerrando el programa*/
	 return 0;
}
