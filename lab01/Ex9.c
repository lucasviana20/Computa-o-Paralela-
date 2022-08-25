#include <iostream> 

using namespace std;

void Substituir(int Matriz[2][2])
{
	int Modulo = (Matriz[0][0] * Matriz[1][1]) - (Matriz[0][1] * Matriz[1][0]);
	
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			if(Matriz[i][j] < 0)
			{
				Matriz[i][j] = Modulo;
			}
		}
	}
}

void PrintMatriz(int Matriz[2][2])
{
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			cout << Matriz[i][j] << " ";
		}
		
		cout << "\n";
	}
}

int main()
{
	int Matriz[2][2] = {{-2,1} , {3,-4}};
	
	cout << "Matriz: " << endl;
	
	PrintMatriz(Matriz);
	
	Substituir(Matriz);
	
	cout << "Matriz depois de trocar os negativos pelo modulo: " << endl;
	
	PrintMatriz(Matriz);
	
	return 0;
}
