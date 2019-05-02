#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"



int main()
{

    int ret;
    int numer;
    int num[3];
    int ret2;
    char letras[20];

    ret = utn_getIntNumberInRange(&numer,"numero: ","error",1,34,2);
    if(!ret)
    {
        printf("NUMERO: %d\n",numer);
    }
    else
        printf("Se acabaron los intentos");

    cargarArraySecuencialInt(num,3,"Ingrese elemento: ","ERROR\n");

    ret2 = utn_getString(letras,"Ingrese solo letras: ","ERROR.\n");
    if(!ret2)
    {
        printf("%s",letras);
    }
}






