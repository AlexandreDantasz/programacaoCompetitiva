#include <iostream>

using namespace std;

int paridade(string wifi)
{
	int tam=wifi.size(),cont1=0;
	for(int i=0;i<tam;i++)
	{//varredura da string
		if(wifi[i]=='1')
		{
			cont1++;
		}
	}
	if(cont1%2==0)
	{//é par
		return 0;
	}
	return 1;
}
int main()
{
	string wifi;
	cin>>wifi;
	cout<<wifi<<paridade(wifi)<<'\n';
}
