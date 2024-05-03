#include <iostream>

using namespace std;

int pares(int x,int y)
{
	if(x<=y)
	{
		if(x%2==0)
		{
			cout<<x<<'\n';
			return pares(x+2,y);
		} 
		return pares(x+1,y);
	}
	return 0;
}
int main()
{
	pares(1,100);
}
