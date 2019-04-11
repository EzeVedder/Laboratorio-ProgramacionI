#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LEN_LISTA    100
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
                printf("agregar nombre\n");

                break;
            }
        }

    }






    return 0;
}
