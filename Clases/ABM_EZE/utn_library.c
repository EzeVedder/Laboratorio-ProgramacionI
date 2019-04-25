#include <stdio.h>
#include <stdlib.h>
#include "utn_library.h"
#include <stdio_ext.h>

int utn_getIntNumber(int *pNumber,char *msg,char *msgError)
{
    int retorno = -1;
    int number;

    printf("%s",msg);
    if(scanf("%d",&number)==1)
    {
        *(pNumber) = number;
        retorno = 0;
        return retorno;
    }
    else
    {
        printf("%s",msgError);
        __fpurge(stdin);
    }
    return retorno;
}




