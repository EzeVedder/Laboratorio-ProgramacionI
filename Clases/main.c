#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include <stdio_ext.h>
#define LEN_LISTA    100

int buscarIndiceLibreEnArray(char lista[][20],int tamanio,int *pIndice);// va a multiplicar el indice por 56
int buscarNombreEnArray(char *pNombre,
                        char lista[][20],
                        int len,
                        int *pIndex);


int main()
{

    int opcion;

    /*
    strncpy(nombres[0],"toto",20);
    strncpy(nombres[1],"pepito",20);
    printf("nombre:%s\n",nombres[0]);
    printf("nombre:%s\n",nombres[1]);
    */

    /*
    strncpy(nombres[0],"\0",20);
    nombres[0][0] = '\0';
    nombres[1][0] = '\0';
    nombres[2][0] = '\0';
    */
    char nombres[LEN_LISTA][20];
    int i;
    char buffer;
    int posAeliminar;
    // Inicializacion
    for(i=0; i<LEN_LISTA; i++)
    {
        nombres[i][0] = '\0';
    }

    //HARCODEO DE PRIMER LUGAR Y SEGUNDO LUGAR
    nombres[0][0] ='A';
    nombres[1][0] ='T';

    //
    while(1)
    {

        getNumber(&opcion,
                      "1)ingresar\n2)listar\n4)Eliminar\n",
                      "NO!",
                      1,10,2);

        printf("elegiste opcion: %d\n",opcion);
        switch(opcion)
        {
            case 1:
            {
                int posLibre;
                printf("agregar nombre\n");
                if(buscarIndiceLibreEnArray(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("se encontro lugar en %d\n",posLibre);
                    getString(&buffer,"Ingrese: ","error",1,20,1);//guarda lo que pone el usuario osea los datos del nombre en buffer
                    //nombres[posLibre] = buffer; ===>> esta mal porque es cadena de carcteres hay que usar la funcion strncpy
                   //fgets(buffer,20,stdin);
                   //buffer[strlen(buffer) - 1] = '\0';
                   printf("Se ingreso %s\n",buffer);
                   strncpy(nombres[posLibre],buffer,20);//ESTO ESTA BIEN
                   i++;

                }
                //__fpurge(stdin);

                scanf("%s",nombres[i]);

                break;
            }
            case 2:
            {
                int i;
                for(i=0;i<LEN_LISTA;i++)
                {
                    printf("\nNombre cargado : %s",nombres[i]);
                    break;
                }
            }
            case 4:
            {
                buscarNombreEnArray(buffer,nombres,LEN_LISTA,&posAeliminar);
                nombres[posAeliminar][0]=='\0';
            }
        }
        i++;

    }


    return 0;
}




int buscarIndiceLibreEnArray(char lista[][20],int tamanio,int *pIndice)
{
    int i;
    int retorno=-1;

    for(i=0;i<tamanio;i++)
    {
        if(lista[i][0]=='\0')
        {
            *pIndice = i;
            retorno = 0;
            break;
        }
    }
    return retorno;
}



int buscarNombreEnArray(char *pNombre,
                        char lista[][20],
                        int len,
                        int *pIndex)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(strcmp(pNombre,lista[i]==0))
        {
            *pIndex=i;
            retorno =0;
            break;
        }
    }
    return retorno;
}
