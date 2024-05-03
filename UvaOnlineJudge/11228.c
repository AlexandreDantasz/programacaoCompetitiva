#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int * parents;

static void initParents(int v)
{
    parents = (int *) malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++) parents[i] = i;
}

struct Edge 
{
    int cityA, cityB;
    double dist;
};

struct Pair
{
    int first, second;
};

int comp(const void * a, const void * b)
{
    return ((struct Edge *) a)->dist < ((struct Edge *) b)->dist ? -1 : 1;
}

static int find(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

static void makeUnion(int x, int y)
{
    int x1 = find(x), y1 = find(y);
    parents[x1] = y1;
}

int main()
{
    int testCases, sets = 1;
    scanf("%d", &testCases);
    while (testCases--) 
    {
        int n, threshold;
        scanf("%d %d", &n, &threshold);
        struct Pair cities[n];
        for (int i = 0; i < n; i++) scanf("%d %d", &cities[i].first, &cities[i].second);
        struct Edge distances[n * n];
        int index = 0;
        // time to calculate all the distances
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++, index++)
            {
                distances[index].cityA = i;
                distances[index].cityB = j;
                int tempCalc = ((cities[j].first - cities[i].first) * (cities[j].first - cities[i].first) + (cities[j].second - cities[i].second) * (cities[j].second - cities[i].second)); 
                distances[index].dist = sqrt((tempCalc));
            }
        }
        initParents(n);
        qsort(distances, index, sizeof(struct Edge), &comp);
        int states = 1, maxItens = 0;
        double roads = 0, rails = 0;
        // begin of Kruskal's algorithm
        for (int i = 0; maxItens < n - 1 && i < index; i++)
        {
            int a = distances[i].cityA;
            int b = distances[i].cityB;
            double dist = distances[i].dist;
            if (find(a) != find(b))
            {
                makeUnion(a, b);
                if (dist <= threshold) roads += dist;
                else 
                {
                    states++;
                    rails += dist;
                }
                maxItens++;
            }
        }
        printf("Case #%d: %d %.lf %.lf\n", sets, states, roads, rails);
        free(parents);
        sets++;
    }
    return 0;
}