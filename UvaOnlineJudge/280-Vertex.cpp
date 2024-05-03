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
#define msvs map <string, vs>
#define f first
#define s second

using namespace std;

int vertices;
vi adj_list[110];
bool visited[110];
queue <int> inaccessible_vertex;
set <int> memory;
set <int> :: iterator it;

void make_false()
{
	for(int i = 0; i <= vertices; i++) visited[i] = false;
}
 
int count_false()
{
	int counter = 0;
	for(int i = 1; i <= vertices; i++)
	{
		if(visited[i] == false)
		{
			counter++;
			inaccessible_vertex.push(i);
		}
	}
	return counter;
} 

void dfs(int start)
{
	for(auto i : adj_list[start])
	{
		if(!visited[i]) 
		{
			visited[i] = true;
			dfs(i);
		}
	}
}

void to_erase()
{
	for(it = memory.begin(); it != memory.end(); it++)
	{
		adj_list[*it].clear();
	}
	memory.clear();
}

int main()
{
	cin >> vertices;
	while(vertices != 0)
	{
		make_false();
		int id, adj;
		cin >> id;
		while(id != 0)
		{
			memory.insert(id);
			cin >> adj;
			while(adj != 0)
			{
				adj_list[id].push_back(adj);
				cin >> adj;
			}
			cin >> id;
		}
		int qt_start;
		cin >> qt_start;
		for(int j = 0; j < qt_start; j++)
		{
			int start;
			cin >> start;
			make_false();
			dfs(start);
			cout << count_false();
			while(!inaccessible_vertex.empty())
			{
				cout << ' ' << inaccessible_vertex.front();
				inaccessible_vertex.pop();
			}
			cout << '\n';
		}
		to_erase();
		cin >> vertices;
	}
	return 0;
}
