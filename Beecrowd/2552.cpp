#include <iostream>

using namespace std;

int main()
{
    int cont=0,n,m;
    while(cin>>n>>m)
    {
        int mat[n][m];
        for(int i=0;i<n;i++)
        {//insere valores na linha
            for(int j=0;j<m;j++)
            {//insere valores na coluna
                cin>>mat[i][j];
            }
        }
        for(int k=0;k<n;k++)
        {//varredura de linhas
            for(int l=0;l<m;l++)
            {//varredura de colunas
				if(mat[k][l]==1)
				{//o número é 1
					cout<<"9";
				}
                else
                {//o número é 0
					if(k!=n-1&&mat[k+1][l]!=0)
					{//abaixo
							cont++;
					}
					if(k!=0&&mat[k-1][l]!=0)
					{//acima
						cont++;
					}
					if(l!=m-1&&mat[k][l+1]!=0)
					{//direita
						cont++;
					}
					if(l!=0&&mat[k][l-1]!=0)
					{//esquerda
						cont++;
					}
					cout<<cont;
					cont=0;
                }
            }
            cout<<'\n';
        }
    }
}
