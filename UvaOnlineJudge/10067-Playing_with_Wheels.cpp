#include <bits/stdc++.h>

using namespace std;

vector <int> ban;

bool isValid(int current)
{
	int size = ban.size(), i;
	for(i = 0; i < size and current != ban[i]; i++);
	if(i < size) return false;
	return true;
}

int bfs(int initial, int end)
{
	queue <int> kiwi;
	vector <long int> dist(100000, -1);
	dist[initial] = 0;
	kiwi.push(initial);
	while(!kiwi.empty())
	{
		int u = kiwi.front();
		kiwi.pop();
		if(u == end) return dist[u];
		int num = u;
		int copy = num, x, i;
		for(i = 0, x = 1; i < 4; i++, x *= 10)
		{
			int alg = copy % 10;
			copy = copy / 10;
			int next = (alg + 10 + 1) % 10;
			int previous = (alg + 10 - 1) % 10;
			int node = (num - alg * x) + next * x;
			if(isValid(node) and dist[node] == -1)
			{
				dist[node] = dist[u] + 1;
				kiwi.push(node);
			}
			node = (num - alg * x) + previous * x;
			if(isValid(node) and dist[node] == -1)
			{
				dist[node] = dist[u] + 1;
				kiwi.push(node);
			}
		}
	}
	return -1;
}


int main()
{
	int cases, n;
	string blank;
	char a;
	cin >> cases;
	cin.ignore();
	for(int i = 0; i < cases; i++)
	{
		int initial = 0, destiny = 0, forbidden = 0;
		for(int j = 0; j < 4; j++)
		{
			cin >> a;
			initial = initial * 10 + (a - 48);
		}
		for(int j = 0; j < 4; j++)
		{
			cin >> a;
			destiny = destiny * 10 + (a - 48);
		}
		if(initial == destiny)
		{
			puts("0"); 
			cin >> n;
			cin.ignore();
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < 4; k++) cin >> a;
			}
			getline(cin, blank);
		}
		else
		{
			cin >> n;
			cin.ignore();
			for(int j = 0; j < n; j++)
			{
				forbidden = 0;
				for(int k = 0; k < 4; k++)
				{
					cin >> a;
					forbidden = forbidden * 10 + (a - 48);
				}
				ban.push_back(forbidden);
			}
			getline(cin, blank);
			cout << bfs(initial, destiny) << "\n";
			ban.clear();
		}
	}
}
