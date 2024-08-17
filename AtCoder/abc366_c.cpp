#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    
    set<int> bag;
    vector<int> entryValues(1000001, 0);
    while (q--)
    {
        int option, x;
        cin >> option;

        if (option == 1)
        {
            cin >> x;
            bag.insert(x);
            entryValues[x]++;
        }
        else
        { 
            if (option == 2) 
            {
                cin >> x;
                if (entryValues[x] == 1) 
                {
                    entryValues[x] = 0;
                    bag.erase(x);
                }
                else entryValues[x]--;
            }
            else cout << bag.size() << '\n';
        }
            
    }

    return 0;
}