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
#include"modulo.h"      //interfaz artesanal

//funcion de comprobacion de datos ingresados
void comprobacion_in(int valor){
    if(valor !=2){
        printf("\n use: \n\t $ejecutable valor\n\n");
        exit(0);
    }
}

//imprimir matrices
void imp_matrix(double **mat, int dimen){
    if(dimen<=10){
        for(int i=0; i<dimen; i++){
            for(int j=0; j<dimen; j++){
                printf(" %f ", mat[i][j]);
            }
            printf("\n");
        }
    }
}

//separador de cada parte de lo que se muestra en consola
void apart(int dim){
    for(int i=0; i<dim; i++){
        printf("--*--*--*");
    }
    printf("--\n");
}

//asignar valores aleatoreos de 1.0 a 10.0
void inicio_matrix(double **mat, int dimen){
    srand(time(NULL));
    for(int i=0; i<dimen; i++){
        for(int j=0; j<dimen; j++){
            mat[i][j] = (double)rand()/RAND_MAX*(10.0-1.0);
        }
    }
}

//suma de las matrices A+B con resultado C
void suma(double **ma, double **mb, double **mc, int dimen){
    for(int i=0; i<dimen; i++){
        for(int j=0; j<dimen; j++){
            mc[i][j]=ma[i][j]+mb[i][j];
        }
    }
}
