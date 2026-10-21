/*****************************************************
* Pontificia Universidad Javeriana
* Autor: Pablo Samuel Leon Hernandez
* Materia: Sistemas Operativos
* Fecha: 21-10-2026
* tema: tercer ejercicio de POSIX
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int processID=fork();

	if (processID>0){
		printf("\n 'proceso padre'....\n");
		for(int i =0; i<5;i++){
			printf(" %d ",i);
		}
	}else if(processID==0){
		printf("\n 'proceso hijo' no hace nada \n");
	}else{
		printf("\n llamada al sistema fork() fallo \n");
	}

	printf("\n fin \n");
}
