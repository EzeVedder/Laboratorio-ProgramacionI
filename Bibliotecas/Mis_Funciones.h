#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define SIZE 20 //Tama�o del array tipo Persona (lista de personas)
#define SIZE_NOMBRE 50 //Tama�o de cada array que guarda un nombre.
#define SIZE_DNI 9 //Tama�o de cada array que guarda un DNI.
#define LIBRE 0 //Si la posici�n est� desocupada y se puede usar.
#define OCUPADO 1 //Si la posici�n ya est� ocupada.

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
 * Modifica una cadena de caracteres seg�n lo ingresado por teclado.
 * @param array - array tipo char donde se guardar� el string.
 * @param message - mensaje a mostrar en pantalla para pedir el ingreso del dato.
 */
void getString(char* array, char* message);

/**
 * Pide que se ingrese por teclado el n�mero correspondiente a la opci�n elegida, valida y devuelve la respuesta.
 * @param maxOptions - Cantidad de opciones/N�mero de la �ltima opci�n. Determina el rango de n�meros v�lidos como opciones (entre 1 y maxOptions, incluido).
 * @return Devuelve la respuesta elegida por el usuario (ya validada).
 */
int getOption(int maxOptions);

//CHECK:
/**
 * Informa la posici�n de la primera letra de una cadena de caracteres, devuelve la posici�n o -1 si no hay letras.
 * @param string - cadena de caracteres a evaluar.
 * @return Devuelve la posici�n de la primera letra que encuentra.
 * @return Devuelve -1 si no contiene ninguna letra.
 */
int checkPositionFirstLetter(char* string);

/**
 * Informa datos de validaci�n sobre el largo del string.
 * @param string - cadena de caracteres a evaluar.
 * @param size - Tama�o del array de caracteres (string).
 * @return Devuelve 0 si el largo de la cadena de caracteres supera al tama�o del array-1 (el ultimo espacio es para el -contrabarra-0).
 * @return Devuelve -1 si la cadena de caracteres est� vac�a (Ni espacios, ni nada).
 * @return Devuelve 1 si la cadena de caracteres no est� vac�a y el largo de la misma es menor o igual al tama�o del array-1.
 */
char checkStringLength(char* string, int size);

/**
 * Informa si el INT a evaluar est� o no dentro de un rango espec�fico.
 * @param value - valor num�rico tipo INT a evaluar.
 * @param minIncluded - m�nimo inclu�do.
 * @param maxIncluded - m�ximo inclu�do.
 * @return Devuelve 0 si NO est� dentro del rango.
 * @return Devuelve 1 si est� dentro del rango.
 */
char checkIntRange(int value, int minIncluded, int maxIncluded);

/**
 * Informa si la cadena de caracteres contiene s�lo letras y espacios, o no.
 * @param array - cadena de caracteres a evaluar.
 * @return Devuelve 0 si NO contiene s�lo letras y espacios.
 * @return Devuelve 1 si contiene s�lo letras y espacios.
 */
char checkOnlyLettersAndSpace(char* array);

/**
 * Informa si la cadena de caracteres contiene s�lo n�meros, o no.
 * @param string - cadena de caracteres a evaluar.
 * @return Devuelve 0 si NO contiene s�lo n�meros.
 * @return Devuelve 1 si contiene s�lo n�meros.
 */
char checkStringOnlyNumbers(char* string);

//CONFIRM:
/**
 * Hace una pregunta y pide por respuesta 'S' para si o 'N' para no. Valida respuesta.
 * @param message - pregunta a mostrar por pantalla.
 * @return Devuelve 1 si la respuesta es s�.
 * @return Devuelve 0 si la respuesta es no.
 */
char confirm(char* message);


//FUNCIONES ESPEC�FICAS DEL PROGRAMA:
/**
 * Obtiene el primer �ndice libre del array.
 * @param lista - el array de la estructura que contiene la lista.
 * @param size - tama�o del array.
 * @return el primer indice disponible.
 * @return Si no hay ningun indice disponible devuelve -1.
 */
int obtenerEspacioLibre(Persona lista[], int size);

/**
 * Obtiene el �ndice que coincide con el dni pasado por parametro (s�lo busca en las posiciones OCUPADAS).
 * @param list - el array de la estructura que contiene la lista.
 * @param size - tama�o del array de la estructura.
 * @param dni - el dni a ser buscado en el array.
 * @return De encontrarlo, devuelve el indice que coincide con el parametro dni.
 * @return Si no encuentra coincidencia devuelve -1.
 */
