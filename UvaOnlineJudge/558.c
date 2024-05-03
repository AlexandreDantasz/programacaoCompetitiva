#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge
{
    int first, second, weight;
} Edge;


typedef struct Graph
{
    int V, E;
    Edge * list;
    int * dist;
} Graph;

static Graph * createGraph(int v, int e)
{
    Graph * temp = (Graph *)malloc(sizeof(Graph));
    temp->E = e;
    temp->V = v;
    temp->list = (Edge * )malloc(sizeof(Edge) * e);
    temp->dist = (int *) malloc(sizeof(int) * v);
    return temp;
}

static inline void init(Graph * G)
{
    for (int i = 0; i < G->V; i++) G->dist[i] = INT_MAX;
}

static void clear(Graph * G)
{
    free(G->list);
    free(G->dist);
    free(G);
}

static void bellmanFord(Graph * G)
{
    init(G);
    G->dist[0] = 0;
    for (int i = 0; i <= G->V - 1; i++)
    {
        for (int j = 0; j < G->E; j++)
        {
            int u = G->list[j].first, v = G->list[j].second, w = G->list[j].weight;
            if (G->dist[u] != INT_MAX && G->dist[u] + w < G->dist[v]) G->dist[v] = G->dist[u] + w;
        }
    }
    
    for (int i = 0; i < G->E; i++)
    {
        int u = G->list[i].first, v = G->list[i].second, w = G->list[i].weight;
        if (G->dist[u] != INT_MAX && G->dist[u] + w < G->dist[v])
        {
            puts("possible");
            return;
        }
    }
    puts("not possible");
}

int main() 
{
    int cases, n, m;
    scanf("%d", &cases);
    while (cases--)
    {
        // reading the number of star systems
        // and the number of wormholes
        scanf("%d %d", &n, &m);
        Graph * graph = createGraph(n, m);
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            graph->list[i].first = x;
            graph->list[i].second = y;
            graph->list[i].weight = w;
        }
        bellmanFord(graph);
        clear(graph);
    }
    return 0;
}