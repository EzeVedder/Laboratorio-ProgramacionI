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




int utn_getFloat (float *pNumber, char* msg, char* msgError)

{
    float number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%f",&number)==1)
    {
        (*pNumber)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
    }
    return ret;
}

int utn_getFloatWithMsg (float *pNumber, char* msg, char* msgError)

{
    float number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%f",&number)==1)
    {
        (*pNumber)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
    }
    return ret;
}

int utn_getStringSoloLetras (char* pString, char* msg, char* msgError)
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

int utn_getStringSoloNumeros (char* pString, char* msg, char* msgError)
{
    char bufferStr[20];
    int retorno;
    if(!utn_getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isNumeric(bufferStr)))
    {
        strncpy(pString,bufferStr,sizeof(bufferStr));
        retorno=0;
    }
    else
    {
        printf(msgError);
        retorno=-1;
    }
    return retorno;
}

int utn_getStringAlphanumeric (char* pString, char* msg, char* msgError,int retry)
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

int utn_getTelephone (char* pString, char* msg, char* msgError,int retry)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && retry>0)
    {
        if(!getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isTelephone(bufferStr)))
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

int utn_getDni (char* pString, char* msg, char* msgError,int retry)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && retry>0)
    {
        if(!getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isDni(bufferStr)))
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

int utn_getCuit (char* pString, char* msg, char* msgError,int retry)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && retry>0)
    {
        if(!getString(bufferStr,msg,msgError)&&(pString!=NULL)&&(utn_isCuit(bufferStr)))
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

int utn_isNumeric (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(pString[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
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

int utn_isTelephone (char* pString)
{
    int i=0;
    int contGuion=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return 0;
        }
        if(pString[i]=='-')
        {
            contGuion++;
        }
        i++;
    }
    if(contGuion==1)
        {
            return 1;
        }
    return 0;
}

int utn_isDni (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(!utn_isNumeric(pString))
        {
            return 0;
        }
        if(strlen(pString)<7 || strlen(pString)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int utn_isCuit (char* pString)
{
    int ret=0;
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return 0;
        }
        else if((pString[2]=='-')&&(pString[10]=='-' || pString[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}

//FUNCIONES PARA OPERACIONES CON ARRAYS================================

int utn_cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgError)

{
    int i;
    int buffer;
    int ret;
    for(i=0;i<len;i++)
    {
        ret=utn_getIntWithMsg(&buffer,msg, msgError);
        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int utn_cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgError)

{
    int i;
    float buffer;
    int ret;
    for(i=0;i<len;i++)
    {
        ret=utn_getFloatWithMsg(&buffer,msg, msgError);
        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int utn_findEmptyPlace (char pArray[][20],int* pIndex,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pArray[i][0]=='\0')
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_findName(char* name, char parray[][20], int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(name,parray[i])==0)
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_ordenarArrayMayorMenor (char* pArray, int len,int limit)
{
    int i;
    int j;
    char buffer[limit];
    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(pArray[i]>pArray[j])
            {
                buffer[i]=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=buffer[i];
            }
        }
    }
    return 0;
}

int utn_showArrayInt(int* pArray,int len)

{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}

int utn_showArrayChar(char* pArray,int len)

{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}