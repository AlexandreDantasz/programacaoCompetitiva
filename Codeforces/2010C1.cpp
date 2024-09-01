#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

vector<int> SearchIndex(char letter, string str)
{
    vector<int> possibleIndex;
    for (int i = 1; i < str.size(); i++)
    {
        if (letter == str[i]) possibleIndex.push_back(i);
    }

    return possibleIndex;
}

int Solution(char letter, string strComplete, string word)
{
    vector<int> toSearch = SearchIndex(letter, word);

    for (auto index : toSearch)
    {
        if (strComplete.substr(index, word.size() + 1) == word) 
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t;
    cin >> t;

    // brute force
    int index = 0, ans = 0;
    do
    {
        index++;
        ans = Solution(t[0], t, t.substr(0, index));
    } while (index < t.size() && ans != 1);
    
    cout << (!ans ? "NO\n" : "YES\n" + t.substr(0, index)); 
    return 0;
}