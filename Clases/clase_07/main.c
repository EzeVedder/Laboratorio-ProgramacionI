#include <stdio.h>
#include <stdlib.h>


int isValidNumber(char *cadena);
int getString(  char *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,//por lo menos 1 caracter
                int maximo,//voy viendo cuantos caracteres maximo necesito para el caso especifico
                int reintentos);



int main()
{

    return 0;
}
