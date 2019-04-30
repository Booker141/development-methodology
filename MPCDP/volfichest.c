#include<stdio.h> 	   //Módulo que realiza el volcado de información de ficheros a estructuras
#include<stdlib.h>
#include<stdio.h>
#include "volfichest.h"

//Cabecera:int volfichest()
//Precondición:
//Postcondición:Volcado a todas las estructuras de la información de ficheros

void volfichest() {

	FILE* f;
	f=fopen("Alumnos.txt","r");
	int len_cad=cuantos_caracteres_fichero(f);

	f=fopen("Usuarios.txt","r");
	nUsuarios=cuantas_lineas(f);
	f=fopen("Usuarios.txt","r");
	vUsuarios=(usuario*)malloc(nUsuarios*sizeof(usuario));
	f=fopen("Usuarios.txt","r");
	volcado_estructura_usuario(f,vUsuarios,len_cad,nUsuarios);


//lectura fichero alumno
	f=fopen("Alumnos.txt","r");
	nAlumnos=cuantas_lineas(f);
	vAlumnos=(alumno*)malloc(nAlumnos*sizeof(alumno));
	f=fopen("Alumnos.txt","r");
	volcado_estructura_alumno(f,vAlumnos,len_cad,nAlumnos);

//lectura fichero materia
	f=fopen("Materia.txt","r");
	nMaterias=cuantas_lineas(f);
	vMaterias=(materia*)malloc(nMaterias*sizeof(materia));
	f=fopen("Materia.txt","r");
	volcado_estructura_materia(f,vMaterias,len_cad,nMaterias);

//lectura fichero matricula
	f=fopen("Matricula.txt","r");
	nMatriculas=cuantas_lineas(f);
	vMatriculas=(matricula*)malloc(nMatriculas*sizeof(matricula));
	f=fopen("Matricula.txt","r");
	volcado_estructura_matricula(f,vMatriculas,len_cad,nMatriculas);

//lectura fichero calificaciones
	f=fopen("Calificaciones.txt","r");
	nCalificaciones=cuantas_lineas(f);
	vCalificaciones=(calificacion*)malloc(nCalificaciones*sizeof(calificacion));
	f=fopen("Calificaciones.txt","r");
	volcado_estructura_calificaciones(f,vCalificaciones,len_cad,nCalificaciones);

//lectura fichero faltas
	f=fopen("Faltas.txt","r");
	nFaltas=cuantas_lineas(f);
	vFaltas=(faltas*)malloc(nFaltas*sizeof(faltas));
	f=fopen("Faltas.txt","r");
	volcado_estructura_faltas(f,vFaltas,len_cad,nFaltas);

//lectura fichero horario
	f=fopen("Horarios.txt","r");
	nHorarios=cuantas_lineas(f);
	vHorarios=(horario*)malloc(nHorarios*sizeof(horario));
	f=fopen("Horarios.txt","r");
	volcado_estructura_horario(f,vHorarios,len_cad,nHorarios);

	

}

//Cabecera:int cuantos_caracteres_fichero(FILE* f)
//Precondición:fichero f inicializado
//Postcondición:Cuenta los caracteres del fichero

int cuantos_caracteres_fichero(FILE* f) {
	int i=0;
	char c;
	while(c!=EOF) {
		c=fgetc(f);
		i++;
	}
	fclose(f);
	return i;
}

//Cabecera:int cuantas_lineas(FILE* f)
//Precondición:fichero f inicializado
//Postcondición:Cuenta las lineas del fichero

int cuantas_lineas(FILE* f) {
	int i=0;
	char c;
	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			i++;

	}
	fclose(f);
	return i+1;
}

//Cabecera:void volcado_estructura_usuario(FILE* f,usuario* usuario,int len_cad,int num_usuarios)
//Precondición:fichero f, vector usuario, len_cad y num_usuarios inicializados
//Postcondición:Realiza el volcado de la estructura usuarios

