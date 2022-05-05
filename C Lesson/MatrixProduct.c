// Programa de multiplicacion de matrices

#include <stdio.h>
#include "Matrix.h"

#define M 4
#define N 3
#define O 4

// Esta rutina calcula el producto punto entre dos vectores
double DotProd(double* x, double* y, int n)
{
    double sum = *(x++) * *(y ++ );
    --n ;
    
    do {
        sum += *( x++ ) * *(y ++ );
    } while (--n);
    
    
    return sum;
}



int main()
{
 
    // Declaramos las matrices
    double m1[M * N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    double m2[N * O] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

    // Apuntadores a las matrices
    double* m1Ptr = m1;
    double* m2Ptr = m2;
    
    // Arreglo new, va guardar los elementos de la columna de la segunda matriz
    double new[N];
    double* nPtr = new;
    
    int i = 0, j = 0, k = 0;
    
    // Declaramos la matriz producto
    double Matrix[M*O];
    double* MPtr = Matrix;
    
    /*
    
    Para hacer la multiplicacion de matrices necesitamos tres ciclos, en el 
    primero, recorremos los elementos de la matriz 1. En el segundo recorremos
    las filas de la matriz 2. Y en el tercero las columnas. Vamos guardando las
    columnas de la matriz 2 en un arreglo llamado new y hacemos el producto 
    punto con los elementos de la fila de la matriz 1.
    
    */
    
    do {
        
        do {
            
            // Apuntamos en la direccion correcta
            nPtr = new;
            m2Ptr = m2;
            j = 0;
           
           do {
               
               // Guardamos la columna en el arreglo new
               *nPtr = *(m2Ptr + i + j*O);
               nPtr ++;
               
               j ++;
               
           } while (j<N);
            
            // Apuntamos en la direccion correcta
            nPtr = new;
            
            /*
            
            Hacemos el producto punto entre la fila de la matriz 1 y la columna 
            de la matriz 2
            
            */
            *MPtr = DotProd(m1Ptr, nPtr, N);
            MPtr ++;
            
            i ++;
            
        } while(i<O);
    
        i = 0;
        k ++;
        
        // Sumamos para estar en la siguiente fila
        m1Ptr = m1Ptr + N;
    
    } while(k<M);
    
    printf("La matriz numero 1. (%d, %d)\n", M, N);
    MatrixShow(M, N, m1);

    printf("La matriz numero 2. (%d, %d) \n",N, O);
    MatrixShow(N, O, m2);
    printf("\n");

    printf("El productode ambas matrices. (%d, %d)\n", M, O);
    MatrixShow(M, O, Matrix);

    return 0;
}