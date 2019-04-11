#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LEN_LISTA    100

int buscarIndiceLibreEnArray(char lista[][20],int tamanio,int *pIndice);// va a multiplicar el indice por 56

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

        utn_getNumber(&opcion,
                      "1)ingresar\n2)listar\n",
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

                }
                scanf("%s",nombres[i]);
                i++;
                break;
            }
            case 2:
            {
                for(i=0;i<LEN_LISTA;i++)
                {
                    printf("Nombre cargado : %s",nombres[i]);
                    break;
                }
            }
        }

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
