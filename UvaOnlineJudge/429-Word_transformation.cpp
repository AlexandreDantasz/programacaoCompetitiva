#include <bits/stdc++.h>
#define inf 2147483647
#define ii pair <int, int>
#define ip pair <int, ii>
#define vii vector <ii>
#define vip vector <ip>
#define vs vector <string>
#define msvs map <string, vs>
#define f first
#define s second

using namespace std;

queue <string> dictionary;

int difference(string a, string b)
{
	int cont = 0, size = a.size();
	for(int i = 0; i < size; i++)
	{
		if(a[i] != b[i])
		{
			cont++;
		}
	}
	return cont;
}

int bfs(string start, string end, msvs adj)
{
	queue <string> kiwi;
	map <string, int> dist;
	int cont = dictionary.size();
	for(int i = 0; i < cont; i++)
	{
		dist[dictionary.front()] = inf;
		dictionary.push(dictionary.front());
		dictionary.pop();
	}
	dist[start] = 0;
	kiwi.push(start);
	while(!kiwi.empty())
	{
		string u = kiwi.front();
		kiwi.pop();
		if(u == end) return dist[u];
		int size = adj[u].size();
		for(int i = 0; i < size; i++)
		{
			string v = adj[u][i];
			if(dist[v] == inf)
			{
				dist[v] = dist[u] + 1;
				kiwi.push(v);
			}
		}
	}
	return -1;
}


int main()
{
	int cases;
	string word, start, end;
	cin >> cases;
	cin.ignore();
	for(int i = 0; i < cases; i++)
	{
		if(i > 0) cout << '\n';
		vs treco;
		msvs adj_list;
		cin >> word;
		while(word != "*")
		{
			dictionary.push(word);
			treco.push_back(word);
			cin >> word;
		}
		int size = treco.size();
		for(int j = 0; j < size; j++)
		{
			string a = treco[j];
			for(int k = j + 1; k < size; k++)
			{
				string b = treco[k];
				if(a.size() == b.size())
				{
					if(difference(a, b) <= 1) 
					{
						adj_list[a].push_back(b);
						adj_list[b].push_back(a);
					}
				}
			}
		}
		cin >> start >> end;
		cin.ignore();
		string trem, trem2;
		while(!start.empty())
		{
			int j;
			cout << start << ' ' << end << ' ' << bfs(start, end, adj_list) << '\n';
			start.clear();
			getline(cin, start);
			for(j = 0; j < start.size() and start[j] != ' '; j++)
			{
				trem += start[j];
			}
			for(j = j + 1; j < start.size(); j++)
			{
				trem2 += start[j];
			}
			start = trem;
			end = trem2;
			trem.clear();
			trem2.clear();
		}
		while(!dictionary.empty())
		{
			dictionary.pop();
		}
	}
	return 0;
}
