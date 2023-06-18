#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const int MAXN = 3e6;
long long  seg[4 * MAXN];
int n;
#define ll long long

ll query(int l,int r){
    ll res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res+=seg[l++];
        if(r&1) res+=seg[--r];
    }
    return res;
}
void update(int in,int val){
    in+=n;
    seg[in]=val;
    while(in>=1){
        in>>=1;
        seg[in]=seg[2*in]+seg[2*in+1];

    }
    return;
}
void build(vector<int> ar){
for(int i=0;i<n;i++) seg[i+n]=ar[i];
    for(int i=n-1;i>=1;i--) seg[i]=seg[2*i]+seg[2*i+1];
}
int main()
{
    fast_io;
    cin >> n;
    vector<long long> vi(n);
    vector<int> present(n + 1, true);
    
    build(present);
    
 for (auto &elem : vi) cin >> elem;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        int lo = 0, hi = n - 1;
        while (lo != hi)
        {
            int mid = (lo + hi) / 2;
            long long till_mid = query(0,mid);
            if (till_mid > x)
                hi = mid - 1;
            else if (till_mid < x)
                lo = mid + 1;
            else
            {
                if (present[mid])
                {
                    lo = mid;
                    break;
                }
                else
                    hi = mid - 1;
            }
        }
        present[lo] = 0;
        update( lo, 0);
        cout << vi[lo] << ' ';
    }
}