#include <stdio.h>
#include <stdlib.h>
#include "utn_library.h"



int main()
{

    int numero;

    utn_getIntNumber(&numero,"Ingrese un numero entero: ","Error. \n");

    printf("\nEl numero ingresado es: %d",numero);



    return 0;
}
