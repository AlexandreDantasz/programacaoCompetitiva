#include <bits/stdc++.h>

using namespace std;

int n;

int countCost(string str)
{
	int cost = 0, pt_a = 0, pt_b = 1, wait = 0;

	while (pt_a < n)
	{
		if (str[pt_b] == '(') 
		{
			pt_b++;
			wait++;
		}
		else 
		{
			if (wait) 
			{
				wait--;
				pt_b++;
			}
			else
			{
				cost += abs(pt_a - pt_b);
				pt_a++;
				while (pt_a < n && str[pt_a] == ')') pt_a++;
				pt_b = pt_a + 1;
				wait = 0;
			}
		}
	}

	return cost;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		string str;
		cin >> str;

		str[0] = '(';
		for (int i = 1; i < n - 1; i++)
		{
			if (str[i] == '_')
			{
				if ((str[i - 1] == ')' && str[i + 1] == ')') || (str[i - 1] == ')' && str[i + 1] == '('))
				{	// se chegar aqui, os parênteses devem ser abertos
					str[i] = '(';
				}
				else
				{	// se chegar aqui, os parênteses devem ser fechados
					str[i] = ')';
				}
			}
		}	
		cout << countCost(str) << "\n\n";
	}

	return 0;
}
