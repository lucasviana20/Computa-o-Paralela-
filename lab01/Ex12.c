#include <iostream>
#include <string>      

using namespace std;

int main()
{
	char Mensagem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" , Caracter;
	
	bool Encontrado = false;
	
	cout << "Informe uma letra do Alfabeto: ";
	
	cin >> Caracter;
	
	Caracter = toupper(Caracter);
	
	for(int i = 0 ; i < sizeof(Mensagem) ; i++)
	{
		if(Mensagem[i] == Caracter)
		{
			cout << "Caracter Encontrado na posicao: " << i << endl;
			
			Encontrado = true;
		}
	}
	
	if(!Encontrado)
	{
		cout << "Caracter nao Encontrado";
	}
	
	return 0;
}
