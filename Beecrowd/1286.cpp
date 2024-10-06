#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int knapsack(vector<pii> array, int weight, int index, int ** dp)
{
    if (index < 0)
        return 0;

    if (dp[index][weight] != -1)
        return dp[index][weight];

    if (array[index].s > weight)
    {
        // Se chegar aqui, significa que não podemos adicionar esse pedido.
        // Por essa razão, index - 1 é passado por parâmetro na função pois representa
        // que estamos "pulando" essa opção.

        dp[index][weight] = knapsack(array, weight, index - 1, dp);
        return dp[index][weight];
    }

    dp[index][weight] = max(array[index].f + knapsack(array, weight - array[index].s, index - 1, dp), knapsack(array, weight, index - 1, dp));
    return dp[index][weight];
}

void solution(vector<pii> array, int weight, int n)
{
    int ** dp;
    dp = new int *[n];

    for (int i = 0; i < n; i++)
        dp[i] = new int[weight + 1];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < weight + 1; j++)
            dp[i][j] = -1;

    cout << knapsack(array, weight, n - 1, dp) << " min.\n";

    for (int i = 0; i < n; i++)
        delete[] dp[i];
    
    delete[] dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;

    while (n != 0) 
    {
        int p;
        cin >> p;

        // first: tempo total para ser entregue
        // second: número de pedidos

        vector<pii> pizzas(n);
        for (auto &i : pizzas)
            cin >> i.f >> i.s;

        solution(pizzas, p, n);

        cin >> n;
    }

    return 0;
}