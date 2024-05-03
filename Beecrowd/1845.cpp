#include <iostream>

using namespace std;

int main()
{
	char letra,marca='0';
	int contf=0;
	while(scanf("%c",&letra)!=EOF)
	{//leitura por caractere
		if(letra=='s'||letra=='j'||letra=='v'||letra=='b'||letra=='p'||letra=='z'||letra=='x'||letra=='f')
		{//é uma consoante minúscula que deve ser trocada
			if(letra!=marca&&contf!=1)
			{//não há repetições dessa consoante
				printf("f");
				marca=letra;
				contf++;
			}
		}
		else
		{//é uma consoante maiúscula que deve ser trocada ou é outra letra
			if(letra=='S'||letra=='J'||letra=='V'||letra=='B'||letra=='P'||letra=='Z'||letra=='X'||letra=='F')
			{//é uma consoante maiúscula que deve ser trocada
				if(letra!=marca&&contf!=1)
				{//não há repetições dessa consoante
					printf("F");
					marca=letra;
					contf++;
				}
			}
			else
			{//é uma letra qualquer
				printf("%c",letra);
				marca='0';
				contf=0;
			}
		}
	}
}
