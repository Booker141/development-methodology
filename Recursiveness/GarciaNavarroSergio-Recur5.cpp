/*Diseñe una función recursiva que calcule la función de Ackermann para dos valores
cualesquiera m y n*/

#include<stdio.h>
#include<stdlib.h>

int Ackerman(int,int);

int main() {

	int m,n;
	printf("Introduzca dos numeros para realizar la funcion de Ackerman: ");
	scanf("%d%d",&m,&n); //Lee ambos números
	printf("El resultado es %d",Ackerman(m,n)); //Muestra por pantalla el resultado de la función Ackerman
	return 0;
}

/*		/n+1   				si m=0
A(m,n)=	/A(m-1,1)			si m>0 y n=0
		/A(m-1,A(m,n-1))    si m>0 y n>0 */



//Cabecera:int Ackerman(int m,int n)
//Precondición:Valor de m y n inicializados en el main
//Postcondición:Devuelve el valor que resulta de realizar la función de Ackerman

int Ackerman(int m,int n)
{
    if(m==0)  //Debido a que m=0 entonces la función es n+1
      return n+1; 
    else
    {
        if(n==0) //Si n=0 entonces la función es A(m-1,1) luego devuelve el valor de la función Ackerman(m-1,1)(Llamada a sí misma)
           return Ackerman(m-1, 1);
        else 	//Si no ya que n será mayor que 0, devuelve el valor de una función cuyo segundo parámetro es, de nuevo una llamada a si misma
           return Ackerman(m-1, Ackerman(m, n-1));
    }
}
