#include<stdio.h>		//Módulo para las tareas de profesor
#include<stdlib.h>
#include<string.h>
#include"Profesor.h"

/*FICHAS*/

//Cabecera:void listarficha(alumno *vAlumnos,int nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Imprime los datos personales del alumno en cuestión

void listarficha(alumno *vAlumnos,int nAlumnos) {

	int i;
	char ID[7];
	
	printf("Introduzca de nuevo id de alumno para listar ficha: ");
	scanf("%s",ID);

	printf("\n========Alumno========\n\n");

	printf("Id-Nombre-Direccion-Localidad-Curso-Grupo\n");

	for(i=0; i<nAlumnos; i++) {
	  if(strcmp(vAlumnos[i].Id_alum,ID)==0)	
		printf("%s-%s-%s-%s-%s-%s\n",vAlumnos[i].Id_alum,vAlumnos[i].Nombre_alum,vAlumnos[i].Direc_alum,vAlumnos[i].Local_alum,vAlumnos[i].Curso,vAlumnos[i].Grupo);
	}
}

//Cabecera:void modificarficha(alumno **vAlumnos,int nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Realiza modificaciones de los datos personales del alumno

void modificarficha(alumno **vAlumnos,int nAlumnos) {
	
	int i;
	int a=-1;
	char resp=' ';
	char ID[7];

	int nModAlumno=0;

	alumno *modAlumno;

	modAlumno=(alumno*)malloc(sizeof(alumno));

	printf("Modificar Alumnos\n\n");


	while(a == -1) {

		printf("Introduzca la id del alumno cuya ficha desea modificar: ");
		scanf("%6s",ID);

		for(i=0; i<nAlumnos; i++) {

			if(strcmp((*vAlumnos)[i].Id_alum,ID)==0) {

				a=i;

			}

		}

		if(a == -1) {

			printf("Error: Ese alumno no está registrado\n");

		} else {

			printf("Informacion del alumno (actual): %s-%s-%s-%s-%s-%s\n\n",(*vAlumnos)[a].Id_alum,(*vAlumnos)[a].Nombre_alum,(*vAlumnos)[a].Direc_alum,(*vAlumnos)[a].Local_alum,(*vAlumnos)[a].Curso,(*vAlumnos)[a].Grupo);

			printf("Introduzca la nueva informacion del alumno (Id-Nombre-Direccion-Localidad-Curso-Grupo): ");

			altaAlumno(&modAlumno,&nModAlumno);

			while(resp!='s' && resp!='n') {

				printf("¿Modificar alumno? (s/n)\n");
				fflush(stdin);
				scanf("%c",&resp);

			}

			if(resp=='s') {

				(*vAlumnos)[a]=modAlumno[0];

			} else {

				printf("Se ha denegado la modificacion del alumno\n");

			}

		}

	}
}

/*CALIFICACIÓN*/

//Cabecera:void listarcalificacion(calificacion *vCalificaciones,int nCalificaciones)
//Precondición:vector vCalificaciones y nCalificaciones inicializados
//Postcondición:Imprime las calificaciones del alumno

void listarcalificacion(calificacion *vCalificaciones,int nCalificaciones) {

	int i;
	char ID[7];
	
	printf("Introduzca de nuevo id de alumno para listar calificacion: ");
	scanf("%s",ID);

	vCalificaciones=(calificacion*)malloc(sizeof(calificacion));

	printf("\n========Calificacion========\n\n");
	printf("Dia/Mes/Ano-Calificacion-Descrip_calif-Id_materia-Id_alumno\n");

	for(i=0; i<nCalificaciones; i++) {
		if(strcmp(vCalificaciones[i].Id_alum,ID)==0)
			printf("%s/%s/%s-%s-%s-%s-%s\n",vCalificaciones[i].dia,vCalificaciones[i].mes,vCalificaciones[i].ano,vCalificaciones[i].calificacion,vCalificaciones[i].Descrip_calif,vCalificaciones[i].Id_materia,vCalificaciones[i].Id_alum);
	}
}

//Cabecera:void anadircalificacion(calificacion **vCalificaciones,int *nCalificaciones)
//Precondición:vector vCalificaciones y nCalificaciones inicializados
//Postcondición:Añade nueva calificación al alumno

