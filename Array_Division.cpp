#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


void solve() {
    ll n,k;see(n,k);
    ll val[n];
    ll mxval=INT_MIN;
    for(int i=0;i<n;i++) see(val[i]),mxval=max(mxval,val[i]);
    ll low=mxval;
    ll high=1e18;
    ll mxsum=1e18;
    while(low<=high){
        ll mid = low + (high - low)/2;
        ll sum=0,blk=1;
        for(int i=0;i<n;i++){
            if(sum+val[i]>mid){
                sum=0;
                blk++;
            }
            sum+=val[i];
        }
        if(blk > k){
            low=mid+1;
        }else {
            mxsum= min ( mxsum,mid);
            high = mid-1;
        }
    }
    put(mxsum);
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
