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
#define inf 1e9
pair<ll,ll> dp[1<<20];
void solve() {
        ll n,x;
        see(n,x);
        int limit = 1<<n;
        ll val[n];
        for(int i=0;i<n;i++) see(val[i]);
        dp[0]={1,0};
        for(int mask=1;mask<limit;mask++){
            pair<ll,ll> pr ={inf,inf};
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    auto res = dp[(1<<i)^mask];// removing the person and calculating optimal rides
                    if(res.second+val[i]<=x){
                        res.second+=val[i];
                    }else{
                        res.first+=1;
                        res.second=val[i];
                    }
                    pr=min(pr,res);
                }
            }
                dp[mask]=pr;
        }
        put(dp[limit-1].first);
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
