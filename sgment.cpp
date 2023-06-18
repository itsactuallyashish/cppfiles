#include<bits/stdc++.h>
#include<vector>
using namespace std;
 int n;
 const int maxN=1e7;
#define ll long long
 ll st[maxN],d[maxN];
void build(int si, int ss, int se,vector<long long>& ar)
{
    if (ss == se)
    {
        st[si] = ar[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * si, ss, mid,ar);
    build(2 * si + 1, mid + 1, se,ar);
    st[si] = st[2 * si] + st[2 * si + 1];
}
void update(ll si, ll ss, ll se, ll qs, ll qe, ll val)
{
    if (d[si] != 0)
    {
        ll dx = d[si];
        d[si] = 0;
        st[si] += dx * (se - ss + 1);
        if (se != ss)
            d[2 * si] += dx, d[2 * si + 1] += dx;
    }
    if (ss > qe || qs > se)
        return;
    if (ss >= qs && se <= qe)
    {
        ll dx = (se - ss + 1) * val;
        st[si] += dx;
        if (ss != se)
            d[2 * si] += val, d[2 * si + 1] += val;
        return;
    }
   ll mid = (se + ss) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);
    st[si] = st[2 * si] + st[2 * si + 1];
}
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{

    // check the lazy tree if there are any pending update handle them first;
    if (d[si] != 0)
    {
        ll dx = d[si];
        d[si] = 0;
        st[si] += (1ll)*dx * (se - ss + 1);
        if (se != ss)
            d[2 * si] += dx, d[2 * si + 1] += dx;
    }

    if (qe < ss || qs > se)
        return 0;
    if (ss >= qs && se <= qe)
        return st[si];
   ll mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}
 
int main(){
   int q;
    cin>>n>>q;
     vector<ll> ar(n);
     for(int i=1;i<n+1;i++) cin>>ar[i];
    //  for(auto &elem:ar) cin>>elem;
    //  for(ll i=0;i<n;i++) st[i+n]=ar[i];
    //  for(ll i=n-1;i>=1;i--) st[i]=st[2*i]+st[2*i+1];
   build(1,1,n,ar);
        for(ll i=0;i<q;i++){
            int code;
            cin>>code;
            if(code==1){
               ll l,r;
               ll val;
                cin>>l>>r>>val;
                
                update(1,1,n,l,r,val);
            }
            else{
                int k;
                cin>>k;
                
                cout<<query(1,1,n,k,k)<<"\n";
            }
        }
        
}