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

int n;

void dfs(int v,int p,vector<ll>&dp,vector<vector<int>>&adj){
    for(auto ch:adj[v]){
        if(ch==p) continue;
        dp[ch]=dp[v]+1;
        dfs(ch,v,dp,adj);
    }
}
void solve() {
        see(n);
        vector<vector<int>>adj(n+2);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll>depth(n+1,0);
        dfs(1,-1,depth,adj);
        int mxdepth=INT_MIN,mxA=-1;
        for(int i=1;i<=n;i++){
                if(mxdepth < depth[i]){
                    mxA=i;
                    mxdepth=depth[i];
                }
                depth[i]=0;
        }
        depth[0]=0;
        dfs(mxA,-1,depth,adj);
        int mxB=-1;
        mxdepth=-1;
         for(int i=1;i<=n;i++){
                if(mxdepth < depth[i]){
                    mxB=i;
                    mxdepth=depth[i];
                }
        }
        put(mxdepth);
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
