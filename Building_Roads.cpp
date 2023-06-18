#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int mx = 1e6;
vector<vector<int>> adj(mx);
vector<int> lead;
int n, m;
vector<bool> vis(mx, false);
void dfs(int x)
{
    vis[x] = 1;
    for (auto &child : adj[x])
    {
        if (!vis[child])
            dfs(child);
    }
}
int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cmp++;
            lead.push_back(i);
        }
    }
    cout << cmp - 1 << "\n";
    if (cmp > 1)
    {
        int v = lead[0], u;
        for (int i = 1; i < cmp; i++)
        {
            u = lead[i];
            cout << u << " " << v << "\n";
            u = v;
        }
    }
}
