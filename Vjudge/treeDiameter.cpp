#include <bits/stdc++.h>
#define VVI vector<vector<int>>

using namespace std;

int bfsLeaf(VVI adj, int start, int s) {
    int dist[s];
    for (int i = 0; i < s; i++) dist[i] = -1;
    int counter = 0;
    dist[start] = 0;
    queue <int> kiwi;
    kiwi.push(start);
    int node = -1;
    while (!kiwi.empty()) {
        int u = kiwi.front();
        kiwi.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (counter < dist[v]) {
                    counter = dist[v];
                    node = v;
                }
                kiwi.push(v);
            }
        }
    }
    return node;
}

int bfsResp(VVI adj, int start, int s) {
    int dist[s];
    for (int i = 0; i < s; i++) dist[i] = -1;
    int counter = 0;
    dist[start] = 0;
    queue <int> kiwi;
    kiwi.push(start);
    while (!kiwi.empty()) {
        int u = kiwi.front();
        kiwi.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                counter = counter < dist[v] ? dist[v] : counter;
                kiwi.push(v);
            }
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    VVI adj(n + 1);
    int vis[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int resp = 0, leafNode = bfsLeaf(adj, 1, n + 1);
    resp = bfsResp(adj, leafNode, n + 1);
    cout << resp << '\n';
}