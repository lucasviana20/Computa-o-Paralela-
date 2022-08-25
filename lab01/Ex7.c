#include <iostream>
#include <string>      

using namespace std;

typedef struct 
{
    float Peso;
	   
    int Idade;
	    
    float Altura; 
    
} Pessoa; 

Pessoa AlocaInformacoes(string Nome , Pessoa Individuo)
{
	cout << "\nQual a idade de " << Nome << "? ";
	
	cin >> Individuo.Idade;
	
	cout << "\nQual o Peso de " << Nome << "? ";
	
	cin >> Individuo.Peso;
	
	cout << "\nQual a Altura de " << Nome << "? ";
	
	cin >> Individuo.Altura;
	
	return Individuo;
}

void PrintaInformacoes(string Nome , Pessoa Individuo)
{
	cout << "\n" << Nome << "\n\nIdade: " << Individuo.Idade << "\nPeso: " << Individuo.Peso << "\nAltura: " << Individuo.Altura << endl;
}


int main()
{
	string ListaPessoas[3];
	
	Pessoa Pessoa1 , Pessoa2 , Pessoa3;
	
	for(int i = 0 ; i < 3 ; i++)
	{
		cout << "\nInforme o Nome da " << i + 1 << " Pessoa: ";
		
		cin >> ListaPessoas[i];
	}
	
	Pessoa1 = AlocaInformacoes(ListaPessoas[0] , Pessoa1);
	
	Pessoa2 = AlocaInformacoes(ListaPessoas[1] , Pessoa2);
	
	Pessoa3 = AlocaInformacoes(ListaPessoas[2] , Pessoa3);
	
	PrintaInformacoes(ListaPessoas[0] , Pessoa1);
	
	PrintaInformacoes(ListaPessoas[1] , Pessoa2);
	
	PrintaInformacoes(ListaPessoas[2] , Pessoa3);
	
	return 0;
}
