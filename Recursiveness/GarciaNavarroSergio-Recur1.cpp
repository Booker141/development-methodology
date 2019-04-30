#include<stdio.h>
#include<stdlib.h>

//Cabecera:int MaxComDiv(int, int)
//Precondici�n:x e y inicializadas en el main
//Postcondici�n:Devuelve el MCD de dos n�meros

int MaxComDiv(int,int);

int main() {

	int a,b;

	printf("------Maximo Comun Divisor------\n");
	printf("Introduce ambos numeros: ");
	scanf("%d %d",&a,&b); //Lee n�mero 1 y 2
	printf("El resultado es: %d", MaxComDiv(a, b)); //Llama a la funci�n recursiva MaxComDiv

	return 0;
}


int MaxComDiv(int x,int y) {

	if(y==0)      //Si y=0 devuelve el valor de x,en caso contrario hace la llamada a la funci�n
		return x; //MaxComDiv mandando como n�meros para el c�lculo de MCD "y" como primer par�metro
				  //y como segundo el resto que resulta de la divisi�n entre x e y.La variable "y" acabar� 
	else		  //valiendo 0 tras varias llamadas si su valor inical no lo es.
		return MaxComDiv(y,x%y);

}
