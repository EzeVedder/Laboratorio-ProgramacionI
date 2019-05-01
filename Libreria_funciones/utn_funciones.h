#ifndef UTN_FUNCIONES_H_INCLUDED
#define UTN_FUNCIONES_H_INCLUDED

int utn_getString(char* pStr, char* msg, char*msgError);
int utn_getInt (int *pNumber, char* msg, char* msgError);
int utn_getFloat (float *pNumber, char* msg, char* msgError);

int utn_getIntInRange (int *pNumber,char *msg,char *msgE,int minimo,int maximo,int retry);
int utn_cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
int utn_cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);

int utn_getStringLetras (char* pStr, char* msg, char* msgE);
int utn_getStringNumeros (char* pStr, char* msg, char* msgE);
int utn_getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);
int utn_getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
int utn_getDni (char* pStr, char* msg, char* msgE,int reintentos);
int utn_getCuit (char* pStr, char* msg, char* msgE,int reintentos);

int utn_findEmptyPlace (char pArray[][20],int* pIndex,int len);
int utn_findName(char* name, char parray[][20], int len, int* pIndex);
int utn_ordenarArrayMayorMenor (char* pArray, int len,int limit);

int utn_showArrayInt(int* pArray,int len);
int utn_showArrayChar(char* pArray,int len);

int utn_isNumeric(char* pStr);
int utn_isLetter (char* pStr);
int utn_isAlphanumeric (char* pStr);
int utn_isTelephone (char* pStr);
int utn_isDni (char* pStr);
int utn_isCuit (char* pStr);









#endif // UTN_FUNCIONES_H_INCLUDED
