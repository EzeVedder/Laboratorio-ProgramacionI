#include <stdio.h>
#include <stdlib.h>
#include "utn_herramientas.h"

int main()
{
    float radio;

    utn_getAreaCircle(&radio,"Ingrese el radio del circulo: ","Reintente");
    printf("El area del circulo es: %.2f",radio);

    return 0;
}