void anadircalificacion(calificacion **vCalificaciones,int *nCalificaciones) {

	char resp=' ';

	realloc(vCalificaciones,((*nCalificaciones)+1));

	do {

		printf("Anadir calificacion\n\n");

		printf("Introduzca dia (2 cifras maximo):");
		fflush(stdin);
		scanf("%2s",(*vCalificaciones)[*nCalificaciones].dia);
		
		printf("Introduzca mes (2 cifras maximo):");
		fflush(stdin);
		scanf("%2s",(*vCalificaciones)[*nCalificaciones].mes);
		
		printf("Introduzca ano (4 cifras maximo):");
		fflush(stdin);
		scanf("%4s",(*vCalificaciones)[*nCalificaciones].ano);

		printf("Introduzca la calificacion (2 caracteres como maximo):");
		fflush(stdin);
		scanf("%2s",(*vCalificaciones)[*nCalificaciones].calificacion);

		printf("Introduzca la descripcion de la calificacion (30 caracteres maximo):");
		fflush(stdin);
		scanf("%30s",(*vCalificaciones)[*nCalificaciones].Descrip_calif);
		
		printf("Introduzca la id de la materia (4 caracteres maximo):");
		fflush(stdin);
		scanf("%4s",(*vCalificaciones)[*nCalificaciones].Id_materia);
		
		printf("Introduzca la id del alumno (6 caracteres maximo):");
		fflush(stdin);
		scanf("%6s",(*vCalificaciones)[*nCalificaciones].Id_alum);

		do {

			printf("¿Quiere dar anadir otra calificacion? (s/n): ");
			fflush(stdin);
			scanf("%c",&resp);


		} while(resp!='s' && resp!='n');


	} while(resp=='s' && resp!='n');


	(*nCalificaciones)++;
}

//Cabecera:void eliminarcalificacion(calificacion **vCalificaciones,int *nCalificaciones)
//Precondición:vector vCalificaciones y nCalificaciones inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void eliminarcalificacion(calificacion **vCalificaciones,int *nCalificaciones) {


	int i;
	int c;
	char resp=' ';
	char ID[7]; 	

	printf("Eliminacion de la calificacion\n\n");

	printf("Introduzca de nuevo la id del alumno con calificacion a eliminar: ");
	scanf("%6s",ID);

	for(i=0; i<(*nCalificaciones); i++) {

		if(strcmp((*vCalificaciones)[i].Id_alum,ID)==0) {

			c=i;

		}

	}

	while(resp!='s' && resp!='n') {

		printf("Se va a eliminar la siguiente calificacion: %s/%s/%s-%s-%s-%s-%s\n",(*vCalificaciones)[c].dia,(*vCalificaciones)[c].mes,(*vCalificaciones)[c].ano,(*vCalificaciones)[c].calificacion,(*vCalificaciones)[c].Descrip_calif,(*vCalificaciones)[c].Id_materia,(*vCalificaciones)[c].Id_alum);
		printf("¿Eliminar calificacion? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		for(i=c; i+1<(*nCalificaciones); i++) {

			strcpy((*vCalificaciones)[i].dia,(*vCalificaciones)[i+1].dia);
			strcpy((*vCalificaciones)[i].mes,(*vCalificaciones)[i+1].mes);
			strcpy((*vCalificaciones)[i].ano,(*vCalificaciones)[i+1].ano);
			strcpy((*vCalificaciones)[i].calificacion,(*vCalificaciones)[i+1].calificacion);
			strcpy((*vCalificaciones)[i].Descrip_calif,(*vCalificaciones)[i+1].Descrip_calif);
			strcpy((*vCalificaciones)[i].Id_materia,(*vCalificaciones)[i+1].Id_materia);
			strcpy((*vCalificaciones)[i].Id_alum,(*vCalificaciones)[i+1].Id_alum);

		}

		(*nCalificaciones)--;

		realloc(vCalificaciones,(*nCalificaciones));

	} else {

		printf("Se ha denegado la eliminacion de la calificacion\n");

	}
}

