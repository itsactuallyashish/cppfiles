#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
const int mx=1e6;
vector<vector<int>> adj(mx);
vector<int> lead;
int n,m;
vector<bool> vis(mx,false);
vector<int> path(mx,-1);
queue<int> q;
void bfs(){
    while(!q.empty()){
        int j=q.front();
        q.pop();
        for(auto &y:adj[j])
        if(!vis[y]){
            vis[y]=1;
            q.push(y);
            path[y]=j;
        }
    }

}

int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    q.push(1);
    bfs();
    vector<int>ans;
    if(!vis[n]) cout<<"IMPOSSIBLE";
    else{
        int p=n;
        ans.push_back(p);
        while(p!=1){
            
            p=path[p];
            ans.push_back(p);
        }

    cout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto & elem :ans) cout<<elem<<" ";
    }

}