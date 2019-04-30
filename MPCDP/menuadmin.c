#include "tipos.h"		//Módulo que contiene todos los menus
#include "menuadmin.h"
#include "admin.h"
#include "login.h"
#include "volestfich.h"

//Cabecera:void menu()
//Precondición:
//Postcondición:Imprime un menu para acceder al sistema
//con un usuario y contraseña o salir del programa

void menu() {

	int opc;

	while(opc!=3) {

		system("cls");

		puts("==========Cuaderno del Profesor==========");
		puts("\n");
		puts("Seleccione una opcion: ");
		printf("1. Acceso al sistema\n");
		printf("2. Salir del programa\n");
		printf("Introduzca una opcion: ");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				login(vUsuarios,nUsuarios);
				break;

			case 2:
				break;

		}

	}

}

//Cabecera:void menuadmin()
//Precondición:
//Postcondición:Imprime un menu para acceder a modificacion de
//usuarios, alumnos, materias y horarios respectivamente

void menuadmin() {

	int opc=0;

	while(opc!=5) {

		printf("========Menu del Administrador========\n");
		printf("1. Usuarios\n");
		printf("2. Alumnos\n");
		printf("3. Materias\n");
		printf("4. Horarios\n");
		printf("5.Salir del programa\n");
		printf("Introduzca una opcion: ");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				menuAUsuarios();
				break;

			case 2:
				menuAAlumnos();
				break;

			case 3:
				menuAMaterias();
				break;

			case 4:
				menuAHorarios();
				break;
		}

	}


}

//Cabecera:void menuAUsuarios()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de la info de usuarios

void menuAUsuarios() {

	int opc=0;

	while(opc!=5) {


		printf("========Administracion de Usuarios========\n");
		printf("1. Listar usuarios\n");
		printf("2. Modificar usuario\n");
		printf("3. Alta de usuario\n");
		printf("4. Baja de usuario\n");
		printf("5. Volver a menu administrador\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarUsuario(vUsuarios,nUsuarios);
				break;

			case 2:
				modificarUsuario(&vUsuarios,nUsuarios);
				break;

			case 3:
				printf("========Dar de alta al usuario========\n");
				altaUsuario(&vUsuarios,&nUsuarios,1);
				break;

			case 4:
				printf("========Dar de baja al usuario========\n");
				bajaUsuario(&vUsuarios,&nUsuarios);
				break;

			case 5:
				break;
		}

	}

}

//Cabecera:void menuAAlumnos()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de la info de alumnos

void menuAAlumnos() {

	int opc=0;

	while(opc!=6) {


		printf("========Administracion de Alumnos========\n");
		printf("1. Listar alumno\n");
		printf("2. Modificar alumno\n");
		printf("3. Alta de alumno\n");
		printf("4. Baja de alumno\n");
		printf("5. Modificar Matricula del alumno");
		printf("6. Volver a menu administrador\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarAlumno(vAlumnos,nAlumnos);
				break;

			case 2:
				modificarAlumno(&vAlumnos,nAlumnos);
				break;

			case 3:
				printf("========Dar de alta al alumno========\n");
				altaAlumno(&vAlumnos,&nAlumnos);
				break;

			case 4:
				printf("========Dar de baja al alumno========\n");
				bajaAlumno(&vAlumnos,&nAlumnos);
				break;

			case 5:
				Matricula(vAlumnos,vMatriculas,nAlumnos,nMatriculas);
				break;

			case 6:
				break;
		}

	}

}

//Cabecera:void menuAMaterias()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de la info de materias

void menuAMaterias() {

	int opc=0;

	while(opc!=5) {


		printf("========Administracion de Materias========\n");
		printf("1. Listar materias\n");
		printf("2. Modificar materia\n");
		printf("3. Alta de materia\n");
		printf("4. Baja de materia\n");
		printf("5. Volver a menu administrador\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarMateria(vMaterias,nMaterias);
				break;

			case 2:
				modificarMateria(&vMaterias,nMaterias);
				break;

			case 3:
				printf("========Dar de alta a una materia========\n");
				altaMateria(vMaterias,&nMaterias);
				break;

			case 4:
				printf("========Dar de baja a una materia========\n");
				bajaMateria(&vMaterias,&nMaterias);
				break;

			case 5:
				break;
		}

	}

}

//Cabecera:void menuAHorarios()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de la info de horarios

