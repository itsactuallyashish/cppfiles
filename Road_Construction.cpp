#include <bits/stdc++.h>
using namespace std;
// implementation of dsu
#define ll long long
const int maxn = 1e6 + 12;
vector<int> parent(maxn), siz(maxn);
void make(int v)
{
    parent[v] = v;
    siz[v] = 1;
}
int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
};
bool union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (siz[a] < siz[b])
        swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return true;
}
int main()
{
    int n, q;
    cin >> n >> q;
    int ans = n, mx = 1;
    for (int i = 1; i <= n; i++)
        make(i);
    int x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        if (union_set(x, y))
        {
            mx = max(mx, siz[find(y)]);
            ans--;
        }
            
        cout << ans << " " << mx << "\n";
    }
}