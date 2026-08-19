/**************************************************************************
 *                  INTERFAZ DE FUNCIONES                                 *
 **************************************************************************/
#ifndef __MODULO_H__
#define __MODULO_H__

//funcion de comprobacion de datos ingresados
void comprobacion_in(int valor);

//imprimir matrices
void imp_matrix(double **mat, int dimen);

//separador de cada parte de lo que se muestra en consola
void apart(int dim);

//asignar valores aleatoreos de 1.0 a 10.0
void inicio_matrix(double **mat, int dimen);

//suma de las matrices A+B con resultado C
void suma(double **ma, double **mb, double **mc, int dimen);

#endif
