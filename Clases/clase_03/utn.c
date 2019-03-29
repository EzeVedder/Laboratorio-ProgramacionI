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
    //*pNumero = num;

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

    //*pNumero = num;
    }//fin while
    return retorno;
}


