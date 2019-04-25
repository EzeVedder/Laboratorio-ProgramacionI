#ifndef UTN_LIBRARY_H_INCLUDED


//BIBLIOTECA DE FUNCIONES ESENCIALES

int utn_getIntNumber(int *number, char *msg,char *msgError);
float utn_getFloatNumber(float *pNumber,char *msg,char *msgError);
int utn_getIntNumberWithRety(int *pNumber,char *msg,char *msgError,int minimo,int maximo,int retry);









#endif // UTN_LIBRARY_H_INCLUDED
