#include <iostream>
#define f first
#define s second
#define ii pair <int, int>

using namespace std;

char map[101][101];
ii xy[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n;

bool isValid(ii x)
{
	if(x.f >= 0 and x.s >= 0 and x.f < n  and x.s < n) return true;
	return false;
}

void floodfill(ii x)
{
	map[x.f][x.s] = 'v';
	for(int i = 0; i < 4; i++)
	{
		ii y = {x.f + xy[i].f, x.s + xy[i].s};
		if(isValid(y) and (map[y.f][y.s] == 'x' or map[y.f][y.s] == '@'))
		{
			floodfill(y);
		}
	}
}

int main()
{
	int t;
	scanf("%i", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%i", &n);
		cin.ignore();
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				char x;
				x = getchar();
				map[j][k] = x;
			}
			cin.ignore();
		}
		int counter = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(map[j][k] == 'x')
				{
					ii x = {j, k};
					counter++;
					floodfill(x);
				}
			}
		}
		printf("Case %i: %i\n", i + 1, counter);
	}
}
