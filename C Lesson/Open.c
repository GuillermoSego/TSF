
#include <stdio.h>
#include "Matrix.h"

// Manejador de errores
void ErrorManagement(int e)
{
    if (e == 0) {
        
        printf("Error al abrir el archivo\n");
    }

}

int* OpenCSV(char* arg, double DatV[], int BF)
{
    
  // Declaramos una variable tipo FILE
  FILE* Doc;

  // Abrimos el archivo. "r": Abrir un archivo existente para leer. 
  // Hacemos que el apuntador Doc apunte en la direccion de los datos
  Doc = fopen ( arg, "r" );
 
  // Manejamos el error: no se pueda abrir el archivo
  if (Doc == NULL)
  {
      ErrorManagement( 0 );
      return 0;
  } 
 
  // Continuamos con la estructura para leer los datos
 
  // Primero creamos un buffer para guardar los datos
	char buffer[BF];

  // Se lee la primera linea y se almacena en el buffer como variable char
	fgets(buffer, BF, Doc);
  
  /* 
 
    En este punto todo esta almacenado en el buffer como una sola cadena de 
    caracteres. Por lo que para poder acceso a los datos se tiene que convertir
    esta cadena a binario, separando por comas "," ya que un archivo tipo csv
    separa los datos por comas.
 
  */
  
  // Creamos un apuntador que apunte a la cadena de caracteres
  char* BfPtr = buffer;
 
  // Calculamos el número de columnas contando las comas de la primera linea
  int column = 0;
    
  do{
      column += ( *BfPtr == ',' );

  } while( *BfPtr ++);
 
  // Convertimos a binario
 
  // Apuntamos en la direccion del buffer
  BfPtr = buffer;
 
  // Apuntador al vector de datos
  double* DatPtr = DatV;
  
  // Creamos un contador igual al número de columnas
  // Declaramos el parámetro adicional para la función sscanf
  int i = column, length;
 
  // Leemos el primer renglon 

  do{
        
      BfPtr += length;
      sscanf( BfPtr, "%lf,%n", DatPtr ++, &length );
        
    } while(i--);

  /*
  
    En este punto en el vector DatV tenemos guardado la primer fila de los datos.
    Ahora tenemos que guardar las siguientes filas.
 
    El apuntador del buffer BfPtr se encuentra apuntando hacia el primer dato 
    de la última columna, para asegurarnos de que apuntamos exactamente al ultimo
    elemento de la primera fila, le sumamos la longitud length

  */
  BfPtr += length;

  /*
 
  Leemos las siguientes lineas del buffer y las ponemos en el apuntador 
  de los datos

  */
  sscanf( BfPtr, "%lf", DatPtr); 

  // Recorremos el apuntador de los datos
  i = column;
  DatPtr = DatV;

	do {
		*DatPtr ++;
	} while( i-- );
		
	// Se termina de leer el archivo
	
  /*
 
  En este momento leemos los demas datos del apuntador Doc, y los guardamos en
  el apuntador de los datos DatPtr, sin embargo, tenemos que llegar al final de
  los datos. Esto lo hacemos creando una variable llamada dummy en la que guar-
  damos el momento en el que se llega al final, es decir cuando tenemos que los 
  datos tienen la forma "%lf%c"

 */
  
  int Error = 0, col = column+1; 
  char dummy;

	do{

		Error = fscanf(Doc, "%lf%c", DatPtr ++, &dummy);
         
	} while(Error > 0);


  // Cerramos el archivo, es muy importante cerrar el archivo
  fclose ( Doc );
 
  static int size[2];
  size[0] = (DatPtr - DatV)/ (col);
  size[1] = col;
 
  return size;

}