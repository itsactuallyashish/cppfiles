#include <bits/stdc++.h>
using namespace std;
#define ll long long
using matrix = vector<vector<ll>>;
matrix adj, g;
int n;
bool vis[501];
int pa[501];
bool reachable()
{
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int rem = q.front();
        q.pop();
        for (int x = 0; x < adj[rem].size(); x++)
        {
            if (!vis[x] && adj[rem][x] > 0)
            {
                vis[x] = 1;
                pa[x] = rem;
                q.push(x);
            }
        }
    }
    return vis[n - 1];
}
vector<vector<int>> paths;

int main()
{
    int m;
    cin >> n >> m;
    g.assign(n, vector<ll>(n));
    adj.assign(n, vector<ll>(n));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // ll w; cin>>w;
        a--, b--;
        g[a][b] = adj[a][b] = 1;
    }
    ll mxflow = 0;
    while (reachable())
    {
        ll flow = 1e18;
        for (int i = n - 1; i != 0; i = pa[i])
        {
            flow = min(flow, adj[pa[i]][i]);
        }
        mxflow += flow;
        for (int i = n - 1; i != 0; i = pa[i])
        {
            adj[pa[i]][i] -= flow;
            adj[i][pa[i]] += flow;
        }
    }
    cout << mxflow << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == adj[i][j])
            {
                adj[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < mxflow; i++)
    {
        list<int> ls;
        vector<int> x = {0};

        vector<bool> vis(n, false);
        vis[0] = 1;
        while (x.back() != n - 1)
        {
            bool flag = 0;
            for (int v = 0; v < n; v++)
            {
                if (adj[v][x.back()] > 0 && !vis[v])
                {

                    adj[v][x.back()] = 0;
                    vis[v] = 1;
                    x.push_back(v);
                    break;
                }
            }
        }

        paths.push_back(x);
    }

    for (int i = paths.size() - 1; i >= 0; i--)
    {
        cout << paths[i].size() << "\n";
        for (auto x : paths[i])
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}