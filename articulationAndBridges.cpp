#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int tmt=0,cntt=0;
int dis[N];
vector<set<int>>brd;
std::vector<int>low(N,INT_MAX);
bool vis[N],ap[N];
int n,m;
std::vector<int>adj[N];

 void dfs(int x,int par){
    vis[x]=1;
    dis[x]=low[x]=tmt;
    tmt++;
    for(auto e:adj[x]){
        if(par==e) continue;
        else if(vis[e]){
            low[x]=std::min(low[x],dis[e]);
        }
        else{
                dfs(e,x);
                if(par==-1) cntt++;
                low[x]=std::min(low[x],low[e]);
                if(par!=-1){
                        if(low[e]>=dis[x]) ap[x]=1;
                        
                }else{
                        if(cntt>1) ap[x]=1;
                        
                }
                if(low[e]>dis[x]){
                    set<int>s;
                    s.insert(x);
                    s.insert(e);
                    brd.push_back(s);
                } 
        }
    }


 }
int main(){
    std::cin>>n>>m;
    int a,b;
    int cnt=0;
    for(int i=0;i<m;i++){
           std::cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);

            
    }
    dfs(0,-1);
     for(int i=0;i<n;i++)
        if(ap[i]==1) cnt++;
    cout<<cnt<<"\n";
    for(int i=0;i<n;i++)
        if(ap[i]==1) cout<<i<<" ";
    cout<<"\n";
    cnt=0;
    for(auto in:brd)
       cnt++;
    cout<<cnt<<"\n";
    reverse(brd.begin(),brd.end());
    for(auto in:brd){
        for(auto el:in){
            cout<<el<<" ";
        }
        cout<<"\n";
    }

}