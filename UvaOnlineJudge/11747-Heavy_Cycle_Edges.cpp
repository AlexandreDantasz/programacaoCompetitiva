#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second

using namespace std;

struct Mst
{
	int *father;
	Mst(int n)
	{
		father = new int[n];
		for(int i = 0; i < n; i++) father[i] = i;
	}
	int find(int x)
	{
		if(father[x] == x) return x;
		return father[x] = find(father[x]);
	}
	void makeUnion(int x, int y)
	{
		int x1 = find(x), y2 = find(y);
		father[x1] = y2;
	}
	~Mst()
	{
		delete []father;
	}
};

class Graph
{
	private:
		vector <pair <int, pair <int, int>>> adjList;
		vector <int> edges;
		int nodes;
	public:
		Graph(int n)
		{
			nodes = n;
		}
		void addEdge(int weight, int x, int y)
		{
			adjList.push_back({weight, {x, y}});
		}
		int kruskal()
		{
			int answer = 0, si = adjList.size();
			//answer == 0 significa que não forma ciclo
			//answer == 1 significa que forma ciclo
			sort(adjList.begin(), adjList.end());
			Mst tree(nodes);
			for(int i = 0; i < si; i++)
			{
				int x = adjList[i].s.f;
				int y = adjList[i].s.s;
				if(tree.find(x) != tree.find(y))
				{//não forma ciclo
					tree.makeUnion(x, y);
				}
				else
				{//forma ciclo
					answer = 1;
					int maior = -1;
					for(int j = 0; j < si; j++)
					{//busca os vértices na lista de adjacência
						if((x == adjList[i].s.f and tree.find(x) == tree.find(adjList[i].s.s)) or (x == adjList[i].s.s and tree.find(x) == tree.find(adjList[i].s.f)))
						{//achou uma aresta que está dentro do ciclo
							if(adjList[i].f >= maior) maior = adjList[i].f;
						}
					}
					edges.push_back(maior);
				}
			}
			return answer;
		}
		void listEdge()
		{
			int s = edges.size();
			for(int i = 0; i < s; i++)
			{
				if(i) cout << ' ';
				cout << edges[i];
			}
			cout << endl;
		}
		void clear()
		{
			edges.clear();
			adjList.clear();
		}
};

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;
	while(nodes != 0 or edges != 0)
	{
		Graph G(nodes);
		for(int i = 0; i < edges; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			G.addEdge(w, x, y);
		}
		if(G.kruskal()) G.listEdge();
		else puts("forest");
		G.clear();
		cin >> nodes >> edges;
	}
	return 0;
}
