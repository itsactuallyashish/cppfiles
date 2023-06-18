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
const ll md = (10e8) + 7;
ll binex ( int a,int b){
    ll res=1;
    while(b>0){
        if(b&1) res = res * a %md;
        a= (ll)a * a %md;
        b>>=1;
    }
    return res;
}
void solve() {
            int n;see(n);
            ll ssum = (n * (n+1))/2;
            if(ssum&1){
                put(0);
                return;
            }
            int sum = ssum/2;
            vector<int>dp(sum+1,0);
            dp[0]=1;
            for(int i=1;i<=n;i++){
                    for(int s=sum ;s>=i;s--){
                        dp[s]  = (dp[s] + dp[s-i])%md;
                    }
            }
            put((dp[sum] * binex(2,md-2))%md);
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
