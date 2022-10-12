#include <iostream>

using namespace std;

int main()
{
    double Soma = 0;
    
    int Iteracoes = 1000000000;
    
    for(double i = 1 ; i < Iteracoes + 1 ; i++)
    {
        Soma = Soma + (1/i);
    }
    
    return 0;
}
