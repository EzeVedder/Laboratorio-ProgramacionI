#include <stdio.h>
#include <stdlib.h>
#include "utn_library.h"



int main()
{

    int numero;
    //float numero;
    //utn_getIntNumber(&numero,"Ingrese un numero entero: ","Error. \n");
    //utn_getFloatNumber(&numero,"Ingrese un numero flotante: ","Error. \n");
    utn_getIntNumberWithRety(&numero,"\nIngrese un numero: ","\nError",10,20,3);
    printf("\nEl numero ingresado es: %d",numero);



    return 0;
}
