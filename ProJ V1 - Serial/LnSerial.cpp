#include <iostream>

using namespace std;

double Fatorial(int Num)
{
    double Fat = 1;
    
    for(double i = Num ; i > 0 ; i--)
    {
        Fat = Fat * i;
    }
    
    return Fat;
}

int main()
{
    double Soma = 1;
    
    int Iteracoes = 10000;
    
    for(double i = 1 ; i < Iteracoes + 1 ; i++)
    {
        Soma = Soma + (1/Fatorial(i));
    }
    
    cout << Soma;
    
    return 0;
}
