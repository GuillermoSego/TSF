// Metodo de potencias

#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "Open.h"
#include "Statistics.h"

#define BF 100

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
    double* DatTPtr = DatM;
    
    // Determinamos la transpuesta
    MatrixT(SA, ST, VecM, DatM);


    // Declaramos la matriz de la Covarianza y le apuntamos
    double CovM[ST*ST];
    double* CovPtr = CovM;
    
    /*
    Hacemos un apuntador de apuntadores para manejar los datos
    El unico problema del programa es que para ejecutar el programa hay que 
    reservar la memoria segun el número de columnas
    */
    double* DatPtr[] = {DatM, DatM + SA, DatM + 2*SA, DatM + 3*SA, DatM + 4*SA};

    // Declaramos un arreglo para las sumas y le apuntamos     
    double sum_xM[ST];
    double* sum_xPtr = sum_xM;

    // Varianza
    Variance(sum_xPtr, CovPtr, DatPtr, ST, SA);
    
    // Nos cercioramos que estamos apuntando en la dirección correcta
    DatPtr[ST - 1] = &DatM[0];
    
    CovPtr = CovM + 1;
    sum_xPtr = sum_xM;


    // Covarianza 
    Covariance(sum_xPtr, CovPtr, DatPtr, ST, SA);
    
    // En este punto tenemos la matriz de covarianza, ahora hay que calcular el metodo de potencias
    printf( "La matriz de Covarianza es: \n");
    MatrixShow(ST,ST, CovM);

    // Inicializamos las matrices
    double St[ST];
    double t[ST];
    double nt[ST];

    double U[ST*ST];
    double* UPtr = U;

    double v[ST*ST];
    double* vPtr = v;

    double l[ST];
    double* lPtr = l;
    
    // Declaramos un nuevo vector en el que guardaremos la de transpuesta de S
    double Sprime[ST*SA];
    double* SprimePtr = Sprime;
    MatrixT(ST, ST, CovM, Sprime);

    // El error
    double e = 0.01;

    int i = 0, j = 0; 

    do {

        // Calculamos St = sum(S)
        MatrixSum(Sprime,St, ST);
        // Incializamos la matriz de unos
        Ones(t, ST);

        do {
          
          // nt = St/max(St)
          Divide(St, maximus(St, ST), nt, ST);

          // Condicion de paro

          // t = nt
          MatrixT(ST, 1, nt, t);
          // St = S*t
          MatrixProduct(CovM, t, St, ST, ST, 1);

          j ++;

        } while(j<10);

        // Calculamos las U(:,i) = t/norm(t)
        Divide(t, sqrt(DotProd(t, t, ST)), U, ST);
        UPtr += ST;

        // Calculamos las l(i) = max(St)
        *lPtr = maximus(St, ST);
        lPtr += ST;

        break;

        i++;

    } while(i<ST);


    // Declaramos un nuevo vector en el que guardaremos la de transpuesta de S

    
    MatrixShow(1,ST,l);

    return 0;
}