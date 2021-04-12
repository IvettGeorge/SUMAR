/* Archivo que realiza la funcion de servidor*/

#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp) //Parametros recividos en variable argp
{
	static int  result;

	/* codigo agregado manualmente */
	 printf("El procedimiento ha sido invocado remotamente\n");
	 printf("Server is working...\n");
	 printf("Parametros: %d, %d\n",argp->a,argp->b);
	 
	 /*Se realiza la suma para nuestras variables definidas en la estructura inicial */
	 result=argp->a+argp->b;
	 printf("Returning: %d\n",result);
	 
	 //Envia el resultado al cliente
	return &result;
}