//Cabecera:void modificarcalificacion(calificacion **vCalificaciones,int nCalificaciones)
//Precondición:vector vCalificaciones y nCalificaciones inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void modificarcalificacion(calificacion **vCalificaciones,int nCalificaciones) {

	int i;
	int c=-1;
	char resp=' ';
	char ID[7];

	int nModCalificacion=0;

	calificacion *modCalificacion;

	modCalificacion=(calificacion*)malloc(sizeof(calificacion));

	printf("Modificar calificacion\n\n");


	while(c == -1) {

		printf("Introduzca la id del alumno con calificacion a modificar: ");
		fflush(stdin);
		scanf("%6s",ID);

		for(i=0; i<nCalificaciones; i++) {

			if(strcmp((*vCalificaciones)[i].Id_alum,ID)==0) {

				c=i;

			}

		}

		if(c == -1) {

			printf("Error: Esa calificacion no está registrada\n");

		} else {

			printf("Informacion de la calificacion (actual): %s/%s/%s-%s-%s-%s-%s\n",(*vCalificaciones)[c].dia,(*vCalificaciones)[c].mes,(*vCalificaciones)[c].ano,(*vCalificaciones)[c].calificacion,(*vCalificaciones)[c].Descrip_calif,(*vCalificaciones)[c].Id_materia,(*vCalificaciones)[c].Id_alum);

			printf("Introduzca la nueva informacion de la calificacion (Dia/Mes/Ano-Calificacion-Descrip_calif-id_materia-Id_alum): ");

			anadircalificacion(&modCalificacion,&nModCalificacion);

			while(resp!='s' && resp!='n') {

				printf("¿Modificar calificacion? (s/n)\n");
				fflush(stdin);
				scanf("%c",&resp);

			}

			if(resp=='s') {

				(*vCalificaciones)[c]=modCalificacion[0];

			} else {

				printf("Se ha denegado la modificacion de la calificacion\n");

			}

		}

	}
}

/*FALTAS*/

//Cabecera:void listarfalta(faltas *vFaltas,int nFaltas)
//Precondición:vector vFaltas y nFaltas inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void listarfalta(faltas *vFaltas,int nFaltas) {

	int i;
	char ID[7];

	vFaltas=(faltas*)malloc(sizeof(faltas));
	
	printf("Introduzca de nuevo id de alumno para listar faltas: ");
	scanf("%s",ID);

	printf("\n========Faltas========\n\n");
	printf("Dia/Mes/Ano-Hora-Descripcion-Estado-Id alumno\n");


	for(i=0; i<nFaltas; i++) {
	 if(strcmp(vFaltas[i].Id_alum,ID)==0)
		printf("%s/%s/%s-%s-%s-%s-%s\n",vFaltas[i].dia,vFaltas[i].mes,vFaltas[i].ano,vFaltas[i].hora,vFaltas[i].Descrip_falta,vFaltas[i].Estado_falta,vFaltas[i].Id_alum);
	}

}

//Cabecera:void anadirfalta(faltas **vFaltas,int *nFaltas)
//Precondición:vector vFaltas y nFaltas inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void anadirfalta(faltas **vFaltas,int *nFaltas) {

	char resp=' ';

	realloc(vFaltas,((*nFaltas)+1));

	do {
		printf("Anadir falta\n\n");

		printf("Introduzca dia (2 cifras maximo):");
		fflush(stdin);
		scanf("%2s",(*vFaltas)[*nFaltas].dia);
		
		printf("Introduzca mes (2 cifras maximo):");
		fflush(stdin);
		scanf("%2s",(*vFaltas)[*nFaltas].mes);
		
		printf("Introduzca ano (4 cifras maximo):");
		fflush(stdin);
		scanf("%4s",(*vFaltas)[*nFaltas].ano);

		printf("Introduzca la hora (2 caracteres como maximo):");
		fflush(stdin);
		scanf("%2s",(*vFaltas)[*nFaltas].hora);

		printf("Introduzca la descripcion de la falta (30 caracteres maximo):");
		fflush(stdin);
		scanf("%30s",(*vFaltas)[*nFaltas].Descrip_falta);
		
		printf("Introduzca el estado de la falta (13 caracteres maximo):");
		fflush(stdin);
		scanf("%13s",(*vFaltas)[*nFaltas].Estado_falta);
		
		printf("Introduzca la id del alumno (6 caracteres maximo):");
		fflush(stdin);
		scanf("%6s",(*vFaltas)[*nFaltas].Id_alum);

		do {

			printf("¿Quiere anadir otra falta? (s/n): ");
			fflush(stdin);
			scanf("%c",&resp);


		} while(resp!='s' && resp!='n');


	} while(resp=='s' && resp!='n');


	(*nFaltas)++;
}

