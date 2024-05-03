#include <iostream>

using namespace std;
int impar(int x,int y)
{
	int inicio,limite,soma=0;
	if(x>y)
	{
		limite=x;
		inicio=y;
	}
	else
	{
		limite=y;
		inicio=x;
	}
	for(inicio=inicio+1;inicio<limite;inicio++)
	{
		if(inicio%2!=0)
		{
			soma+=inicio;
		}
	}
	return soma;
}
int main()
{
	int x,y,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		cout<<impar(x,y)<<'\n';
	}
}
