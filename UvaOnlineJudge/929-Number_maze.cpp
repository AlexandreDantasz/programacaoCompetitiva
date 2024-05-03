#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define ip pair <int, ii>
#define vii vector <ii>
#define vip vector <ip>
#define f first
#define s second

using namespace std;

int rows, columns, mat[1000][1000], dist[1000][1000];
ii xy[4] = {{0, 1}, {0, -1}, {-1, 0}, {1,0}};

bool isValid(ip coord)
{
	if(coord.s.f < 0 or coord.s.f >= rows) return false;
	if(coord.s.s < 0 or coord.s.s >= columns) return false;
	return true;
}

int dijkstra()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++) dist[i][j] = inf;
	}
	dist[0][0] = mat[0][0];
	priority_queue <ip, vip, greater <ip>> kiwi;
	kiwi.push({mat[0][0], {0,0}});
	while(!kiwi.empty())
	{
		ip u = kiwi.top();
		kiwi.pop();
		for(int i = 0; i < 4; i++)
		{
			ip v = {u.f, {u.s.f + xy[i].f, u.s.s + xy[i].s}};
			if(isValid(v) and dist[u.s.f][u.s.s] + mat[u.s.f + xy[i].f][u.s.s + xy[i].s] < dist[u.s.f + xy[i].f][u.s.s + xy[i].s])
			{
				dist[u.s.f + xy[i].f][u.s.s + xy[i].s] = dist[u.s.f][u.s.s] + mat[u.s.f + xy[i].f][u.s.s + xy[i].s];
				kiwi.push({dist[u.s.f + xy[i].f][u.s.s + xy[i].s], {u.s.f + xy[i].f, u.s.s + xy[i].s}});
			}
		}
	}
	return dist[rows - 1][columns - 1];
	
}

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		cin >> rows >> columns;
		for(int j = 0; j < rows; j++)
		{
			for(int k = 0; k < columns; k++) cin >> mat[j][k];
		}
		cout << dijkstra() << '\n';
	}
	return 0;
}
