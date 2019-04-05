#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LIMIT 3

int main()
{

    int array[LIMIT];
    int maximo;
    int minimo;
    int promedio;
    int numeroBuscado;

    utn_getArrayInt(array,LIMIT,"Ingrese un numero: ","ERROR.",0,100,3);
    utn_showArrayInt(array,LIMIT);

    utn_calcularMaximo(array,&maximo,LIMIT,"Error.");
    utn_calcularMinimo(array,&minimo,LIMIT,"Error.");
    utn_calcularPromedio(array,&promedio,LIMIT,"Error.");

    utn_getInt(&numeroBuscado,100,0,"Ingrese el numero a buscar: ","dd",3);
    utn_buscarNumeroEnArray(array,&numeroBuscado,LIMIT,"El numero no se encuentra en el Array.\n");

    printf("El numero maximo en el array es: %d\n",maximo);
    printf("El numero minimo en el array es: %d\n",minimo);
    printf("El promedio en el array es: %d\n",promedio);


    return 0;
}
