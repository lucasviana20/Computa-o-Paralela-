#include <gmp.h>
#include <iostream>
#include <assert.h>

class GrandesNumeros
{
    public:
    
        mpf_t m_Numero;
};

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
    //FILE* Arquivo;

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
    
    //Arquivo = fopen("Euler.txt", "w");
    //mpf_out_str(Arquivo, 10, 0, Soma.m_Numero);
    //fclose(Arquivo);
    
    return 0;
}
