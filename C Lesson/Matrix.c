/*

En ese documento se escribe la definicion de las rutinas

*/


#include <stdio.h>

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
void MatrixT(int n, int m, double v[], double* VecPtr )
{

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
    double sum = *(x++) * *(y ++ );
    --n ;
    
    do {
        sum += *( x++ ) * *(y ++ );
    } while (--n);
    
    return sum;
}

