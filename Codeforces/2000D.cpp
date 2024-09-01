#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<li, li>
#define li unsigned long long int
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    li t;
    cin >> t;
 
    while (t--)
    {
        li n;
        cin >> n;
 
        li array[n];
        vector<li> sumPrefix(n + 1);
        sumPrefix[0] = 0;
        int i = 1;
        for (auto &value : array) 
        {
            cin >> value;
            sumPrefix[i] = value + sumPrefix[i - 1];
            i++;
        }

        list<li> l_positions;
        list<li> r_positions;
 
        for (li i = 0; i < n; i++)
        {
            char letter;
            cin >> letter;
            if (letter == 'L') l_positions.push_back(i);
            else r_positions.push_back(i);
        }
 
        r_positions.reverse();
 
        li ans = 0;
        for (auto index : l_positions)
        {
            if (r_positions.empty()) break;
            li index_r = r_positions.front();
            if (index_r > index) 
            {
                ans += sumPrefix[index_r + 1] - sumPrefix[index];
            }
            else break;
            r_positions.pop_front();
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}