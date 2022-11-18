#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

using namespace std;

double Fatorial(int Num , int FatorialSalvo, double ResultadoSalvo)
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
	
    return Fat;
}

double Thread_Soma(int Iteracoes)
{
    double Soma_Local = 0 , Resultado = 0 , Resultado_Fatorial_Salvo = 1;
    
    int id_thread = omp_get_thread_num() , thread_count = omp_get_num_threads() , Fatorial_Salvo = 0;
	
	for(int i = id_thread ; i < Iteracoes + 1 ; i = i + thread_count)
    {
        Resultado = Fatorial(i, Fatorial_Salvo, Resultado_Fatorial_Salvo);
        
        if(i % 3 == 0)
        {
            Fatorial_Salvo = i;
            
            Resultado_Fatorial_Salvo = Resultado;
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
