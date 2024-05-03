#include <bits/stdc++.h>

using namespace std;

int sum[11];

string bfs(int current, int password, int buttons)
{
    vector <int> dist(10001, -1);
    queue <int> kiwi;
    kiwi.push(current);
    dist[current] = 0;
    while(!kiwi.empty())
    {
        int u = kiwi.front();
        kiwi.pop();
        if(u == password) return to_string(dist[u]);
        for(int i = 0; i < buttons; i++)
        {
            int v = u + sum[i];
            v = v % 10000;
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                kiwi.push(v);
            }
        }
    }
    return "Permanently Locked";
}

int main()
{
    int current_lock, password, buttons, counter = 1;
    cin >> current_lock >> password >> buttons;
    while(current_lock != 0 or password != 0 or buttons != 0)
    {
        for(int i = 0; i < buttons; i++)
        {
            cin >> sum[i];
        }
        cout << "Case " << counter << ": " << bfs(current_lock, password, buttons) << '\n';
        counter++;
        cin >> current_lock >> password >> buttons;
    }
    return 0;
}
