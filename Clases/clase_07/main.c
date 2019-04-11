#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


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
    int numero;

    getNumber(&numero,"Ingrese numero: ","ERROR. REINTENTE\n",0,12,2);
    printf("%d",numero);

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
    int ret;
    fgets(bufferStr,sizeof(bufferStr),stdin);// fgets ==>trae un string de un archivo sizeof ==>tamanio de bufferstr osea el maximo
    bufferStr[strlen(bufferStr)-1] = '\0'; //strlen me devuelve el indice en donde esta el \0
    if(strlen(bufferStr)>=minimo && strlen(bufferStr)<=maximo)

    //NO HAY QUE COPIAR NUNCA ALGO DE MAS ====> PUEDE PERMITIR HACKING
    //strncpy(resultado,"1234",maximo) ===>DESTINO,ORIGEN,TAMANIO

    //1234 + \0 necesita un lugar mas para el \0 osea 5 lugares en el array
    strncpy(pResultado,"1234",maximo);
    return 0;
}

int isValidNumber(char *cadena)
{
    int i;
    int ret=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0'||cadena[i]>'9')
            {
                break;
            }
            i++;
        }
        if(cadena[i]=='0')
        ret=1;
    }
    return ret;
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
        reintentos--;
    }


    return retorno;
}



