
#include <stdio.h>
#include "Matrix.h"

/*
Esta rutina calcula la varianza de los grupos de datos y llena la diagonal 
principal de la matriz de covarianza
*/
void Variance(double* sum_xPtr, double* CovPtr, double* DatPtr[], int N, int M )
{
    // En estas variables se van a hacer las sumas
    double sum_x = 0, sum_x2 = 0;  
    
    int i = 0, k = 0;
    
    do {  
    
        sum_x = 0, sum_x2 = 0;    
    
            do {
                
                // Hacemos las sumas de x y x^2
                sum_x2 += *(DatPtr[k]) * *(DatPtr[k]);
                sum_x += *(DatPtr[k] ++);
                
                i ++;
            
            } while(i<M);
    
        // Guardamos el valor de sum x en un arreglo
        *sum_xPtr = sum_x;
        sum_xPtr ++;
        
        /*
        Calculamos la varianza y directamente guardamos estos valores en la 
        matriz de covarianza
        */
        *CovPtr = (M * (sum_x2) - (sum_x) * (sum_x)) / ( M*(M-1) );
        
        // Recorremos el apuntador para tener solo los valores de la diagonal
        CovPtr  = CovPtr + (N+1);
        
        k ++;
        i = 0;
    
    } while(k < N);
    
    
}

/*
En esta rutina se calcula la covarianza entre todas las variables y se guarda 
en la matriz de covarianza
*/
void Covariance(double* sum_xPtr, double* CovPtr, double* DatPtr[], int N, int M )
{
    
    int i = 0, k = 0;
    
    do {
        
        do {
            
            /*
            Calculamos la covarianza y lo guardamos directamente en la matriz. 
            La covarianza se calcula por renglon, un ciclo es para los renglones 
            y otro para las columnas. Avanzamos de manera que permutamos en 
            cada renglon todas las variables, permutando una variable fija con 
            todas las demas. De esta manera, si en el primer renglon tenemos x,
            hacemo xy, xz, xw, xe, xd, ... Cuando avanzamos al siguiente renglon
            hacemos yz, yw, ye, yd, ... Avanzamos zw, ze, zd, ... y asi hasta 
            acabar
            */
            *CovPtr = (M * DotProd(DatPtr[i],  DatPtr[k+1], M) - 
            (*sum_xPtr)* *(sum_xPtr + (k+1)) ) / ( M*(M-1) );
            
            //printf("%lf\n", DotProd(DatPtr[i],  DatPtr[k+1], M) );
            //printf("%d\n", k);
            
            //*CovPtr = 45;
            
            /*
            Llenamos los lugares transpuestos de la matriz sumando los lugares 
            que corresponden. (k+1)(n-1)
            */
            *(CovPtr + (k+1)*(N-1)) = *CovPtr;
            
            CovPtr ++;
            
            k ++;    
        
        // Movemos los indices para estar en la diagonal superior de la matriz
        
         } while( k < (N - 1) - i );
        
        // Apuntamos en la dirección superior de la diagonal principal 
        CovPtr = CovPtr + (i+2);
        sum_xPtr ++;
        
        k = 0;
        i ++;
    } while( i < N-1);

    
}