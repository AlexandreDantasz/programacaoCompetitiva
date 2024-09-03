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

        int ans = INT_MAX, c = a;

        while (c <= b)
        {
            ans = min((c - a) + (b - c), ans);
            c++;
        }

        cout << ans << '\n';

    }
    return 0;
}