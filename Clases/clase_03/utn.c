#include <stdio.h>

void utn_pruebita(void)
{
    printf("Hola mundo desde utn.c\n");
}

//los mensajes tambien son punteros con un array de char
int utn_getInt(int* pNumero,int maximo,int minimo,char* msg,char* msgError)//int asterisco para pasar (guardar) la direccion de memoria
{
    int num;
    int retorno;

    printf("%s",msg);//para escribir una cadena de caracteres
    scanf("%d",&num);
    *pNumero = num;

    if(num>minimo && num<maximo)
    {
        *pNumero = num;
        retorno = 0;
    }
    else
    {
        printf("%s",msgError);
        retorno = -1;
    }

    return retorno;
}