//Cabecera:void eliminarfalta(faltas **vFaltas,int *nFaltas)
//Precondición:vector vFaltas y nFaltas inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void eliminarfalta(faltas **vFaltas,int *nFaltas) {

	int i;
	int f;
	char resp=' ';
	char ID[7];

	printf("Eliminacion de la falta\n\n");

	printf("Introduzca la id del alumno a quitar la falta: ");
	scanf("%6s",ID);
	for(i=0; i<(*nFaltas); i++) {

		if(strcmp((*vFaltas)[i].Id_alum,ID)==0) {

			f=i;

		}

	}

	while(resp!='s' && resp!='n') {

		printf("Se va a eliminar la siguiente falta:%s/%s/%s-%s-%s-%s-%s\n",(*vFaltas)[f].dia,(*vFaltas)[f].mes,(*vFaltas)[f].ano,(*vFaltas)[f].hora,(*vFaltas)[f].Descrip_falta,(*vFaltas)[f].Estado_falta,(*vFaltas)[f].Id_alum);
		printf("¿Eliminar falta? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		for(i=f; i+1<(*nFaltas); i++) {

			strcpy((*vFaltas)[i].dia,(*vFaltas)[i+1].dia);
			strcpy((*vFaltas)[i].mes,(*vFaltas)[i+1].mes);
			strcpy((*vFaltas)[i].ano,(*vFaltas)[i+1].ano);
			strcpy((*vFaltas)[i].hora,(*vFaltas)[i+1].hora);
			strcpy((*vFaltas)[i].Descrip_falta,(*vFaltas)[i+1].Descrip_falta);
			strcpy((*vFaltas)[i].Estado_falta,(*vFaltas)[i+1].Estado_falta);
			strcpy((*vFaltas)[i].Id_alum,(*vFaltas)[i+1].Id_alum);

		}

		(*nFaltas)--;

		realloc(vFaltas,(*nFaltas));

	} else {

		printf("Se ha denegado la eliminacion de la falta\n");

	}
}

//Cabecera:void modificarfalta(faltas **vFaltas,int nFaltas)
//Precondición:vector vFaltas y nFaltas inicializados
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void modificarfalta(faltas **vFaltas,int nFaltas) {

	int i;
	int f=-1;
	char resp=' ';
	char ID[7];

	int nModFalta=0;

	faltas *modFalta;

	modFalta=(faltas*)malloc(sizeof(faltas));

	printf("Modificar Faltas\n\n");


	while(f == -1) {

		printf("Introduzca la id del alumno con falta a modificar: ");
		fflush(stdin);
		scanf("%6s",ID);

		for(i=0; i<nFaltas; i++) {

			if(strcmp((*vFaltas)[i].Id_alum,ID)==0) {

				f=i;

			}

		}

		if(f == -1) {

			printf("Error: Esa falta no está registrada\n");

		} else {

			printf("Informacion de la falta (actual): %s/%s/%s-%s-%s-%s-%s\n",(*vFaltas)[f].dia,(*vFaltas)[f].mes,(*vFaltas)[f].ano,(*vFaltas)[f].hora,(*vFaltas)[f].Descrip_falta,(*vFaltas)[f].Estado_falta,(*vFaltas)[f].Id_alum);

			printf("Introduzca la nueva informacion de la falta (Dia/Mes/Ano-Hora-Descripcion-Estado-Id alumno): ");

			anadirfalta(&modFalta,&nModFalta);

			while(resp!='s' && resp!='n') {

				printf("¿Modificar falta? (s/n)\n");
				fflush(stdin);
				scanf("%c",&resp);

			}

			if(resp=='s') {

				(*vFaltas)[f]=modFalta[0];

			} else {

				printf("Se ha denegado la modificacion de la falta\n");

			}

		}

	}
}

