#include <iostream>

using namespace std;

int main()
{
	char t;
	int contp=0;
	while(scanf("%c",&t)!=EOF)
	{
		if(t=='p'||t=='P')
		{
			contp++;
		}
		else
		{
			printf("%c",t);
			if(contp!=0)
			{
				contp--;
			}
		}
		if(contp>1)
		{
			printf("%c",t);
			contp=0;
		}
	}
}
