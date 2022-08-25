#include <iostream>
#include <string>           

using namespace std;

int main()
{
	int Piramide;
	
	while(true)
	{
		cout << "Informe o tamanho da Piramide , apenas Numeros IMPARES: ";
	
		cin >> Piramide;
		
		if(Piramide % 2 == 0)
		{
			cout << "\nNumero par fornecido! , tente novamente\n\n";
		}
		
		else
		{
			break;
		}
	}
	
	int Auxiliar = Piramide , Contador = 0;
	
	string Ajuste = "";
	
	cout << "\n";
	
	while(Auxiliar > 0)
	{
		cout << Ajuste;
		
		for(int i = 1 + Contador ; i < Piramide + 1 - Contador ; i++)
		{
			cout << i  << " ";
		}
		
		cout << endl;
		
		Auxiliar = Auxiliar - 2;
		
		Contador = Contador + 1;
		
		Ajuste = Ajuste + "  ";
	}
	
	return 0;
}
