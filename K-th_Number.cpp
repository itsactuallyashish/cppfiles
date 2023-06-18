// persistent segment tree
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Vertex
{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};
Vertex *build(int tl, int tr)
{
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
}

Vertex *update(Vertex *v, int tl, int tr, int pos)
{
    if (tl == tr)
        return new Vertex(v->sum + 1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos));
}

int find_kth(Vertex *vl, Vertex *vr, int tl, int tr, int k)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm + 1, tr, k - left_count);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> rank(a);
    sort(rank.begin(), rank.end());
    rank.erase(unique(rank.begin(), rank.end()), rank.end());
    map<int, int> mp;
    for (int i = 0; i < rank.size(); i++)
        mp[rank[i]] = i;
    int tl = 0, tr = n - 1;
    vector<Vertex *> roots;
    roots.push_back(build(tl, tr));
    for (int i = 0; i < rank.size(); i++)
    {
        roots.push_back(update(roots.back(), tl, tr, mp[a[i]]));
    }

    int k, l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r >> k;
        l--, r--;
        cout << rank[find_kth(roots[l], roots[r + 1], tl, tr, k)] << "\n";
    }
}