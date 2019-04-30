/*En un vector de enteros se genera un «cambio de tendencia» cuando dada una
secuencia creciente o decreciente de números que ocupan posiciones consecutivas
del vector, el elemento que le sucede es inferior o superior, respectivamente. Dado
un vector de N enteros, diseñe una función recursiva que calcule el número de
«cambios de tendencia» que contiene dicho vector.*/

#include<stdio.h>
#include<stdlib.h>

//No comprendo el fallo de compilación del programa.

int CamTen(int,int,int);

int main() {
	int n,i,in=0;
	int v[n];
	do {

		printf("Introduzca tamano del vector: ");
		scanf("%d",&n);
		
	} while(n<0);
	for(i=0; i<n; i++) {

		printf("Introduzca elemento %d del vector: ",i+1); //Inicialización del vector.
		scanf("%d",&v[i]);
	}
	printf("Cambio de tendencia\n");
	printf("Hay %d cambios de tendencia en el vector",CamTen(v,n,in));
	return 0;
}

//Cabecera:CamTen(int v[],int n,int in)
//Precondición:Vector v y n inicializados en el main
//Postcondición:Devuelve nº de cambios de tendencia en el vector

int CamTen(int v[],int n,int in) {
//{n>=0^in=0}
	int cam=0;
	if(n==0)	//No hay cambios de tendencia si el vector tiene 0 como tamaño, es decir no hay elementos en el.
		return 0;

	if(v[in-1]<v[in]&&v[in]>v[in+1]) //En estos bucles lo principal es comparar el elemento anterior y posterior
		cam++;						//con el elemento en el que se encuentra el índice para comprobar si hay un cambio
	if(v[in-1]>v[in]&&v[in]<v[in+1])//de tendencia. Luego, si alguna de las condiciones de los bucles se cumple implica
		cam++;						//que hay un cambio de tendencia.
	if(v[in-1]==v[in]&&v[in]<v[in+1])
		cam++;
	if(v[in-1]==v[in]&&v[in]>v[in+1])
		cam++;
	if(in==n)
		return cam;	//Devuelve los cambios si el indice ha llegado al tamaño del vector.

	return CamTen(v,n,in+1); //Va recorriendo todos los elementos del vector.
//{in==n^cam>=0}
}
