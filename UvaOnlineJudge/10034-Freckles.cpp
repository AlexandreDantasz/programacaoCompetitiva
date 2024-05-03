#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define f first
#define s second

using namespace std;

class Graph
{
	private:
		vector <pair <double, pair <double, pair <double, pair <double, double>>>>> adj_list;
		map <pair <double, double>, pair <double, double>> father;
	public:
		void makeFather(double x, double y)
		{
			father[{x, y}] = {x, y};
		}
		void addEdge(double weight, pair <double, double> x, pair <double, double> y)
		{
			adj_list.push_back({weight, {x.f, {x.s, {y.f, y.s}}}});
		}
		pair <double, double> find(pair <double, double> x)
		{
			if(father[x] == x) return x;
			return father[x] = find(father[x]);
		}
		double kruskal()
		{
			sort(adj_list.begin(), adj_list.end());
			int s = adj_list.size();
			double answer = 0;
			for(int i = 0; i < s; i++)
			{
				double weight = adj_list[i].f;
				pair <double, double> x = {adj_list[i].s.f, adj_list[i].s.s.f};
				pair <double, double> y = {adj_list[i].s.s.s.f, adj_list[i].s.s.s.s};
				pair <double, double> x1 = find(x);
				pair <double, double> y1 = find(y);
				if(x1 != y1)
				{
					answer += weight;
					father[x1] = y1;
				}
			}
			return answer;
		}
		void clear()
		{
			adj_list.clear();
			father.clear();
		}
};

int main()
{
	int number_of_cases;
	cin >> number_of_cases;
	for(int i = 0; i < number_of_cases; i++)
	{
		if(i) cout << "\n";
		int number_of_freckles;
		cin >> number_of_freckles;
		vector <pair <float, float>> list_of_freckles;
		Graph G;
		for(int j = 0; j < number_of_freckles; j++)
		{
			float x, y;
			cin >> x >> y;
			G.makeFather(x, y);
			list_of_freckles.push_back({x, y});
		}
		for(int j = 0; j < number_of_freckles; j++)
		{
			double x1 = list_of_freckles[j].f, y1 = list_of_freckles[j].s;
			for(int k = j + 1; k < number_of_freckles; k++)
			{
				double x2 = list_of_freckles[k].f, y2 = list_of_freckles[k].s;
				double weight =  sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
				G.addEdge(weight, list_of_freckles[j], list_of_freckles[k]);
			}
		}
		printf("%.2f\n", G.kruskal());
		G.clear();
		list_of_freckles.clear();
	}
	return 0;
}
