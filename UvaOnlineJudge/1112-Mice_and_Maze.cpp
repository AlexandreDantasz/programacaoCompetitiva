#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define vii vector <ii>

using namespace std;

vii adj_list[110];
int dist[110];

int dijkstra(int s, int e, int edges, int t)
{
	for(int i = 0; i <= 109; i++) dist[i] = INT_MAX;
	dist[s] = 0;
	priority_queue <ii, vii, greater <ii>> kiwi;
	kiwi.push({0, s});
	while(!kiwi.empty())
	{
		ii u = kiwi.top();
		kiwi.pop();
		for(int i = 0; i < adj_list[u.second].size(); i++)
		{
			ii v = adj_list[u.second][i];
			if(dist[u.second] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u.second] + v.second;
				kiwi.push({v.second, v.first});
			}
		}
	}
	return dist[e];
}

int main()
{
	string fdse;
	int c, cont = 0;
	cin >> c;
	for(int i = 0; i < c; i++)
	{
	    if(i > 0) cout << endl;
		int n, e, tempo, m, x, y, z;
		cin >> n >> e >> tempo >> m;
		for(int j = 0; j < m; j++)
		{
			cin >> x >> y >> z;
			adj_list[x].push_back({y, z});
		}
		for(int j = 1; j <= n; j++)
		{
			x = dijkstra(j, e, n, tempo);
			if(x <= tempo) cont++;
		}
		for(int j = 0; j <= 100; j++) adj_list[j].clear();
		cout << cont << '\n';
		cont = 0;
	}
	return 0;
}
