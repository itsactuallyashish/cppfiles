#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define ll long long
// taken care of overflow error
struct node
{
    // s represents the sum of the subtree
    // z0 represent the starting element of the range which is to be added to the subrange
    // z1 represent the number of operation of type (0,1,2,3,4...)*z1 needs to be performed
    ll s = 0, z0 = 0, z1 = 0;
} tree[1000006];
ll helper(int x)
{
    long long ans = x * (x + 1);
    ans /= 2;
    return ans;
}
 
void build(int p, int v, int k, int x, int y)
{
    if (x == y)
    {
        if (p == x)
            tree[k].s = v;
        return;
    }
 
    if (x <= p && p <= y)
    {
        int d = (x + y) / 2;
        build(p, v, 2 * k, x, d);
        build(p, v, 2 * k + 1, d + 1, y);
        tree[k].s = tree[2 * k].s + tree[2 * k + 1].s;
    }
}
void upd(int a, int b, int k, int x, int y)
{
    if (x > b || y < a)
        return;
    if (x >= a && y <= b)
    {
        // we have encountered a segment in the range
        // increment the z0 to the new value which would be added to all member of subtree
        // increment the number of operation needs to be performed on the subtree of type(0,1,2,3,4,...)*tree[k].z0;
        tree[k].z0 += (1 + x - a);
        tree[k].z1++;
        return;
    }
    // increment the value of the subset of the range encountered
    ll xx = max(a, x), yy = min(b, y);
    tree[k].s +=  (yy - xx + 1) * (1 + x - min(a, x)) + (yy - xx) * (yy - xx + 1) / 2;
    // update the subtree
    int d = (x + y) / 2;
    upd(a, b, 2 * k, x, d);
    upd(a, b, 2 * k + 1, d + 1, y);
}
ll sum(int a, int b, int k, int x, int y)
{
    if (a > y || b < x)
        return 0;
    if (a <= x && b >= y)
    {
        // calculate the pending update to the node from the corresponding value of z0,z1;
 
        return tree[k].s + tree[k].z0 * (y - x + 1) + tree[k].z1 * (y - x) * (y - x + 1) / 2;
    }
    // propagate the pending update to the subtree
 
    tree[k].s += tree[k].z0 * (y - x + 1) + tree[k].z1 * (y - x) * (y - x + 1) / 2;
    tree[2 * k].z1 += tree[k].z1, tree[2 * k + 1].z1 += tree[k].z1;
    tree[2 * k].z0 += tree[k].z0;
    // increment the z0 of the right subtree according to new starting value of range denoted by it (x+(y-x)/2); but instead of x it will be the older value of the parent z0;
 
    tree[2 * k + 1].z0 += ((y - x + 1) / 2) * tree[k].z1 + tree[k].z0;
    tree[k].z0 = 0, tree[k].z1 = 0;
    int d = (x + y) / 2;
    return sum(a, b, 2 * k, x, d) + sum(a, b, 2 * k + 1, d + 1, y);
}
 
signed main()
{
    int n, q;
    cin >> n >> q;
    int x;
    int nn = pow(2,(int)ceil(log2(n)));
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        build(i, x, 1, 0, nn - 1);
    }
    int code, l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> code;
        if (code == 1)
        {
            cin >> l >> r;
            l--, r--;
            upd(l, r, 1, 0, nn - 1);
        }
        else
        {
            cin >> l >> r;
            l--, r--;
            cout << sum(l, r, 1, 0, nn - 1) << "\n";
        }
    }
}