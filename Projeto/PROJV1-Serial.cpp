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
    double Soma = 0;
    
    int Iteracoes = 1000000;
    
    cout.precision(16);
    
    for(double i = 0 ; i < Iteracoes + 1 ; i++)
    {
        Soma = Soma + (1/Fatorial(i));
    }
    
    cout << fixed << Soma << endl;
    
    return 0;
}
