#include<stdio.h>
#include<stdlib.h>

//Cabecera:int MaxComDiv(int, int)
//Precondición:x e y inicializadas en el main
//Postcondición:Devuelve el MCD de dos números

int MaxComDiv(int,int);

int main() {

	int a,b;

	printf("------Maximo Comun Divisor------\n");
	printf("Introduce ambos numeros: ");
	scanf("%d %d",&a,&b); //Lee número 1 y 2
	printf("El resultado es: %d", MaxComDiv(a, b)); //Llama a la función recursiva MaxComDiv

	return 0;
}


int MaxComDiv(int x,int y) {

	if(y==0)      //Si y=0 devuelve el valor de x,en caso contrario hace la llamada a la función
		return x; //MaxComDiv mandando como números para el cálculo de MCD "y" como primer parámetro
				  //y como segundo el resto que resulta de la división entre x e y.La variable "y" acabará 
	else		  //valiendo 0 tras varias llamadas si su valor inical no lo es.
		return MaxComDiv(y,x%y);

}
