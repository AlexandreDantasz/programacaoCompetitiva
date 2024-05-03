#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge
{
    int first, second, weight;
} Edge;


typedef struct Graph
{
    int V, E, index;
    Edge * list;
    int * dist;
} Graph;

static Graph * createGraph(int v, int e)
{
    Graph * temp = (Graph *) malloc(sizeof(Graph));
    temp->E = e;
    temp->V = v;
    temp->list = (Edge *) malloc(sizeof(Edge) * e);
    temp->dist = (int *) malloc(sizeof(int) * v);
    int i;
    for (i = 0; i < v; i++) 
    {
        temp->list[i].first = i;
        temp->list[i].second = i;
        temp->list[i].weight = 0;
    }
    temp->index = i;
    return temp;
}

static inline void init(Graph * G)
{
    for (int i = 0; i < G->V; i++) G->dist[i] = INT_MAX;
}

static void printAns(Graph * G)
{
    int sum = 0;
    for (int i = 0; i < G->V; i++)
    {
        if (G->dist[i] != INT_MAX && G->dist[i] > sum) sum = G->dist[i]; 
    }
    printf("%d\n", sum);
}

static void bellmanFord(Graph * G, int src)
{
    init(G);
    G->dist[src] = 0;
    int flag = 1;
    for (int i = 0; flag != 0 && i <= G->V - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < G->index; j++)
        {
            int u = G->list[j].first, v = G->list[j].second, w = G->list[j].weight;
            if (G->dist[u] != INT_MAX && G->dist[u] + w < G->dist[v]) 
            {
                G->dist[v] = G->dist[u] + w;
                flag = 1;
            }
        }
    }
    printAns(G);
}

int main()
{
    int n, col = 1;
    scanf("%d", &n);
    Graph * G = createGraph(n, n * n);
    for (int i = 1; i < n; i++, col++)
    {
        for (int j = 0; j < col; j++)
        {
            char line[12];
            scanf("%s", line);
            if (line[0] != 'x')
            {
                int w;
                w = atoi(line);
                G->list[G->index].first = i;
                G->list[G->index].second = j;
                G->list[G->index].weight = w;
                G->list[G->index + 1].first = j;
                G->list[G->index + 1].second = i;
                G->list[G->index + 1].weight = w;
                G->index += 2;
            }
        }
    }
    bellmanFord(G, 0);
    free(G);
    return 0;
}