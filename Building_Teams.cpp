#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
const int mx=1e6;
vector<vector<int>>adj(mx);
vector<bool> vis(mx,false);
int n,m;
vi color(mx,-1);
bool dfs(int v,int c,int parent){
    vis[v]=1;
    color[v]=c;
    int cl=1;
    if(c==1) cl=2;
    
    for(auto &ch:adj[v]){
        if(ch!=parent){
            if(color[ch]==-1) 
                if(!dfs(ch,cl,v)) return false;
            if(color[ch]==c) return false;
        
        }
    }
    return true;
}
bool color_all(){
    for(int i=1;i<=n;i++){
        if(!vis[i])
          if(! dfs(i,1,-1)) return false;
    }
    return true;

}

int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(int i=1;i<=n;i++){
    //     for(auto elem:adj[i]) cout<<elem<<" ";
    //     cout<<endl;
    // }
    if(color_all()){
        for(int i=1;i<=n;i++)
        cout<< color[i]<<" ";
    }
    else {
        cout<<"IMPOSSIBLE";
    }
}