#include <gmp.h>
#include <stdio.h>
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
    mpf_t r;
    mpf_init2 (r, 256);
    mpf_set_str(r, "0.1111111111111111111111111111111111111111", 10); 
    mpf_add(r,r,r);
    mpf_add(r,r,r);
    mpf_add_ui(r,r,1); 
    
    GrandesNumeros Numero1;
    
    //printf (" r = ");
    //gmp_printf("%.40Ff\n", r);
    //printf ("\n");
  
    for(int i = 1 ; i < 200 ; i++)
    {
        Numero1 = Fatorial(i);
        gmp_printf("r(%d)= %.0Ff\n", i, Numero1.m_Numero);
    }
    
    return 0;
}
