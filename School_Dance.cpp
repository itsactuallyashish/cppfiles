#include<bits/stdc++.h>
using namespace std;
const int mxn=1e3+4;
const int inf = INT_MAX;
int nil=-1;
vector<int>adj[mxn];
int pair_U[591];
int pair_V[591];
int dis[mxn];
int n,m;
bool bfs(){
    queue<int>q;
        for(int x=0;x<n;x++){
            if(pair_U[x]==nil){
                dis[x]=0;
                q.push(x);
            }
            else dis[x]=inf;
        }
        dis[nil]=inf;
        while(!q.empty()){
            int rem=q.front();q.pop();
            if(dis[rem]<dis[nil]){
                for(auto v:adj[rem])
                if(dis[pair_V[v]]==inf){
                    dis[pair_V[v]]=dis[rem]+1;
                    q.push(pair_V[v]);
                }
            }
        }
        return dis[nil]!=inf;
}
bool dfs(int u){
        if(u==nil) return true;
        for(auto x:adj[u]){
            if(dis[pair_V[x]]==dis[u]+1){
                if(dfs(pair_V[x])){
                    pair_V[x]=u;
                    pair_U[u]=x;
                    return true;
                }
            }
        }
        dis[u]=inf;
        return false;
}
void hopkroft(){
    for(int x=0;x<n;x++) pair_U[x]=nil;
    for(int x=0;x<m;x++) pair_V[x]=nil;
    int matching=0;
    while(bfs()){
        for(int i=0;i<n;i++){
            if(pair_U[i]==nil)
                if(dfs(i))
                    matching ++;
        }
    }
    cout<<matching<<"\n";

}
int main(){
    int k;cin>>n>>m>>k;
    for(int i=0;i<k;i++){
            int a,b;cin>>a>>b;
            a--,b--;
            adj[a].push_back(b);
            
    }
    nil=n+1;
    hopkroft();
    for(int i=0;i<n;i++){
        if(pair_U[i]!=nil){
            cout<<i+1<<" "<<pair_U[i]+1<<"\n";
        }
    }
    
}