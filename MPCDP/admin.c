#include "admin.h"  //Módulo para las tareas del administrador

/*USUARIOS*/

//Cabecera:void listarUsuario(usuario *vUsuarios,int nUsuarios)
//Precondición:vector vUsuarios y nUsuarios inicializados
//Postcondición:Imprime por pantalla los usuarios registrados

void listarUsuario(usuario *vUsuarios,int nUsuarios) {

	int i;
	
	vUsuarios=(usuario*)malloc(sizeof(usuario));

	printf("\n========Usuarios========\n\n");
	printf("Id-Nombre-Perfil-Usuario-Contraseña\n");

	for(i=0; i<nUsuarios; i++) {
		printf("%s-%s-%s-%s-%s\n",vUsuarios[i].Id,vUsuarios[i].Nombre,vUsuarios[i].Perfil,vUsuarios[i].Usuario,vUsuarios[i].Contrasena);
	}

}

//Cabecera:void modificarUsuario(usuario **vUsuarios,int nUsuarios)
//Precondición:vector vUsuarios y nUsuarios inicializados
//Postcondición:Modifica la informacion del usuario seleccionado

void modificarUsuario(usuario **vUsuarios,int nUsuarios) {

	int i;
	int u=-1;
	char resp=' ';
	char id[3];

	int nModUsuario=0;

	usuario *modUsuario;

	modUsuario=(usuario*)malloc(sizeof(usuario));

	printf("Modificar usuarios\n\n");


	while(u == -1) {

		printf("Introduzca el id del usuario que desea modificar: ");
		scanf("%3s",id);

		for(i=0; i<nUsuarios; i++) {

			if(strcmp((*vUsuarios)[i].Id,id)==0) {

				u=i;

			}

		}

		if(u == -1) {

			printf("Error: Ese usuario no está registrado\n");

		} else {

			printf("Informacion del usuario (actual): %s-%s-%s-%s-%s\n\n",(*vUsuarios)[u].Id,(*vUsuarios)[u].Nombre,(*vUsuarios)[u].Perfil,(*vUsuarios)[u].Usuario,(*vUsuarios)[u].Contrasena);

			printf("Introduzca la nueva informacion del usuario: (Id-Nombre-Perfil-Usuario-Contraseña)\n");

			altaUsuario(&modUsuario,&nModUsuario,1);

			while(resp!='s' && resp!='n') {

				printf("¿Modificar usuario? (s/n)\n");
				fflush(stdin);
				scanf("%c",&resp);

			}

			if(resp=='s') {

				(*vUsuarios)[u]=modUsuario[0];

			} else {

				printf("Se ha denegado la modificacion del usuario\n");

			}

		}

	}

}

//Cabecera:void altaUsuario(usuario **vUsuarios,int *nUsuarios,int admin)
//Precondición:vector vUsuarios y nUsuarios inicializados
//Postcondición:Añade un nuevo usuario

void altaUsuario(usuario **vUsuarios,int *nUsuarios,int admin) {

	int n;

	realloc(vUsuarios,((*nUsuarios)+1)); 

	puts("Introduzca el id del usuario (3 cifras maximo):");
	fflush(stdin);
	scanf("%3s",(*vUsuarios)[*nUsuarios].Id);

	puts("Introduzca el nombre completo del usuario (20 caracteres como maximo):");
	fflush(stdin);
	scanf("%20s",(*vUsuarios)[*nUsuarios].Nombre);


	while(n<1 || n>3) {

		if(admin==1) {

			puts("Seleccione el perfil de usuario:");
			puts("1. Administrador");
			puts("2. Profesor");
			fflush(stdin);
			scanf("%d",&n);

		} else {

			n=3;

		}

		switch(n) {

			case 1:
				strcpy((*vUsuarios)[*nUsuarios].Perfil,"Administrador");
				break;

			case 2:
				strcpy((*vUsuarios)[*nUsuarios].Perfil,"Profesor");
				break;

			default:
				puts("Error: La opcion introducida no es valida");

		}

	}

	puts("Introduzca el usuario (5 caracteres maximo):");
	fflush(stdin);
	scanf("%5s",(*vUsuarios)[*nUsuarios].Usuario);

	puts("Introduzca la contraseña del usuario (8 caracteres maximo):");
	fflush(stdin);
	scanf("%8s",(*vUsuarios)[*nUsuarios].Contrasena);

	(*nUsuarios)++;

}

