#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy;
const int mx = 1e3 + 10;
vector<vector<int>> grid(mx, vector<int>(mx, INT_MAX));
vector<vector<int>> parent(mx, vector<int>(mx, 4));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";
bool isvalid(int x, int y, int time)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (grid[x][y] <= time)
        return false;
    return true;
}
queue<array<int, 3>> q;
void flow()
{
    while (!q.empty())
    {
        array<int, 3> ar = q.front();
        q.pop();
        int time = ar[2] + 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = ar[0] + dx[i];
            int yy = ar[1] + dy[i];
            if (isvalid(xx, yy, time))
            {
                grid[xx][yy] = time;
                q.push({xx, yy, time});
                // cerr << xx << " " << yy << " " << time << "\n";
            }
        }
    }
}
bool isescape(int i, int j, int time)
{
    if (!isvalid(i, j, time))
        return false;
    if (i == n - 1 || j == m - 1 || i == 0 || j == 0)
        return true;
    return false;
}
string ss;
int ex, ey;
bool bfs()
{
    queue<array<int, 3>> qu;
    qu.push({sx, sy, 0});
    while (!qu.empty())
    {
        array<int, 3> ar = qu.front();
        qu.pop();
        int time = ar[2] + 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = ar[0] + dx[i], yy = ar[1] + dy[i];
            if (isescape(xx, yy, time))
            {
                parent[xx][yy] = i;
                ex = xx, ey = yy;
                return true;
            }
            if (isvalid(xx, yy, time))
            {
                parent[xx][yy] = i;
                qu.push({xx, yy, time});
                grid[xx][yy] = time;
                // cerr<<xx <<" "<< yy <<" "<<time<<"\n";
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            if (ch == 'M')
            {
                q.push({i, j, 0});
                grid[i][j] = 0;
            }
            else if (ch == '#')
                grid[i][j] = 0;
            else if (ch == 'A')
            {
                sx = i, sy = j;
                grid[i][j] = 0;
            }
        }
    }
    if(sx==0|| sy==0 || sx==n-1|| sy==m-1) {
        cout<< "YES\n";
        cout<<0;
        exit(0);
    }
    flow();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cerr<<grid[i][j]<<"  ";
    //     }
    //     cerr<<"\n";
    // }

    if (bfs())
    {
        cout << "YES\n";
        while (sx != ex || sy != ey)
        {
            int i = parent[ex][ey];
            ex -= dx[i], ey -= dy[i];
            ss.push_back(stepDir[i]);
        }
        reverse(ss.begin(), ss.end());
        cout << ss.size() << "\n";
        for (auto &ch : ss)
            cout << ch;
    }

    else
    {
        cout << "NO";
        exit(0);
    }
}