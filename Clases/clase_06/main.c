#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LIMIT 10

int main()
{

    int array[LIMIT];
    int maximo;

    utn_getArrayInt(array,LIMIT,"Ingrese un numero: ","ERROR.",0,100,3);
    utn_showArrayInt(array,LIMIT);

    utn_calcularMaximo(array,&maximo,LIMIT,"Error.");
    printf("El numero maximo en el array es: %d",maximo);



    return 0;
}
