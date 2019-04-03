#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define MAX 5

int main()
{
    int numeros[MAX];
    //int promedio;

    utn_getArrayInt(numeros,MAX,"Ingrese un numero: ","Numero invalido.",0,100,3);
    utn_showArrayInt(numeros,MAX);




    return 0;
}
