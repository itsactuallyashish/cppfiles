#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mx = 5 * (int)1e6;
ll xmax = 0;
vector<ll> result(mx, -1), ans(mx);

ll getcollatz(ll x)
{
    if (x > mx)
    {
        return 1 + getcollatz(x & 1 ? 3 * x + 1 : x / 2);
    }
    if (result[x] != -1)
        return result[x];
    if (x <= 1)
    {
        return 0;
    }
    return result[x] = getcollatz(x & 1 ? 3 * x + 1 : x / 2) + 1;
}
void solve()
{
    result[0] = 0;
    result[1] = 0;
    int in = 0;
    for (int i = 1; i < mx; i++)
    {
        ll xx = getcollatz(i);
        if (xx >= xmax)
        {
            xmax = xx;
            in = i;
        }
        ans[i] = in;
    }
}
int main()
{
    solve();
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}