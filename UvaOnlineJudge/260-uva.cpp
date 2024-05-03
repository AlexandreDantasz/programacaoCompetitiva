#include <iostream>
#define f first
#define s second

using namespace std;

int n;
pair <int, int> xy[6] = {{-1, -1,}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
char board[201][201];
bool ans = false;

bool isValid(pair <int, int> x)
{
	if(x.f >= 0 and x.f < n and x.s >= 0 and x.s < n) return true;
	return false;
}

void floodfill(pair <int, int> coord)
{
	int i = 0;
	board[coord.f][coord.s] = 'v';
	if(coord.f == n - 1)
	{
		i = 7;
		ans = true;
	}
	for(; i < 6; i++)
	{
		pair <int, int> idk;
		idk = {coord.f + xy[i].f, coord.s + xy[i].s};
		if(isValid(idk) and board[idk.f][idk.s] == 'b')
		{
			floodfill(idk);
		}
	}
}

int main()
{
	int counter = 1;
	scanf("%i", &n);
	while(n != 0)
	{
		cin.ignore();
		ans = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%c", &board[i][j]);
			}
			cin.ignore();
		}
		for(int j = 0; j < n and !ans; j++)
		{
			if(board[0][j] == 'b')
			{
				pair <int, int> black = {0, j};
				floodfill(black);
			}
		}
		if(ans)
		{
			printf("%i B\n", counter);
		}
		else
		{
			printf("%i W\n", counter);
		}
		counter++;
		scanf("%i", &n);
	}
}
