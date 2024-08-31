#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

bool SearchValues(map<int, char> myMap, char letter)
{ 
    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second == letter) return false;
    }
    return true;
}

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

        int array_a[n];

        for (auto &a : array_a) cin >> a;

        int m;
        cin >> m;

        vector<string> inputs(m);
        for (auto &input : inputs) cin >> input;

        for (auto str : inputs)
        {
            if (str.size() != n) cout << "NO\n";
            else 
            {
                map<int, char> myMap;
                map<int, char>::iterator it;
                string ans = "YES\n";
                // Montando o mapa
                int counter = 0;
                for (auto num : array_a)
                {
                    it = myMap.find(num);
                    if (it == myMap.end())
                    {// O número ainda não foi inserido
                        if (SearchValues(myMap, str[counter])) myMap[num] = str[counter];
                        else 
                        {
                            ans = "NO\n";
                            break;
                        }
                    }
                    else
                    {// O número já foi inserido
                        if (myMap[num] != str[counter])
                        {
                            ans = "NO\n";
                            break;
                        } 
                    }
                    counter++; 
                }

                cout << ans;
            }
        }
    }

    return 0;
}