int searchDniCoincidence(Persona list[], int size, char* dni);

/**
 * BubleSort para ordenar un array por estado (orden descendente).
 * @param array - el array a ordenar.
 * @param size - tama�o del array a ordenar.
 */
void sortByStatus(Persona array[], int size);

/**
 * BubleSort para ordenar un array por nombre (orden ascendente).
 * @param array - el array a ordenar.
 * @param size - tama�o del array a ordenar.
 */
void sortByName(Persona array[], int size);

/**
 * Pide y obtiene un nombre por teclado, valida, y guarda en array de caracteres.
 * Sobre la validaci�n: Se debe ingresar algo; el primer caracter debe ser una letra;(...)
 * (...) s�lo se pueden ingresar letras y espacios; el tama�o de la cadena de caracteres no puede superar el tama�o del array-1.
 * @param arrayName - el array de caracteres donde se guarda el nombre.
 * @param size - tama�o del array donde se guarda el nombre.
 */
void getName(char* arrayName, int sizeArrayName);

/**
 * Pide y obtiene una edad por teclado.
 * @return Devuelve la respuesta VALIDADA (Debe estar entre 0 y 120, rango l�gico para una edad)
 */
unsigned char getAge(void);

/**
 * Pide y obtiene un DNI por teclado, valida, y guarda en array de caracteres.
 * Sobre la validaci�n: Se deben ingresar 8 caracteres y todos deben ser n�meros;(...)
 * (...) adem�s el DNI no puede coincidir con otro que ya est� en la lista (en posici�n OCUPADA).
 * (...) Si encuentra coincidencia, se le permitir� elegir al usuario si abortar la operaci�n o ingresar otro DNI.
 * @param arrayDni - el array de caracteres donde se guarda el DNI.
 * @param arrayPersonas - el array de la estructura que contiene la lista.
 * @param sizeArrayPersonas - tama�o del array de la estructura.
 * @return Devuelve 1 si se ingres� el dni correctamente.
 * @return Devuelve 0 si se abort� la operaci�n.
 */
char getDNI(char* arrayDni, Persona* arrayPersonas, int sizeArrayPersonas);

/**
 * Contador de posiciones ocupadas que est�n en un rango de edad determinado por par�metros.
 * @param arrayPersonas - el array de la estructura que contiene la lista.
 * @param sizeArrayPersonas - tama�o del array de la estructura.
 * @param minIncluded - m�nimo inclu�do.
 * @param maxIncluded - m�ximo inclu�do.
 * @return Devuelve la cantidad de edades de la lista que est�n dentro del rango.
 */
int counterAge(Persona* arrayPersonas, int sizeArrayPersonas, int minIncluded, int maxIncluded);


//ESTRUCTURA DEL PROGRAMA:
/**
 * Muestra el men� y pide que el usuario ingrese la opci�n deseada por teclado.
 * @return Devuelve la opci�n elegida por el usuario (Validada: Debe estar entre 0 y maxOptions).
 */
int showMenu(int maxOptions);

/**
 * Pide el ingreso de datos para agregar una nueva persona a la lista.
 * @param array con la lista de personas.
 * @param tama�o del array de personas.
 * @param tama�o del array donde se guarda el nombre.
 * @return Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
 */
char addPerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeName);

/**
 * Pide que se ingrese el DNI de la persona a borrar de la lista, valida que haya coincidencia (con alguna posici�n ocupada) y pide confirmaci�n antes de proceder.
 * @param array con la lista de personas.
 * @param tama�o del array de personas.
 * @param tama�o del array donde se guarda el DNI.
 * @return Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
 */
char deletePerson(Persona* arrayPersonas, int sizeArrayPersonas, int sizeDni);

/**
 * Imprime la lista actual de personas por orden alfab�tico ascendente.
 * @param array con la lista de personas.
 * @param tama�o del array.
 * @return Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
 */
char printOrderedList(Persona* arrayPersonas, int size);

/**
 * Imprime gr�fico (tipo columnas) de edades de las personas en la lista, categorizado por: <18, 19-35, y >35.
 * @param array con la lista de personas.
 * @param tama�o del array de personas.
 * @return Devuelve 1 si el usuario quiere realizar otra operaci�n, 0 si no lo desea.
 */
char printAgesGraphic(Persona* arrayPersonas, int sizeArrayPersonas);

#endif // FUNCIONES_H_INCLUDED
