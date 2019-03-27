#include <stdio.h>
#include <stdlib.h>

int pedirMaxMin(void);//devuelve vacio (void)

int main()
{

    pedirMaxMin();

    return 0;
}

int pedirMaxMin(void)
{
    int max;
    int min;
    int numero;
    int flag=0;
    int aux=0;

    while(numero!=-1)
    {


        printf("\nIngrese un numero: ");
        scanf("%d",&numero);

        if(flag==0)
        {
            max=numero;//primera vuelta
            min=numero;
        }
        else
        {
                //comparo numero con max
            if(numero>max)
            {
                max=numero;
            }
            if(numero<min)
            {
                min=numero;
            }
        }
        flag++;
    }

    printf("\nEl numero maximo es %d",max);
    printf("\nEl numero minimo es %d",min);

    return 0;
}
