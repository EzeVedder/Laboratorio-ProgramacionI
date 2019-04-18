#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LEN_LISTA    100


int buscarLibre(char lista[][20],
                int len,
                int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len ; i++)
    {
        if(lista[i][0]=='\0')
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;

}


int buscarNombre(char* pNombre,
                 char lista[][20],
                 int len,
                 int* pIndex
)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(strcmp(pNombre,lista[i])==0)
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;


}

//EXISTEN LOS DATOS PRIMITIVOS (DEL LENGUAJE) Y LOS DATOS PROPIOS (ESTRUCTURAS)

/*struct Josecito ====> NO LO VAMOS A USAR ASI. ESTA ES LA MANERA MICKEY
{
    int edad;
    float peso;
}*/

typedef struct
{
    int edad;
    float peso;
}Josecito;

typedef struct
{
    int isEmpty;//UN FLAG PARA USAR Y SABER SI ESTA VACIO OSEA 1 o 0 SI ESTA VACIO ES 1 SI NO ESTA VACIO 0
    int idEmpleado;//estos dos datos van siempre. HACER UN GENERADOR DE ID
    //--------------
    char nombre[50];
    char apellido[50];

}Empleado;//DECLARAR EN EMPLEADOS .H y en .C TODAS LAS FUNCIONES PARA ABM DE EMPLEADOS
int inicializarEmpleados(Empleado* pEmpleado, int TAM);
int buscarLugarLibre(Empleado* pEmpleado,int TAM,int* pIndex);
int alta_empleado(Empleado* pEmpleado,int TAM,int* pIndex);

int main()
{
    //struct Josecito arrayJosecitos[200];
    //Josecito arrayJosecitos[200];
    Josecito auxiliar;

    auxiliar.peso = 20.45;
    printf("%.2f\n",auxiliar.peso);

    Empleado arrayEmpleados[LEN_LISTA];
    //incializacion de array empleados utilizando estructuras
    inicializarEmpleados(arrayEmpleados,LEN_LISTA);

    int opcion=0;
    char nombres[LEN_LISTA][20];
    int i,posLibre,posAeliminar;
    char buffer[20];

    // Inicializo la lista de nombres
    for(i=0; i<LEN_LISTA;i++)
        nombres[i][0]='\0';

    //INICIALIZANDO ARRAY DE ESTRUCTURAS
    int ret;
    int lugarLibre;
    int indice;
    arrayEmpleados[0].isEmpty = 0;//harcodeando valores de array
    arrayEmpleados[1].isEmpty = 0;
    arrayEmpleados[2].isEmpty = 0;
    ret = buscarLugarLibre(arrayEmpleados,LEN_LISTA,&lugarLibre);
    printf("Lugar libre (RETORNO) - %d POSICION - %d\n",ret,lugarLibre);

    alta_empleado(arrayEmpleados,LEN_LISTA,&indice);

    //_______________________________

    while(opcion!=5)
    {
        utn_getNumber(&opcion,
                      "1)ingresar\n2)listar\n4)eliminar\n5)Salir\n",
                      "NO!",
                      1,10,2);

        switch(opcion)
        {
            case 1:
            {
                printf("agregar nombre\n");

                if(buscarLibre(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("Se encontro lugar en %d\n",posLibre);

                    utn_getString(buffer,"Ingrese nombre:","No!",0,20,1);

                    strncpy(nombres[posLibre],buffer,20);
                }
                else
                    printf("No hay mas lugar!\n");

                break;
            }
            case 2:
            {
                for(i=0;i<10; i++)
                {
                    //printf("-%d: %s\n",i,nombres[i]);
                    printf("%d:\n",arrayEmpleados[i].isEmpty);
                }
                break;
            }
            case 4:
            {
                // PIDO NOMBRE
                utn_getString(buffer,"Ingrese nombre a borrar:","No!",0,20,1);

                // en buffer esta el nombre
                if(buscarNombre(buffer,nombres,LEN_LISTA,&posAeliminar)==0)
                {
                    //borro
                    nombres[posAeliminar][0]='\0';
                    printf("Eliminado\n");
                }
                else
                    printf("No existe el nombre\n");
                break;
            }
        }
    }

    return 0;
}


int inicializarEmpleados(Empleado* pEmpleado, int TAM){
    int i;
    int retorno = -1;
    if(TAM > 1 && pEmpleado != NULL){
        for(i = 0; i < TAM; i++)
            pEmpleado[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}






int buscarLugarLibre(Empleado* pEmpleado,int TAM,int* pIndex)
{
    int i;
    int retorno = -1;

    for(i=0;i<TAM;i++)
    {
        if(pEmpleado[i].isEmpty == 1)
        {
            *pIndex = i;
            retorno = 0;
            break;
        }
    }
    return retorno;
}



int alta_empleado(Empleado* pEmpleado,int TAM,int* pIndex)
{
    //int i;
    int retorno = -1;
    int indiceLibre;
    char buffer;

    buscarLugarLibre(pEmpleado,LEN_LISTA,&indiceLibre);
    if(indiceLibre==0)
    {
        utn_getString(&buffer,"Ingrese el nombre","no",1,20,2);
        retorno = 0;
    }


    return retorno;
}
