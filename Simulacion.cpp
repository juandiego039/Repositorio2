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
/*Función que encuentra el máximo de un vector.
s[] = Vector de fuerza del ejercito
u = número de unidades   1 <= u <= N
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

/*Función principal del programa*/
int main(void)
{
	/* *** *** Entradas del programa *** *** */
	int N = 10000;                   //Total de fuerza de ataque del ejercito
	double nu = 0.9;              //Probabilidad de que la unidad se fragmente
	int Num_iteraciones =20000;     //Se define el número de iteraciones
		
	/* *** *** Definición de variables *** *** */
	int s[N];					   //Vector de fuerza
	s[0] = N;					   //Valor inicial como un ejercito unido
	for(int i=1;i<N;i++){s[i]=0;}  //Las casillas sobrantes se llenan con 0
	int u = 1;                     //Número de unidades 1<= u <= N
	int sj=0;					   //Variable auxiliar. Se usa cuando hay fragmentación.
	bool coalision = true;         //Determina si se hace una coalision (true) o fragmentación (false).
	int x;    					   //Variable para guardar un número aleatorio tipo int
	double y = 0;				   //Variable para guardar un número aleatorio tipo double
	int unidad = 1;				   //Variable para guardar la unidad seleccionada
	int unidad2= 1;				   //Variable para guardar la segunda unidad seleccionada (en el caso coalisión)
	int cantidad;				   //Variable donde se guarda la cantidad de unidades con determinada fuerza (Parte 6)
	int funcion[N];				   //Vector donde se guardan los datos de salida (En enteros).
	for(int i=0;i<N;i++){funcion[i]=0;}  //Las casillas sobrantes se llenan con 0
	funcion[N-1]=1; 				     //Inicialmente existe una unidad con fuerza N
	int fuerza_max;						 //Vector donde se guarda la fuerza máxima (Parte 6)
    srand(time(NULL));    			     //Semilla aleatoria para la función rand()
    
    printf ("Total de fuerza: N=%d\n",N);
    printf ("Total de iteraciones: %d\n",Num_iteraciones);
    printf ("Probabilidad de fragmentaci\242n: %lf\n",nu);
    
    /* Inicio de las iteraciones */
    for(int iteracion=1;iteracion<=Num_iteraciones;iteracion++)
	{
		printf ("Iteraci\242n: %d\r",iteracion);
		//1 - Se selecciona una unidad
    	x = 1 + rand()%N;                    //Genera un número entre 1 y N
		unidad = seleccionar(s, u, x);
				
		//2 - Se determina si se fragmenta o se coalisiona la unidad seleccionada
		
		if(u==1||u==N)  //Si sólo hay una unidad (sólo hay fragmentación) 
		{               //Si quedan sólo las unidades individiales (sólo hay coalisión)
			if(u==1)
				coalision = false;
			if(u==N)
				coalision = true;	
		}
		else //En los demas casos se determinan con la probabilidad "nu"
		{
			for(int i=1;i<=3;i++) { x = rand();}
			y = double(x)/32767;				   //Se crea un número aleatorio para compararlo con "nu".
			//printf ("Numero y: %lf -> ", y);
			if(s[unidad-1]==1){coalision = true;} //Si la unidad seleccionada tiene fuerza 1,
			else								  //entonces se coalisiona.
			{
				if(y>nu){coalision = true;}       //1-nu (y>nu) es la probabilidad de coalision    
				else{coalision = false;}
			}
		}
		
		//Si hay coalisión
		if(coalision == true)
		{
			//3 - Se selecciona otra unidad para la coalisión
			x = 1 + rand()%N;                    //Genera un número entre 1 y N
			unidad2 = seleccionar(s, u, x);
			if(unidad2==unidad)					//Si las unidades seleccionadas son iguales, se busca la siguiente
			{
				if(unidad==u){unidad2=unidad-1;}
				else{unidad2=unidad+1;}
			}
			//Las unidades seleccionadas son siempre diferentes
			
			//4 - Se realiza la coalisión
			//printf ("Se Coalisionan las unidades %d y %d: \n",unidad, unidad2);
			*s = coalisionar(s,N,u,unidad, unidad2);
			u = u - 1;		
		}
		//Si hay fragmentación
		else 
		{
			//5 - Se realiza la fragmentación
			//printf ("Se Fragmenta la unidad %d: \n",unidad);
			sj = s[unidad-1];
			*s = fragmentar(s,u,unidad);
			u = u + sj -1;
			
		}
		//for(int k=0;k<N;k++){printf ("%d ", s[k]);}
		//printf ("\n");
		
		//6 - Cuenta las unidades con determinada cantidad de fuerza
		
		fuerza_max = maximo(s,u);
		//printf("La fuerza mas grande es: %d \n", fuerza_max);
		
		for(int fuerza=1;fuerza<=fuerza_max;fuerza++)
		{
			cantidad = 0;
			for(int k=0;k<u;k++)//Cuenta cuantas unidades tienen fuerza "fuerza"
			{
				if(s[k]==fuerza){cantidad=cantidad+1;}
			}
			if(cantidad>funcion[fuerza-1]) //Guarda las cantidades en auxf
			{
				funcion[fuerza-1]=cantidad;
			}
		}
	}
	printf ("Se realizaron %d iteraciones.\nEl tama\xA4o del ejercito es %d.\n\n",Num_iteraciones,N);
	
	//7 - Guardar Datos en un archivo.
	ofstream fs("Datos.txt");	  //Crea un archivo en donde se van a guardar los datos
	double F;				 	  //Log de la fuerza (F)
	double T;                 	  //Log del número de unidades con fuerza F
	
	printf("Se muestran los primeros 15 valores.\n");
	printf("log(Fuerza)\t\tlog(Num. de Unidades)\n");
	for(int fuerza=1;fuerza<=N;fuerza++)
	{
		if(funcion[fuerza-1]!=0)	//Se guardan sólo los datos distintos de 0
		{
			F = log10((double(fuerza)));
			T = log10(double(funcion[fuerza-1]));
			if(fuerza<=15){printf("%lf\t\t%lf\n",F,T);} //Imprime únicamente los primeros 15 valores para comparar.
			fs <<""<<F<<"\t"<<T<<endl;
		}
	}
		
	fs.close();
	return 0;
}
