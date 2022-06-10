/*

En ese documento se escribe la definicion de las rutinas

*/


#include <stdio.h>
#include "Statistics2.h"
#include <math.h>

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double v[])
{
    
     
    int i, j, k=0;
    
    for(i=0 ; i<m ; i++){
        
        for (j=0 ; j<n ; j ++){
            
            printf("%lf \t", v[k]);
            k ++;
        }
        
        printf("\n");
    }
    
    
}

// Esta rutina calcula la matriz transpuesta de un vector y la guarda en otro
void MatrixT(int n, int m, double v[], double Vec[] )
{

  double* VecPtr = Vec;
  double* vPtr = v;

  int i = 0, j = 0;
 
  do {

    do {
        
       *VecPtr = *vPtr;

        VecPtr ++; 

        vPtr += m;

      j ++;
    } while (j<n);   

    vPtr = v + (i+1);

    j = 0;
    i ++;
  } while (i<m);


}

// Esta rutina calcula el producto punto entre dos vectores
double DotProd(double x[], double y[], int n)
{
    
    double* xPtr = x;
    double* yPtr = y;
    
    double sum = 0;
    int i=0;
    
    do {
        sum += *( xPtr++ ) * *(yPtr ++ );
        i ++;
    } while (i<n);
    
    return sum;
}

// Esta rutina hace el producto entre dos matrices
void MatrixProduct(double m1[], double m2[], double Matrix[], int M, int N, int O)
{

  // Apuntadores a las matrices
  double* m1Ptr = m1;
  double* m2Ptr = m2;
    
  // Arreglo new, va guardar los elementos de la columna de la segunda matriz
  double new[N];
  double* nPtr = new;
    
  int i = 0, j = 0, k = 0;
    
  // Declaramos la matriz producto
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

}

// Este programa calcula el valor maxino de un arreglo
double maximus(double v[], int s)
{
    
    // Apuntamos
    double* vPtr = v;
    
    // Donde guardamos el minimo
    double m;
    
    int i = 0;
    
    // Guardamos el primer valor del arreglo en m
    m = *vPtr;
    
    do {
        
        // Comparamos
        if (*vPtr >= m) {
            
            m = *vPtr;
            
        }
        
        vPtr ++;
        i ++;
        
    } while(i< s);
    
    return m;
    
}

// Esta rutina inicializa a cero un arreglo
void Initialize(double in[], int n)
{

  double* inPtr = in;
  int i = 0;

  do {

    *inPtr = 0;
    inPtr ++;

    i ++;

  } while(i<n);

}

// Este programa suma todos los elementos de un vector, y los pone en otro vec
void Sum(double in[], double out[], int n)
{

  Initialize(out, n);

  double sum = 0;
  // Apuntamos
  double* inPtr = in;
  double* outPtr = out;
  int i = 0, j = 0;

  do{

    do {

      sum += *inPtr;
      inPtr ++;

      i ++;

    } while(i<n);

    *outPtr += sum; 
    outPtr ++;
    sum = 0;
    i = 0;
    j ++;

  } while(j<n);

}

// Esta rutina calcula un arreglo de unos
void Ones(double t[], int n)
{

  double* tPtr = t;

  int i = 0;

  do {

    *tPtr = 1;
    tPtr ++;

    i++;

  } while(i<n);


}

// Este programa divide un arreglo por un escalar
void Divide(double matrix[], double scalar, double out[], int s)
{

  double* mPtr = matrix;
  double* outPtr = out;
  int i = 0;

  do {

    *outPtr = *mPtr/scalar;
    outPtr ++;
    mPtr ++;

    i ++;

  } while( i < s );

}

// Esta rutina calcula la suma de dos matrices cuadradas
void MatrixSum(double m1[], double m2[], double mout[], int n)
{

  double* m1Ptr = m1;
  double* m2Ptr = m2;
  double* outPtr = mout;

  int i = 0;

  do {

    *outPtr = *m1Ptr - *m2Ptr;
    m2Ptr ++;
    m1Ptr ++;
    outPtr ++;

    i ++;

  } while( i < (n*n) );

}

// Esta rutina calcula los componentes principales
void PrincipalComponents(double m1[], double m2[], double Matrix[], int M, int N, int O, double sum)
{

  // Apuntadores a las matrices
  double* m1Ptr = m1;
  double* m2Ptr = m2;
    
  // Arreglo new, va guardar los elementos de la columna de la segunda matriz
  double new[N];
  double* nPtr = new;
    
  int i = 0, j = 0, k = 0;
    
  // Declaramos la matriz producto
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
          *MPtr = DotProd(m1Ptr, nPtr, N) - sum/M;
          MPtr ++;
            
          i ++;
            
      } while(i<O);
    
      i = 0;
      k ++;
        
      // Sumamos para estar en la siguiente fila
      m1Ptr = m1Ptr + N;
    
  } while(k<M);

}

