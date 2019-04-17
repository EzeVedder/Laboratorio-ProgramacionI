#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int initEmployees(employee* pEmployee, int length){
    int i, retorno = -1;
    if(length > 1 && pEmployee != NULL){
        for(i = 0; i < length; i++)
            pEmployee[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector){
    int i, retorno = -1;
    if(length > 1 && pEmployee != NULL){
        for(i = 0; i < length; i++)
            if(pEmployee[i].isEmpty){
                retorno = 0;
                pEmployee[i].isEmpty = 0;
                pEmployee[i].id = id;
                strcpy(pEmployee[i].name,name);
                strcpy(pEmployee[i].lastName,lastName);
                pEmployee[i].salary = salary;
                pEmployee[i].sector = sector;
                break;
            }
    }
    return retorno;
}

employee* findEmployeeById(employee* pEmployee, int length,int id){
    int i;
    employee* retorno = NULL;
    if(length > 1 && pEmployee != NULL){
        for(i = 0; i < length; i++)
            if(pEmployee[i].isEmpty == 0 && pEmployee[i].id == id){
                retorno = pEmployee + i;
                break;
            }
    }

    return retorno;
}

int removeEmployee(employee* pEmployee, int length, int id){
    int i, retorno = -1;
    if(length > 1 && pEmployee != NULL){
        for(i = 0; i < length; i++)
            if(pEmployee[i].isEmpty == 0 && pEmployee[i].id == id){
                pEmployee[i].isEmpty = 1;
                retorno = 0;
                break;
            }
    }
    return retorno;

    /*
        employee* auxiliar = findEmployeedById(pEmployee,length,id);
        retorno = -1;
        if(auxiliar!=NULL){
            retorno = 0;
            auxiliar->isEmpty = 1;

        }
    */

}

int sortEmployeeByName(employee* pEmployee, int length, int order)
{
    char flagswap;
    employee aux;
    int retorno = -1;
    if(length > 1 && pEmployee != NULL){
        do{
            flagswap = 0;
            int i;
            for(i = 0; i < length-1; i++){
                    if((order == 1 && strcmp(pEmployee[i].name,pEmployee[i+1].name) > 0) ||\
                       (order == 0 && strcmp(pEmployee[i].name,pEmployee[i+1].name) < 0)){
                        aux = pEmployee[i];
                        pEmployee[i] = pEmployee[i+1];
                        pEmployee[i+1] = aux;
                        flagswap = 1;

                    }
            }
        }while(flagswap);

        retorno = 0;
    }

    return retorno;
}

int printEmployees(employee* pEmployee, int length)
{
    int i;
    printf("\n  Id   -       Name       -     Last Name    - Salary  - Sector");
    for(i=0; i< length; i++)
    {
        if(!pEmployee[i].isEmpty)
            printf("\n%6i - %-16s - %-16s - %4.2f - %6d",pEmployee[i].id, pEmployee[i].name, pEmployee[i].lastName, pEmployee[i].salary, pEmployee[i].sector );
    }
    return 0;
}

//FUNCIONES GENERALES:
char getChar(char* message){ //Pide y obtiene un dato tipo CHAR por teclado.
    char buffer;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&buffer);
    return buffer;
}

int getInt(char* message){ //Pide y obtiene un dato tipo INT por teclado.
    int buffer;
    printf("%s",message);
    fflush(stdin);
    scanf("%d",&buffer);
    return buffer;
}

void getString(char* array, char* message){ //Modifica una cadena de caracteres seg�n lo ingresado por teclado.
    printf("%s",message);
    fflush(stdin);
    gets(array);
}

int getOption(int maxOptions){ //Pide que se ingrese por teclado el n�mero correspondiente a la opci�n elegida, valida y devuelve la respuesta.
    int option = getInt("\nElija una opcion: ");
    while(checkIntRange(option,1,maxOptions) == 0){ //Valida que la opci�n ingresada est� en el rango correcto.
        printf("\nERROR. Debe ingresar un numero entre 1 y %d incluidos: ",maxOptions);
        option = getInt("\nElija una opcion: ");
    }
    return option;
}

