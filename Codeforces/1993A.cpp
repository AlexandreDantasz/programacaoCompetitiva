#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		int vet[4] = {n, n, n, n};
		
		string str;
		cin >> str;

		int ans = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '?')
			{
				if (str[i] == 'A' && vet[0])
				{
					ans++;
					vet[0]--;
				}
				else
				{
					if (str[i] == 'B' && vet[1])
					{
						ans++;
						vet[1]--;
					}
					else
					{
						if (str[i] == 'C' && vet[2])
						{
							ans++;
							vet[2]--;
						}
						else
						{
							if (str[i] == 'D' && vet[3])
							{
								ans++;
								vet[3]--;
							}
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
