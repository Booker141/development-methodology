#include<stdio.h>
#include<stdlib.h>
#define N 20

int SumVec(int,int);

int main() {
	
	int v[N],n,i;

	printf("Introduzca el tamano del vector: ");
	scanf("%d",&n); //Lee tamaño del vector

	for(i=0; i<n; i++) {
		do {
			
			printf("Introduzca valor en posicion %d: ",i); //Inicialización del vector
			scanf("%d",&v[i]);
			
		} while(v[i]<1&&v[i]>(n/2)-1);
	}

	printf("La suma de todos los elementos es: %d",SumVec(v,n));
	return 0;

}

//Cabecera:int SumVec(int v [], int n)
//Precondición:Vector v y n inicializados en el main
//Postcondición:Devuelve la suma de los elementos de un vector

int SumVec(int v[], int n) {
	if (n == 0) {
		return v[n];
	} else {
		return SumVec(v, n - 1) + v [n];
	}
}
