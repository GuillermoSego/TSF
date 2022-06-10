// Metodo de potencias

#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "Open.h"
#include "Statistics2.h"

#define BF 10000

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
    double U[ST*ST];
    double l[ST];

    // Aplicamos el metodo de potencias
    PowerMethod(CovM, U, l, ST);

    printf("La matrix U\n");
    MatrixShow(ST,ST, U);

    printf("La matrix l\n");
    MatrixShow(1,ST, l);

    // Graficamos
    PlotPCA(CovM, U, l, VecM, sum_xM, ST, SA);
    // MatrixShow(ST, SA, DatM);

    return 0;
}