//Cabecera:void bajaUsuario(usuario **vUsuarios,int *nUsuarios)
//Precondición:vector vUsuarios y nUsuarios inicializados
//Postcondición:Elimina un usuario ya existente

void bajaUsuario(usuario **vUsuarios,int *nUsuarios) {

	int i;
	int u;
	char resp=' ';
	char id[3];

	printf("Baja del usuario\n\n");

	printf("Introduzca la id del usuario a dar de baja: ");
	scanf("%3s",id);

	for(i=0; i<(*nUsuarios); i++) {

		if(strcmp((*vUsuarios)[i].Id,id)==0) {

			u=i;

		}

	}

	while(resp!='s' && resp!='n') {

		printf("Se va a dar de baja el siguiente usuario: %s-%s-%s-%s-%s\n",(*vUsuarios)[u].Id,(*vUsuarios)[u].Nombre,(*vUsuarios)[u].Perfil,(*vUsuarios)[u].Usuario,(*vUsuarios)[u].Contrasena);
		printf("¿Dar de baja al usuario? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		for(i=u; i+1<(*nUsuarios); i++) {

			strcpy((*vUsuarios)[i].Id,(*vUsuarios)[i+1].Id);
			strcpy((*vUsuarios)[i].Nombre,(*vUsuarios)[i+1].Nombre);
			strcpy((*vUsuarios)[i].Perfil,(*vUsuarios)[i+1].Perfil);
			strcpy((*vUsuarios)[i].Usuario,(*vUsuarios)[i+1].Usuario);
			strcpy((*vUsuarios)[i].Contrasena,(*vUsuarios)[i+1].Contrasena);

		}

		(*nUsuarios)--;

		realloc(vUsuarios,(*nUsuarios));

	} else {

		printf("Se ha denegado la eliminacion del usuario\n");

	}

}



/*ALUMNOS*/

//Cabecera:void listarAlumno(alumno *vAlumnos,int nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Imprime por pantalla los alumnos

void listarAlumno(alumno *vAlumnos,int nAlumnos) {

	int i;

	printf("\n========Alumnos========\n\n");

	printf("Id-Nombre-Direccion-Localidad-Curso-Grupo\n");

	for(i=0; i<nAlumnos; i++) {
		printf("%s-%s-%s-%s-%s-%s\n",vAlumnos[i].Id_alum,vAlumnos[i].Nombre_alum,vAlumnos[i].Direc_alum,vAlumnos[i].Local_alum,vAlumnos[i].Curso,vAlumnos[i].Grupo);
	}

}

//Cabecera:void modificarAlumno(alumno **vAlumnos,int nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Modifica la informacion del alumno seleccionado

