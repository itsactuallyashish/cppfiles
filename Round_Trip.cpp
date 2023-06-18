#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
const int mx=1e6;
vector<vector<int>>adj(mx);
vector<bool> vis(mx,false);
int n,m,ev,sv;
vi parent(mx,-1),an(mx);
bool dfs(int v,int par){
    parent[v]=par;
    vis[v]=1;
    for(auto &ch:adj[v]){
        if(ch==par) continue;
        if(vis[ch]){
            sv=ch;
            ev=v;
            return true;
        }
        if(!vis[ch]){
            if(dfs(ch,v))
              return true;
        }
    }
   return false;
}
bool check(){
    for(int i=1;i<=n;i++){
        if(!vis[i])
          if(dfs(i,-1))
             return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    if(check()){
    int t=ev;
       int xx=parent[t];
        //  ans.push_back(parent[t]);
        while(sv!=ev){
           ans.push_back(parent[ev]);
           ev=parent[ev];
        }
         ans.push_back(t);
         ans.push_back(xx);
         reverse(ans.begin(),ans.end());
         cout<<ans.size()<<"\n";
         for(auto &el :ans) cout<<el<<" ";
    }
    else {
        cout<<"IMPOSSIBLE";
    }
}