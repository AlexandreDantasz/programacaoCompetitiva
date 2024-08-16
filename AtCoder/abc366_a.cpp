#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, a;
    cin >> n >> t >> a;

    cout << (t >= (n + 1) / 2 || a >= (n + 1) / 2 ? "Yes\n" : "No\n");
    return 0;
}