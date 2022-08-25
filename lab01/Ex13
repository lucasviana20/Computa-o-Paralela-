#include <iostream>
#include <string>      

using namespace std;

char Remove(char String[100] , int Posicao)
{
	if(Posicao == 99)
	{
		String[99] = ' ';
	}
	
	else
	{
		for(int i = 0 ; i < 100 ;i++)
		{
			if(i >= Posicao)
			{
				String[i] = String[i + 1];
			}
		}
		
		String[99] = ' ';
	}	
}

int main()
{
	int Posicao;
	
	char Mensagem[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!”#$%&’()*+,-./0123456789:<;=>?@[]^_{`|}~abcdef";
	
	cout << "Mensagem: \n" << Mensagem << "\n\nQual a posicao que vamos excluir?(0-98): ";
	
	cin >> Posicao;
	
	Remove(Mensagem , Posicao);
	
	cout << "\nMensagem Atualizada: \n" << Mensagem;
	
	return 0;
}
