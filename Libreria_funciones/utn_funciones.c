#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn_funciones.h"

int utn_getString(char* pStr, char* msg, char*msgError)
{
    char bufferStr[20];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pStr!=NULL)
    {
        strncpy(pStr,bufferStr,sizeof(bufferStr));
    }
    return 0;
}

int utn_getInt (int *pNumber, char* msg, char* msgError)
{
    int number;
    int ret=-1;
    printf("%s",msg);
    if(utn_isNumeric(number)==1)
    {
        (*pNumber)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        __fpurge(stdin);
    }
    return ret;
}

int utn_isNumeric(char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
