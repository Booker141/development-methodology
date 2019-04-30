#include <stdio.h>
#include <stdlib.h>


//Cabecera:int buscar(int *v, int i, int f, int *may)
//Precondición:Vector v , i, f y may inicializados
//Postcondición:Busca el elemento mayoritario del vector inicializado

int buscar(int *v, int i, int f, int *may) {
	if(f-i == 0) {
		*may = v[i];
		return 1;
	}
	int m = (i+f)/2, m1, m2, c1, c2;
	c1 = buscar(v, i, m, &m1);
	c2 = buscar(v, m+1, f, &m2);
	if(m1 == m2) {
		*may = m1;
		return c1 + c2;
	} else {
		if(c1 > c2) {
			*may = m1;
			return c1-c2;
		} else {
			*may = m2;
			return c2-c1;
		}
	}
}

//Cabecera:bool verificar(int *v, int n, int may)
//Precondición:Vector v , n, y may inicializados
//Postcondición:Verifica el elemento mayoritario

bool verificar(int *v, int n, int may) {
	int c=0;
	for(int i=0; i<n; i++) {
		if(v[i] == may) {
			c++;
		}
	}
	return (c > n/2); //Es mayoritario si aparece más que n/2 veces
}

int main() {

	int *v, n, may, c;
	printf("Introduzca tamano vector: ");
	scanf("%d", &n); //Lee n, tamaño del vector

	for(int i=0; i<n; i++) {
		printf("Introduzca el elemento %d del vector: ",i); //Inicialización del vector
		scanf("%d", &v[i]);
	}
	if(buscar(v, 0, n-1, &may) > 0) {
		if(verificar(v, n, may))  //Si verificar devuelve 1(verdadero) entonces muestra el elemento mayoritario
			printf("El elemento mayoritario es %d", may);
		else  //Si no, no existe ese elemento mayoritario
			printf("No existe un elemento mayoritario");

	} else //Si el elemento devuelto por la función buscar es 0 o menor entonces no existe elemnto mayoritario en el vector
		printf("No existe un elemento mayoritario");

	return 0;
}
