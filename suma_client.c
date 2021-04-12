/*Archivo que realiza la funcion de cliente */

#include "suma.h"
#include <stdio.h>


void
suma_prog_1(char *host, int a, int b) //Se han agregado argumentos host, y valores a sumar 
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp"); //Parametros: servidor, número, versión de programa, protocolo de red
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	

//Asignamos a nuestras variables creadas automaticamente por la estructura nuestros valores recividos desde consola
suma_1_arg.a=a;
suma_1_arg.b=b;

	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	} else {
		//Se imprime el resultado devuelto por nuestro servidor
			printf("El resultado de la suma es = %d\n",*result_1);
		}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 
}


int
main (int argc, char *argv[])
{
	char *host;
	int a, b; //Valores que seran ingresados por el usuario
	
	//Verifica que los valores sean validos para nuestro host, y valores a sumar
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	if((a=atoi(argv[2]))==0 && *argv[2]!='0'){
		fprintf(stderr,"invalid value:%s\n",argv[2]);
		exit(1);
	}
	if((b=atoi(argv[3]))==0 && *argv[3]!='0'){
		fprintf(stderr,"invalid value:%s\n",argv[3]);
		exit(1);
	}
	
	//Realiza el llamado a nuestra funcion ubicada en este mismo archivo
	suma_prog_1 (host,a,b);
exit (0);
}
