/*********************************************
			Pontificia Universidad Javeriana
Autor: Pablo Samuel Leon Hernandez
Fecha: 4/1/2026
Tema: Creacion de hilos con el API Posix
Objetivos
	-creacion de funcion
	-semaforos
	-llamadas de funcion
*********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t semaf;													//variable GLOBAl para semaforo

void *funcHilo(void *arq){									//se crea la funcion para el hilo
	sem_wait(&semaf);
	printf("\n Hilo entrando...");
	sleep(4);
	printf("\n Hilo saliendo...");
	sem_post(&semaf);
}

int main(){
	sem_init(&semaf,0,1);									//Saber si esta bloqueado
	pthread_t hilo01, hilo02;								//Se declaran los hilos
	pthread_create(&hilo01,NULL, funcHilo, NULL);
	sleep(4);
	pthread_create(&hilo02,NULL, funcHilo, NULL);
	pthread_join(hilo01,NULL);
	pthread_join(hilo02,NULL);
	sem_destroy(&semaf);										//Se destruye el semaforo
	printf("\n");

	return 0;
}