int checkPositionFirstLetter(char* string){ //Informa la posici�n de la primera letra de una cadena de caracteres, devuelve la posici�n o -1 si no hay letras.
    int i;
    for(i = 0; string[i]!= '\0'; i++)
        if((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))
            return i; //Devuelve la posici�n de la primera letra que encuentra
    return -1; //Si no encuentra ninguna letra devuelve -1.
}

char checkStringLength(char* string, int size){ //Informa datos de validaci�n sobre el largo del string.
    if(strlen(string) > size-1)
        return 0; //Devuelve 0 si el largo de la cadena de caracteres supera al tama�o del array-1 (el ultimo espacio es para el -contrabarra-0).
    else if(strlen(string) == 0)
        return -1; //Devuelve -1 si la cadena de caracteres est� vac�a (Ni espacios, ni nada).
    return 1; //Devuelve 1 si la cadena de caracteres no est� vac�a y el largo de la misma es menor o igual al tama�o del array-1.
}

char checkIntRange(int value, int minIncluded, int maxIncluded){ //Informa si el INT a evaluar est� o no dentro de un rango espec�fico.
    if(value < minIncluded || value > maxIncluded)
        return 0;
    return 1; //Devuelve 1 si est� en el rango, sino 0.
}

char checkOnlyLettersAndSpace(char* array){ //Informa si la cadena de caracteres contiene s�lo letras y espacios, o no.
    int i;
    for(i=0; array[i]!='\0'; i++)
        if(!(array[i] >= 'A' && array[i] <= 'Z') && !(array[i] >= 'a' && array[i] <= 'z') && array[i] != ' ')
            return 0;
    return 1; //Devuelve 1 si solo contiene letras y espacios, sino 0.
}

char checkStringOnlyNumbers(char* string){ //Informa si la cadena de caracteres contiene s�lo n�meros, o no.
    int i;
    for(i=0; string[i]!='\0'; i++)
        if(isdigit(string[i]) == 0)
            return 0;
    return 1; //Devuelve 1 si son todos numeros, sino 0.
}

char confirm(char* message){ //Hace una pregunta y pide por respuesta 'S' para si o 'N' para no. Valida respuesta.
    char answer;
    printf("%s (S/N): ",message);
    fflush(stdin);
    scanf("%c",&answer);
    while(answer != 'S' &&  answer != 's' &&  answer != 'N' &&  answer != 'n')
        answer = getChar("ERROR. Debe ingresar S para si o N para no. Reingrese: ");
    if(answer == 'S' || answer == 's')
        return 1;
    return 0; //Devuelve 1 si la respuesta es S�, 0 si es NO.
}


//FUNCIONES ESPEC�FICAS DEL PROGRAMA:
int obtenerEspacioLibre(Persona lista[], int size){ //Obtiene el primer �ndice libre del array.
    int i;
    for(i = 0; i < size; i++)
        if(lista[i].estado == LIBRE)
            return i; //Devuelve el �ndice de la primera posici�n del array que se encuentre desocupada.
    return -1; //Si no hay posiciones desocupadas devuelve -1.
}

int searchDniCoincidence(Persona list[], int size, char* dni){ //Obtiene el �ndice (OCUPADO) que coincide con el dni pasado por parametro.
    int i;
    for(i = 0; i < size; i++)
        if(strcmp(list[i].dni, dni) == 0 && list[i].estado != LIBRE) //S�lo busca en los espacios que NO est�n LIBRES.
            return i; //De encontrarlo, devuelve el indice que coincide con el parametro dni.
    return -1; //Si no hay coincidencia devuelve -1.
}

