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
        printf("Llevas %d intento de tres\n",reintento);
        retorno = -1;
    }
    reintento--;

    *pNumero = num;
    }//fin while
    return retorno;
}



int utn_getArrayInt(int* pNumeros,int MAX,const char* msg,const char* msgError,int minimo,int maximo,int reintentos);
{
    int i;
    int numero;
    int aux;
    int ret;
    for(i=0;i<MAX;i++)
    {
        ret = utn_getInt(&aux,100,0,"Ingrese un numero: ")
        if(ret)
        {
            break;
        }
        *pNumeros+1 = aux;
    }
    return ret;
}


int utn_showArrayInt(int* pNumero,int MAX)
{
    int numero;
    int i;

    for(i=0;i<MAX;i++)
    {
        printf("%d\n",array[i]);
    }

    return 0;
}


