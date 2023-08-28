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
constexpr int mxn=2e5+9;
vector<ll>value(mxn,0);
vector<int>adj[mxn];
ll dp[mxn][3];

void dfs(int v=1,int p=-1){
    for(auto to:adj[v]){
        if(to==p) continue;
        dfs(to,v);
          dp[v][2]+=max(dp[to][1],dp[to][2]);

    }
    for(auto to :adj[v]){
        if(to==p) continue;
        dp[v][1] =max(dp[to][2]+1+dp[v][2]-max(dp[to][1],dp[to][2]),dp[v][1]);
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
        put(max(dp[1][1],dp[1][2]));
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
