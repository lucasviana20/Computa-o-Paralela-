#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

using namespace std;

double Soma = 0 , ResultadoSalvo = 1;

int Iteracoes = 100 , thread_count = 2 , FatorialSalvo = 0;

double Fatorial(int Num)
{
    double Fat = 1;
    
    for(double i = Num ; i > 0 ; i--)
    {
        if(FatorialSalvo == i)
        {
            return Fat * ResultadoSalvo;
        }
        
        Fat = Fat * i;
    }
    
    //cout << "Escapou! " << Num << endl;
    return Fat;
}

void *Thread_Soma(void *rank)
{
    double Resultado = 0;
    
    long my_rank = (long) rank;
	
	long long i;
	
	for(i = my_rank ; i < Iteracoes + 1 ; i = i + thread_count)
    {
        Resultado = Fatorial(i);
        
        if(i % 7 == 0)
        {
            FatorialSalvo = i;
            
            ResultadoSalvo = Resultado;
        }
        
        #pragma omp critical
        Soma = Soma + (1/Resultado);
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
