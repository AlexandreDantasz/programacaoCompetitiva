#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
#define ull unsigned long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ull a, b;
        cin >> a >> b;

        vector<ull> ans;
        ans.push_back(a);

        int sum = 1;

        while (ans[ans.size() - 1] + sum <= b)
            ans.push_back(ans[ans.size() - 1] + sum++);
        
        cout << ans.size() << '\n';
    }

    return 0;
}