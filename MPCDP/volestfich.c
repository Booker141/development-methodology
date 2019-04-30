#include"volestfich.h" //Módulo para el volcado de estructuras a ficheros

//Cabecera:volestfich()
//Precondición:
//Postcondición:Almacena en fichero la información

void volestfich() {

	char resp=' ';

	while(resp!='s' && resp!='n') {

		printf("Va a salir del programa. Desea guardar los cambios realizados? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		Guardusuario(vUsuarios,nUsuarios); 
		Guardalum(vAlumnos,nAlumnos);
		Guardcalifica(vCalificaciones,nCalificaciones);
		Guardfalta(vFaltas,nFaltas);
		Guardhorario(vHorarios,nHorarios);
		Guardmateria(vMaterias,nMaterias);
		Guardmatricula(vMatriculas,nMatriculas);

		exit(0);

	} else {

		printf("No se han guardado los cambios realizados\n");

	}

}

//Cabecera:void Guardusuario(usuario *vUsuarios, size_t tam)
//Precondición:vector vUsuarios y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de usuario

void  Guardusuario(usuario *vUsuarios,size_t tam) {

	int i;
	FILE *fich;
	fich = fopen("Fich/Usuarios.txt","w");

	if ( fich == NULL) {
		printf("Error al abrir fichero");
		exit (1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s-%s-%s",vUsuarios[i].Id,vUsuarios[i].Nombre,vUsuarios[i].Perfil,vUsuarios[i].Usuario,vUsuarios[i].Contrasena);
			i++;
		}
	}

	fclose(fich);

	printf("\n");
	system ("pause");
}
//Cabecera:void Guardalum(alumno *vAlumnos, size_t tam)
//Precondición:vector vAlumnos y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de alumno

void Guardalum(alumno *vAlumnos, size_t tam) {

	int i;

	FILE *fich;

	fich = fopen("Fich/Alumnos.txt","w+");
	if (fich == NULL) {

		printf("Error al abrir fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s-%s-%s-%s",vAlumnos[i].Id_alum,vAlumnos[i].Nombre_alum,vAlumnos[i].Direc_alum,vAlumnos[i].Local_alum,vAlumnos[i].Curso,vAlumnos[i].Grupo);
			i++;
		}
	}
	fclose(fich);

}
//Cabecera:void Guardcalifica(calificaciones *vCalificaciones, size_t tam)
//Precondición:vector vCalificaciones y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de calificación
void Guardcalifica(calificaciones *vCalificaciones, size_t tam) {
	int i;

	FILE *fich;

	fich = fopen("Fich/Calificaciones.txt","w");
	if(fich == NULL) {
		printf("Error al abrir el fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s-%s-%s-%s-%s",vCalificaciones[i].dia,vCalificaciones[i].mes,vCalificaciones[i].ano,vCalificaciones[i].calificacion,vCalificaciones[i].Descrip_calif,vCalificaciones[i].Id_materia,vCalificaciones[i].Id_alum);
			i++;
		}
	}

	fclose(fich);

	printf("\n");
	system ("pause");
}
//Cabecera:void Guardfalta(faltas *vFaltas, size_t tam)
//Precondición:vector vFaltas y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de falta
void Guardfalta(faltas *vFaltas, size_t tam) {
	int i;

	FILE *fich;

	fich = fopen("Fich/Faltas.txt","w+");
	if(fich == NULL) {
		printf("Error al abrir el fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s-%s-%s-%s-%s",vFaltas[i].dia,vFaltas[i].mes,vFaltas[i].ano,vFaltas[i].hora,vFaltas[i].Descrip_falta,vFaltas[i].Estado_falta,vFaltas[i].Id_alum);
			i++;
		}
	}

	fclose(fich);

	printf("\n");
	system ("pause");
}
//Cabecera:void Guardhorario(horario *vHorarios, size_t tam)
//Precondición:vector vHorarios y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de horario
void Guardhorario(horario *vHorarios, size_t tam) {

	int i;

	FILE *fich;

	fich = fopen("Fich/Horarios.txt","w");
	if (fich == NULL) {

		printf("Error al abrir fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s-%s-%s",vHorarios[i].dia,vHorarios[i].hora,vHorarios[i].Id_profesor,vHorarios[i].Id_materia,vHorarios[i].Grupo);
			i++;
		}
	}
	fclose(fich);

}
//Cabecera:void Guardmateria(materia *vMaterias, size_t tam)
//Precondición:vector vMaterias y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de materia
void Guardmateria(materia *vMaterias, size_t tam) {
	int i;

	FILE *fich;

	fich = fopen("Fich/Materias.txt","w");
	if(fich == NULL) {
		printf("Error al abrir el fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s-%s",vMaterias[i].Id_materia,vMaterias[i].Nombre_materia,vMaterias[i].Abrev_materia);
			i++;
		}
	}

	fclose(fich);

	printf("\n");
	system("pause");
}

//Cabecera:void Guardmatricula(matricula *vMatriculas,size_t tam)
//Precondición:vector vMatriculas y tamaño del vector inicializados
//Postcondición:Almacena en fichero la información de matricula

void Guardmatricula(matricula *vMatriculas,size_t tam) {
	int i;

	FILE *fich;

	fich = fopen("Fich/Matriculas.txt","w");

	if (fich == NULL) {
		printf("Error al abrir fichero");
		exit(1);
	} else {

		while(i < tam-1) {

			fprintf(fich,"%s-%s",vMatriculas[i].Id_materia,vMatriculas[i].Id_alum);
			i++;
		}
	}

	fclose(fich);

	printf("\n");
	system("pause");
}
