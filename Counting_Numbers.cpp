#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()

ll dp[20];
ll count(ll a)
{
    if (a < 1)
        return a == 0 ? 1 : 0;
    string x = to_string(a);
    ll res = 0;
    int prev = 0;
    for (int i = 0; i < x.size(); i++)
        res += dp[i];
    for (int i = 0; i < x.size(); i++)
    {
        int digit = x[i] - '0';
        int diff = x.size() - i - 1;
        int back = prev < digit ? digit - 1 : digit;
        res += (digit == 0) ? 0 : back * (dp[diff]);
        if (prev == digit)
        {
            return res;
        }
        prev = digit;
    }
    return res + 1;
}
void solve()
{
    dp[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        dp[i] = dp[i - 1] * 9;
    }
    ll a, b;
    see(a, b);
    put(count(b) - count(a - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
        cout << '\n';
    }
}
