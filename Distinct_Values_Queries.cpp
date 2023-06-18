#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
int blk = 700;
 int freq[1000006];
const int mx = 2e5 + 5;
ll v[mx];
int ans[mx];
struct node
{
    int in, l, r;
};
int cnt = 0;

void add(int i)
{
     
    freq[v[i]]++;
   
    if (freq[v[i]]== 1)
        cnt++;
}
void erase(int i)
{
    
    freq[v[i]]--;
    if (freq[v[i]] == 0)
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
    fast_io;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
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

        // cordinate compression
        unordered_map<ll, ll> mp;
        vector<ll>rank;
        for(int i=0;i<n;i++) rank.push_back(v[i]);
        sort(rank.begin(),rank.end());
        rank.erase(unique(rank.begin(),rank.end()),rank.end());
        for(int i=0;i<rank.size();i++){
            mp[rank[i]]=i;
        }
        for(int i=0;i<n;i++){
            auto it=mp.find(v[i]);
            v[i]=it->second;
        }
        
    solve(query);
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}