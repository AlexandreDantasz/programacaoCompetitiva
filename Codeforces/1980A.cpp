#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int problems[7] = {0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < n; i++)
        {
            char letter;
            cin >> letter;
            problems[((int) letter) - 65]++;
        }

        int ans = 0;
        while (m--)
        {
            for (int i = 0; i < 7; i++)
            {
                if (problems[i]) problems[i]--;
                else ans++;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}