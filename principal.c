/**************************************************************************
 *                      Pontificia Universidad Javeriana                  *
 * Autor: Pablo Samuel Leon Hernandez                                     *
 * Profesor: John Jairo Corredor Franco                                   *
 * Fecha: 29/07/2026                                                      *
 * Materia: Sistemas Operativos                                           *
 *                                                                        *
 * Tema: Programacion Modular                                             *
 * Objetivos:                                                             *
 * - implementar en funciones la funcion principal                        *
 * - implementar una funcion: suma de matrices                            *
 * - implementar un fichero de funciones                                  *
 * - implementar un fichero de interfaz de funciones                      *
 * - crear un fichero de automatizacion de compilacion                    *
 * - documentar y anunciar las instrucciones significativas*              *
 * - comprimir todo y enviarlo a asignacion                               *
 **************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"modulo.c"

int main(int argc, char* argv[]){

    comprobacion_in(argc);
    //variables iniciales
    double **matrizA;    //matriz A
    double **matrizB;    //matriz B
    double **matrizC;    //matriz A+B
    
    int N = (int)atoi(argv[1]); //casting a entero al 2 argumento

    //reserva de memoria
    matrizA = (double **)malloc(N*sizeof(double *));
    matrizB = (double **)malloc(N*sizeof(double *));
    matrizC = (double **)malloc(N*sizeof(double *));

    for(int i=0; i<N; i++){
        matrizA[i] = (double *)malloc(N*sizeof(double));
        matrizB[i] = (double *)malloc(N*sizeof(double));
        matrizC[i] = (double *)malloc(N*sizeof(double));
    }

    //iniciar matrices
    inicio_matrix(matrizA,N);
    inicio_matrix(matrizB,N);
    
    //imprimir matrices
    printf("matriz A\n");
    imp_matrix(matrizA,N);
    apart(N);
    
    printf("matriz B\n");
    imp_matrix(matrizB,N);
    apart(N);

    //suma de matrices
    suma(matrizA,matrizB,matrizC,N);
    
    printf("matriz C\n");
    imp_matrix(matrizC,N);
    apart(N);

    //liberar memoria
    for(int i=0; i<N; i++){
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

return 0;
}
