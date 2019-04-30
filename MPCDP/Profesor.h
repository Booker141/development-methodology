#ifndef _PROFESOR_H_	//Este módulo contiene todas las declaraciones de las funciones que van a ser
#define _PROFESOR_H_	//utilizadas en el módulo de implementación "Profesor.c"
#include "tipos.h"
#include "menuadmin.h"
#include "admin.h"

void listarficha(alumno *,int);
void modificarficha(alumno **,int);
void listarcalificacion(calificacion *,int);
void anadircalificacion(calificacion **,int *);
void eliminarcalificacion(calificacion **,int *);
void modificarcalificacion(calificacion **,int);
void listarfalta(faltas *,int);
void anadirfalta(faltas **,int *);
void eliminarfalta(faltas **,int *);
void modificarfalta(faltas **,int);


#endif
