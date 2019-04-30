#include<stdio.h>
#include<stdlib.h>


//Cabecera:int conj(int,int)
//Precondici�n:n y k inicializados en el main
//Postcondici�n:Devuelve la cantidad de diferentes conjuntos de "n" personas
//que pueden formarse, dadas "k" personas entre las que elegir.

int conj(int,int);

int main() {
	int n,k,r;

	do {
		puts("Introduce el numero de personas");
		scanf("%d",&n);  //Lee n
		puts("Introduce el tamano de los grupos");
		scanf("%d",&k); //Lee k
		if (n<=0 || k<=0) 
			printf("Los valores introducidos no son v�lidos. Por favor, introduzca valores iguales o mayores a 1\n");
	} while (n<=0 || k<=0); //Realiza la comprobaci�n para que los datos sean v�lidos

	r=conj(n,k);
	printf("La cantidad de conjuntos dadas %d personas y %d personas elegidas es : %d",n,k,r);
	return 0;
}

int conj(int n, int k) {

	if (k==0 || n==k)
		return 1;  //Devuelve 1 en el caso de que el n� de personas y el tama�o del grupo sean iguales o el tama�o del grupo sea 0
	else
		return (conj(n-1,k)+conj(n-1,k-1));
}
