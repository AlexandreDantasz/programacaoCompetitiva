#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#define ii pair <int, int>
#define f first
#define s second

using namespace std;

class Mst
{
	private:
		int *father;
	public:
		Mst(int n)
		{
			father = new int[n];
			for(int i = 1; i <= n; i++) father[i] = i;
		}
		int find(int x)
		{
			if(father[x] == x) return x;
			return find(father[x]);
		}
		void makeUnion(int x, int y)
		{
			int x1 = find(x);
			int y1 = find(y);
			father[x1] = y1;
		}
		~Mst()
		{
			delete[] father;
		}
};

class Graph
{
	private:
		int nodes;
		vector <pair <int, ii>> adjList;
	public:
		Graph(int n)
		{
			nodes = n;
		}
		void addEdge(int x, int y, int z)
		{
			adjList.push_back({z, {x, y}});
		}
		int kruskal()
		{
			sort(adjList.begin(), adjList.end());
			Mst tree(nodes);
			int answer = 0, s = adjList.size();
			for(int i = 0; i < s; i++)
			{
				int z = adjList[i].f;
				int x = adjList[i].s.f;
				int y = adjList[i].s.s;
				if(tree.find(x) != tree.find(y))
				{
					tree.makeUnion(x, y);
					answer += z;
				}
			}
			return answer;
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int nodes;
	bool ver = false;
	while(cin >> nodes)
	{
		if(ver) cout << endl;
		Graph G(nodes);
		for(int i = 0; i < nodes - 1; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			G.addEdge(x, y, w);
		}
		int n;
		cin >> n;
		list <pair <int, ii>> k_new_lines;
		for(int i = 0; i < n; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			k_new_lines.push_back({w, {x, y}});
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			G.addEdge(x, y, w);
		}
		cout << G.kruskal() << endl;
		for(int i = 0; i < n; i++)
		{
			int x = k_new_lines.front().s.f, y = k_new_lines.front().s.s, w = k_new_lines.front().f;
			G.addEdge(x, y, w);
		}
		cout << G.kruskal() << endl;
		k_new_lines.clear();
		ver = true;
	}
}
