#include <iostream> 
#include <string>

using namespace std;

int main()
{
	string Nome1 = "Guilherme" , Nome2 = "Gustavo";
	
	cout << "Informe o Primeiro Nome: ";
	
	cin >> Nome1;
	
	cout << "\nAgora informe o Segundo Nome: ";
	
	cin >> Nome2;
	
	cout << "\nNomes em Ordem Alfabetica: " << endl;
	
	cout << (Nome1 < Nome2 ? Nome1 + "\n" + Nome2 : Nome2 + "\n" + Nome1);
	
	return 0;
}
