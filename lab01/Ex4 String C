#include<stdio.h>
#include<conio.h>

int main()
{
	char Nome1[99] , Nome2[99];
	
	int Auxiliar = 0;
	
	printf("Informe o Primeiro Nome: ");
	
	scanf("%s",Nome1);
	
	printf("\nAgora informe o Segundo Nome: ");
	
	scanf("%s",Nome2);
	
	while(Auxiliar > -1)
	{ 
		if(Nome1[Auxiliar] == Nome2[Auxiliar])
		{
			Auxiliar = Auxiliar + 1;
		}
		
		else
		{
			if(Nome1[Auxiliar] > Nome2[Auxiliar])
			{
			  	printf("\n%s", Nome2);
			  	
			  	printf("\n%s", Nome1);
			  	
			  	Auxiliar = -1;
			}
			
			else
			{
				printf("\n%s", Nome1);
					
				printf("\n%s", Nome2);
				
				Auxiliar = -1;
			}
		}
	}
	return 0;
}
