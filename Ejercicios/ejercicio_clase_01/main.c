#include <stdio.h>
#include <stdlib.h>

int getInt(int* nPuntero,char* mensaje);


int main()
{
    int numero;
    int contadorMax=0;
    int contadorMin=0;
    int i;

    for(i=0;i < 10;i++)
    {
        getInt(&numero,"Ingrese un numero: ");
        if(numero<0)
        {
            contadorMin++;
        }
        else
        {
            contadorMax++;
        }
    }

    printf("La cantidad de numero positivos es: %d y la cantidad de numeros negativos es: %d",contadorMax,contadorMin);

    return 0;
}


int getInt(int* nPuntero,char* mensaje)
{
    int numero;

    printf("%s",mensaje);
    scanf("%d",&numero);
    *nPuntero = numero;

    return 0;
}
