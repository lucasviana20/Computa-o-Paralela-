#include <iostream> 

using namespace std;

void SomaLinhas(int Matriz[3][3])
{
	for(int i = 0 ; i < 3 ; i++)
	{
		Matriz[2][i] = Matriz[2][i] + Matriz[1][i];
	}
}

void MultiplicaLinhas(int Matriz[3][3])
{
	for(int i = 0 ; i < 3 ; i++)
	{
		Matriz[2][i] = Matriz[2][i] * Matriz[1][i];
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
	int Matriz[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
	
	cout << "Matriz: " << endl;
	
	PrintMatriz(Matriz);
	
	SomaLinhas(Matriz);
	
	cout << "\nMatriz depois de Somar as Linhas 1 e 2: " << endl;
	
	PrintMatriz(Matriz);
	
	MultiplicaLinhas(Matriz);
	
	cout << "\nMatriz depois de Multiplicar as Linhas 1 e 2: " << endl;
	
	PrintMatriz(Matriz);
	
	return 0;
}
