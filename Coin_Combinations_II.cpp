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
const int md=1e9+7;

void solve() {
        int n,k;see(n,k);
        vector<ll>dp(k+1);
        dp[0]=1;
        vector<ll>val(n);
        for(auto &in :val) see(in);
        for(auto in:val){
            for(int t=1;t<=k;t++){
                if(t>=in)
                dp[t] = (dp[t]+dp[t-in])%md;
            }
        }
        put(dp[k]);
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
