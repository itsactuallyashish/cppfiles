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

constexpr int mxn=5e4+5;
vector<int>adj[mxn];
ll dp[mxn][505];
ll ans=0;
int k;
void dfs(int v=1,int p=-1){
        dp[v][0]=1;
        for(auto c:adj[v]){
            if(c==p) continue;
            dfs(c,v);
            ans+=dp[c][k-1];
            // update the answer first
            for(int j=0;j<k-1;j++){
               ans+= dp[v][k-1-j]*dp[c][j];
            }
            // include the values of c in v
            for(int j=1;j<=k;j++)
                    dp[v][j]+=dp[c][j-1];
        }
}
void solve() {
             int n;
        see(n,k);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs();
       put(ans);
        
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
