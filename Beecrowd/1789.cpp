#include <iostream>

using namespace std;
int velo (int maior)
{
	if(maior<10)
	{
		maior=1;
	}
	else
	{
		if(maior>=10&&maior<20)
		{
			maior=2;
		}
		else
		{
			if(maior>=20)
			{
				maior=3;
			}
		}
	}
	return maior;
}
int main()
{
	int n,vel,maior;
	while(cin>>n)
	{
		maior=0;
		for(int i=0;i<n;i++)
		{
			cin>>vel;
			if(vel>maior)
			{
				maior=vel;
			}
		}
		cout<<velo(maior)<<'\n';
	}
}
