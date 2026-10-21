/*****************************************************
* Pontificia Universidad Javeriana
* Autor: Pablo Samuel Leon Hernandez
* Materia: Sistemas Operativos
* Fecha: 21-10-2026
* tema: quinto ejercicio de POSIX
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int processID=fork();

	if (processID>0){
		printf("\n 'proceso padre'....\n");//1-10
		for(int i =0; i<10;i++){
			printf(" %d ",i);
		}
	}else if(processID==0){
		printf("\n 'proceso hijo'....\n");//10-1
		for(int i =10; i>0;i--){
			printf(" %d ",i);
		}
	}else{
		printf("\n llamada al sistema fork() fallo \n");
	}

	printf("\n fin \n");
}
