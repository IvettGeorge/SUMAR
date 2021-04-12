/*Archivo necesario para cliente y servidor que define nuestras funciones pedidas en suma.x */

#ifndef _SUMA_H_RPCGEN
#define _SUMA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct dupla_int {
	/*Parametros a sumar*/
	int a;
	int b;
};
typedef struct dupla_int dupla_int;

#define SUMA_PROG 0x23451111
#define SUMA_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define SUMA 1
extern  int * suma_1(dupla_int *, CLIENT *);
extern  int * suma_1_svc(dupla_int *, struct svc_req *);
extern int suma_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else 
#define SUMA 1
extern  int * suma_1(); //Verifica interfaz del cliente
extern  int * suma_1_svc();//Verifica interfaz del servidor
extern int suma_prog_1_freeresult ();
#endif 

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_dupla_int (XDR *, dupla_int*); //Funcion para verificar la consistencia del parámetro enviado

#else 
extern bool_t xdr_dupla_int ();

#endif 

#ifdef __cplusplus
}
#endif

#endif 
