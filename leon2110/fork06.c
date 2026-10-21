/*****************************************************
* Pontificia Universidad Javeriana
* Autor: Pablo Samuel Leon Hernandez
* Materia: Sistemas Operativos
* Fecha: 21-10-2026
* tema: sexto ejercicio de POSIX
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
	int pipeComunicacion[2];	//in:0 out:1
	pid_t phijo_PID;				//identidad proceso hijo

	if(pipe(pipeComunicacion) == -1){	//caso de error creacion PIPE
		perror("PIPE FALLO: creacion(pipeComunicacion)\n");
		exit(EXIT_FAILURE);
	}

	phijo_PID = fork();				//creacion de proceso
	if(phijo_PID == -1){				//caso de error creacion proceso
		perror("PROCESS FALLO: creacion(fork())\n");
		exit(EXIT_FAILURE);
	}

	if(phijo_PID == 0){																//proceso hijo
		close(pipeComunicacion[1]);													//cierro salida para leer (PIPE)
		char mensaje[100];															//captura del mensaje (MAX 100 characters)
		int lectura;																	//tamaño del mensaje
		lectura = read(pipeComunicacion[0],mensaje, sizeof(mensaje));
		if(lectura == -1){
			perror("READ FALLO: lectura de mensaje");
			exit(EXIT_FAILURE);
		}
		printf("proceso hijo recibe mensaje del padre: \n");
		printf("mensaje:  %.*s\n", lectura,mensaje);
		close(pipeComunicacion[0]);												//cierro entrada para leer (PIPE)
	} else{																				//aqui ya estare en el proceso padre
		close(pipeComunicacion[0]);												//cierro entrada para escritura (PIPE)
		char mensajePadre[100] = "pipe test...,,,PIPE TEST";														//vector para escribir(MAX 100 characters)
		int escritura;																	//cantidad de letras del mensaje a enviar por el padre
		escritura = write(pipeComunicacion[1], mensajePadre, strlen(mensajePadre));
		if(escritura == -1){
			perror("WRITE FALLO: escritura de mensaje");
			exit(EXIT_FAILURE);
		}
		close(pipeComunicacion[1]); 												//cierro salida para escritura (PIPE)
	}
	printf("\nFIN\n");
	return 0;
}
