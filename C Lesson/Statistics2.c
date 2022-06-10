// Esta libreria es Statitistics 2.0
/*
La modificacion va en el orden de introducir los arreglos en lugar de apuntadores
en las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Matrix.h"

/*
Esta rutina calcula la varianza de los grupos de datos y llena la diagonal 
principal de la matriz de covarianza
*/
void Variance(double sum_array[], double CovM[], double DatM[], int N, int M )
{
    
    // Apuntmos
    double* sum_xPtr = sum_array;
    double* CovPtr = CovM;
    double* DatPtr = DatM;
    
    // En estas variables se van a hacer las sumas
    double sum_x = 0, sum_x2 = 0;  
    
    int i = 0, k = 0;
    
    do {  
    
        sum_x = 0, sum_x2 = 0;    
    
            do {
                
                // Hacemos las sumas de x y x^2
                sum_x2 += *(DatPtr) * *(DatPtr);
                sum_x += *DatPtr;
                
                DatPtr ++;

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

        // printf("%lf\n", *CovPtr);
        
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
void Covariance(double sum_array[], double CovM[], double DatM[], int N, int M )
{
    
    // Apuntmos
    double* sum_xPtr = sum_array;
    double* CovPtr = CovM + 1;
    double* DatPtr = DatM;


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
            acabars
            */
            *CovPtr = (M * DotProd(DatPtr,  (DatPtr + ((k+1)*M)), M) - 
            (*sum_xPtr)* *(sum_xPtr + (k+1)) ) / ( M*(M-1) );
            
            
            /*
            Llenamos los lugares transpuestos de la matriz sumando los lugares 
            que corresponden. (k+1)(n-1)
            */
            *(CovPtr + (k+1)*(N-1)) = *CovPtr;
            
            CovPtr ++;
            
            k ++;    
        
        // Movemos los indices para estar en la diagonal superior de la matriz
        
         } while( k < (N - 1) - i );
        
        // Apuntamos a la siguiente fila
        DatPtr += M;

        // Apuntamos en la dirección superior de la diagonal principal 
        CovPtr = CovPtr + (i+2);
        sum_xPtr ++;
        
        k = 0;
        i ++;
    } while( i < N-1);

    
}

/*
    En esta rutina implementamos una condicion de paro para el programa de 
    Metodo de potenicas
*/

double ConditionCheck(double ta[], double td[], int n)
{

    // Definiimos el error
    double error = 0.00000001;
    
    // Apuntamos
    double* taPtr = ta;
    double* tdPtr = td;

    int count = 0, r = 0, i = 0;

    do {

        // El posible resultado de r es 0 o 1. Si se cumple (1) si no (0)
        r = fabs(*tdPtr ++ - *taPtr ++) <= error;
        count += r;

        i++;

    } while(i<n && r != 0 );

    // Regresamos un valor binario, 1 si son iguales 0 si no
    return count == n;


}

// Esta rutina calcula el metodo de potencias.
void PowerMethod(double CovM[], double U[], double l[], int ST)
{

    // Inicializamos las matrices
    double St[ST];
    double t[ST];
    double nt[ST];

    double* UPtr = U;

    double v[ST];
    double vprime[ST];
    double vvp[ST*ST];

    double* lPtr = l;
    
    // Declaramos un nuevo vector en el que guardaremos la nueva S
    double Snew[ST*ST];
    Divide(CovM, 1, Snew, ST*ST);


    int i = 0, j = 0, k; 

    do {

        // Calculamos St = sum(S)
        Sum(Snew,St, ST);
        // Incializamos la matriz de unos
        Ones(t, ST);

        do {
          
          // nt = St/max(St)
          Divide(St, maximus(St, ST), nt, ST);

          // Condicion de paro
          k = ConditionCheck(t, nt, ST);
          if (k == 1) {
            break;

          }

          // t = nt
          MatrixT(ST, 1, nt, t);
          // St = S*t
          MatrixProduct(Snew, t, St, ST, ST, 1);
          j ++;

        } while(j<1000);

        // Calculamos las U(:,i) = t/norm(t)
        Divide(t, sqrt(DotProd(t, t, ST)), UPtr, ST);

        // Calculamos las v(:,i) = sqrt(max(St)) * U(:,i)
        Divide(UPtr, 1/sqrt(maximus(St, ST)), v, ST);

        // Calculamos las l(i) = max(St)
        *lPtr = maximus(St, ST);

        // Redefinimos la matriz de covarianza S = S - v(:,i)*v(:,i)'
        MatrixT( ST, 1, v, vprime );
        MatrixProduct( v, vprime, vvp, ST, 1, ST );
        // Copiamos la version de la matriz Snew en Scov
        // Divide(Snew, 1, CovM, ST*ST);
        MatrixSum(Snew, vvp, Snew, ST);

        UPtr += ST;
        lPtr ++;

        j = 0;
        i++;

    } while(i<ST);


}