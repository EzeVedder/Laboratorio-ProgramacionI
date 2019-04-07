#include <stdio.h>
#include <stdlib.h>

int utn_validateInt(int *pNumero,char *msgError)
{
    int retorno = -1;
    int numero = *pNumero;

    while(numero < 0 || numero > 100)
    {
        printf("%s",msgError);
        scanf("%d",&numero);
    }
    *pNumero = numero;
    retorno = 0;
    return retorno;
}

int utn_getInt(int *pNumero,char *msg,char *msgError)
{
    int retorno;
    int numero;

    printf("%s",msg);
    scanf("%d",&numero);
    if(!utn_validateInt(&numero,"Error. Ingrese nuevamente.\n"))
    {
        *pNumero = numero;
        retorno = 0;
    }
    return retorno;
}


