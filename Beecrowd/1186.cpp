#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long double mat[12][12],soma=0;
	int cont=0;
	char op;
	cin>>op;
	cout<<fixed<<setprecision(1);
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			cin>>mat[i][j];
		}
	}
	for(int k=1;k<12;k++)
	{
		for(int l=12-k;l<12;l++)
		{
			soma+=mat[k][l];
			cont++;
		}
	}
	if(op=='S')
	{
		cout<<soma<<endl;
	}
	else
	{
		cout<<soma/cont<<endl;
	}
}
