#ifndef UTN_FUNCIONES_H_INCLUDED
#define UTN_FUNCIONES_H_INCLUDED

int utn_getString(char* pString,char* msg,char* msgError);
int utn_getStringLetras (char* pString, char* msg, char* msgError);
int utn_getStringNumeros (char* pStr, char* msg, char* msgError);
int utn_getStringAlphanumeric(char* pString, char* msg, char* msgError,int retry);
int utn_getIntNumberInRange(int* pNumero,char* msg,char*msgError,int minimo,int maximo,int retry);
int utn_getInt(int* pResultado);
int utn_getIntWithMsg (int *pNumber, char* msg, char* msgError);
int utn_getFloat (float *pNumber, char* msg, char* msgError);
int utn_isNumeric(char* cadena);
int utn_getCuit(char* pCadena,char* msg,char* msgError,int retry);
int utn_isCuit(char* pResultado);
int utn_isDni(char* pStr);
int utn_isLetter (char* pString);
int utn_isAlphanumeric (char* pString);

int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgError);



#endif // UTN_FUNCIONES_H_INCLUDED
