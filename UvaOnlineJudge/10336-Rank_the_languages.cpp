#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define ip pair <int, ii>
#define ic pair <int, char>
#define vii vector <ii>
#define vic vector <ic>
#define vip vector <ip>
#define vs vector <string>
#define msvs map <string, vs>
#define f first
#define s second

using namespace std;

int rows, columns;
char mat[1000][1000];
ii xy[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValid(ii x)
{
	if(x.f >= 0 and x.f < rows and x.s >= 0 and x.s < columns) return true;
	return false;
}

void flood_fill(char letter, int r, int c)
{
	mat[r][c] = '1';
	for(int i = 0; i < 4; i++)
	{
		ii coord = {r + xy[i].f, c + xy[i].second};
		if(isValid(coord) and mat[coord.f][coord.s]== letter) flood_fill(letter, coord.f, coord.s);
	}
}

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		vic ord;
		set <char> to_search;
		set <char>:: iterator it;
		cin >> rows >> columns;
		for(int j = 0; j < rows; j++)
		{
			for(int k = 0; k < columns; k++) 
			{
				cin >> mat[j][k];
				to_search.insert(mat[j][k]);
			}
		}
		for(it = to_search.begin(); it != to_search.end(); it++)
		{
			int cont = 0;
			for(int j = 0; j < rows; j++)
			{
				for(int k = 0; k < columns; k++) 
				{
					if(mat[j][k] == *it)
					{
						flood_fill(*it, j, k);
						cont++;
					}
				}
			}
			ord.push_back({cont, *it});
		}
		printf("World #%i\n", i + 1);
		for(int j = 0; j < to_search.size(); j++)
		{
			int aux;
			char aux_letter;
			for(int k = j + 1; k < to_search.size(); k++)
			{
				if(ord[j].f < ord[k].f)
				{
					aux = ord[j].f;
					aux_letter = ord[j].s;
					ord[j].f = ord[k].f;
					ord[k].f = aux;
					ord[j].s = ord[k].s;
					ord[k].s = aux_letter;
				}
				else
				{
					if(ord[j].f == ord[k].f)
					{
						if(ord[j].s > ord[k].s)
						{
							aux_letter = ord[j].s;
							ord[j].s = ord[k].s;
							ord[k].s = aux_letter;
						}
					}
				}
			}
		}
		for(int j = 0; j < to_search.size(); j++)
		{
			printf("%c: %i\n", ord[j].s, ord[j].f);
		}
	}
	return 0;
}
