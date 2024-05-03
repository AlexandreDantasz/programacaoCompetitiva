#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Object
{
    char key[9];
} Id;

typedef struct Links 
{
    int first;
    int second;
    int dist;
} Adj;

static int * parents;
static Id * map;

static void init(int cities)
{
    parents = (int *) malloc(sizeof(int) * cities);
    map = (Id *) malloc(sizeof(Id) * cities);
    for (int i = 0; i < cities; i++) parents[i] = i;
}

static int find(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

static inline void makeUnion(int x, int y) 
{
    parents[x] = y;
}

static int comp(const void * a, const void * b)
{
    return ((Adj *)a)->dist < ((Adj *)b)->dist ? -1 : 1;
}

static int position(char * str, int * len)
{
    int i;
    for (i = 0; i < * len; i++)
    {
        if (!strcmp(str, map[i].key)) return i;
    }
    (* len)++;
    strcpy(map[i].key, str);
    return i;
}

int main()
{
    int testCases, cities, links, distance, answer = 0;
    Adj * list = NULL;
    char cityA[9], cityB[9];
    scanf("%d", &testCases);
    while (testCases--)
    {
        scanf("%d %d", &cities, &links);
        answer = 0;
        list = (Adj *) malloc(sizeof(Adj) * links);
        init(cities);
        int limit = 0;
        for (int i = 0; i < links; i++)
        {
            scanf("%s %s %d", cityA, cityB, &distance);
            list[i].first = position(cityA, &limit);
            list[i].second = position(cityB, &limit);
            list[i].dist = distance;
        }
        qsort(list, links, sizeof(Adj), &comp);
        int components = 0;
        for (int i = 0; components < cities - 1 && i < links; i++)
        {
            int x = list[i].first, y = list[i].second, w = list[i].dist;
            int x1 = find(x), y1 = find(y);
            if (x1 != y1)
            {
                makeUnion(x1, y1);
                answer += w;
                components++;
            }
        }
        free(parents);
        free(map);
        free(list);
        printf("%d\n", answer);
        if (testCases) printf("\n");
    }
    return 0;
}