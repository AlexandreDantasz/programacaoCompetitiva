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
        
        long long int array[n];
        for (auto &value : array) cin >> value;

        for (int i = 1; i < n; i++)
        {
            if (i % 2) array[i] = array[i - 1] - array[i];
            else array[i] = array[i - 1] + array[i]; 
        }

        cout << array[n - 1] << '\n';
    }

    return 0;
}