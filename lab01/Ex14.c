#include <iostream>
#include <string>      

using namespace std;

char AdicionarCaracter(char String[100] , int Posicao , char Adicionar)
{
	String[101];
	
	for(int i = 100 ; i > Posicao - 1 ; i--)
	{
		if(i == Posicao)
		{
			String[i] = Adicionar;
		}
		
		else
		{
			String[i] = String[i - 1];
		}
	}
}

int main()
{
	int Posicao;
	
	char Mensagem[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!”#$%&’()*+,-./0123456789:<;=>?@[]^_{`|}~abcdef" , Adicionar;
	
	cout << "Mensagem: \n" << Mensagem << "\n\nQual a posicao que vamos adicionar?(0-99): ";
	
	cin >> Posicao;
	
	cout << "\nQual caracter vamos adicionar na mensagem: ";
	
	cin >> Adicionar;
	
	AdicionarCaracter(Mensagem , Posicao , Adicionar);
	
	cout << "\nMensagem Atualizada: \n" << Mensagem;
	
	return 0;
}
