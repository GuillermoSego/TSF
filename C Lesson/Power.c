// Redefinicion del programa 

#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "Open.h"
#include "Statistics2.h"

#define BF 1024

int main(int nArg, char *arg[])
{

    /*
 
      Declaramos un vector en el que vamos a guardar los datos.
      Le apuntamos dos veces.
 
    */
    double VecM[BF]; 
 
    // Creamos un vector en el que vamos a guardar los valores de N y M
    int size[2];
    int* sizePtr = size;

    // Abrimos el archivo y guardamos en el vector DatM los datos
    sizePtr = OpenCSV(*(arg+1), VecM, BF);
 
    int SA = *sizePtr, ST = *(sizePtr+1);
 
    // Declaramos un nuevo vector en el que guardaremos la transpuesta 
    double DatM[ST*SA];
    
    // Determinamos la transpuesta
    MatrixT(SA, ST, VecM, DatM);

    // Necesitamos un arreglo donde guardaremos las sumas
    double sum_xM[ST];
    // Donde guardaremos la covarianza
    double CovM[ST*ST];

    // Calculamos la matriz de covarianza
    Variance(sum_xM, CovM, DatM, ST, SA);
    Covariance(sum_xM, CovM, DatM, ST, SA);
    
    printf( "La matriz de Covarianza es: \n");
    MatrixShow(ST,ST, CovM);

// Inicializamos las matrices
    double St[ST];
    double t[ST];
    double nt[ST];

    double U[ST*ST];
    double* UPtr = U;

    double v[ST*ST];
    double vprime[ST];
    double vvp[ST*ST];
    double* vPtr = v;

    double l[ST];
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

        k = ConditionCheck(t, nt, ST);

        // Calculamos las v(:,i) = sqrt(max(St)) * U(:,i)
        Divide(U, 1/sqrt(maximus(St, ST)), vPtr, ST);

        // Calculamos las l(i) = max(St)
        *lPtr = maximus(St, ST);

        // Redefinimos la matriz de covarianza S = S - v(:,i)*v(:,i)'
        MatrixT( ST, 1, vPtr, vprime );
        MatrixProduct( vPtr, vprime, vvp, ST, 1, ST );
        // Copiamos la version de la matriz Snew en Scov
        Divide(Snew, 1, CovM, ST*ST);
        MatrixSum(CovM, vvp, Snew, ST);

        UPtr += ST;
        vPtr += ST;
        lPtr ++;

        j = 0;
        i++;

    } while(i<ST);


    // Declaramos un nuevo vector en el que guardaremos la de transpuesta de S

    
    //MatrixShow(1,ST,v);
    //MatrixShow(1,ST,vprime);
    printf("La matrix U\n");
    MatrixShow(ST,ST, U);

    printf("La matrix l\n");
    MatrixShow(1,ST, l);

    return 0;
}