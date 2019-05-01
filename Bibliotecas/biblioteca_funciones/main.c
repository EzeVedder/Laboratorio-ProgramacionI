#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"

int main()
{
    int numero;
    int ret;

    ret = utn_getNumber(&numero,"Ingrese un numero del 2 al 10: ","Error.Fuera de rango\n",2,10,3);
    if(!ret)
    {
        printf("El numero elegido es: %d",numero);
    }



}
