#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define vii vector <ii>

using namespace std;

vii adj_list[20011];
set <int> to_erase;
set <int> ::iterator it;
int dist[20010];

int dijkstra(int s, int e, int edges)
{
	for(int i = 0; i < edges; i++) dist[i] = inf;
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
	int c;
	cin >> c;
	for(int i = 0; i < c; i++)
	{
		int n, m, s, t, x, y, z;
		cin >> n >> m >> s >> t;
		dist[t] = inf;
		for(int j = 0; j < m; j++)
		{
			cin >> x >> y >> z;
			adj_list[x].push_back({y, z});
			adj_list[y].push_back({x, z});
			to_erase.insert(x);
			to_erase.insert(y);
		}
		if(m == 0)
		{
			printf("Case #%i: unreachable\n", i + 1);
		}
		else
		{
			int x = dijkstra(s, t, n);
			if(dist[t] == inf)
			{
				printf("Case #%i: unreachable\n", i + 1);
			}
			else
			{
				printf("Case #%i: %i\n", i + 1, x);
			}
			while(!to_erase.empty())
			{
				it = to_erase.begin();
				adj_list[*it].clear();
				to_erase.erase(*it);
			}
		}
	}
	return 0;
}
