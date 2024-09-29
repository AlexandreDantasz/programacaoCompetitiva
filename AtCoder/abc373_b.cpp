#include <bits/stdc++.h>

#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // A variável a seguir representa a ordem de busca
    // A letra 'A' não está presente pois sempre começamos nela
    string order("BCDEFGHIJKLMNOPQRSTUVWXYZ"); 
    
    string s;
    cin >> s;  

    int ans = 0, lastIndex = s.find('A');
    for (auto c : order)
    { 
        int it = s.find(c);
        ans += max(it - lastIndex, lastIndex - it);
        lastIndex = it;
    }

    cout << ans << '\n';

    return 0;
}