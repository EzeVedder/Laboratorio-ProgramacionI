#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include <stdio_ext.h>
#include <string.h>


int utn_getString(char* pString,char* msg,char* msgError)
{
    char bufferStr[20];

    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pString!=NULL)
    {
        strncpy(pString,bufferStr,sizeof(bufferStr));
    }
    return 0;
}

int utn_getIntWithMsg (int *pNumber, char* msg, char* msgError)

{
    int number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&number)==1)
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


int utn_getIntNumberInRange(int* pNumber,char* msg,char*msgError,int min,int max,int retry)
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
    fgets(buffer,sizeof(buffer),stdin);//scanf("%s",buffer);//REEMPLAZAMOS SCANF POR FGETS PARA QUE EL TXT NO PASE DEL TAMANIO DEL BUFFER DEFINIDO
    buffer[strlen(buffer)-1]='\0';
    if(utn_isNumeric(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}

int utn_getFloat (float *pNumber, char* msg, char* msgError)

{
    float number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%f",&number)==1)
    {
        *pNumber=number;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
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

int utn_getCuit(char* pCadena,char* msg,char* msgError,int retry)
{
    char bufferString[20];
    int ret=-1;

    while(ret==-1 && retry>0)
    {
        if(!utn_getString(bufferString,msg,msgError)&&(pCadena!=NULL)&&(utn_isCuit(bufferString)))
        {
            strncpy(pCadena,bufferString,20);
            ret=0;
        }
        else
        {
            printf("%s",msgError);
            retry--;
        }
    }
    return ret;
}

int utn_getDni (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!utn_getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(utn_isDni(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int utn_isDni(char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(!utn_isNumeric(pStr))
        {
            return 0;
        }
        if(strlen(pStr)<7 || strlen(pStr)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int utn_getStringLetras (char* pString, char* msg, char* msgError)
{
    char bufferStr[20];
    int ret=-1;
    if(!utn_getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isLetter(bufferStr)))
    {
        strncpy(pString,bufferStr,sizeof(bufferStr));
        ret=0;
    }
    else
    {
        printf(msgError);
    }
    return ret;
}

int utn_isLetter (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]<'a'||pString[i]>'z')&&(pString[i]<'A'||pString[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int utn_getStringAlphanumeric(char* pString, char* msg, char* msgError,int retry)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && retry>0)
    {
        if(!utn_getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isAlphanumeric(bufferStr)))
        {
            strncpy(pString,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgError);
            retry--;
        }
    }
    return ret;
}

int utn_isAlphanumeric (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]<'a'||pString[i]>'z')&&(pString[i]<'A'||pString[i]>'Z')
           &&(pString[i]<'0' || pString[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

















int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgError)

{
    int i;
    int buffer;
    int ret;
    for(i=0;i<len;i++)
    {
        ret=utn_getIntWithMsg(&buffer,msg,msgError);
        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}





