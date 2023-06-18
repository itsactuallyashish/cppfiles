// persistent segment tree
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
struct Vertex
{
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};
Vertex *build(vector<ll> &a, int tl, int tr)
{
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

ll get_sum(Vertex *v, ll tl, ll tr, int &l, int &r)
{
    if (tl > r || tr < l)
        return 0;
    if (tl >= l && tr <= r)
        return v->sum;
    ll d = (tl + tr) / 2;
    return get_sum(v->l, tl, d, l, r) + get_sum(v->r, d + 1, tr, l, r);
}

Vertex *update(Vertex *v, ll tl, ll tr, int &pos, ll &new_val)
{
    if (tl == tr)
        return new Vertex(new_val);
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int tl = 0, tr = n - 1;
    vector<Vertex *> roots;
    roots.push_back(build(ar, tl, tr));
    vector<Vertex *> lis;
    lis.push_back(roots.back());

    int code, l, r, k, a, b;
    ll x;
    for (int i = 0; i < q; i++)
    {
        cin >> code;
        if (code == 1)
        {
            cin >> k >> a >> x;
            a--;
            lis[k - 1] = (update(lis[k - 1], tl, tr, a, x));
        }
        else if (code == 2)
        {
            cin >> k >> a >> b;
            a--, b--;
            cout << get_sum(lis[k - 1], tl, tr, a, b) << "\n";
        }
        else
        {
            cin >> k;
            lis.push_back(lis[k - 1]);
        }
    }
}