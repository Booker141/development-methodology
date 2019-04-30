#ifndef _VOLFICHEST_H_
#define _VOLFICHEST_H_
#include "tipos.h"


int cuantos_caracteres_fichero(FILE* );
int cuantas_lineas(FILE* );
void volfichest();
void volcado_estructura_usuario(FILE* ,usuario* ,int ,int );
void volcado_estructura_alumno(FILE* ,alumno* ,int ,int );
void volcado_estructura_materia(FILE* ,materia* ,int,int );
void volcado_estructura_matricula(FILE* ,matricula* ,int ,int);
void volcado_estructura_calificaciones(FILE* ,calificacion* ,int ,int );
void volcado_estructura_faltas(FILE* ,faltas* ,int,int );
void volcado_estructura_horario(FILE* ,horario* ,int ,int );

#endif 
  
