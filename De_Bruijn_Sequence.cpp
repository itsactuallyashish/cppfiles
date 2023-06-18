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
void dfs(int u=0){
    while(adj[u].size()){
        int x=adj[u].back();
        adj[u].pop_back();
        if(vis[x]) continue;
        vis[x]=1;
        dfs(eu[x]^ev[x]^u);
    order.push_back(x);
    }
}

int main(){
    
    int n,m;see(n);
    m=1<<n;
    
    for(int i=0;i<m;i++){
        eu[i]=i/2;
        ev[i]=i&((1<<n-1)-1);
        adj[eu[i]].push_back(i);
    }
    dfs();
    for(int i=0;i<n-1;i++){
        cout<<0;
    }
    reverse(order.begin(),order.end());
    for(auto x:order)cout<<x%2;
}