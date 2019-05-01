#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"



int main()
{

    int ret;
    int numer;

    ret = utn_getIntNumber(&numer,"numero: ","error",1,10,2);
    if(!ret)
    {
        printf("NUMERO: %d\n",numer);
    }

}






