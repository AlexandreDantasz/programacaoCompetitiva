#include <iostream>
#include <queue>
#include <vector>
#define f first
#define s second

using namespace std;

vector <int> dist(1001, -1);

void eraseThat(int size)
{
    for(int i = 0; i < size; i++)
    {
        dist[i] = -1;
    }
}

void bfs(int start, vector <int> adj_list[])
{
    queue <int> kiwi;
    dist[start] = 0;
    kiwi.push(start);
    while(!kiwi.empty())
    {
		int u = kiwi.front();
		kiwi.pop();
		for(int i = 0; i < adj_list[u].size(); i++)
		{
			int v = adj_list[u][i];
			if(dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				kiwi.push(v);
			}
		}
    }
}

int main()
{
    int cases;
    scanf("%i", &cases);
    for(int i = 0; i < cases; i++)
    {
        vector <int> adj_list[1001];
        if(i > 0) printf("\n");
        int p, d;
        scanf("%i %i", &p, &d);
        for(int j = 0; j < d; j++)
        {
            int x, y;
            scanf("%i %i", &x, &y);
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        bfs(0, adj_list);
        for(int j = 1; j < p; j++)
        {
            printf("%i\n", dist[j]);
        }
        eraseThat(p);
    }
}
