#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define SIZE 20 //Tamaño del array tipo Persona (lista de personas)
#define SIZE_NOMBRE 50 //Tamaño de cada array que guarda un nombre.
#define SIZE_DNI 9 //Tamaño de cada array que guarda un DNI.
#define LIBRE 0 //Si la posición está desocupada y se puede usar.
#define OCUPADO 1 //Si la posición ya está ocupada.

typedef struct {
    char nombre[SIZE_NOMBRE];
    unsigned char edad;
    char dni[SIZE_DNI];
    char estado;
}Persona;

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param pEmployee employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(employee* pEmployee, int length);

/** \brief add in a existing list of employees the values recived as parameters
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector);

/** \brief find a Employee by Id
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return employee* Return a (Employee pointer) if ok or (NULL pointer) if [Invalid length or NULL pointer recived or employeed not found]
 *
 */
employee* findEmployeeById(employee* pEmployee, int length,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(employee* pEmployee, int length, int id);

/** \brief Sort the elements in the array of employees by Name, the argument order indicate UP or DOWN order
 *
 * \param pEmployee employee*
 * \param length int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeeByName(employee* pEmployee, int length, int order);

/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee* pEmployee, int length);


//FUNCIONES GENERALES:
//GET:
/**
 * Obtiene y obtiene un dato tipo CHAR por teclado.
 * @param message - mensaje a mostrar en pantalla para pedir el ingreso del dato.
 * @return dato tipo CHAR ingresado por teclado.
 */
char getChar(char* message);

/**
 * Obtiene y obtiene un dato tipo INT por teclado.
 * @param message - mensaje a mostrar en pantalla para pedir el ingreso del dato.
 * @return dato tipo INT ingresado por teclado.
 */
int getInt(char* message);

/**
 * Modifica una cadena de caracteres según lo ingresado por teclado.
 * @param array - array tipo char donde se guardará el string.
 * @param message - mensaje a mostrar en pantalla para pedir el ingreso del dato.
 */
void getString(char* array, char* message);

/**
 * Pide que se ingrese por teclado el número correspondiente a la opción elegida, valida y devuelve la respuesta.
 * @param maxOptions - Cantidad de opciones/Número de la última opción. Determina el rango de números válidos como opciones (entre 1 y maxOptions, incluido).
 * @return Devuelve la respuesta elegida por el usuario (ya validada).
 */
int getOption(int maxOptions);

//CHECK:
/**
 * Informa la posición de la primera letra de una cadena de caracteres, devuelve la posición o -1 si no hay letras.
 * @param string - cadena de caracteres a evaluar.
 * @return Devuelve la posición de la primera letra que encuentra.
 * @return Devuelve -1 si no contiene ninguna letra.
 */
int checkPositionFirstLetter(char* string);

/**
 * Informa datos de validación sobre el largo del string.
 * @param string - cadena de caracteres a evaluar.
 * @param size - Tamaño del array de caracteres (string).
 * @return Devuelve 0 si el largo de la cadena de caracteres supera al tamaño del array-1 (el ultimo espacio es para el -contrabarra-0).
 * @return Devuelve -1 si la cadena de caracteres está vacía (Ni espacios, ni nada).
 * @return Devuelve 1 si la cadena de caracteres no está vacía y el largo de la misma es menor o igual al tamaño del array-1.
 */
char checkStringLength(char* string, int size);

/**
 * Informa si el INT a evaluar está o no dentro de un rango específico.
 * @param value - valor numérico tipo INT a evaluar.
 * @param minIncluded - mínimo incluído.
 * @param maxIncluded - máximo incluído.
 * @return Devuelve 0 si NO está dentro del rango.
 * @return Devuelve 1 si está dentro del rango.
 */
char checkIntRange(int value, int minIncluded, int maxIncluded);

/**
 * Informa si la cadena de caracteres contiene sólo letras y espacios, o no.
 * @param array - cadena de caracteres a evaluar.
 * @return Devuelve 0 si NO contiene sólo letras y espacios.
 * @return Devuelve 1 si contiene sólo letras y espacios.
 */
char checkOnlyLettersAndSpace(char* array);

/**
 * Informa si la cadena de caracteres contiene sólo números, o no.
 * @param string - cadena de caracteres a evaluar.
 * @return Devuelve 0 si NO contiene sólo números.
 * @return Devuelve 1 si contiene sólo números.
 */
char checkStringOnlyNumbers(char* string);

//CONFIRM:
/**
 * Hace una pregunta y pide por respuesta 'S' para si o 'N' para no. Valida respuesta.
 * @param message - pregunta a mostrar por pantalla.
 * @return Devuelve 1 si la respuesta es sí.
 * @return Devuelve 0 si la respuesta es no.
 */
char confirm(char* message);


//FUNCIONES ESPECÍFICAS DEL PROGRAMA:
/**
 * Obtiene el primer índice libre del array.
 * @param lista - el array de la estructura que contiene la lista.
 * @param size - tamaño del array.
 * @return el primer indice disponible.
 * @return Si no hay ningun indice disponible devuelve -1.
 */
int obtenerEspacioLibre(Persona lista[], int size);

/**
 * Obtiene el índice que coincide con el dni pasado por parametro (sólo busca en las posiciones OCUPADAS).
 * @param list - el array de la estructura que contiene la lista.
 * @param size - tamaño del array de la estructura.
 * @param dni - el dni a ser buscado en el array.
 * @return De encontrarlo, devuelve el indice que coincide con el parametro dni.
 * @return Si no encuentra coincidencia devuelve -1.
 */
int searchDniCoincidence(Persona list[], int size, char* dni);

/**
 * BubleSort para ordenar un array por estado (orden descendente).
 * @param array - el array a ordenar.
 * @param size - tamaño del array a ordenar.
 */
void sortByStatus(Persona array[], int size);

/**
 * BubleSort para ordenar un array por nombre (orden ascendente).
 * @param array - el array a ordenar.
 * @param size - tamaño del array a ordenar.
 */
void sortByName(Persona array[], int size);

/**
 * Pide y obtiene un nombre por teclado, valida, y guarda en array de caracteres.
 * Sobre la validación: Se debe ingresar algo; el primer caracter debe ser una letra;(...)
 * (...) sólo se pueden ingresar letras y espacios; el tamaño de la cadena de caracteres no puede superar el tamaño del array-1.
 * @param arrayName - el array de caracteres donde se guarda el nombre.
 * @param size - tamaño del array donde se guarda el nombre.
 */
void getName(char* arrayName, int sizeArrayName);

/**
 * Pide y obtiene una edad por teclado.
 * @return Devuelve la respuesta VALIDADA (Debe estar entre 0 y 120, rango lógico para una edad)
 */
unsigned char getAge(void);

/**
 * Pide y obtiene un DNI por teclado, valida, y guarda en array de caracteres.
 * Sobre la validación: Se deben ingresar 8 caracteres y todos deben ser números;(...)
 * (...) además el DNI no puede coincidir con otro que ya esté en la lista (en posición OCUPADA).
 * (...) Si encuentra coincidencia, se le permitirá elegir al usuario si abortar la operación o ingresar otro DNI.
 * @param arrayDni - el array de caracteres donde se guarda el DNI.
 * @param arrayPersonas - el array de la estructura que contiene la lista.
 * @param sizeArrayPersonas - tamaño del array de la estructura.
 * @return Devuelve 1 si se ingresó el dni correctamente.
 * @return Devuelve 0 si se abortó la operación.
 */
char getDNI(char* arrayDni, Persona* arrayPersonas, int sizeArrayPersonas);

/**
 * Contador de posiciones ocupadas que están en un rango de edad determinado por parámetros.
 * @param arrayPersonas - el array de la estructura que contiene la lista.
 * @param sizeArrayPersonas - tamaño del array de la estructura.
 * @param minIncluded - mínimo incluído.
 * @param maxIncluded - máximo incluído.
 * @return Devuelve la cantidad de edades de la lista que están dentro del rango.
 */
int counterAge(Persona* arrayPersonas, int sizeArrayPersonas, int minIncluded, int maxIncluded);


//ESTRUCTURA DEL PROGRAMA:
/**
 * Muestra el menú y pide que el usuario ingrese la opción deseada por teclado.
 * @return Devuelve la opción elegida por el usuario (Validada: Debe estar entre 0 y maxOptions).
 */
int showMenu(int maxOptions);

/**
 * Pide el ingreso de datos para agregar una nueva persona a la lista.
 * @param array con la lista de personas.
 * @param tamaño del array de personas.
 * @param tamaño del array donde se guarda el nombre.
 * @return Devuelve 1 si el usuario quiere realizar otra operación, 0 si no lo desea.
 */
char addPerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeName);

/**
 * Pide que se ingrese el DNI de la persona a borrar de la lista, valida que haya coincidencia (con alguna posición ocupada) y pide confirmación antes de proceder.
 * @param array con la lista de personas.
 * @param tamaño del array de personas.
 * @param tamaño del array donde se guarda el DNI.
 * @return Devuelve 1 si el usuario quiere realizar otra operación, 0 si no lo desea.
 */
char deletePerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeDni);

/**
 * Imprime la lista actual de personas por orden alfabético ascendente.
 * @param array con la lista de personas.
 * @param tamaño del array.
 * @return Devuelve 1 si el usuario quiere realizar otra operación, 0 si no lo desea.
 */
char printOrderedList(Persona* arrayPersonas, int size);

/**
 * Imprime gráfico (tipo columnas) de edades de las personas en la lista, categorizado por: <18, 19-35, y >35.
 * @param array con la lista de personas.
 * @param tamaño del array de personas.
 * @return Devuelve 1 si el usuario quiere realizar otra operación, 0 si no lo desea.
 */
char printAgesGraphic(Persona* arrayPersonas, int sizeArrayPersonas);

#endif // FUNCIONES_H_INCLUDED
