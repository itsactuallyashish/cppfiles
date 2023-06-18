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

void solve()
{
    int n;
    see(n);
    vector<tuple<ll, ll, ll>> events;
    for (int i = 0; i < n; i++)
    {
        ll s, e, r;
        see(s, e, r);
        events.push_back({e, s, r});
    }
    sort(all(events));
    vector<pair<ll,ll>>dpp;
    dpp.push_back({0,0});
    ll mxreward = 0;
    for (auto [e, s, r] : events)
    {
        pair<ll,ll>pr={s,0};
         auto it=lower_bound(all(dpp),pr)-dpp.begin();
        mxreward = max(mxreward, dpp[it-1].second + r);
        dpp.push_back({e,mxreward});
    }
    put(mxreward);
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
