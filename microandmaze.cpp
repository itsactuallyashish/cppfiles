#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat(1000,vector<int>(1000,0));
int n, m;

bool dfs(int i, int j)
{
    bool ans = false;
    if (i == n - 1 && j == m - 1)
        return true;
    mat[i][j] = 0;
    auto valid = [](int x, int y)
    {
        if (x < 0 || x >= n || y >= m || y < 0 || mat[x][y]==0)
            return false;
        return true;
    };
    string dir = "UDLR";
    int x[] = {-1, 1, 0, 0};
    int y[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++)
    {
        if (valid(i + x[k], j + y[k]))
        {
            // cerr<<i+x[k]<<' '<<j+y[k]<<endl;
            ans = ans || dfs(i + x[k], j + y[k]);
        }
    }
        return ans;
}
int main()
{
    cin >> n >> m;
    
    int in;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
    }
    if (dfs(0, 0))
        cout << "Yes";
    else
        cout << "No";
}