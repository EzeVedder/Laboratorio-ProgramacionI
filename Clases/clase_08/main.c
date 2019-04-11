#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdio_ext.h>
#include <string.h>
#define LEN_LISTA 4

int unt_getArrayNombre(char *pArrayNombre,char *msg,char *msgError,int minimo,int tamanio);

int main()
{
    //int i;
    //primero es el tamanio del array y despues cuantos caracteres cada posicion

    //strncpy(nombres[0],"toto",20);
    //strncpy(nombres[1],"pedro",20);
    //printf("nombre: %s\n",nombres[0]);
    //printf("nombre: %s\n",nombres[1]);
    char nombres[LEN_LISTA][20];
    int i;

    //inicializar el array
    for(i=0;i<LEN_LISTA;i++)
    {
        nombres[i][20] = '\0';
    }

    //COPIAR BUFFERSTRING EN PRESULTADO EN LA FUNCION GETSTRING
    //STRNCPY(PRESULTADO,BUFFERSTRING,MAXIMO     ===>>CONTROLAR DE NO PISAR MEMORIA



    //menu
    int opcion;
    while(1)
    {
        utn_getNumero(&opcion,"1)Ingresar\n2)Listar ","ERROR.",1,2,2);
        printf("elegiste %d",opcion);
    }




    return 0;
   /* for(i=0;i<MAX;i++)
    {
        printf("Ingrese el nombre: ");
        scanf("%s",nombre[i]);
        //__fpurge(stdin);
    }

    for(i=0;i<MAX;i++)
    {
        printf("Nombre: %s\n",nombre[i]);
    }*/




}

int unt_getArrayNombre(char *pArrayNombre,char *msg,char *msgError,int minimo,int tamanio)
{
    int i;
    char aux[tamanio];


    for(i=0;i<tamanio;i++)
    {
        printf("Ingrese el nombre: ");
        scanf("%s",&aux[i]);
    }

    return 0;
}


