#include <iostream> 

using namespace std;

void MultiplicarLinha(int Matriz[3][3] , int Valor , int Linha)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		Matriz[Linha][i] = Matriz[Linha][i] * Valor;
	}
}

void MultiplicarColuna(int Matriz[3][3] , int Valor , int Coluna)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		Matriz[i][Coluna] = Matriz[i][Coluna] * Valor;
	}
}

void PrintMatriz(int Matriz[3][3])
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cout << Matriz[i][j] << " ";
		}
		
		cout << "\n";
	}
}

int main()
{
	int Matriz[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}} , Linha = 0 , Coluna = 2 , Valor = 10;
	
	cout << "Matriz antes das operacoes: " << endl;
	
	PrintMatriz(Matriz);
	
	MultiplicarLinha(Matriz , Valor , Linha);
	
	cout << "Matriz depois de multiplicar a linha 0 por 10: " << endl;
	
	PrintMatriz(Matriz);
	
	MultiplicarColuna(Matriz , Valor , Coluna);
	
	cout << "Matriz depois de multiplicar a coluna 2 por 10: " << endl;
	
	PrintMatriz(Matriz);
	
	return 0;
}
