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

sem_t semaf;																			//variable GLOBAl para semaforo

void *funcHilo(void *arq){															//se crea la funcion para el hilo
	sem_wait(&semaf);
	printf("\n Hilo entrando...");
	sleep(4);
	printf("\n Hilo saliendo...");
	sem_post(&semaf);
}

int main(){
	pthread_t hilo01;																	//Se declaran los hilos
	sem_init(&semaf,0,1);															//Se inicia el semaforo
	int hilo_crea= pthread_create(&hilo01,NULL, funcHilo, NULL);
	if(hilo_crea){
		printf("no se creo el hilo");
	}else{
		printf("se creo el hilo con ID %d \n",hilo_crea);
	}

	hilo_crea = pthread_join(hilo01, NULL);
	if(hilo_crea)
		printf("Fallo de salida de hilo...\n"); 								//Se verifica si sale

	printf("fin del programa!\n");

	return 0;
}
