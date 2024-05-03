#include <bits/stdc++.h>

using namespace std;

int mat[1001][1001], r, c;

pair <int, int> xy[4]{{-1,0}, {0,1}, {1, 0}, {0, -1}};

void clear_mat(int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            mat[i][j] = 0;
        }
    }
}

bool isValid(pair <int, int> coord)
{
    if(coord.first < 0 or coord.second < 0) return false;
    if(coord.first >= r or coord.second >= c) return false;
    return true;
}

int bfs(pair <int, int> robot, pair <int, int> the_end)
{
    int dist[r][c];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            dist[i][j] = -1;
        }
    }
    queue <pair <int, int>> kiwi;
    kiwi.push(robot);
    dist[robot.first][robot.second] = 0;
    while(!kiwi.empty())
    {
        pair <int, int> u = kiwi.front();
        kiwi.pop();
        if(u == the_end) return dist[u.first][u.second];
        for(int i = 0; i < 4; i++)
        {
            pair <int, int> v = {u.first + xy[i].first, u.second + xy[i].second};
            if(isValid(v) and mat[v.first][v.second] != 1 and dist[v.first][v.second] == -1)
            {
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
                kiwi.push(v);
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    while(r != 0 or c != 0)
    {
        clear_mat(r, c);
        int lin;
        cin >> lin;
        for(int i = 0; i < lin; i++)
        {
            int row, bombs;
            cin >> row >> bombs;
            for(int j = 0; j < bombs; j++)
            {
                int col;
                cin >> col;
                mat[row][col] = 1;
            }
        }
        pair <int, int> start;
        pair <int, int> destiny;
        cin >> start.first >> start.second >> destiny.first >> destiny.second;
        cout << bfs(start, destiny) << '\n';
        cin >> r >> c;
    }
    return 0;
}
