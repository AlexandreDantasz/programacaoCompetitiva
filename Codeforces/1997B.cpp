#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		char map[2][n];

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		int ans = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == '.')
				{
					if (i + 1 < 2 && j + 1 < n && map[i + 1][j + 1] == 'x')
					{	// olhando para o canto inferior direito
						if (i + 1 < 2 && j - 1 >= 0 && map[i + 1][j - 1] == 'x')
						{	// olhando para o canto inferior esquerdo
							if (j + 1 < n && j - 1 >= 0 && map[i][j + 1] == '.' && map[i][j - 1] == '.')
							{	// olhando para a direita e esquerda
								if (i + 1 < 2 && map[i + 1][j] == '.') 
								{	// olhando para baixo
									ans++;
								}
							}
						}
					}
					else
					{
						if (i - 1 >= 0 && j + 1 < n && map[i - 1][j + 1] == 'x')
						{	// olhando para o canto superior direito
							if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == 'x')
							{	// olhando para o canto superior esquerdo
								if (j + 1 < n && j - 1 >= 0 && map[i][j + 1] == '.' && map[i][j - 1] == '.')
								{	// olhando para a direita e para esquerda
									if (i - 1 >= 0 && map[i - 1][j] == '.') 
									{	// olhando para cima
										ans++;
									}
								}
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
