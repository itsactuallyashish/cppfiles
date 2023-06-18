#include<bits/stdc++.h>
// using namespace std;
const int N=1e6+5;
int tm=0,count=0;
int dis[N];
std::vector<int>low(N,INT_MAX);
bool vis[N],ap[N];
int n,m;
std::vector<int>adj[N];

 void dfs(int x,int par){
    vis[x]=1;
    dis[x]=low[x]=tm;
    tm++;
    for(auto e:adj[x]){
        if(par==e) continue;
        else if(vis[e]){
            low[x]=std::min(low[x],dis[e]);
        }
        else{
                dfs(e,x);
                if(par==-1) count++;
                low[x]=std::min(low[x],low[e]);
                if(par!=-1){
                        if(low[e]>=dis[x]) ap[x]=1;
                }else{
                        if(count>1) ap[x]=1;
                }
        }
    }


 }
int main(){
    std::cin>>n>>m;
    int a,b;
    int cnt=0;
    for(int i=0;i<n;i++){
           std::cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
        if(ap[i]==1) cnt++;
   std::cout<<cnt;
}