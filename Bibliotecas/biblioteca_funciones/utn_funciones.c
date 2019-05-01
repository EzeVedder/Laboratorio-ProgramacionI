#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include <stdio_ext.h>


int utn_getNumber(int* pNumber,char* msg,char*msgError,int min,int max,int retry)
{
    int numero;
    int ret=-1;

    while(retry>0)
    {
        printf("%s",msg);
        if(scanf("%d",&numero)==1)
        {
            if(numero>=min && numero<=max)
            {
                break;
            }
        }
        __fpurge(stdin);
        retry--;
        printf("%s",msgError);
    }
    if(retry==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pNumber=numero;
    }
    return ret;
}
