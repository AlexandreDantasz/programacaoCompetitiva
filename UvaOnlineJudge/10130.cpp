#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int dp[1002][31];

// Knapsack 0/1: tabulation method
int solution(int n, vector<pii> products, int weight)
{
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= weight; w++)
        {
            if (products[i - 1].s <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - products[i - 1].s] + products[i - 1].f); 
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][weight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pii> products(n);
        // first -> price
        // second -> weight
        for (auto &i : products) cin >> i.f >> i.s;

        int g;
        cin >> g;

        int people[g];
        for (auto &i : people) cin >> i;

        int sum = 0;
        for (auto weight : people) 
        {
            for (int r = 0; r < n + 1; r++)
                for (int c = 0; c < weight + 1; c++)
                    dp[r][c] = 0;

            sum += solution(n, products, weight);

        }
        cout << sum << endl;

    }

    return 0;
}