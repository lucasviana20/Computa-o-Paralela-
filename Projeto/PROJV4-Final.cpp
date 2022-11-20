#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <gmp.h>
#include <assert.h>

using namespace std;

class GrandesNumeros
{
    public:
	
	int m_Numero;
    
        mpf_t m_Resultado;
};

GrandesNumeros Fatorial(int Num , GrandesNumeros Numero)
{
    GrandesNumeros Auxiliar;
    mpf_init2(Auxiliar.m_Resultado, 256);
    mpf_set_str(Auxiliar.m_Resultado, "1", 10);
	
    for(int i = Num ; i > 0 ; i--)
    {
        if(Numero.m_Numero == i)
        {
	    mpf_mul(Auxiliar.m_Resultado, Auxiliar.m_Resultado, Numero.m_Resultado);
            return Auxiliar;
        }
        
        mpf_mul_ui(Auxiliar.m_Resultado, Auxiliar.m_Resultado, i);
    }
    
    return Auxiliar;
}

GrandesNumeros Thread_Soma(int Iteracoes)
{
    GrandesNumeros Numero1;
    GrandesNumeros Numero2;
    GrandesNumeros Numero3;
    GrandesNumeros Soma;
    
    mpf_init2(Numero2.m_Resultado, 256);
    mpf_set_str(Numero2.m_Resultado, "0", 10);
    
    mpf_init2(Soma.m_Resultado, 256);
    mpf_set_str(Soma.m_Resultado, "0", 10);
    
    mpf_init2(Numero3.m_Resultado, 256);
    mpf_set_str(Numero3.m_Resultado, "0", 10);
    Numero3.m_Numero = 0;
    
    int id_thread = omp_get_thread_num() , thread_count = omp_get_num_threads();
	
	for(int i = id_thread ; i < Iteracoes + 1 ; i = i + thread_count)
    {
        Numero1 = Fatorial(i, Numero3);
        Numero3 = Numero1;
        Numero3.m_Numero = i;
        mpf_ui_div(Numero2.m_Resultado, 1, Numero1.m_Resultado);
        mpf_add(Soma.m_Resultado, Soma.m_Resultado, Numero2.m_Resultado);
    }
	
	return Soma;
}

int main(int  argc, char *argv[])
{
	GrandesNumeros Euler;
	mpf_init2(Euler.m_Resultado, 256);
    mpf_set_str(Euler.m_Resultado, "0", 10);
	
	int Iteracoes = atoi(argv[1]);
	
        int thread_count = atoi(argv[2]);
    
    #pragma omp parallel num_threads(thread_count) 
    {
        mpf_add(Euler.m_Resultado, Euler.m_Resultado,Thread_Soma(Iteracoes).m_Resultado);
    }
    
    gmp_printf("e = %.100Ff\n", Euler.m_Resultado);
    
    return 0;
}