// Funcion para realizar un arreglo con cierta separacion
void linspace(double x[], double init, double end, int n)
{

  // Apuntamos
  double* xPtr = x;
  double delta;
  // Calculamos el paso
  delta = (end - init)/(n-1);

  int i = 0;
  do {

    // Calculamos el paso de vectores
    *xPtr += delta*i + init;
    xPtr ++;

    i ++;
  } while(i<n);


}

// Esta funcion calcula las elipses
void ConfidenceEllipse(double U[], double l[], double sum[], int ST, int SA)
{

  double* UPtr = U;

  // Tamaño del arreglo
  int size = 101;
  
  double x[size];
  double* xPtr = x;
  linspace(x, 0, 2*3.1415, size);

  double Quartil = 8.187;

  // Calculamos los semiejes de las elipses
  double a[size*2], b[size];
  double* aPtr = a;
  double* bPtr = b;

  int i = 0, j = 0;

  double accum = 0;

  // Hacmos dos ciclos para una multiplicacion de matrices
  do {

    // aPtr = a;
    // bPtr = b; 
    xPtr = x;

    do {
      
      // Semiejes
      /*
      *aPtr = 2*cos(*xPtr )*S[0]*sqrt(Quartil* l[0]) ;  
      *bPtr = 2*sin(*xPtr )*S[ST + 1]*sqrt(Quartil* l[1]) ;  
      */

      
      accum = cos(*xPtr )*sqrt(Quartil* l[0]) * *(UPtr) + 
      sin(*xPtr )*sqrt(Quartil* l[1]) * *(UPtr + ST) ;
      
      /*
      accum = 2*cos(*xPtr )*S[0]*sqrt(Quartil* l[0])   + 
      2*sin(*xPtr )*S[ST + 1]*sqrt(Quartil* l[1])  ;
      */


      *aPtr = accum;
      accum = 0;

      aPtr ++;
      // bPtr ++;

      xPtr ++;

      i ++;
    } while(i<size);
    // Movemos el apuntados
    UPtr ++;

    i = 0;
    j ++;  
  } while(j<2);

  // Imprimimos los valores de la matriz
  printf("El valor de la elipse\n");
  MatrixShow(2, size, a);


}

// Esta rutina calcula los datoa para graficar PCA y las elipses de confianza
void PlotPCA(double S[], double U[], double l[], double Dat[], double sum[], int ST, int SA)
{
  
  // Apuntamos
  double* SPtr = S;
  double* UPtr = U;
  double* lPtr = l;
  double* sumPtr = sum;

  // Declaramos las z
  double z1[SA];
  double z2[SA];

  // Calculamos los componentes principales (Z)
  PrincipalComponents(Dat, UPtr, z1, SA, ST, 1, sum[0]);
  PrincipalComponents(Dat, UPtr + ST, z2, SA, ST, 1, sum[1]);

  printf("Imprimimos los valores de z1 \n");
  MatrixShow(1, SA, z1);

  printf("Imprimimos los valores de z2 \n");
  MatrixShow(1, SA, z2);

  // Hacemos un nuevo set de datos guardamos z1 + z2
  // newdata = [z1 , z2];
  double ndata[SA*2]; 
  double newdata[SA*2];
  double* ndataPtr = ndata;


  Divide(z1, 1, ndataPtr, SA);
  Divide(z2, 1, ndataPtr + SA, SA);

  // MatrixT(2, SA*2, ndata, newdata);

  // La matriz de los nuevos datos
  // printf("Los nuevos datos son los siguientes\n");
  // MatrixShow(SA*2, 1, newdata);


  // Hacemos el metodo de potencias con el nuevo set de datos

  // Primero calculamos la matriz de covarianza
  double sum_new[2];
  // Donde guardaremos la covarianza
  double S_new[2*2];

  Variance(sum_new, S_new, ndata, 2, SA);
  Covariance(sum_new, S_new, ndata, 2, SA);

  // Ahora implementamos el metodo de potencias 

  // Inicializamos las matrices
  double Unew[2*2];
  double lnew[2];

  // Aplicamos el metodo de potencias
  PowerMethod(S_new, Unew, lnew, 2);

  
  printf("La nueva matrix U\n");
  MatrixShow(2,2, Unew);

  printf("La nueva matrix l\n");
  MatrixShow(1,2, lnew);
  

  // Calculamos las elipses de confianza
  ConfidenceEllipse(Unew, lnew, sum, 2, SA);


}