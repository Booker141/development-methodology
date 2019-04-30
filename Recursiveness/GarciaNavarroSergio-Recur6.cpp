/*Dados dos vectores A y B de n y m elementos enteros, respectivamente,
cumpli�ndose que n>=m, que ning�n elemento se repite y que est�n ordenados
crecientemente, dise�a una funci�n recursiva que determine si todos los elementos
de B est�n contenidos en A.*/

#include<stdio.h>
#include<stdlib.h>

//Cabecera: int contenido(int A[], int B[], int m, int pos, int desp)
//Precondici�n: vector A y B inicializados, n y m son los tama�os de los vectores respectivamente,
//pos es una variable entera que contiene el valor de m y desp una variable que act�a como un �ndice
//para poder desplazarse por el vector e ir comprobando los elementos de ambos uno a uno
//Postcondici�n: Devuelve 1 al terminar las comprobaciones

int contenido(int A[], int B[], int m, int pos, int desp) {
	if (pos == m) return 1;
	else if (A[desp+pos] == B[pos])
		return contenido(A,B,m, pos+1, desp);
	else
		return 0;
}

//Cabecera:int esSubarray(int A[], int B[], int n, int m, int desp)
//Precondici�n:vector A y B inicializados, n y m son los tama�os de los vectores respectivamente,
//desp es una variable que act�a como un �ndice
//Postcondici�n: Devuelve 1 si la funci�n contenido devuelve 1, es decir, si el vector B est� contenido en A

int esSubarray(int A[], int B[], int n, int m, int desp) {
	if (desp+m > n)
		return 0;
	else if (contenido(A, B, m, 0, desp)) //Si contenido devuelve 1 (pos==m) entonces estar� B contenido en A
		return 1;
	else                                  //Si no, se incrementa el desplazamiento en 1
		return esSubarray(A, B, n, m, desp+1);
}

int main() {

	int A[4] = {2, 3, 4, 5}; //Ambos vectores inicializados
	int B[3] = {3, 4, 5};
	if (esSubarray(A, B, 4, 3, 0)) //Llamada a la funci�n esSubarray y en el caso de que esta devuelva 1, B estar� contenido en A
		printf("Todos los elementos de B estan contenidos en A\n");
	else //Si no, no estar� contenido en A
		printf("Los elementos de B no estan contenidos en A\n");
}
