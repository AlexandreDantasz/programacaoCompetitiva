#include <bits/stdc++.h>
#define ii pair <int, int>
#define f first
#define s second
#define vi vector <int>

using namespace std;

vi adj_list[2501]; 

int maximum_boom_size(int start, int &days)
{
	if(adj_list[start].size() == 0) return -1;
	int counter, memory = -1, day = 1;
	int size, adj = 0;
	bool vis[2501];
	for(int i = 0; i < 2501; i++) vis[i] = false;
	vis[start] = true;
	queue <int> kiwi;
	kiwi.push(start);
	size = adj_list[start].size();
	counter = size - 1;
	while(!kiwi.empty())
	{
		int u = kiwi.front();
		kiwi.pop();
		counter++;
		for(int i = 0; i < adj_list[u].size(); i++)
		{
			int v = adj_list[u][i];
			if(!vis[v])
			{
				vis[v] = true;
				adj++;
				kiwi.push(v);
			}
		}
		if(size == counter)
		{
			if(adj > memory)
			{
				days = day;
				memory = adj;
			}
			size = adj;
			adj = 0;
			day++;
			counter = 0;
		}
	}
	return memory;
}

int main()
{
	int e;
	cin >> e;
	for(int i = 0; i < e; i++)
	{
		int n;
		cin >> n;
		for(int j = 0; j < n; j++)
		{
			int f;
			cin >> f;
			adj_list[i].push_back(f);
		}
	} 
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int start;
		cin >> start;
		int ans_day;
		int ans = maximum_boom_size(start, ans_day);
		if(ans == -1) 
		{
			puts("0");
		}
		else
		{
			printf("%i %i\n", ans, ans_day);
		}
	}
	return 0;
}
