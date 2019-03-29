#include <stdio.h>
#include <stdlib.h>

#include "utn.h"//se ponen comillas para que la funcion se busque en el proyecto



int main()
{
    int A;


    //utn_pruebita();
    //con el & le pase la direccion de memoria de la variable y no el numero
    utn_getInt(&A,100,0,"Ingrese un numero: ","El numero ingresado no es valido.\n",3);

    printf("%d\n",A);

    return 0;
}



