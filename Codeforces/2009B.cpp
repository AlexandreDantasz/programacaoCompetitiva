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
        int n, col = 1;
        vector<int> ans;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            char input;
            for (int j = 0; j < 4; j++)
            {
                cin >> input;
                if (input == '#') ans.push_back(j + 1);
            }            
        }

        reverse(ans.begin(), ans.end());
        for (auto r : ans) cout << r << ' ';
        cout << '\n';
    }
    
    return 0;
}