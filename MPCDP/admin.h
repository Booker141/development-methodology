#ifndef _ADMIN_H_    //Este módulo contiene todas las declaraciones de las funciones que van a ser 
#define _ADMIN_H_     //utilizadas en el módulo de implementación "admin.c"
#include "tipos.h"

void listarUsuario(usuario *,int);
void modificarUsuario(usuario **,int);
void altaUsuario(usuario **,int *,int);       
void bajaUsuario(usuario **,int *);
void listarAlumno(alumno *,int);
void listarAlumno2(alumno *,int);
void modificarAlumno(alumno **,int);
void altaAlumno(alumno **,int *);
void bajaAlumno(alumno **,int *);
void Matricula(alumno *,matricula *,int,int);
void listarMateria(materia *,int);
void modificarMateria(materia **,int);
void altaMateria(materia *,int *);
void bajaMateria(materia **,int *);
void listarHorario(horario *,int );
void listarProfesor(usuario *,int);
void anadirHora(int);
void eliminarHora(int);

#endif

