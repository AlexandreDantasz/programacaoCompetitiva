#include <iostream>

using namespace std;

int main()
{
	int col,linM,linL,decM,decL,at;
	while(cin>>col>>linM>>linL)
	{
		int barM[linM][col];
		int barL[linL][col];
		for(int i=0;i<linM;i++)
		{
			for(int j=0;j<col;j++)
			{
				cin>>barM[i][j];
			}
		}
		for(int k=0;k<linL;k++)
		{
			for(int l=0;l<col;l++)
			{
				cin>>barL[k][l];
			}
		}
		cin>>decM>>decL>>at;
		if(barM[decM-1][at-1]>barL[decL-1][at-1])
		{
			cout<<"Marcos\n";
		}
		else
		{
			if(barM[decM-1][at-1]<barL[decL-1][at-1])
			{
				cout<<"Leonardo\n";
			}
			else
			{
				cout<<"Empate\n";
			}
		}
	}
}
