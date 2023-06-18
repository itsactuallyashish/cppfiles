#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
#define ll long long
const int mxn=2e6+9;
vector<int>adj[mxn];
bool vis[mxn];
vector<int>order;
int eu[mxn],ev[mxn];
void dfs(int u=1){
    while(adj[u].size()){
        int x=adj[u].back();
        adj[u].pop_back();
        if(vis[x]) continue;
        vis[x]=1;
        dfs(eu[x]^ev[x]^u);
    }
    order.push_back(u);
}
int main(){
    int n,m;see(n,m);
    vector<int>deg(n+1,0);
    for(int i=0;i<m;i++){
        // int a,b; cin>>a>>b;
         see(eu[i],ev[i]);
        adj[eu[i]].push_back(i);
        adj[ev[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()&1){
            put("IMPOSSIBLE");
            exit(0);
        }
    }
    dfs();
    if(order.size()<m){
        cout<<"IMPOSSIBLE";return 0;
    }
    for(auto x:order) put(x);
    
}