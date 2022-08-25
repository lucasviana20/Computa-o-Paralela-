#include <iostream>      
#include <stdlib.h>     
#include <time.h>

using namespace std;

int main()
{
	int TamanhoMatriz = 3 , Numero_Sorteado = 0 , Matriz[TamanhoMatriz][TamanhoMatriz] , Menor = 101;
	
	srand (time(NULL));
	
	for(int i = 0 ; i < TamanhoMatriz ; i++)
	{
		for(int j = 0 ; j < TamanhoMatriz ; j++)
		{
			Numero_Sorteado = rand() % 100 + 1;
			
			Matriz[i][j] = Numero_Sorteado;
		}
	}
	
	for(int i = 0 ; i < TamanhoMatriz ; i++)
	{
		for(int j = 0 ; j < TamanhoMatriz ; j++)
		{
			cout << Matriz[i][j] << " ";
			
			if(Matriz[i][j] < Menor)
			{
				Menor = Matriz[i][j];
				
				Numero_Sorteado = i;
			}
		}
		
		cout << "\n";
	}
	
	cout << "Menor Valor: " << Menor << " Encontrado na Linha: " << Numero_Sorteado;
	
	return 0;
}
