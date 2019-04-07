#include <stdio.h>
#include <stdlib.h>

int utn_validateInt(int *pNumero,char *msgError,int min,int max)
{
    int retorno = -1;
    int numero = *pNumero;

    while(numero < min || numero > max)
    {
        printf("%s",msgError);
        scanf("%d",&numero);
    }
    *pNumero = numero;
    retorno = 0;
    return retorno;
}

int utn_getInt(int *pNumero,char *msg,char *msgError,int min,int max)
{
    int retorno;
    int numero;

    printf("%s",msg);
    scanf("%d",&numero);
    if(!utn_validateInt(&numero,"Error. Ingrese nuevamente.\n",0,200))
    {
        *pNumero = numero;
        retorno = 0;
    }
    return retorno;
}


