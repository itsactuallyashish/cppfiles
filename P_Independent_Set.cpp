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
constexpr int md=1e9+7;
constexpr int mxn=2e5+9;
vector<int>adj[mxn];
ll dp[mxn][2];

void dfs(int v=1,int p=-1){
     dp[v][0]=1;
     dp[v][1]=1;
        for(auto c:adj[v]){
            if(c==p) continue;
            dfs(c,v);
            dp[v][0]=(dp[v][0]*(dp[c][0]+dp[c][1]))%md;
            dp[v][1]=(dp[v][1]*dp[c][0])%md;
        }
        
}
void solve() {
             int n;
        see(n);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs();
        ll ans = (dp[1][0]+dp[1][1])%md;
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
