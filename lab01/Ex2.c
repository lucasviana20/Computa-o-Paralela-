#include <iostream>      

using namespace std;

float Aproveitamento(float N1 , float N2 , float N3 , float ME)
{
    float MA = (N1 + N2*2 + N3*3 + ME)/7;
    
    if(MA >= 9)
    {
        cout << "\nAproveitamento: A";
        
        return MA;
    }
    
    if(MA >= 7.5)
    {
        cout << "\nAproveitamento: B";
        
        return MA;
    }
    
    if(MA >= 6)
    {
        cout << "\nAproveitamento: C";
        
        return MA;
    }
    
    if(MA >= 4)
    {
        cout << "\nAproveitamento: D";
        
        return MA;
    }
    
    if(MA >= 0)
    {
        cout << "\nAproveitamento: E";
        
        return MA;
    }
}

int main()
{
	float Nota1 , Nota2 , Nota3 , MediaExercicios;
	
	cout << "Nota 1: ";
	
	cin >> Nota1;
	
	cout << "\nNota 2: ";
	
	cin >> Nota2;
	
	cout << "\nNota 3: ";
	
	cin >> Nota3;
	
	cout << "\nMedia dos Exercicios: ";
	
	cin >> MediaExercicios;
	
	Aproveitamento(Nota1 , Nota2 , Nota3 , MediaExercicios);
			
	return 0;
}
