/*Dise�e una funci�n recursiva que calcule el producto de dos n�meros mediante la
multiplicaci�n rusa*/

#include<stdio.h>
#include<stdlib.h>

int MulRusa(int, int);

int main() {
	int x,y;
	printf("Introduzca ambos numeros a multiplicar: ");
	scanf("%d%d",&x,&y); //Lee ambos n�meros
	printf("El resultado es %d",MulRusa(x,y)); //Muestra por pantalla el resultado de la multiplicaci�n
	return 0;
}

//Cabecera:int MulRusa(int A, int B)
//Precondici�n:Valor de x e y inicializados en el main
//Postcondici�n:Devuelve la multiplicaci�n al m�todo ruso de los valores inicializados

int MulRusa(int A, int B) {
	if(A==1) {
		return (B); //Si A=1 devuelve B, debido a la propiedad del producto de un n�mero por la unidad
	}
	if(A%2!=0) {
		
		return (B+MulRusa( A/2 , B*2)); //Si A/2 da un resto distinto de cero entonces devuelve la suma de 
										//de B y el valor que devuelva la llamada a s� misma
	} else {		//En caso contrario, realiza a una llamada a s� misma en el que A se divide por 2 y B es multiplicado por 2
		return(MulRusa( A/2 , B*2));
	}
}

