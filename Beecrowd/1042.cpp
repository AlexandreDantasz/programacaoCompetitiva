#include <iostream>

using namespace std;

void cresc(int *a, int *b, int *c)
{
	int aux;
	if(*a>*b&&*a>*c&&*b>*c)
	{
		aux=*a;
		*a=*c;
		*c=aux;
	}
	else
	{
		if(*a>*b&&*a>*c&&*b<*c)
		{
			aux=*a;
			*a=*b;
			*b=*c;
			*c=aux;
		}
		else
		{
			if(*b>*a&&*b>*c&&*a>*c)
			{
				aux=*a;
				*a=*c;
				*c=*b;
				*b=aux;
			}
			else
			{
				if(*b>*a&&*b>*c&&*a<*c)
				{
					aux=*b;
					*b=*c;
					*c=aux;
				}
				else
				{
					if(*c>*a&&*c>*b&&*a>*b)
					{
						aux=*a;
						*a=*b;
						*b=aux;
					}
				}
			}
		}
	}
}
int main()
{
	int a,b,c,p1,p2,p3;
	cin>>a>>b>>c;
	p1=a;
	p2=b;
	p3=c;
	cresc(&a,&b,&c);
	cout<<a<<'\n'<<b<<'\n'<<c<<'\n'<<'\n'<<p1<<'\n'<<p2<<'\n'<<p3<<'\n';
	
}
