#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

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

        int array[n], currentSits[n];

        fill(currentSits, currentSits + n, 0);

        for (auto &a : array) cin >> a;

        bool ans = true;
        currentSits[array[0] - 1] = 1;
        for (int i = 1; ans && i < n; i++)
        {
            if ((array[i] - 1 < n - 1 && currentSits[array[i]]) || (array[i] - 1 > 0 && currentSits[array[i] - 2]))
                currentSits[array[i] - 1] = 1;
            else 
                ans = false;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}