void menuAHorarios() {

	int opc=0;

	while(opc!=5) {


		printf("========Administracion de Horarios========\n");
		printf("1. Listar Horarios\n");
		printf("2. Modificar hora\n");
		printf("3. Añadir hora\n");
		printf("4. Eliminar hora\n");
		printf("5. Volver a menu administrador\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarHorario(vHorarios,nHorarios);
				break;

			case 2:
				printf("========Modificar hora a profesor========\n");
				listarProfesor(vUsuarios,nUsuarios);
				break;

			case 3:
				printf("========Anadir hora a profesor========\n");
				listarProfesor(vUsuarios,nUsuarios);
				break;

			case 4:
				printf("========Eliminar hora a profesor========\n");
				listarProfesor(vUsuarios,nUsuarios);
				break;

			case 5:
				break;
		}

	}

}

//Cabecera:void menuprof(alumno *vAlumnos,int nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Imprime un menu dependiendo de la elección de grupo y sus materias correspondientes
//para listar los alumnos pertenecientes a ese grupo y materia y otra opción para cambiar de grupo

menuprof(alumno *vAlumnos,int nAlumnos) {

	int i,opc=0;
	char ID[7];

	printf("\n========Alumnos========\n\n");

	printf("Id-Nombre-Direccion-Localidad-Curso-Grupo\n");

	for(i=0; i<nAlumnos; i++) {
		printf("%d.%s-%s-%s-%s-%s-%s\n",(i+1),vAlumnos[i].Id_alum,vAlumnos[i].Nombre_alum,vAlumnos[i].Direc_alum,vAlumnos[i].Local_alum,vAlumnos[i].Curso,vAlumnos[i].Grupo);
	}

	printf("Seleccione alumno introduciendo id: ");
	scanf("%s",ID);

	for(i=0; i<nAlumnos; i++) {
		if(strcmp(vAlumnos[i].Id_alum,ID)==0) {

			while(opc!=4) {


				printf("ALUMNO CON ID: %s\n",vAlumnos[i].Id_alum);
				printf("1. Ficha del alumno\n");
				printf("2. Calificaciones del alumno\n");
				printf("3. Faltas de asistencia\n");
				printf("4. Volver\n");
				printf("Introduzca una opcion:");
				scanf("%d",&opc);

				system("cls");

				switch(opc) {

					case 1:
						menuAlficha();
						break;

					case 2:
						menuAlcalificacion();
						break;

					case 3:
						menuAlfalta();
						break;

					case 4:
						break;


				}

			}
		}

	}
}

//Cabecera:void menuAlficha()
//Precondición:
//Postcondición:Imprime un menu con opciones como listar los datos de la ficha del alumno o
//modificar esos datos

void menuAlficha() {

	int opc=0;

	while(opc!=2) {


		printf("========Ficha del alumno========\n");
		printf("1. Listar datos\n");
		printf("2. Modificar datos\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarficha(vAlumnos,nAlumnos);
				break;

			case 2:
				modificarficha(&vAlumnos,nAlumnos);
				break;


		}

	}

}

//Cabecera:void menuAlcalificacion()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de las calificaciones del alumno

void menuAlcalificacion() {

	int opc=0;

	while(opc!=4) {


		printf("========Calificaciones del alumno========\n");
		printf("1. Listar calificaciones\n");
		printf("2. Anadir calificacion\n");
		printf("3. Eliminar calificacion\n");
		printf("4. Modificar calificacion\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarcalificacion(vCalificaciones,nCalificaciones);
				break;

			case 2:
				anadircalificacion(&vCalificaciones,&nCalificaciones);
				break;

			case 3:
				eliminarcalificacion(&vCalificaciones,&nCalificaciones);
				break;

			case 4:
				modificarcalificacion(&vCalificaciones,nCalificaciones);
				break;


		}

	}

}

//Cabecera:void menuAlfalta()
//Precondición:
//Postcondición:Imprime un menu con opciones sobre la modificación de las faltas de asistencia del alumno

void menuAlfalta() {

	int opc=0;

	while(opc!=4) {


		printf("========Faltas de asistencia del alumno========\n");
		printf("1. Listar faltas\n");
		printf("2. Anadir falta\n");
		printf("3. Eliminar falta\n");
		printf("4. Modificar falta\n");
		printf("Introduzca una opcion:");
		scanf("%d",&opc);

		system("cls");

		switch(opc) {

			case 1:
				listarfalta(vFaltas,nFaltas);
				break;

			case 2:
				anadirfalta(&vFaltas,&nFaltas);
				break;

			case 3:
				eliminarfalta(&vFaltas,&nFaltas);
				break;

			case 4:
				modificarfalta(&vFaltas,nFaltas);
				break;


		}

	}

}

