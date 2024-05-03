#include <bits/stdc++.h>

using namespace std;

map <string, vector <string>> adj_list;
map <string, bool> vis;
map <string, string> path_map;

void make_false()
{
	map <string, vector <string>> :: iterator it;
	for(it = adj_list.begin(); it != adj_list.end(); it++)
	{
		vis[it->first] = false;
	}
}

void bfs(string start, string end)
{
	make_false();
	queue <string> kiwi;
	kiwi.push(start);
	vis[start] = true;
	while(!kiwi.empty())
	{
		string u = kiwi.front();
		kiwi.pop();
		if(u == end) break;
		for(int i = 0; i < adj_list[u].size(); i++)
		{
			string v = adj_list[u][i];
			if(!vis[v])
			{
				vis[v] = true;
				kiwi.push(v);
				path_map[v] = u;
			}
		}
	}
}

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		if(i > 0) printf("\n");
		int m, n;
		cin >> m >> n;
		for(int j = 0; j < m; j++)
		{
			string x, y;
			cin >> x >> y;
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}
		for(int j = 0; j < n; j++)
		{
			string start, end;
			cin >> start >> end;
			bfs(start, end);
			string x = end;
			vector <char> path;
			while(x != start)
			{
				path.push_back(x[0]);
				x = path_map[x];
			}
			path.push_back(x[0]);
			reverse(path.begin(), path.end());
			for(int k = 0; k < path.size(); k++)
			{
				printf("%c", path[k]);
			}
			printf("\n");
		}
		adj_list.clear();
	}
}
