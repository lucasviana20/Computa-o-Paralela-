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


GrandesNumeros Fatorial(int Num)
{
    GrandesNumeros Numero;
    mpf_init2(Numero.m_Numero, 256);
    mpf_set_str(Numero.m_Numero, "1", 10);
    
    for(int i = 1 ; i < Num + 1 ; i++)
    {
        mpf_mul_ui(Numero.m_Numero, Numero.m_Numero, i);
    }
    
    return Numero;
}

int main()
{
    GrandesNumeros Numero1;
    GrandesNumeros Numero2;
    GrandesNumeros Soma;
    
    mpf_init2(Numero2.m_Numero, 256);
    mpf_set_str(Numero2.m_Numero, "0", 10);
    
    mpf_init2(Soma.m_Numero, 256);
    mpf_set_str(Soma.m_Numero, "0", 10);
    
  
    for(int i = 0 ; i < 1000 + 1 ; i++)
    {
        Numero1 = Fatorial(i);
        mpf_ui_div(Numero2.m_Numero, 1, Numero1.m_Numero);
        mpf_add(Soma.m_Numero, Soma.m_Numero, Numero2.m_Numero);
    }
    
    gmp_printf("e= %.75Ff\n", Soma.m_Numero);
    
    return 0;
}
