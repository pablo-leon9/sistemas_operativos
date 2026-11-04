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
#include<pthread.h>

int counter = 0;
int max = 4;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;

int main(){
	pthread_t proHilo[max], conHilo[max];
	int i;
	for(i=0; i<5;i++){
		pthread_create(&proHilo[i], NULL, &productor, NULL):
		pthread_create(&conHilo[i], NULL, &consumidor, NULL);
	}
	for(i=0;i<5;i++){
		pthread_join(proHilo[i], NULL);
		pthread_join(conHilo[i], NULL);
	}
	return 0;
}
void * productor(){
   while(1) {
      pthread_mutex_lock(&condp_mutex);
      while(counter>=10){
         pthread_cond_wait(&condVarProd,&condp_mutex);
      }
      pthread_mutex_unlock(&condp_mutex);
      pthread_mutex_lock(&counter_mutex);
      counter++;
      pthread_cond_signal(&counterVarCons);
      printf("Soy Productor %d valor contador = %d\n", pthread_self(), counter);
      pthread_mutex_unlock(&condp_mutex);
      pthread_mutex_unlock(&counter_mutex);
      if(counter==5)
         sleep(1);
   }
}

void * consumidor(){
   while(1) {
      sleep(1);
      pthread_mutex_lock(&condp_mutex);
      while(counter<=0){
         pthread_cond_signal(&condVarProd);
         pthread_cond_wait(&condVarCons,&condp_mutex);
      }
      pthread_mutex_unlock(&condp_mutex);
      pthread_mutex_lock(&counter_mutex);
      if(counter>0){
         printf("Soy Contador %d valor contador = %d\n", pthread_self(), counter);
         counter--;
         pthread_cond_signal(&condVarProd);
      }
      pthread_mutex_unlock(&counter_mutex);
      pthread_mutex_unlock(&condp_mutex);
   }
}
