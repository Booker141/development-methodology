/*Dise�e una funci�n recursiva que calcule la funci�n de Ackermann para dos valores
cualesquiera m y n*/

#include<stdio.h>
#include<stdlib.h>

int Ackerman(int,int);

int main() {

	int m,n;
	printf("Introduzca dos numeros para realizar la funcion de Ackerman: ");
	scanf("%d%d",&m,&n); //Lee ambos n�meros
	printf("El resultado es %d",Ackerman(m,n)); //Muestra por pantalla el resultado de la funci�n Ackerman
	return 0;
}

/*		/n+1   				si m=0
A(m,n)=	/A(m-1,1)			si m>0 y n=0
		/A(m-1,A(m,n-1))    si m>0 y n>0 */



//Cabecera:int Ackerman(int m,int n)
//Precondici�n:Valor de m y n inicializados en el main
//Postcondici�n:Devuelve el valor que resulta de realizar la funci�n de Ackerman

int Ackerman(int m,int n)
{
    if(m==0)  //Debido a que m=0 entonces la funci�n es n+1
      return n+1; 
    else
    {
        if(n==0) //Si n=0 entonces la funci�n es A(m-1,1) luego devuelve el valor de la funci�n Ackerman(m-1,1)(Llamada a s� misma)
           return Ackerman(m-1, 1);
        else 	//Si no ya que n ser� mayor que 0, devuelve el valor de una funci�n cuyo segundo par�metro es, de nuevo una llamada a si misma
           return Ackerman(m-1, Ackerman(m, n-1));
    }
}