void modificarAlumno(alumno **vAlumnos,int nAlumnos) {

	int i;
	int a=-1;
	char resp=' ';
	char ID[6];

	int nModAlumno=0;

	alumno *modAlumno;

	modAlumno=(alumno*)malloc(sizeof(alumno));

	printf("Modificar Alumnos\n\n");


	while(a == -1) {

		printf("Introduzca la id del alumno que desea modificar: ");
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

//Cabecera:void altaAlumno(alumno **vAlumnos,int *nAlumnos,int admin)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Añade un nuevo alumno

void altaAlumno(alumno **vAlumnos,int *nAlumnos) {

	char resp=' ';

	realloc(vAlumnos,((*nAlumnos)+1)); //	REVISAR

	do {
		printf("Alta del alumno\n\n");

		printf("Introduzca la id del alumno (6 cifras maximo):");
		fflush(stdin);
		scanf("%6s",(*vAlumnos)[*nAlumnos].Id_alum);

		printf("Introduzca el nombre del alumno (20 caracteres como maximo):");
		fflush(stdin);
		scanf("%20s",(*vAlumnos)[*nAlumnos].Nombre_alum);

		printf("Introduzca la direccion del alumno (30 caracteres maximo):");
		fflush(stdin);
		scanf("%30s",(*vAlumnos)[*nAlumnos].Direc_alum);

		printf("Introduzca la localidad del alumno (30 caracteres maximo):");
		fflush(stdin);
		scanf("%30s",(*vAlumnos)[*nAlumnos].Local_alum);

		printf("Introduzca el curso al que pertenece el alumno (30 caracteres maximo):");
		fflush(stdin);
		scanf("%30s",(*vAlumnos)[*nAlumnos].Curso);

		printf("Introduzca el grupo al que pertenece el alumno (10 caracteres maximo):");
		fflush(stdin);
		scanf("%10s",(*vAlumnos)[*nAlumnos].Grupo);

		do {

			printf("¿Quiere dar de alta a otro alumno? (s/n): ");
			fflush(stdin);
			scanf("%c",&resp);


		} while(resp!='s' && resp!='n');


	} while(resp=='s' && resp!='n');


	(*nAlumnos)++;

}

//Cabecera:void bajaAlumno(alumno **vAlumnos,int *nAlumnos)
//Precondición:vector vAlumnos y nAlumnos inicializados
//Postcondición:Elimina un alumno ya existente

void bajaAlumno(alumno **vAlumnos,int *nAlumnos) {

	int i;
	int a;
	char resp=' ';
	char ID[6];

	printf("Baja del alumno\n\n");

	printf("Introduzca la id del alumno a dar de baja: ");
	scanf("%6s",ID);

	for(i=0; i<(*nAlumnos); i++) {

		if(strcmp((*vAlumnos)[i].Id_alum,ID)==0) {

			a=i;

		}

	}

	while(resp!='s' && resp!='n') {

		printf("Se va a dar de baja al siguiente alumno: %s-%s-%s-%s-%s-%s\n",(*vAlumnos)[a].Id_alum,(*vAlumnos)[a].Nombre_alum,(*vAlumnos)[a].Direc_alum,(*vAlumnos)[a].Local_alum,(*vAlumnos)[a].Curso,(*vAlumnos)[a].Grupo);
		printf("¿Dar de baja al alumno? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		for(i=a; i+1<(*nAlumnos); i++) {

			strcpy((*vAlumnos)[i].Id_alum,(*vAlumnos)[i+1].Id_alum);
			strcpy((*vAlumnos)[i].Nombre_alum,(*vAlumnos)[i+1].Nombre_alum);
			strcpy((*vAlumnos)[i].Direc_alum,(*vAlumnos)[i+1].Direc_alum);
			strcpy((*vAlumnos)[i].Local_alum,(*vAlumnos)[i+1].Local_alum);
			strcpy((*vAlumnos)[i].Curso,(*vAlumnos)[i+1].Curso);
			strcpy((*vAlumnos)[i].Grupo,(*vAlumnos)[i+1].Grupo);

		}

		(*nAlumnos)--;

		realloc(vAlumnos,(*nAlumnos)); 

	} else {

		printf("Se ha denegado la baja del alumno\n");

	}

}

//Cabecera:void Matricula(alumno *vAlumnos,matricula *vMatriculas,int nAlumnos,int *nMatriculas)
//Precondición:vector vAlumnos, vMatriculas, nAlumnos y nMatriculas inicializados
//Postcondición:Realiza cualquier modificacion en la matricula de un alumno previamente seleccionado

void Matricula(alumno *vAlumnos,matricula *vMatriculas,int nAlumnos,int nMatriculas) {
	
	int i;
	char id[5];
	int opc=0;
	int a=-1;
	char resp=' ';
	char ID[7];

	while(a == -1) {

		printf("Introduzca la id del alumno cuya matricula desea modificar: ");
		scanf("%6s",ID);

		for(i=0; i<nAlumnos; i++) {

			if(strcmp(vAlumnos[i].Id_alum,ID)==0) {

				a=i;

			}

		}

		if(a == -1) {

			printf("Error: Ese alumno no está registrado\n");

		} else {

			do {
				
				for(i=0;i<nMatriculas;i++){
					if(strcmp(vAlumnos[i].Id_alum,vMatriculas[i].Id_alum))
						printf("%s-%s\n",vMatriculas[i].Id_alum,vMatriculas[i].Id_materia);
				}


				printf("========Matriculas========\n\n");
				printf("1. Modificar matricula\n");
				printf("2. Crear matricula\n");
				printf("3. Eliminar matricula\n");
				printf("Introduzca una opcion:");
				scanf("%d",&opc);

				system("cls");

				switch(opc) {

					case 1:
						printf("Introduzca nueva id materia: ");
						fflush(stdin);
						scanf("%5s",id);
						strcpy(vMatriculas[a].Id_materia,id);
						break;

					case 2:
						printf("Introduzca de nuevo la ID del alumno: ");
						fflush(stdin);
						scanf("%6s",(vMatriculas)[nMatriculas].Id_alum);
						printf("Introduzca la id de la materia de la nueva matricula para el alumno seleccionado: ");
						fflush(stdin);
						scanf("%4s",(vMatriculas)[nMatriculas].Id_materia);
						break;

					case 3:
						strcpy(vMatriculas[a].Id_materia,vMatriculas[a+1].Id_materia);
						strcpy(vMatriculas[a].Id_alum,vMatriculas[a+1].Id_alum);
						break;


				}

			} while(opc=!3);

		}
	}

}

/*MATERIAS*/

//Cabecera:void listarMateria(materia *vMaterias,int nMaterias)
//Precondición:vector vMaterias y nMaterias inicializados
//Postcondición:Imprime por pantalla las materias

void listarMateria(materia *vMaterias,int nMaterias) {
	int i;

	printf("\n========Materias========\n\n");

	printf("Id-Nombre-Abreviatura\n");

	for(i=0; i<nMaterias; i++) {
		printf("%s-%s-%s\n",vMaterias[i].Id_materia,vMaterias[i].Nombre_materia,vMaterias[i].Abrev_materia);
	}

}

//Cabecera:void modificarMateria(materia **vMaterias,int nMaterias)
//Precondición:vector vMaterias y nMaterias inicializados
//Postcondición:Modifica la informacion de la materia seleccionada

void modificarMateria(materia **vMaterias,int nMaterias) {

	int i;
	int m=-1;
	char resp=' ';
	char Id[5];

	int nModMateria=0;

	materia *modMateria;

	modMateria=(materia*)malloc(sizeof(materia));

	printf("Modificar Materias\n\n");


	while(m == -1) {

		printf("Introduzca la id de la materia que desea modificar: ");
		fflush(stdin);
		scanf("%4s",Id);

		for(i=0; i<nMaterias; i++) {

			if(strcmp((*vMaterias)[i].Id_materia,Id)==0) {

				m=i;

			}

		}

		if(m == -1) {

			printf("Error: Esa materia no está registrada\n");

		} else {

			printf("Informacion de la materia (actual): %s-%s-%s\n",(*vMaterias)[m].Id_materia,(*vMaterias)[m].Nombre_materia,(*vMaterias)[m].Abrev_materia);

			printf("Introduzca la nueva informacion de la materia (Id-Nombre-Abreviatura): ");

			altaMateria(modMateria,&nModMateria);

			while(resp!='s' && resp!='n') {

				printf("¿Modificar materia? (s/n)\n");
				fflush(stdin);
				scanf("%c",&resp);

			}

			if(resp=='s') {

				(*vMaterias)[m]=modMateria[0];

			} else {

				printf("Se ha denegado la modificacion de la materia\n");

			}

		}

	}

}

//Cabecera:void altaMateria(materia **vMaterias,int *nMaterias)
//Precondición:vector vMaterias y nMaterias inicializados
//Postcondición:Añade una nueva materia

void altaMateria(materia *vMaterias,int *nMaterias) {


	char resp=' ';

	realloc(vMaterias,((*nMaterias)+1)); 

	do {
		printf("Alta de la materia\n\n");

		printf("Introduzca la id de la materia (4 cifras maximo):");
		fflush(stdin);
		scanf("%4s",(vMaterias)[*nMaterias].Id_materia);

		printf("Introduzca el nombre de la materia (50 caracteres como maximo):");
		fflush(stdin);
		scanf("%50s",(vMaterias)[*nMaterias].Nombre_materia);

		printf("Introduzca la abreviatura de la materia (3 caracteres maximo):");
		fflush(stdin);
		scanf("%3s",(vMaterias)[*nMaterias].Abrev_materia);

		do {

			printf("¿Quiere dar de alta a otro materia? (s/n): ");
			fflush(stdin);
			scanf("%c",&resp);


		} while(resp!='s' && resp!='n');


	} while(resp=='s' && resp!='n');


	(*nMaterias)++;

}

//Cabecera:void bajaMateria(materia **vMaterias,int *nMaterias)
//Precondición:vector vMaterias y nMaterias inicializados
//Postcondición:Elimina una materia ya existente

void bajaMateria(materia **vMaterias,int *nMaterias) {

	int i;
	int m;
	char resp=' ';
	char Id[5];

	printf("Baja de la materia\n\n");

	printf("Introduzca la id de la materia a dar de baja: ");
	scanf("%5s",Id);

	for(i=0; i<(*nMaterias); i++) {

		if(strcmp((*vMaterias)[i].Id_materia,Id)==0) {

			m=i;

		}

	}

	while(resp!='s' && resp!='n') {

		printf("Se va a dar de baja a la siguiente matricula: %s-%s-%s\n",(*vMaterias)[m].Id_materia,(*vMaterias)[m].Nombre_materia,(*vMaterias)[m].Abrev_materia);
		printf("¿Dar de baja a la materia? (s/n)\n");
		fflush(stdin);
		scanf("%c",&resp);

	}

	if(resp=='s') {

		for(i=m; i+1<(*nMaterias); i++) {

			strcpy((*vMaterias)[i].Id_materia,(*vMaterias)[i+1].Id_materia);
			strcpy((*vMaterias)[i].Nombre_materia,(*vMaterias)[i+1].Nombre_materia);
			strcpy((*vMaterias)[i].Abrev_materia,(*vMaterias)[i+1].Abrev_materia);

		}

		(*nMaterias)--;

		realloc(vMaterias,(*nMaterias)); 

	} else {

		printf("Se ha denegado la baja de la materia\n");

	}

}

/*HORARIOS*/

//Cabecera:void listarHorario(horario *vHorarios,int nHorarios)
//Precondición:vector vHorarios y nHorarios inicializados
//Postcondición:Imprime por pantalla los horarios

void listarHorario(horario *vHorarios,int nHorarios) {
	int i;

	printf("\n========Horarios========\n\n");

	printf("Id(profesor)-Dia(clase)-Hora(clase)-Id(materia)-Grupo\n");

	for(i=0; i<nHorarios; i++) {
		printf("%s-%s-%s-%s-%s\n",vHorarios[i].Id_profesor,vHorarios[i].dia,vHorarios[i].hora,vHorarios[i].Id_materia,vHorarios[i].Grupo);
	}

}

//Cabecera:void listarProfesor(usuario *vUsuarios,int nUsuarios)
//Precondición:vector vUsuarios y nUsuarios inicializados
//Postcondición:Imprime por pantalla los profesores

void listarProfesor(usuario *vUsuarios,int nUsuarios) {

	int i,opc=0;

	while(opc!=nUsuarios) {

		printf("\n========Profesores========\n\n");

		printf("Id-Nombre-Perfil\n");

		for(i=0; i<nUsuarios; i++) {
			printf("%d.%s-%s-%s\n",(i+1),vUsuarios[i].Id,vUsuarios[i].Nombre,vUsuarios[i].Perfil);
		}

		printf("Introduzca una opcion: ");
		scanf("%d",&opc);

		for(i=0; i<nUsuarios; i++) {
			if(opc=i) {
				anadirHora(i);
				eliminarHora(i);
			}
		}
	}
}

//Cabecera:void anadirHora(int j)
//Precondición:variable j inicializada
//Postcondición:Añade una hora para un profesor seleccionado

void anadirHora(int j) {
	char HORA[2];
	char resp=' ';
	printf("¿Desea añadir hora? (s/n): ");
	scanf("%c",&resp);
	fflush(stdin);
	if(resp=='s' && resp!='n') {
		printf("Introduzca nueva hora (1-6): ");
		scanf("%s",HORA);
		strcpy(vHorarios[j].hora,HORA);
		printf("¿Desea introducir otra nueva hora? (s/n): ");
		scanf("%c",&resp);
	}
}

//Cabecera:void eliminarHora(int h)
//Precondición:variable h inicializada
//Postcondición:Elimina la hora al profesor seleccionado

void eliminarHora(int h) {
	char Hora[2];
	char resp=' ';
	printf("¿Desea eliminar hora? (s/n): ");
	scanf("%c",&resp);
	fflush(stdin);
	if(resp=='s' && resp!='n') {

		strcpy(vHorarios[h].hora,vHorarios[h+1].hora);

		resp='n';
	} else {
		printf("Debe crear una nueva hora\n");
		anadirHora(h);
	}
}
