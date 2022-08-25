#include <iostream> 

using namespace std;

void MatrizTransposta(int Matriz[3][2])
{
	int Auxiliar[2][3];
	
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			Auxiliar[j][i] = Matriz[i][j];
		}
	}
	
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cout << Auxiliar[i][j] << " ";
		}
		
		cout << "\n";
	}
}

int main()
{
	int Matriz[3][2];

	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			cout << "Qual valor a ser colocado na Matriz na posicao [" << i << "][" << j << "]: ";
			
			cin >> Matriz[i][j];
		}
	}
	
	cout << "Matriz: " << endl;
	
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			cout << Matriz[i][j] << " ";
		}
		
		cout << "\n";
	}
	
	cout << "Matriz Transposta: " << endl;
	
	MatrizTransposta(Matriz);
	
	return 0;
}
