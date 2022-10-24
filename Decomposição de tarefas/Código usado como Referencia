#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

double Soma = 0;

int Iteracoes = 1000000 , thread_count = 2;

double Fatorial(int Num)
{
    double Fat = 1;
    
    for(double i = Num ; i > 0 ; i--)
    {
        Fat = Fat * i;
    }
    
    return Fat;
}

void *Thread_Soma(void* rank)
{
    long my_rank = (long) rank;
	
	long long i;
	
	for(i = my_rank ; i < Iteracoes + 1 ; i = i + 2)
    {
        Soma = Soma + (1/Fatorial(i));
    }
	
	
	return NULL;
}

int main()
{
    pthread_t thread_handles[thread_count];
    
	for (pthread_t thread = 0 ; thread < thread_count ; thread++)
	{
	    pthread_create(&thread_handles[thread] , NULL , Thread_Soma , (void*) thread);
	}
	
	for (pthread_t thread = 0 ; thread < thread_count ; thread++)
	{
	    pthread_join(thread_handles[thread] , NULL);
	}
    
    cout.precision(16);
    
    cout << Soma;
    
    return 0;
}
