#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LIMITE 4

int main()
{
    int numeros[LIMITE];
    //int arrayNumeros[4] = {5,34,3,1};
    int i;
    //int promedio;

    utn_getArrayInt(numeros,LIMITE,"Ingrese un numero: ","Numero invalido.",0,100,3);
    //utn_showArrayInt(numeros,LIMITE);
    for(i=0;i<LIMITE;i++)
    {
        printf("%d\n",numeros[i]);
    }












    return 0;
}
