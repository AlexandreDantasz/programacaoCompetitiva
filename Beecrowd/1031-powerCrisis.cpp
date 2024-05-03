#include <iostream>

using namespace std;

int main()
{
	bool vet[101];
	int n;
	cin >> n;
	while(n != 0)
	{
		int m = 1, regionsOn = n - 1, i = 0;
		for(int x = 0; x < n; x++) vet[x] = true;
		while(regionsOn > 0)
		{
			vet[i] = false;
			for(int j = 0; j < m; j++)
			{
				i = (i + 1) % n;
				while(!vet[i]) i = (i + 1) % n;
			}
			if(i == 12 and regionsOn > 1)
			{//Wellington is not the last region turned off
				regionsOn = n - 1;
				m++;
				i = 0;
				for(int x = 0; x < n; x++) vet[x] = true;
			}
			else regionsOn--;
		}
		cout << m << endl;
		cin >> n;
	}
}
