#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libros.h" //cambiar por nombre entidad
#include "socios.h"
#include "autor.h"
#include "prestamos.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    //int contadorIdlibros=0;                   //cambiar
    int contadorIdSocios=0;

    Libros arrayLibros[QTY_TIPO];                   //cambiar
    libros_Inicializar(arrayLibros,QTY_TIPO);                   //cambiar
    Socios arraySocios[QTY_TIPO];
    socios_Inicializar(arraySocios,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                //libros_alta(arrayLibros,QTY_TIPO,&contadorIdlibros);                   //cambiar
                socios_alta(arraySocios,QTY_TIPO,&contadorIdSocios);
                break;

            case 2: //Modificar
                libros_modificar(arrayLibros,QTY_TIPO);                   //cambiar
                socios_modificar(arraySocios,QTY_TIPO);
                break;

            case 3: //Baja
                libros_baja(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                libros_listar(arrayLibros,QTY_TIPO);                   //cambiar
                socios_listar(arraySocios,QTY_TIPO);
                break;

            case 5://Ordenar
                libros_ordenarPorString(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
