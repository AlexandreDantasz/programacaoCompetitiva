#include <iostream>
using namespace std;
void vetor(int *nome, int pos)
{
	nome[pos]=1;
}
int main()
{
	int x[10];
	for(int j=0;j<10;j++)
	{
		cin>>x[j];
	}
	for(int i=0;i<10;i++)
	{
		if(x[i]<=0)
		{
			vetor(x,i);
		}
	}
	for(int k=0;k<10;k++)
	{
		cout<<"X["<<k<<"] = "<<x[k]<<'\n';
	}
}
