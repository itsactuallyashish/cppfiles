#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=1e5+1;
vector<int>adj[mxn][2];
bool vis[mxn];
void dfs(int v,int to){
    vis[v]=1;
    for(auto ch:adj[v][to]){
        if(vis[ch]) continue;
        dfs(ch,to);
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout << "NO" << '\n';
                cout<<1<<" "<<i+1;
                return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(0,1);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout << "NO" << '\n';
                cout<<i+1<<" "<<1;
                return 0;
        }
    }
    cout << "YES" << '\n';

}