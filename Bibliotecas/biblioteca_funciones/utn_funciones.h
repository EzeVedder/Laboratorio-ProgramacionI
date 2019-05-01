#ifndef UTN_FUNCIONES_H_INCLUDED
#define UTN_FUNCIONES_H_INCLUDED

int utn_getString(char* pStr,char* msg,char* msgError);
int utn_getStringNumeros (char* pStr, char* msg, char* msgError);
int utn_getIntNumber(int* pNumero,char* msg,char*msgError,int min,int max,int retry);
int utn_getInt(int* pResultado);
int utn_getFloat (float *pNumber, char* msg, char* msgError);
int utn_isNumeric(char* cadena);
int utn_getCuit(char* pCadena,char* msg,char* msgError,int retry);
int utn_isCuit(char* pResultado);
int utn_isDni(char* pStr);
#endif // UTN_FUNCIONES_H_INCLUDED
