// Metodo de potencias

#include <stdio.h>
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
    MatrixT(SA, ST, VecM, DatTPtr);


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
    
    // Se imprime la matriz
    printf( "La matriz de Covarianza es: \n");
    MatrixShow(ST,ST, CovM);
    
    
    return 0;
}