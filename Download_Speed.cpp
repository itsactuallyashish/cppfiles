#include<bits/stdc++.h>
using namespace std;
#define ll long long
using matrix=vector<vector<ll>>;
matrix adj,g;
int n;
bool vis[501];
int pa[501];
bool reachable(){
    memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int rem=q.front();q.pop();
        for(int x=0;x<adj[rem].size();x++){
                if(!vis[x] && adj[rem][x]>0){
                        vis[x]=1;
                        pa[x]=rem;
                        q.push(x);
                }
        }
    }
    return vis[n-1];
}
int main(){
    int m;cin>>n>>m;
    // g.assign(n,vector<ll>(n));
    adj.assign(n,vector<ll>(n));
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ll w; cin>>w;
        a--,b--;
        adj[a][b]+=w;
    }
    ll mxflow=0;
    while(reachable()){ 
        ll flow=1e18;
        for(int i=n-1;i!=0;i=pa[i]){
            flow=min(flow,adj[pa[i]][i]);
        }
         mxflow+=flow;
        for(int i=n-1;i!=0;i=pa[i]){
            adj[pa[i]][i]-=flow;
            adj[i][pa[i]]+=flow;
        }
    }
    cout<<mxflow;
}