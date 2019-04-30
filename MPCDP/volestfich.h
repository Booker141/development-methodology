#ifndef _VOLESTFICH_H_    //Este módulo contiene todas las declaraciones de las funciones que van a ser 
#define _VOLESTFICH_H_     //utilizadas en el módulo de implementación "volestfich.c"
#include "tipos.h"

void volestfich();
void Guardusuario(usuario *,size_t tam); 
void Guardalum(alumno *,size_t tam);
void Guardcalifica(calificacion *,size_t tam);
void Guardfalta(faltas *,size_t tam);
void Guardhorario(horario *,size_t tam);
void Guardmateria(materia *,size_t tam);
void Guardmatricula(matricula *,size_t tam);

#endif
