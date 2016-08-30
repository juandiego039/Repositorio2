#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

/*
*** *** *** *** *** *** *** *** *** *** *** *** *** *** 
Definici�n de Variables:
    1  2  3      u         N
s=[s1,s2,s3,...,su,0,0,...,0]  -> vector de tama�o N
u representa el n�mero de unidades
sum_{i=1}^{N}s(i) = sum_{i=1}^{u}s(i) = N

*** *** *** *** *** *** *** *** *** *** *** *** *** *** 
*/

/* Funci�n para fragmentar una unidad
s[] = Vector de fuerza del ejercito
u = n�mero de unidades   1 <= u <= N
j = unidad que se quiere fragmentar   1 <= j <= u
*/
int fragmentar(int s[], int u, int j)
{
	int sj = s[j-1];
	s[j-1]=1;
	for(int ind=u; ind <= u+sj-2;ind++)
	{
		s[ind]=1;
	}
	return *s;
}

/* Funci�n para coalisionar dos unidades
s[] = Vector de fuerza del ejercito
N = Total de fuerza de ataque del ejercito
u = n�mero de unidades   1 <= u <= N
j1, j2 = unidad que se quiere fragmentar   1 <= j1, j2 <= u
j1 y j2 DEBEN ser diferentes
*/
int coalisionar(int s[], int N, int u, int j1, int j2)
{
	if(j1>j2)
	{
		int aux = j1;
		j1 = j2;
		j2 = aux;
	}
	//Siempre j2 > j1
	
	s[j1-1]=s[j1-1]+s[j2-1];
	
	for(int ind=j2; ind <= u;ind++)
	{
		s[ind-1]=s[ind];
	}
	if(u==N)
	{
		s[u-1]=0;
	}
	return *s;
}

/*Funci�n que selecciona una unidad. La selecci�n se hace proporcional a su fuerza.
s[] = Vector de fuerza del ejercito
u = n�mero de unidades   1 <= u <= N
x = n�mero aleatorio 1 <= x <= N
*/
int seleccionar(int s[], int u, int x)
{
	int suma =0;
	int suma_m=0;
	int unidad_seleccionada = 0;
	for(int ind=1;ind<=u;ind++)
	{
		suma_m = suma + s[ind-1];
		if(suma<x && x<=suma_m)
		{
			unidad_seleccionada = ind;
			break;
		}
		suma = suma_m;
	}
	return unidad_seleccionada;
	
}

/*Funci�n que encuentra el m�ximo de un vector.
s[] = Vector de fuerza del ejercito
u = n�mero de unidades   1 <= u <= N
*/
int maximo(int s[], int u)
{
	int max=s[0];
	for(int k=1;k<u;k++)
	{
		if(s[k]>max){max=s[k];}	
	}
	return max;
}

/*Funci�n principal del programa*/
int main(void)
{
	/* *** *** Entradas del programa *** *** */
	int N = 10000;                   //Total de fuerza de ataque del ejercito
	double nu = 0.01;              //Probabilidad de que la unidad se fragmente
	int Num_iteraciones =20000;     //Se define el n�mero de iteraciones
		
	/* *** *** Definici�n de variables *** *** */
	int s[N];					   //Vector de fuerza
	s[0] = N;					   //Valor inicial como un ejercito unido
	for(int i=1;i<N;i++){s[i]=0;}  //Las casillas sobrantes se llenan con 0
	int u = 1;                     //N�mero de unidades 1<= u <= N
	int sj=0;					   //Variable auxiliar. Se usa cuando hay fragmentaci�n.
	bool coalision = true;         //Determina si se hace una coalision (true) o fragmentaci�n (false).
	int x;    					   //Variable para guardar un n�mero aleatorio tipo int
	double y = 0;				   //Variable para guardar un n�mero aleatorio tipo double
	int unidad = 1;				   //Variable para guardar la unidad seleccionada
	int unidad2= 1;				   //Variable para guardar la segunda unidad seleccionada (en el caso coalisi�n)
	int cantidad;				   //Variable donde se guarda la cantidad de unidades con determinada fuerza (Parte 6)
	int funcion[N];				   //Vector donde se guardan los datos de salida (En enteros).
	for(int i=0;i<N;i++){funcion[i]=0;}  //Las casillas sobrantes se llenan con 0
	funcion[N-1]=1; 				     //Inicialmente existe una unidad con fuerza N
	int fuerza_max;						 //Vector donde se guarda la fuerza m�xima (Parte 6)
	srand(time(NULL));    			     //Semilla aleatoria para la funci�n rand()
	
	
	
	return 0;
}
