#ifndef _TIPOS_H_	//M�dulo que contiene todas las declaraciones y estructuras utilizadas en el programa
#define _TIPOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {       /*Registro para fich. Usuarios.txt*/
	char Id[4];
	char Nombre[21];
	char Perfil[14];   /*Perfil:usuario o administrador*/
	char Usuario[6];
	char Contrasena[9];
} usuario;

typedef struct {        /*Registro para fich. Alumnos.txt*/
	char Id_alum[7];
	char Nombre_alum[21];
	char Direc_alum[31];
	char Local_alum[31];
	char Curso[31];
	char Grupo[11];
} alumno;

typedef struct {        /*Registro para fich. Materias.txt*/
	char Id_materia[5];
	char Nombre_materia[51];
	char Abrev_materia[4];
} materia;


typedef struct {        /*Registro para fich. Matriculas.txt*/
	char Id_materia[5];
	char Id_alum[7];
} matricula;

typedef struct {         /*Registro para fich. Calificaciones.txt*/
	char dia[3];
	char mes[3];
	char ano[5];
	char calificacion[3];
	char Descrip_calif[31];
	char Id_materia[5];
	char Id_alum[7];
} calificacion;

typedef struct {          /*Registro para fich. Faltas.txt*/
	char dia[3];
	char mes[3];
	char ano[5];
	char hora[2];
	char Descrip_falta[31];
	char Estado_falta[14];   /*Retraso,justificada o injustificada*/
	char Id_alum[7];
} faltas;


typedef struct {           /*Registro para fich. Horarios.txt*/
	char dia[3];
	char hora[2];
	char Id_profesor[4];
	char Id_materia[5];
	char Grupo[11];
} horario;


int nUsuarios;                    	/*N�mero de usuarios*/
int nAlumnos;                     	/*N�mero de alumnos*/
int nMaterias;                    	/*N�mero de materias*/
int nHorarios;                    	/*N�mero de horarios(depender� del numero de profesores)*/
int nMatriculas;                    /*N�mero de matriculas(depender� del numero de alumnos)*/
int nCalificaciones;                /*N�mero de calificaciones*/
int nFaltas;                        /*N�mero de faltas*/

usuario *vUsuarios;               	 /*Puntero que apunta a la direcci�n de un vector de usuarios*/
alumno  *vAlumnos;                 	 /*Puntero que apunta a la direcci�n de un vector de alumnos*/
materia *vMaterias;              	 /*Puntero que apunta a la direcci�n de un vector de materias*/
horario *vHorarios;               	 /*Puntero que apunta a la direcci�n de un vector de horarios*/
matricula *vMatriculas;           	 /*Puntero que apunta a la direcci�n de un vector de matriculas*/
calificacion *vCalificaciones;     	 /*Puntero que apunta a la direcci�n de un vector de calificaciones*/
faltas *vFaltas;                     /*Puntero que apunta a la direcci�n de un vector de faltas*/

#endif
