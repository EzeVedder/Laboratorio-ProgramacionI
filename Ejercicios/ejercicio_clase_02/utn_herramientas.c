#include <stdio.h>
#include <stdlib.h>



int utn_getInt(int *pNumero,char *msg,char *msgError)
{
    int retorno;
    int numero;

    printf("%s",msg);
    scanf("%d",&numero);
    *pNumero = numero;
    retorno = 0;

    return retorno;
}
