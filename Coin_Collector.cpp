#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
struct scc{
    int n,cnt=0;
    vector<vector<ll>>adj,radj;
    vector<int>who,order;
    vector<bool>vis;
    void init(int _N){
        n=_N;
        adj.resize(n+1);radj.resize(n+1);who.resize(n+1,-1),vis.resize(n+1,false);
    }
    void add(int x,int y){
        adj[x].push_back(y);radj[y].push_back(x);
    }
    void dfs(int u){
        vis[u]=1;
        for(int x:adj[u]){
            if(!vis[x]) dfs(x);
        }
        order.push_back(u);
    }
    void dfs2(int u,int a){
        who[u]=a;
        for(auto x:radj[u]){
            if(who[x]==-1)
                    dfs2(x,a);
        }
    }
    void gen(){
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
        for(int i=order.size()-1;i>=0;i--){
            if(who[order[i]]==-1)
              dfs2(order[i],++cnt);
        }
        
    }
};
vector<vector<int>>g;
vector<bool>vis;
vector<ll>dp,grp;
ll dfs(int u){
    if(dp[u]!=-1) return dp[u];
    dp[u]=grp[u];
    for(auto x:g[u]){
        dp[u]=max(dp[u],dfs(x)+grp[u]);
    }
    return dp[u];
}
int main(){
    int n,m;cin>>n>>m;
    ll val[n];
    for(int i=0;i<n;i++){
            cin>>val[i];
    }
    scc w;
    w.init(n);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        a--,b--;
        w.add(a,b);
    }
    w.gen();
    grp.assign(w.cnt+1,0);
    for(int i=0;i<n;i++){
            grp[w.who[i]]+=val[i];
    }
    g.resize(w.cnt+1);
    dp.assign(w.cnt+1,-1);
    vis.assign(w.cnt+1,false);
    for(int i=0;i<n;i++){
        for(auto x:w.adj[i]){
            if(w.who[i]!=w.who[x]){
                g[w.who[i]].push_back(w.who[x]);
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=w.cnt;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;

    
}