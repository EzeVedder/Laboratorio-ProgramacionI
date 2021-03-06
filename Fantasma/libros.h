#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];//nombre
    int varInt; //codigo autor
    //float varFloat;
    //char varChar;
    char varLongString[TEXT_SIZE];//apellido

}Libros;




#endif // LIBROS_H_INCLUDED

int libros_Inicializar(Libros array[], int size);                                    //cambiar libros
int libros_buscarEmpty(Libros array[], int size, int* posicion);                    //cambiar libros
int libros_buscarID(Libros array[], int size, int valorBuscado, int* posicion);                    //cambiar libros
int libros_buscarInt(Libros array[], int size, int valorBuscado, int* posicion);                    //cambiar libros
int libros_buscarString(Libros array[], int size, char* valorBuscado, int* indice);                    //cambiar libros
int libros_alta(Libros array[], int size, int* contadorID);                          //cambiar libros
int libros_baja(Libros array[], int sizeArray);                                      //cambiar libros
int libros_bajaValorRepetidoInt(Libros array[], int sizeArray, int valorBuscado);
int libros_modificar(Libros array[], int sizeArray);                                //cambiar libros
int libros_ordenarPorString(Libros array[],int size);                              //cambiar libros
int libros_listar(Libros array[], int size);                      //cambiar libros


