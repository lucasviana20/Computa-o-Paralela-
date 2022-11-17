#include <iostream>

using namespace std;

long double Fatorial(int Num)
{
    long double Fat = 1;
    
    for(long double i = Num ; i > 0 ; i--)
    {
        Fat = Fat * i;
    }
    
    return Fat;
}

int main()
{
    long double Soma = 0;
    
    int Iteracoes = 100000;
    
    cout.precision(20);
    
    for(long double i = 0 ; i < Iteracoes + 1 ; i++)
    {
        Soma = Soma + (1/Fatorial(i));
    }
    
    cout << fixed << Soma << endl;
    
    return 0;
}
