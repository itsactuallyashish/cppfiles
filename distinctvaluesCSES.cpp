#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int, int> pii;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const int MAXN = 3e6;
long long seg[4 * MAXN];
int n;
#define ll long long

ll query(int l, int r)
{
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += seg[l++];
        if (r & 1)
            res += seg[--r];
    }
    return res;
}
void update(int in, int val)
{
    in += n;
    seg[in] = val;
    while (in >= 1)
    {
        in >>= 1;
        seg[in] = seg[2 * in] + seg[2 * in + 1];
    }
    return;
}
void build(vector<ll> ar)
{
    for (int i = 0; i < n; i++)
        seg[i + n] = ar[i];
    for (int i = n - 1; i >= 1; i--)
        seg[i] = seg[2 * i] + seg[2 * i + 1];
}

vector<pii> que[MAXN];
int main()
{
    fast_io;
    int nn, q;
    cin >> nn >> q;
    n = ceil(pow(2, log2(nn)));
    // n=nn;
    vector<ll> x(nn);
    for (int i = 0; i < nn; i++)
        cin >> x[i];
    build(x);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        que[b].push_back(make_pair(a, i));
    }
    vector<int> ans(q);

    map<int, int> mp;
    for (int i = 0; i < nn; ++i)
    {
        update(i, 1);
        if (mp.find(x[i]) != mp.end())
            update(mp[x[i]], 0);
        mp[x[i]] = i;
        for (auto &p : que[i])
        {
            ans[p.second] = query(p.first, i);
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}