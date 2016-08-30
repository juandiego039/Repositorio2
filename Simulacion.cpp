#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

/*
*** *** *** *** *** *** *** *** *** *** *** *** *** *** 
Definición de Variables:
    1  2  3      u         N
s=[s1,s2,s3,...,su,0,0,...,0]  -> vector de tamaño N
u representa el número de unidades
sum_{i=1}^{N}s(i) = sum_{i=1}^{u}s(i) = N

*** *** *** *** *** *** *** *** *** *** *** *** *** *** 
*/

/* Función para fragmentar una unidad
s[] = Vector de fuerza del ejercito
u = número de unidades   1 <= u <= N
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

/* Función para coalisionar dos unidades
s[] = Vector de fuerza del ejercito
N = Total de fuerza de ataque del ejercito
u = número de unidades   1 <= u <= N
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

/*Función que selecciona una unidad. La selección se hace proporcional a su fuerza.
s[] = Vector de fuerza del ejercito
u = número de unidades   1 <= u <= N
x = número aleatorio 1 <= x <= N
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

/*Función principal del programa*/
int main(void)
{
	/* *** *** Entradas del programa *** *** */
	int N = 10000;                   //Total de fuerza de ataque del ejercito
	double nu = 0.01;              //Probabilidad de que la unidad se fragmente
	int Num_iteraciones =20000;     //Se define el número de iteraciones
		
	/* *** *** Definición de variables *** *** */
	int s[N];					   //Vector de fuerza
	s[0] = N;					   //Valor inicial como un ejercito unido
	for(int i=1;i<N;i++){s[i]=0;}  //Las casillas sobrantes se llenan con 0
	int u = 1;                     //Número de unidades 1<= u <= N
	int sj=0;					   //Variable auxiliar. Se usa cuando hay fragmentación.
	
	return 0;
}
