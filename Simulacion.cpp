#include <iostream>
#include <cstdio>


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

int main(void)
{
	int N = 100;                   
	double nu = 0.01;              
	int Num_iteraciones =1000;     
		
	
	int s[N];					   
	s[0] = N;					   
	for(int i=1;i<N;i++){s[i]=0;}  
	return 0;
}