void volcado_estructura_usuario(FILE* f,usuario *usuario,int len_cad,int nUsuarios) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(usuario[0].Id,token);
	usuario[0].Id[3]='\0';

	while(j<nUsuarios) {
		token=strtok(NULL,"-");
		strcpy(usuario[j].Nombre,token);
		usuario[j].Nombre[20]='\0';

		token=strtok(NULL,"-");
		strcpy(usuario[j].Perfil,token);
		usuario[j].Perfil[13]='\0';

		token=strtok(NULL,"-");
		strcpy(usuario[j].Usuario,token);
		usuario[j].Usuario[5]='\0';

		token=strtok(NULL,"-");
		strcpy(usuario[j].Contrasena,token);
		usuario[j].Contrasena[8]='\0';

		j++;

		if(j==nUsuarios)
			break;

		token=strtok(NULL,"-");
		strcpy(usuario[j].Id,token);
		usuario[j].Id[3]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_alumno(FILE* f,alumno* alumno,int len_cad,int num_alumno)
//Precondición:fichero f, vector alumno, len_cad y num_alumno inicializados
//Postcondición:Realiza el volcado de la estructura alumno

void volcado_estructura_alumno(FILE* f,alumno *alumno,int len_cad,int nAlumnos) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(alumno[0].Id_alum,token);
	alumno[0].Id_alum[6]='\0';

	while(j<nAlumnos) {
		token=strtok(NULL,"-");
		strcpy(alumno[j].Nombre_alum,token);
		alumno[j].Nombre_alum[20]='\0';

		token=strtok(NULL,"-");
		strcpy(alumno[j].Direc_alum,token);
		alumno[j].Direc_alum[30]='\0';

		token=strtok(NULL,"-");
		strcpy(alumno[j].Local_alum,token);
		alumno[j].Local_alum[30]='\0';

		token=strtok(NULL,"-");
		strcpy(alumno[j].Curso,token);
		alumno[j].Curso[30]='\0';

		token=strtok(NULL,"-");
		strcpy(alumno[j].Grupo,token);
		alumno[j].Grupo[30]='\0';

		j++;

		if(j==nAlumnos)
			break;

		token=strtok(NULL,"-");
		strcpy(alumno[j].Id_alum,token);
		alumno[j].Id_alum[3]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_materia(FILE* f,materia* materia,int len_cad,int num_materias)
//Precondición:fichero f, vector materia, len_cad y num_materias inicializados
//Postcondición:Realiza el volcado de la estructura materia

void volcado_estructura_materia(FILE* f,materia *materia,int len_cad,int nMaterias) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(materia[0].Id_materia,token);
	materia[0].Id_materia[4]='\0';

	while(j<nMaterias) {
		token=strtok(NULL,"-");
		strcpy(materia[j].Nombre_materia,token);
		materia[j].Nombre_materia[50]='\0';

		token=strtok(NULL,"-");
		strcpy(materia[j].Abrev_materia,token);
		materia[j].Abrev_materia[3]='\0';

		j++;

		if(j==nMaterias)
			break;

		token=strtok(NULL,"-");
		strcpy(materia[j].Id_materia,token);
		materia[j].Id_materia[4]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_matricula(FILE* f,materia* materia,int len_cad,int num_materias)
//Precondición:fichero f, vector matricula, len_cad y num_matriculas inicializados
//Postcondición:Realiza el volcado de la estructura matricula

void volcado_estructura_matricula(FILE* f,matricula *matricula,int len_cad,int nMatriculas) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(matricula[0].Id_materia,token);
	matricula[0].Id_materia[4]='\0';

	while(j<nMatriculas) {
		token=strtok(NULL,"-");
		strcpy(matricula[j].Id_alum,token);
		matricula[j].Id_alum[6]='\0';

		j++;

		if(j==nMatriculas)
			break;

		token=strtok(NULL,"-");
		strcpy(matricula[j].Id_materia,token);
		matricula[j].Id_materia[4]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_calificaciones(FILE* f,calificaciones* calis,int len_cad,int num_calis)
//Precondición:fichero f, vector calis, len_cad y num_calis inicializados
//Postcondición:Realiza el volcado de la estructura calificaciones

void volcado_estructura_calificaciones(FILE* f,calificacion *calis,int len_cad,int nCalificaciones) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(calis[0].dia,token);
	calis[0].dia[2]='\0';

	while(j<nCalificaciones) {
		token=strtok(NULL,"-");
		strcpy(calis[j].mes,token);
		calis[j].mes[2]='\0';

		token=strtok(NULL,"-");
		strcpy(calis[j].ano,token);
		calis[j].ano[4]='\0';

		token=strtok(NULL,"-");
		strcpy(calis[j].calificacion,token);
		calis[j].calificacion[2]='\0';

		token=strtok(NULL,"-");
		strcpy(calis[j].Descrip_calif,token);
		calis[j].Descrip_calif[30]='\0';

		token=strtok(NULL,"-");
		strcpy(calis[j].Id_materia,token);
		calis[j].Id_materia[30]='\0';

		token=strtok(NULL,"-");
		strcpy(calis[j].Id_alum,token);
		calis[j].Id_alum[6]='\0';

		j++;

		if(j==nCalificaciones)
			break;

		token=strtok(NULL,"-");
		strcpy(calis[j].dia,token);
		calis[j].dia[2]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_faltas(FILE* f,faltas* falta,int len_cad,int num_faltas)
//Precondición:fichero f, vector falta, len_cad y num_faltas inicializados
//Postcondición:Realiza el volcado de la estructura faltas

void volcado_estructura_faltas(FILE* f,faltas *falta,int len_cad,int nFaltas) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(falta[0].dia,token);
	falta[0].dia[2]='\0';

	while(j<nFaltas) {
		token=strtok(NULL,"-");
		strcpy(falta[j].mes,token);
		falta[j].mes[2]='\0';

		token=strtok(NULL,"-");
		strcpy(falta[j].ano,token);
		falta[j].ano[4]='\0';

		token=strtok(NULL,"-");
		strcpy(falta[j].hora,token);
		falta[j].hora[1]='\0';

		token=strtok(NULL,"-");
		strcpy(falta[j].Descrip_falta,token);
		falta[j].Descrip_falta[30]='\0';

		token=strtok(NULL,"-");
		strcpy(falta[j].Estado_falta,token);
		falta[j].Estado_falta[13]='\0';

		token=strtok(NULL,"-");
		strcpy(falta[j].Id_alum,token);
		falta[j].Id_alum[6]='\0';

		j++;

		if(j==nFaltas)
			break;

		token=strtok(NULL,"-");
		strcpy(falta[j].dia,token);
		falta[j].dia[2]='\0';
	}
	fclose(f);

}

//Cabecera:void volcado_estructura_horario(FILE* f,horario* horario,int len_cad,int num_horarios)
//Precondición:fichero f, vector horario, len_cad y num_horarios inicializados
//Postcondición:Realiza el volcado de la estructura horario

void volcado_estructura_horario(FILE* f,horario *horario,int len_cad,int nHorarios) {

	char* cad=(char*)malloc(len_cad + 1);
	char* token;
	char c;
	int i=0,j=0;

	while(c!=EOF) {
		c=fgetc(f);
		if(c=='\n')
			c='-';

		cad[i]=c;
		i++;
	}
	cad[len_cad]='\0';
	//printf("%s",cad);

	token=strtok(cad,"-");
	strcpy(horario[0].dia,token);
	horario[0].dia[2]='\0';

	while(j<nHorarios) {
		token=strtok(NULL,"-");
		strcpy(horario[j].hora,token);
		horario[j].hora[1]='\0';

		token=strtok(NULL,"-");
		strcpy(horario[j].Id_profesor,token);
		horario[j].Id_profesor[3]='\0';

		token=strtok(NULL,"-");
		strcpy(horario[j].Id_materia,token);
		horario[j].Id_materia[4]='\0';

		token=strtok(NULL,"-");
		strcpy(horario[j].Grupo,token);
		horario[j].Grupo[10]='\0';


		j++;

		if(j==nHorarios)
			break;

		token=strtok(NULL,"-");
		strcpy(horario[j].dia,token);
		horario[j].dia[2]='\0';
	}
	fclose(f);

}
