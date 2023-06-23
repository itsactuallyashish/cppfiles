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
void dfs1(int v,int p,vector<ll>&ans,vector<ll>&dp,ll depth,vector<vector<int>>&adj){
    ans[1]+=depth;
    dp[v]=1;
    for(auto ch:adj[v]){
        if(ch==p) continue;
        dfs1(ch,v,ans,dp,depth+1,adj);
        dp[v]+=dp[ch];
    }
}
void dfs2(int v,int p,vector<vector<int>>&adj,vector<ll>&ans,vector<ll>&dp){
    for(auto ch:adj[v]){
        if(ch==p)continue;
        ans[ch]=ans[v]+(n-dp[ch]) - dp[ch];
        //(n-dp[i]) is the children in another subtree and dp[i] in current subtree 
        dfs2(ch,v,adj,ans,dp);
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
        vector<ll>ans(n+1,0);
        vector<ll>dp(n+1,0);
        dfs1(1,-1,ans,dp,0,adj);
        dfs2(1,-1,adj,ans,dp);
        for(int i =1;i<=n;i++){
            put(ans[i]);
        }
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
