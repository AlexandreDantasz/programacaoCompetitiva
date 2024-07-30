#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main() 
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        int array[n];
        for (int i = 0; i < n; i++) cin >> array[i];
        
        int ans = 0;
        for (int i = 0; i < n; i += 2) ans = max(ans, array[i]);

        cout << ans << '\n';
    }

    return 0;
}