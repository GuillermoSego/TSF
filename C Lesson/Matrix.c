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