#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isValidNumber(char *cadena);
int getString(  char *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int getNumber(  int *pResultado,
                char *msg,
                char *msgError,
                int minimo,//por lo menos 1 caracter
                int maximo,//voy viendo cuantos caracteres maximo necesito para el caso especifico
                int reintentos);



int main()
{
    //int numero;




    return 0;
}









int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    char bufferStr[4096];
    fgets(bufferStr,sizeof(bufferStr),stdin);// fgets ==>trae un string de un archivo sizeof ==>tamanio de bufferstr osea el maximo
    bufferStr[strlen(bufferStr)-1] = '\0'; //strlen me devuelve el indice en donde esta el \0


    //NO HAY QUE COPIAR NUNCA ALGO DE MAS ====> PUEDE PERMITIR HACKING
    //strncpy(resultado,"1234",maximo) ===>DESTINO,ORIGEN,TAMANIO
    strncpy(pResultado,"1234",maximo);//1234 + \0 necesita un lugar mas para el \0 osea 5 lugares en el array
    return 0;
}

int isValidNumber(char *cadena)
{


    return 1;
}


int getNumber(  int *pResultado,
                char *msg,
                char *msgError,
                int minimo,//por lo menos 1 caracter
                int maximo,//voy viendo cuantos caracteres maximo necesito para el caso especifico
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4096];//4kb ES UN AUXILIAR QUE ME SIRVE PARA GUARDAR LOS DATOS
    //el buffer es un array no pongo el &
    int bufferInt;

    if(pResultado != NULL && reintentos >=0)//FALTA
    {
        //BIEN    el 1 es minimo caracter 6 es maximo caracter 1 es reintentos
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidNumber(bufferStr))//no es el mismo minimo y maximo de antes ESTO TIENE QUE VER CON MIN Y MAX DE CARACTERES
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pResultado = bufferInt;
            }
        }
    }
    reintentos--;

    return retorno;
}



