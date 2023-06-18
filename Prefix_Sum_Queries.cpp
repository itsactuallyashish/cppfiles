#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e6;
struct node
{
    ll sum;
    ll prefix;
    node(ll x, ll y) : sum(x), prefix(y) {}
    node(ll x = 0) : sum(x), prefix(max(0LL,x)) {}
    friend node operator+(node x, node y)
    {
        node res;
        res.sum = x.sum + y.sum;
        res.prefix = max(x.prefix, x.sum + y.prefix);
        return res;
    }
} tree[mx];
int n, q;
vector<ll> ar(1);
void build(int si , int ss, int se )
{
    if (ss == se)
    {
        tree[si] = node(ar[ss]);
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    tree[si] = tree[2 * si] + tree[2 * si + 1];
}
void update(int si , int ss , int se , int xi, ll val)
{
    if (ss == se)
    {
        tree[si] = node(val);
        return;
    }
    int mid = (ss + se) / 2;
    if (mid < xi)
        update(2 * si + 1, mid + 1, se, xi, val);
    else
        update(2 * si, ss, mid, xi, val);
    tree[si] = tree[2 * si] + tree[2 * si + 1];
}
node query(int si , int ss , int se , int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    build(1,1,n);
    for (int i = 0; i < q; i++)
    {
         int  ch;
        cin >> ch;
        if (ch == 1)
        {
            int a;
            ll b;
            cin >> a >> b;
            update(1,1,n,a, b);
            // ar[a]=b;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1,1,n,a, b).prefix << "\n";
        }
    }
}