#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=1e5+2;
stack<int>s;
vector<bool>vis;
vector<int>kingdom;
    void dfs(int v,vector<vector<int>>& adj){
        vis[v]=1;
        for(auto ch:adj[v]){
            if(vis[ch]) continue;
            dfs(ch,adj);
        }
        s.push(v);
    }
    void fill(int v,vector<vector<int>>& adj,int &res){
        kingdom[v]=res;
        for(auto ch:adj[v]){
            if(kingdom[ch]!=-1) continue;
            fill(ch,adj,res);
        }
    }
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i])
              dfs(i,adj);
        }
        vis.assign(n+1,false);
        kingdom.assign(n+1,-1);
        int res=0;
        while(!s.empty()){
            int rem=s.top();s.pop();
            if(kingdom[rem]==-1){
                res++;
                fill(rem,g,res);
            }
        }
        cout<<res<<"\n";
        for(int i=0;i<n;i++)
         cout<<kingdom[i]<<" ";
}