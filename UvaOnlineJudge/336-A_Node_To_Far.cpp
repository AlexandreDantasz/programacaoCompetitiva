#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

void clear(queue <int> &q)
{
	queue <int> empty;
	swap(q, empty);
}

int main()
{
	//~ freopen("input.txt", "r", stdin);
	//~ freopen("output.txt", "w", stdout);
	int number_of_connections, node_x, node_y, i, ttl, starting_node, cases = 1;
	int search, nodes_not_reachable, initial_ttl;
	cin >> number_of_connections;
	while(number_of_connections != 0)
	{
		map <int, vector <int> > adj_list;
		map <int, vector <int> > :: iterator it2;
		map <int, bool> visited;
		set <int> keys;
		set <int> :: iterator it;
		queue <int> my_queue;
		queue <int> aux_queue;
		for(i = 0; i < number_of_connections; i++)
		{
			cin >> node_x >> node_y;
			keys.insert(node_x);
			keys.insert(node_y);
			adj_list[node_x].push_back(node_y);
			adj_list[node_y].push_back(node_x);
		}
		cin >> starting_node >> ttl;
		while(starting_node != 0 or ttl != 0)
		{
			if(ttl == 0)
			{
				nodes_not_reachable = keys.size();
				it2 = adj_list.find(starting_node);
				if(it2 != adj_list.end())
				{
					nodes_not_reachable--;
					printf("Case %i: %i nodes not reachable from node %i with TTL = 0.\n", cases, nodes_not_reachable, starting_node);
				}
				else
				{	
					printf("Case %i: %i nodes not reachable from node %i with TTL = 0.\n", cases, nodes_not_reachable, starting_node);
				}
			}
			else
			{
				for(it = keys.begin(); it != keys.end(); it++)
				{
					visited[*it] = false;
				}
				initial_ttl = ttl;
				nodes_not_reachable = 0;
				visited[starting_node] = true;
				for(auto j : adj_list[starting_node])
				{
					if(visited[j] == false)
					{
						visited[j] = true;
						my_queue.push(j);
					}
				}
				ttl--;
				while(!my_queue.empty() and ttl > 0)
				{
					search = my_queue.front();
					visited[search] = true;
					my_queue.pop();
					for(auto j : adj_list[search])
					{
						if(visited[j] == 0)
						{
							visited[j] = true;
							aux_queue.push(j);
						}
					}
					if(my_queue.empty() == true)
					{
						ttl--;
						int size = aux_queue.size();
						for(int k = 0; k < size; k++)
						{
							my_queue.push(aux_queue.front());
							aux_queue.pop();
						}
					}
				}
				for(it = keys.begin(); it != keys.end(); it++)
				{
					if(visited[*it] == false)
					{
						nodes_not_reachable++;
					}
				}
				clear(my_queue);
				printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", cases, nodes_not_reachable, starting_node, initial_ttl);
			}
			cin >> starting_node >> ttl;
			cases++;
		}
		cin >> number_of_connections;
	}
	return 0;
}
