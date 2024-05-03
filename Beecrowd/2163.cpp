#include <iostream>

using namespace std;
void matsabre(int lin1,int col1, int *linf,int *colf)
{
	int mat[lin1][col1];
	*linf=0;
	*colf=0;
	for(int i=0;i<lin1;i++)
	{
		for(int j=0;j<col1;j++)
		{
			cin>>mat[i][j];
		}
	}
	for(int k=0;k<lin1;k++)
	{
		for(int l=0;l<col1;l++)
		{
			if(k!=0&&k!=lin1-1&&l!=0&&l!=col1-1&&mat[k][l]==42)
			{
				if(mat[k-1][l]==7&&mat[k-1][l-1]==7&&mat[k-1][l+1]==7)
				{//linhas de cima com 7
					if(mat[k][l-1]==7&&mat[k][l+1]==7)
					{//direita e esquerda com o 7
						if(mat[k+1][l]==7&&mat[k+1][l-1]==7&&mat[k+1][l+1]==7)
						{//linhas de baixo com 7
							*linf=k+1;
							*colf=l+1;
						}
					}
				}
			}
		}
	}
}
int main()
{
	int n,m,linf=0,colf=0;
	cin>>n>>m;
	matsabre(n,m,&linf,&colf);
	cout<<linf<<" "<<colf<<'\n';
}
