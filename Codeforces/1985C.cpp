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
        int n;
        cin >> n;

        long int array[n];
        for (int i = 0; i < n; i++) cin >> array[i];

        long long int sum = 0;
        long int biggestNumber = array[0];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += array[i];
            biggestNumber = max(biggestNumber, array[i]);
            if (sum - biggestNumber == biggestNumber) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}