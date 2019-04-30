/*Diseñe una función recursiva que calcule el producto de dos números mediante la
multiplicación rusa*/

#include<stdio.h>
#include<stdlib.h>

int MulRusa(int, int);

int main() {
	int x,y;
	printf("Introduzca ambos numeros a multiplicar: ");
	scanf("%d%d",&x,&y); //Lee ambos números
	printf("El resultado es %d",MulRusa(x,y)); //Muestra por pantalla el resultado de la multiplicación
	return 0;
}

//Cabecera:int MulRusa(int A, int B)
//Precondición:Valor de x e y inicializados en el main
//Postcondición:Devuelve la multiplicación al método ruso de los valores inicializados

int MulRusa(int A, int B) {
	if(A==1) {
		return (B); //Si A=1 devuelve B, debido a la propiedad del producto de un número por la unidad
	}
	if(A%2!=0) {
		
		return (B+MulRusa( A/2 , B*2)); //Si A/2 da un resto distinto de cero entonces devuelve la suma de 
										//de B y el valor que devuelva la llamada a sí misma
	} else {		//En caso contrario, realiza a una llamada a sí misma en el que A se divide por 2 y B es multiplicado por 2
		return(MulRusa( A/2 , B*2));
	}
}

