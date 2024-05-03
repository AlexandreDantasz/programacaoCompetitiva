#include <bits/stdc++.h> // for pow() and INT_MAX

using namespace std;

typedef struct Edge
{ // that struct represents an Edge in the graph
    int a, b, w; 
    /*
        "a" means the source junction
        "b" represents the destination junction
        "w" represents the weight of this connection (busyness_of_source - busyness_of_destination)^3
    */
} Edge;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, set = 1; // n represents the number of junctions, and set will represents the number of sets
    // reading the number of junctions (EOF)
    while (cin >> n)
    {
        // vet will be an array to save the busyness value from every junction
        int vet[n + 1];
        long long int dist[n + 1];
        for (int i = 1; i <= n; i++)
        { // reading the busyness value from the junctions
            cin >> vet[i];
            dist[i] = INT_MAX;
        }
        int roads; // in this case, roads will represents the number of edges in the graph
        cin >> roads;
        Edge Adj[roads];
        for (int i = 0; i < roads; i++)
        {
            int a, b; // a and b represents the junctions
            cin >> a >> b; // reading the junctions
            // Adding this edge in the adjacent list of the graph
            Adj[i].a = a; 
            Adj[i].b = b;
            Adj[i].w = (vet[b] - vet[a]) * (vet[b] - vet[a]) * (vet[b] - vet[a]); // represents (busyness_of_destination - busyness_of_source)^3
        }
        int q; // number of queries
        cin >> q;
        cout << "Set #" << set++ << '\n';
        // begin of Bellman-ford's algorithm:
        dist[1] = 0; // source junction
        int flag = 1;
        for (int i = 0; flag && i < n - 1; i++)
        {   // relaxing the vertices
            flag = 0;
            for (int j = 0; j < roads; j++)
            {
                int u = Adj[j].a, v = Adj[j].b, w = Adj[j].w;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
                {
                    flag = 1;
                    dist[v] = dist[u] + w; 
                }
            }
        }
        for (int j = 0; j < roads; j++)
        {   // searching for negative cycles
            int u = Adj[j].a, v = Adj[j].b, w = Adj[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
            {
                dist[v] = INT_MIN; // represents a negative cycle
            } 
        }
        // end of Bellman-ford's algorithm
        for (int i = 0; i < q; i++)
        {
            int junction;
            cin >> junction;
            long long int answer = dist[junction];
            if (answer == INT_MAX || answer < 3) cout << "?\n";
            else cout << answer << '\n';
        }
    }
    return 0;
}