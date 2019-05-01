#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"

int utn_getCuit(char* pCadena,char* msg,char* msgError,int retry);
int utn_isCuit(char* pResultado);

int main()
{
    char CUIT[20]="20-34224420-4";
    int ret;

    ret = utn_isCuit(CUIT);
    printf("%d",ret);

}


/*int utn_getCuit(char* pCadena,char* msg,char* msgError,int retry)
{
    char bufferString[20];
    int ret=-1;

    while(ret==-1 && retry>0)
    {
        if(!utn_getString(bufferString,msg,msgError)&&(pCadena!=NULL)&&)
        printf("%s",msg);


    }
    return ret;
}*/


int utn_isCuit(char* pResultado)
{
    int i=0;
    int ret=-1;

    while(pResultado[i]!='\0')
    {
        if((pResultado[i]!='-')&&(pResultado[i]<'0' || pResultado[i]>'9'))
        {
            return 0;
        }
        else if((pResultado[2]=='-')&&(pResultado[10]=='-' || pResultado[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}
