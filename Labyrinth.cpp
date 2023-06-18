#include <bits/stdc++.h>
using namespace std;
const int mx = 1e3 + 10;
vector<vector<int>> pre(mx, vector<int>(mx, -1));
vector<vector<bool>> vis(mx, vector<bool>(mx, false));
int n, m;
int sx, sy, ex, ey;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";
bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

int main()
{
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            if (ch == '#')
            {

                vis[i][j] = 1;
            }
            else if (ch == 'A')
            {
                sx = i, sy = j;
            }
            else if (ch == 'B')
            {
                ex = i, ey = j;
            }
        }
    // performing bfs
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(xx + dx[i], yy + dy[i]))
            {
                q.push({xx + dx[i], yy + dy[i]});
                vis[xx + dx[i]][yy + dy[i]] = 1;
                pre[xx + dx[i]][yy + dy[i]] = i;
            }
        }
    }
    // assert(path[ex][ey]!={0,0});
    if (vis[ex][ey])
        cout << "YES"
             << "\n";
    else{
        cout<<"NO";
        return 0;
    }
        

    string ss;
    while (ex != sx || ey != sy)
    {
        int p = pre[ex][ey];
        ss.push_back(stepDir[p]);
        ex -= dx[p];
        ey -= dy[p];
    }

    reverse(ss.begin(), ss.end());
    cout << ss.size() << "\n"
         << ss;
}