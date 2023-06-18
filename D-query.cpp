#include <bits/stdc++.h>
using namespace std;
#define ll long long
int blk = 700;
// unordered_map<ll, int> mp;
 int freq[1000006];
const int mx = 2e5 + 5;
ll v[mx];
int ans[mx];
struct node
{
    int in, l, r;
};
int cnt = 0;

void add(int x)
{
    freq[v[x]]++;
    // cout<< v[x]<< " ";
    if (freq[v[x]] == 1)
        cnt++;
}
void erase(int x)
{
    freq[v[x]]--;
    if (freq[v[x]] == 0)
        cnt--;
}
void solve(vector<node> qu)
{
    int mr = -1, ml = 0;
    for (auto &q : qu)
    {
        int l = q.l;
        int r = q.r;
        int in = q.in;

        // extending range
        while (mr < r)
            mr++, add(mr);
        while (ml > l)
            ml--, add(ml);
        // reducing range
        while (mr > r)
            erase(mr), mr--;
        while (ml < l)
            erase(ml), ml++;
        ans[in] = cnt;
    }
}
int main()
{
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
        cin >> q;
    vector<node> query(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        query[i].l = x;
        query[i].r = y;
        query[i].in = i;
    }
    // blk=pow(n,0.5);
    sort(query.begin(), query.end(), [](node a, node b)
         {
        if(a.l/blk != b.l/blk)
        return a.l/blk < b.l/blk;
        return a.r<b.r; });
    solve(query);
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}