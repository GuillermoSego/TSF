// (#) Indica que es una directiva del preprocesador. 
// La directiva stdio.h Es una biblioteca
// Esto se manda al preprocesador
#include <stdio.h>

// La funcion es parte de la tercera parte

double HornerRule( double x, double *coeff , int nCoeff){
    
    double accum = coeff[0];
    int index = 1;

    do{
        accum = accum*x + coeff[index];
        index ++;
    } while(index < nCoeff); // Es una macro me sirve 
    //para saber el tamaño de un arreglo que ya esta declarado
    
    return accum;
    
}

int main() //Indica que el programa comienza, es lo que se manda a la memoria
{
 
    //Primera parte
       
    printf("Hello World");
    // Es una cadena de caracteres, que en realidad es una matriz de numeros, 
    // transformada utilizando codigo ASCII 
    
    
    /* Segunda parte
    
    // Algoritmo de Horner
    // Trata acerca de la factorizacion de un polinomio
    // Es de las maneras mas eficientes de evaluar un polinomio
    
    double coeff[] = {2,-5,10};
    double accum = coeff[0];
    double x = -3;
    int index = 1;

    do{
        accum = accum*x + coeff[index];
        index ++;
    } while(index <sizeof(coeff) / sizeof(double)); // Es una macro me sirve 
    //para saber el tamaño de un arreglo que ya esta declarado
    
    printf("%8.3lf", accum); //1234.123 tenemos 8 caracteres 3 decimales
    return 0;
    
    */
    
    // Tercera parte
    
    // Ahora, para graficar el Algoritmo, transformamos el Algoritmoen una func
    
    double coeff[] = {2,-5, 10};
    
    double x = -3;
    int n = 100;
    
    do{
        printf("%8.3lf, %8.3lf\n", x, 
        HornerRule(x, coeff, sizeof(coeff) / sizeof(double)));
        x += 0.1;
        
    } while(-- n);
    
    return 0;
    
    // Los ciclos descentes son mas eficientes que los ciclos ascendentes
    // Hacen una instruccion menos de ensamblador

}
/*
UTF-8 es una convención para el uso de los símbolos diacríticos, 
es mejor usar esta
*/

/*
Cuando se corre un programa de la linea de comandos, es decir int main( cosas )
es posible darle valor a las variables antes de compilar el programa
*/