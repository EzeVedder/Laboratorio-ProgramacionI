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

float utn_getFloatNumber(float *pNumber,char *msg,char *msgError)
{
    int retorno = -1;
    float number;

    printf("%s",msg);
    if(scanf("%f",&number)==1)
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

int utn_getIntNumberWithRety(int *pNumber,char *msg,char *msgError,int minimo,int maximo,int retry)
{
    int retorno = -1;
    int number;

    while(retry>0)
    {
        printf("%s",msg);
        scanf("%d",&number);
        if(number>minimo && number<maximo)
        {
            *(pNumber) = number;
            retorno = 0;
            return retorno;
        }
        else
        {
            printf("%s",msgError);
            __fpurge(stdin);
            retry --;
        }
    }
    return retorno;
}

