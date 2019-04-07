#include <stdio.h>
#include <stdlib.h>
#include "utn_herramientas.h"

int main()
{
    int i;
    float numero;
    float minimo;
    float maximo;
    float acumulador;

    utn_getFloat(&numero,"\nIngrese un numero: ","Error. Reintente",0,200);
    //printf("%d",numero);
    minimo = numero;
    maximo = numero;
    acumulador = numero;

    for(i=0;i<4;i++)
    {
        utn_getFloat(&numero,"Ingrese un numero: ","Error. Reintente",0,200);
        if(numero<minimo)
        {
            minimo = numero;
        }
        if(numero>maximo)
        {
            maximo = numero;
        }
        acumulador = acumulador + numero;
    }

printf("\nEl numero minimo es %.2f, el numero maximo es %.2f\n",minimo,maximo);
printf("El promedio de los numeros ingresados es %.2f",acumulador/5);

    return 0;
}
