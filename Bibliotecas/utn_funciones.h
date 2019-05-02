#ifndef UTN_FUNCIONES_H_INCLUDED
#define UTN_FUNCIONES_H_INCLUDED




int utn_getString(char* pString,char* msg,char* msgError);
int utn_getIntNumberInRange(int* pNumber,char* msg,char*msgError,int min,int max,int retry);
int utn_getInt(int* pResultado);
int utn_getIntWithMsg (int *pNumber, char* msg, char* msgError);
int utn_getFloat (float *pNumber, char* msg, char* msgError);
int utn_getFloatWithMsg (float *pNumber, char* msg, char* msgError);
int utn_getStringSoloLetras (char* pString, char* msg, char* msgError);
int utn_getStringSoloNumeros (char* pString, char* msg, char* msgError);
int utn_getStringAlphanumeric (char* pString, char* msg, char* msgError,int retry);
int utn_getTelephone (char* pString, char* msg, char* msgError,int retry);
int utn_getDni (char* pString, char* msg, char* msgError,int retry);
int utn_getCuit (char* pString, char* msg, char* msgError,int retry);

int utn_isNumeric (char* pString);
int utn_isLetter (char* pString);
int utn_isAlphanumeric (char* pString);
int utn_isTelephone (char* pString);
int utn_isDni (char* pString);
int utn_isCuit (char* pString);

int utn_cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgError);
int utn_cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgError);
int utn_findEmptyPlace (char pArray[][20],int* pIndex,int len);
int utn_findName(char* name, char parray[][20], int len, int* pIndex);
int utn_ordenarArrayMayorMenor (char* pArray, int len,int limit);
int utn_showArrayInt(int* pArray,int len);
int utn_showArrayChar(char* pArray,int len);

#endif // UTN_FUNCIONES_H_INCLUDED