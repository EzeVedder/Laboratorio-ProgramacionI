#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void utn_pruebita(void);
int utn_getInt(int* pNumero,int maximo,int minimo,char* msg,char* msgError,int reintento);
int utn_getArrayInt(int* pNumeros,int MAX,const char* msg,const char* msgError,int minimo,int maximo,int reintentos);
int utn_showArrayInt(int* pNumeros,int MAX);


#endif // UTN_H_INCLUDED
