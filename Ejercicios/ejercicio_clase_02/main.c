#include <stdio.h>
#include <stdlib.h>
#include "utn_herramientas.h"

int main()
{
    int i;
    int numero;
    int minimo;
    int maximo;
    int acumulador;

    utn_getInt(&numero,"\nIngrese un numero: ","Error. Reintente",0,200);
    //printf("%d",numero);
    minimo = numero;
    maximo = numero;
    acumulador = numero;

    for(i=0;i<4;i++)
    {
        utn_getInt(&numero,"Ingrese un numero: ","Error. Reintente",0,200);
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

printf("\nEl numero minimo es %d, el numero maximo es %d\n",minimo,maximo);
printf("El promedio de los numeros ingresados es %d",acumulador/5);

    return 0;
}
