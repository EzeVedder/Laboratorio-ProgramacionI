#include <stdio.h>
#include <stdlib.h>

#define lenPant 3

typedef struct
{
    char nombre[50];
    char direccion[200];
    float precio;
    int tipo;
    int isEmpty;
    int idPantalla;


}Pantalla;



int initPantalla(Pantalla* pPantalla,int lenPantalla);

int findEmptyPlace(Pantalla* pPantalla,int lenPantalla);

int altaPantalla(Pantalla* pPantalla,int lenPantalla);


int main()
{

    Pantalla pantalla[lenPant];
    int i;
    int posLibre;

    initPantalla(pantalla,lenPant);
    for(i=0;i<lenPant;i++)
    {
        printf("ID vacio en pos %d:   %d\n",i,pantalla[i].isEmpty);
        pantalla[0].isEmpty=0;
        pantalla[1].isEmpty=0;
        pantalla[2].isEmpty=0;
    }
    posLibre = findEmptyPlace(pantalla,lenPant);

    if(posLibre!=-1)
    {
        printf("Lugar en %d :",posLibre);
    }
    else
        printf("No hay mas lugar");




    return 0;
}


int initPantalla(Pantalla* pPantalla,int lenPantalla)
{
    int i;

    if(pPantalla!=NULL && lenPantalla>0)
    {
        for(i=0; i<lenPantalla;i++)
        {
            pPantalla[i].isEmpty=1;
            pPantalla[i].idPantalla=-1;
        }
    }
    return 0;
}


int altaPantalla(Pantalla* pPantalla,int lenPantalla)
{
    //int i;
    int indexFree;


    indexFree = findEmptyPlace(pPantalla,lenPantalla);
    if(indexFree)
    {
        printf("Hay lugar en pos: %d",indexFree);
    }

    return 0;
}


int findEmptyPlace(Pantalla* pPantalla,int lenPantalla)
{
    int i;
    int ret=-1;
    for(i=0;i<lenPantalla;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
