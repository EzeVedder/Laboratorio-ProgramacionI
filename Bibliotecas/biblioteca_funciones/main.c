#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"

int main()
{
    char cadena[20];
    int ret;

    ret = utn_getString(&cadena,"Ingrese un texto: ","ERROR.");
    if(!ret)
    {
        printf("El TEXTO elegido es: %s",cadena);
    }



}
