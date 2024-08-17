#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> array(n);

    // I've learne this by reading the editorial!
    // Awesome!
    for (auto &s : array) cin >> s;
    
    int bigger_size = INT_MIN;
    
    for (auto s : array) bigger_size = max(bigger_size, (int) s.size());

    vector<string> str(bigger_size, string(n, '*'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int) array[i].size(); j++)
        {
            str[j][n - i - 1] = array[i][j]; 
        }
    }

    for (int i = 0; i < bigger_size; i++)
    {
        while (str[i][str[i].size() - 1] == '*') str[i].pop_back();
        cout << str[i] << '\n';
    }

    return 0;
}