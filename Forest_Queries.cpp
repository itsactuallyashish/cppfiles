#include <iostream>
#include <vector>
using namespace std;
const int maxN = 1e4;
int dp[maxN][maxN];
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<bool>> has(n + 2, vector<bool>(n + 2, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
                has[i][j] = 1;
            else
                has[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    dp[1][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + has[i][j] - dp[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >>x1 >> y1 >> x2>>y2;
      
        int ans = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2];
        cout << ans << endl;
    }
}