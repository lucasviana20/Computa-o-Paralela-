#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

using namespace std;

double ResultadoSalvo = 1;

int FatorialSalvo = 0;

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

double Thread_Soma(int Iteracoes)
{
    double Soma_Local = 0 , Resultado = 0;
    
    int id_thread = omp_get_thread_num();
	
    #pragma omp critical
    cout << "Thread id: " << id_thread;
    
    int thread_count = omp_get_num_threads();
	
	for(int i = id_thread ; i < Iteracoes + 1 ; i = i + thread_count)
    {
        Resultado = Fatorial(i);
        
        if(i % 7 == 0)
        {
            FatorialSalvo = i;
            
            ResultadoSalvo = Resultado;
        }
        
    
        Soma_Local = Soma_Local + (1/Resultado);
    }
	
	return Soma_Local;
}

int main(int  argc, char *argv[])
{
	double Soma = 0;
	
	int Iteracoes = atoi(argv[1]);
	
    int thread_count = atoi(argv[2]);
    
    #pragma omp parallel num_threads(thread_count) reduction(+: Soma)
    {
        Soma = Soma + Thread_Soma(Iteracoes);
    }
    
    cout.precision(16);
    
    cout << Soma;
    
    return 0;
}