void sortByStatus(Persona array[], int size){ //BubleSort para ordenar un array por estado (orden descendente).
    char flagswap;
    Persona aux;
    do{
        flagswap = 0;
        int i;
        for(i = 0; i < size-1; i++)
            if(array[i].estado < array[i+1].estado){
                flagswap = 1;
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
    }while(flagswap);
}

void sortByName(Persona array[], int size){ //BubleSort para ordenar un array por nombre (orden ascendente).
    char flagswap;
    Persona aux;
    do{
        flagswap = 0;
        int i;
        for(i = 0; i < size-1; i++)
            if(stricmp(array[i].nombre,array[i+1].nombre) > 0){
                flagswap = 1;
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
    }while(flagswap);
}

void getName(char* arrayName, int sizeArrayName){ //Pide y obtiene un nombre por teclado, valida, y guarda en array de caracteres.
    getString(arrayName,"Nombre: ");
    while(checkStringLength(arrayName,sizeArrayName) != 1 || checkOnlyLettersAndSpace(arrayName) == 0 || checkPositionFirstLetter(arrayName) != 0){
        if(checkStringLength(arrayName,sizeArrayName) == -1 || checkPositionFirstLetter(arrayName) == -1) // Si el array est� vac�o � si no contiene ninguna letra...
            getString(arrayName,"ERROR. Debe ingresar un nombre: ");
        else if(checkPositionFirstLetter(arrayName) != 0) // Si el primer caracter no es una letra...
            getString(arrayName,"ERROR. El primer caracter debe ser una letra. Reingrese: ");
        else if(checkOnlyLettersAndSpace(arrayName) == 0) // Si contiene algo que no sean letras y espacios...
            getString(arrayName,"ERROR. El nombre solo puede contener letras y espacios. Reingrese: ");
        else{ // Si supera la cantidad de caracteres m�ximos (tama�o del array -1)...
            printf("ERROR. El nombre no puede contener mas de %d caracteres. ",sizeArrayName-1);
            getString(arrayName,"Reingrese: ");
        }
    }
}

unsigned char getAge(void){ //Pide y obtiene una edad por teclado, valida y devuelve la respuesta.
    unsigned char buffer = getInt("Edad: ");
    while(checkIntRange(buffer,0,120) == 0) //Valida si se encuentra dentro de un rango l�gico para una edad.
        buffer = getInt("ERROR. Debe ingresar una edad valida. Reingrese: ");
    return buffer;
}

char getDNI(char* arrayDni, Persona* arrayPersonas, int sizeArrayPersonas){ //Pide y obtiene un DNI por teclado, valida, y guarda en array de caracteres.
    getString(arrayDni,"DNI: ");
    while(checkStringOnlyNumbers(arrayDni) == 0 || searchDniCoincidence(arrayPersonas,sizeArrayPersonas,arrayDni) != -1 || strlen(arrayDni) != 8){
        if(checkStringOnlyNumbers(arrayDni) == 0 || strlen(arrayDni) != 8) //Si el dni ingresado no contiene 8 caracteres, todos n�meros...
            getString(arrayDni,"ERROR. Ingrese un DNI valido (solo 8 NUMEROS): ");
        else{ //Si se encontr� coincidencia con otro dni de la lista...
           printf("ERROR. El DNI ingresado ya se encuentra en la lista.");
           if(confirm("\nDesea ingresar otro DNI?")) //Pregunta si, ya que el dni ingresado se encuentra en la lista, desea ingresar otro.
                getString(arrayDni,"DNI: "); //Si lo desea vuelve a pedir.
           else{
                printf("Operacion abortada.");
                return 0; //Si no lo desea devuelve 0 (el usuario abort� la operaci�n).
           }
        }
    }
    return 1; // Devuelve 1 si el DNI se ingres� correctamente.
}

int counterAge(Persona* arrayPersonas, int sizeArrayPersonas, int minIncluded, int maxIncluded){ //Contador de posiciones ocupadas que est�n en un rango de edad determinado por par�metros.
    int i;
    int counter = 0;
    for(i = 0; i < sizeArrayPersonas; i++)
        if(arrayPersonas[i].estado == OCUPADO && arrayPersonas[i].edad >= minIncluded && arrayPersonas[i].edad <= maxIncluded)
            counter++; //Si es una posici�n ocupada y la edad est� dentro del rango, el contador suma 1.
    return counter; //Devuelve la cantidad de edades de la lista que est�n dentro del rango.
}


//ESTRUCTURA DEL PROGRAMA:
int showMenu(int maxOptions){ //Muestra el men� y pide que el usuario ingrese la opci�n deseada por teclado.
    system("cls");
    printf("~ MENU ~\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    return getOption(maxOptions); //Devuelve la opci�n elegida por el usuario (Validada: Debe estar entre 0 y maxOptions).
}

char addPerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeName){
    system("cls");
    int i = obtenerEspacioLibre(arrayPersonas,sizeArrayPersonas); //Obtiene el primer indice libre del array.
    if(i == -1) //Si no hay espacios libres...
        printf("No hay espacios libres. Operacion abortada.\n");
    else{ //Si HAY espacios libres...
        getName(arrayPersonas[i].nombre,sizeName);
        arrayPersonas[i].edad = getAge();
        if(getDNI(arrayPersonas[i].dni, arrayPersonas, sizeArrayPersonas))
            arrayPersonas[i].estado = OCUPADO; //Va a ocupar la posici�n si el DNI se ingres� correctamente (1), si el usuario abort� la operaci�n (0) seguir� libre.
    }
    return confirm("\nDesea realizar otra operacion?"); //Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
}

char deletePerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeDni){ //Pide que se ingrese el DNI de la persona a borrar, valida coincidencia y pide confirmaci�n.
    int dniPosition;
    char buffer[sizeDni];
    do{
        getString(buffer,"Ingrese DNI de la persona a borrar: "); //Pide que se ingrese el DNI de la persona a borrar.
        dniPosition = searchDniCoincidence(arrayPersonas,sizeArrayPersonas,buffer); //Devuelve el indice correspondiente al DNI, -1 si no encontr� coincidencia.
    }while(dniPosition == -1 && confirm("El DNI ingresado es invalido. Desea volver a ingresar?")); //En caso que no haya coincidencia, se pregunta si desea ingresar otro.
    if(dniPosition != -1){ //Si el DNI ingresado es v�lido (hay coincidencia)...
            printf("\nSeguro desea borrar a %s?",arrayPersonas[dniPosition].nombre); //Pide confirmaci�n con nombre de la persona a borrar.
            if(confirm("")){
                arrayPersonas[dniPosition].estado = LIBRE; //Si el usuario confirma, el estado de esa persona pasa a ser LIBRE.
                printf("\nOperacion completada.\n");
            }
            else
                printf("\nOperacion abortada.\n"); //Si el usuario rechaza la confirmaci�n, la operaci�n es abortada.
        }
    else
        printf("\nOperacion abortada.\n"); //Si el DNI ingresado es inv�lido (no hay coincidencia) y el usuario no quiso ingresar otro, la operaci�n es abortada.
    return confirm("\nDesea realizar otra operacion?"); //Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
}

char printOrderedList(Persona* arrayPersonas, int size){ //Imprime la lista actual de personas por orden alfab�tico ascendente.
    sortByStatus(arrayPersonas,size); //Ordena el array por estados, primero los ocupados.
    //Obtiene la primer POSICI�N LIBRE del array, que coincide en n�mero con el TAMA�O de la fracci�n del array con los elementos ocupados.
    int sizeFull = obtenerEspacioLibre(arrayPersonas,size); //Los sectores ocupados est�n todos consecutivos en un mismo fragmento del array porque se lo orden� antes.
    if(sizeFull == -1)
        sizeFull = size; //Si no hay espacios libres, todo el TAMA�O del array est� ocupado.
    sortByName(arrayPersonas,sizeFull); //Ordena la fracci�n OCUPADA del array alfabeticamente (ascendente).

    system("cls");
    printf("~ Nombre - Edad - DNI ~\n");
    if(sizeFull == 0) //Si no hay ningun dato guardado en la lista.
        printf("\nLa lista de personas se encuentra vacia.\n");
    else{
        int i;
        for(i = 0; i < sizeFull; i++) //Imprime hasta el �ltimo espacio ocupado (ya ordenado).
            printf("%d) %s - %d - %s\n",i+1,arrayPersonas[i].nombre,arrayPersonas[i].edad,arrayPersonas[i].dni);
    }
    return confirm("\nDesea realizar otra operacion?"); //Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
}

char printAgesGraphic(Persona* arrayPersonas, int sizeArrayPersonas){ //Imprime gr�fico de edades de las personas en la lista, categorizado por: <18, 19-35, y >35.
    int counterAgeArray[3] = {counterAge(arrayPersonas,sizeArrayPersonas,0,18), counterAge(arrayPersonas,sizeArrayPersonas,19,35), counterAge(arrayPersonas,sizeArrayPersonas,35,120)};
    //counterAgeArray guarda en la posici�n 0 la CANTIDAD de personas menores de 18, en la 1 los que tienen entre 19 y 35, en la 2 los mayores de 35.
    char graphicMax[4] = {' ',' ',' ','\0'}; //ArrayMax se llenar� con un asterisco en la posici�n correspondiente al rango de edad predominante (si existiese).
    char graphicMid[4] = {' ',' ',' ','\0'}; //ArrayMid se llenar� con un asterisco en la posici�n correspondiente al rango de edad intermedio y predominante.
    //cada columna corresponde a cada una de las barras del gr�fico. Por defecto est�n vac�as.
    int i=0; //Posici�n por defecto correspondiente a menores de 18.
    int max = counterAgeArray[i]; //Cantidad correspondiente a la categor�a predominante. Por defecto, cant. menores de 18.
    int min = counterAgeArray[i]; //Cantidad correspondiente a la categor�a en menor proporci�n. Por defecto, cant. menores de 18.
    int mid; //Cantidad correspondiente a la categor�a intermedia.
    int indMax = i; //Posici�n correspondiente a la categor�a predominante. Por defecto, menores de 18.
    int indMin = i; //Posici�n correspondiente en menor proporci�n. Por defecto, menores de 18.
    for(i = 1;i < 3; i++){ //Recorre el array con las cantidades para cada categor�a (counterAgeArray) buscando el m�nimo y el m�ximo.
        if(counterAgeArray[i] < min){
            min = counterAgeArray[i];
            indMin = i;
        }
        if(counterAgeArray[i] > max){
            max = counterAgeArray[i];
            indMax = i;
        } //De encontrar, asignar� nuevos valores y posiciones para las variables correspondientes.
    }
    graphicMax[indMax] = '*';  //Cargar� el asterisco en la columna de arrayMax que corresponda con la categor�a predominante.
    graphicMid[indMax] = '*'; //Cargar� el asterisco en la columna de arrayMid que corresponda con la categor�a predominante.

    for(i=0;i<3;i++)
        if(i != indMin && i != indMax){ //An�lisis de posici�n y valor de mid (explicaci�n detallada abajo).
            mid = counterAgeArray[i]; //Se cargar� la cantidad correspondiente a mid.
            graphicMid[i] = '*'; //Cargar� el asterisco en la columna de arrayMid que corresponda.
        }
    /*(1)Si los 3 par�metros de counterAgeArray son distintos, mid ser� la posici�n que no es min ni max. [mid != min && mid != max]
     *(2)Si los 3 son iguales min y max ser�n la posici�n 0 (por defecto), y mid ser� la posici�n 1, que es el mismo valor que est� en las otras dos. [mid == min && mid == max]
     *Si hay 2 par�metros iguales y uno distinto:
     *(3)Si el repetido es min, mid ser� la posici�n que no se guard� como min o max, pero que es igual al valor de min. [mid == min]
     *(4)Si el repetido es max, mid ser� la posici�n que no se guard� como min o max, pero que es igual al valor de max. [mid == max]
    */
    system("cls");
    printf("Grafico de edades: \n\n"); //Una vez finalizado el an�lisis, imprime el gr�fico.
    for(;max > mid; max--)
        printf(" %c\t %c\t %c\n",graphicMax[0],graphicMax[1],graphicMax[2]);  //Se imprime si max es mayor a mid. Casos: (1)
    for(;mid > min; mid--)
        printf(" %c\t %c\t %c\n",graphicMid[0],graphicMid[1],graphicMid[2]); //Se imprime cuando mid es menor o igual a max y mayor a min. Casos: (1),(4)
    for(;min > 0; min--)
        printf(" *\t *\t *\n"); //Se imprime si min es mayor a cero y menor o igual a mid. Casos: (1),(2),(3),(4) (Siempre que no valga cero).
    printf("<18\t19-35\t>35\n");

    return confirm("\nDesea realizar otra operacion?"); //Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
}
