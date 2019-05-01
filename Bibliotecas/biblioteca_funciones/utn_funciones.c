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
        if(utn_getInt(&numero)==1)//MODIFCO EL SCANF POR LA FUNCION GETINT
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

int utn_getInt(int* pResultado)
{
    char buffer[54];
    int ret=-1;
    scanf("%s",buffer);
    if(utn_isNumeric(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}

int utn_isNumeric(char* cadena)
{
    int ret=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<0||cadena[i]>9)
            {
                break;
                i++;
            }
        }
        if(cadena[i]=='\0')
        ret = 1;
    }
    return ret;
}
