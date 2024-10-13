#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int n, custoPorDia;

static int solution(int* receita)
{
    int res = 0, lucro = 0;

    for (int i = 0; i < n; i++)
    {
        lucro += receita[i] - custoPorDia;

        if (lucro < 0)
            lucro = 0;

        res = max(res, lucro);
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> n)
    {
        cin >> custoPorDia;

        int* receita = new int[n];

        for (int i = 0; i < n; i++)
            cin >> receita[i];

        cout << solution(receita) << endl;
        delete[] receita;
    }


    return 0;
}