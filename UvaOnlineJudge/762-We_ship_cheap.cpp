#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define ip pair <int, ii>
#define ic pair <int, char>
#define vi vector <int>
#define vii vector <ii>
#define vic vector <ic>
#define vip vector <ip>
#define vs vector <string>
#define mss map <string, string>
#define msi map <string, int>
#define msvs map <string, vs>
#define msvi map <string, vi>
#define msvii map <string, vii>
#define f first
#define s second

using namespace std;

msvs adj_list;
msi dist;
mss path;

void default_dist()
{
	msvs :: iterator it;
	for(it = adj_list.begin(); it != adj_list.end(); it++)
	{
		dist[it->first] = -1;
	}
}

int bfs(string start, string end)
{
	queue <string> kiwi;
	default_dist();
	kiwi.push(start);
	dist[start] = 0;
	path[start] = "-1";
	while(!kiwi.empty())
	{
		string u = kiwi.front();
		kiwi.pop();
		if(u == end) return 0;
		int size = adj_list[u].size();
		for(int i = 0; i < size; i++)
		{
			string v = adj_list[u][i];
			if(dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				path[v] = u;
				kiwi.push(v);
			}
		}
	}
	path.clear();
	return -1;
}

int main()
{
	int n;
	bool v = false;
	string x, y;
	while(cin >> n)
	{
		if(v) cout << '\n';
		v = true;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}
		cin >> x >> y;
		if(bfs(x, y) == 0)
		{
			vs the_final_path;
			string search = y;
			while(search != "-1")
			{
				the_final_path.push_back(search);
				search = path[search];
			}
			reverse(the_final_path.begin(), the_final_path.end());
			for(int i = 0; i < the_final_path.size() - 1; i++)
			{
				cout << the_final_path[i] << ' ' << the_final_path[i + 1] << '\n';
			}
		}
		else
		{
			puts("No route");
		}
		adj_list.clear();
		path.clear();
		dist.clear();
	}
	return 0;
}
