#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{ 
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long double>> dp(n+1,vector<long double>(6*n+1,0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 * n; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if (j >= k)
                    dp[i][j] += dp[i - 1][j - k];
            }
            dp[i][j] /= 6;
        }
    }
   long double ans = 0;
    for (int i = m; i <= k; i++)
    {
        ans += dp[n][i];
    }
    ans *= 1e6;

    ans = llround(ans);
    ans /= 1e6;
    cout << fixed << setprecision(6) << ans;
}