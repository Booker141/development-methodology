#ifndef _MENUADMIN_H_     //Este m�dulo contiene todas las declaraciones de las funciones que van a ser
#define _MENUADMIN_H_     //utilizadas en el m�dulo de implementaci�n "menus.c"
#include "tipos.h"
#include "Profesor.h"

void menu();
void menuadmin();
void menuprof(alumno **,int);
void menuAUsuarios();
void menuAAlumnos();
void menuAMaterias();
void menuAHorarios();
void menuAlficha();
void menuAlcalificacion();
void menuAlfalta();

#endif
