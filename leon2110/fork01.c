/*****************************************************
* Pontificia Universidad Javeriana
* Autor: Pablo Samuel Leon Hernandez
* Materia: Sistemas Operativos
* Fecha: 21-10-2026
* tema: primer ejercicio de POSIX
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int processID=fork();
	printf("\n");
	if (processID>0){
		printf("fork() devuelve un valor +ve. este es el 'proceso padre' con ID: %d\n",getpid());
	}else if(processID==0){
		printf("fork() devuelve un valor 0. este es un 'proceso hijo' recien creado con ID: %d\n",getpid());
		printf("el 'proceso padre' de este 'proceso hijo' tiene el ID: %d\n",getppid());
	}else{
		printf("fork() devuelve un valor -ve, por lo que la llamada al sistema fork() fallo \n");
	}
	printf("\n\n esta es una unica impresion. si la llamada al sistema fork() ha tenido exito \n");
	printf("tanto el 'proceso padre' como el 'proceso hijo' se ejecutaran simultaneamente, \n");
	printf("y esta impresion aparecera dos veces. \n");
	
	printf("\n");
	return 0;
}
