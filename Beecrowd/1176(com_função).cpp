#include <iostream>

using namespace std;

long long int fibo(int posi)
{
	long long int calc[posi]={0,1};
	if(posi==0)
	{
		return 0;
	}
	if(posi==1)
	{
		return 1;
	}
	for(int i=2;i<=posi;i++)
	{
		calc[i]=calc[i-1]+calc[i-2];
	}
	return calc[posi];
}
int main()
{
	int n,posi;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>posi;
		cout<<"Fib("<<posi<<") = "<<fibo(posi)<<'\n';
	}
}
