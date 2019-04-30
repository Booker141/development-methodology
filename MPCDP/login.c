#include <stdio.h>	//M�dulo que se encarga del acceso de un usuario al sistema
#include <string.h>
#include "login.h"
#include "menuadmin.h"


//Cabecera:void login(usuario *vUsuarios,int nUsuarios)
//Precondici�n:vector vUsuarios y nUsuarios (n�mero de usuarios) inicializados
//Postcondici�n:Acceso a distintas opciones dependiendo del perfil del usuario

void login(usuario *vUsuarios,int nUsuarios) {

	int i;
	int existente=0;
	char usuario[6];
	char contrasena[9];

	printf("Usuario: ");
	fflush(stdin);
	scanf("%5s",usuario);

	printf("Contrase�a: ");
	fflush(stdin);
	scanf("%8s",contrasena);

	for(i=0; i<nUsuarios; i++) {

		if(strcmp(vUsuarios[i].Usuario,usuario)==0) {

			existente=1;

			if(strcmp(vUsuarios[i].Contrasena,contrasena)==0) {

				if(strcmp(vUsuarios[i].Perfil,"profesor")==0)
					menuprof(&vAlumnos,nAlumnos);
				if(strcmp(vUsuarios[i].Perfil,"administrador")==0)
					menuadmin();

			} else {

				puts("Error: Contrase�a incorrecta.");

				login(vUsuarios,nUsuarios);      /*Uso de la recursividad*/

			}

		}

	}

	if(existente==0)
	
		puts("El usuario no existe, es decir, no esta registrado.");

	system("pause");

}

