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
        int a, b;
        cin >> a >> b;
        
        string ans = string("");
        if (a % 2 == 0 && b % 2 == 0) ans = "YES\n";
        else 
        {
            if (a % 2 == 0)
            {
                if (a == 0) ans = "NO\n";
                else ans = "YES\n";
            }
            else ans = "NO\n";
        }

        cout << ans;
    }

    return 0;
}