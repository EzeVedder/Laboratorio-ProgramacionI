#include <stdio.h>

void utn_pruebita(void)
{
    printf("Hola mundo desde utn.c\n");
}

//los mensajes tambien son punteros con un array de char
int utn_getInt(int* pNumero,int maximo,int minimo,char* msg,char* msgError,int reintento)//int asterisco para pasar (guardar) la direccion de memoria
{
    int num;
    int retorno=-1;
    int reintentos = 1;

    while(reintento>0)
    {
    printf("%s",msg);//para escribir una cadena de caracteres
    scanf("%d",&num);
    // *pNumero = num;

    if(num>minimo && num<maximo)
    {
        //BIEN
        *pNumero = num;
        retorno = 0;
        break;
    }
    else
    {
        //MAL
        printf("%s",msgError);
        printf("Llevas %d intento de tres\n",reintentos);
        retorno = -1;
    }
    reintentos++;
    reintento--;

    *pNumero = num;
    }//fin while
    return retorno;
}



int utn_getArrayInt(int* pNumeros,int MAX,const char* msg,const char* msgError,int minimo,int maximo,int reintentos)
{
    int i;
    int aux;
    int ret;
    for(i=0;i<MAX;i++)
    {
        ret = utn_getInt(&aux,100,0,"Ingrese un numero: ","Error.Reintente\n",3);
        if(ret)
        {
            break;
        }
        *(pNumeros+i) = aux;
    }
    return 0;
}


int utn_showArrayInt(int* pNumeros,int MAX)
{
    int i;

    for(i=0;i<MAX;i++)
    {
        printf("%d\n",pNumeros[i]);
    }


    return 0;
}



int utn_calcularMaximo(int* arreglo,int* pResultado,int MAX,char* msgError)
{
    int i;
    int ret;
    int buffer=arreglo[0];

    for(i=0;i<MAX;i++)
    {
        if(arreglo[i]>buffer)
        {
            buffer = arreglo[i];
        }
        ret = 0;
    }
    *(pResultado) = buffer;

    return ret;
}

int utn_calcularMinimo(int* arreglo,int* pResultado,int MAX,char* msgError)
{
    int i;
    int ret;
    int buffer=arreglo[0];

    for(i=0;i<MAX;i++)
    {
        if(arreglo[i]<buffer)
        {
            buffer = arreglo[i];
        }
        ret = 0;
    }
    *(pResultado) = buffer;
    return ret;
}

int utn_calcularPromedio(int* arreglo,int* pResultado,int MAX,char* msgError)
{
    int i;
    int ret;
    int buffer=0;

    for(i=0;i<MAX;i++)
    {
        buffer = arreglo[i]+buffer;
        ret = 0;
    }
    *(pResultado) = buffer/MAX;

    return ret;
}
