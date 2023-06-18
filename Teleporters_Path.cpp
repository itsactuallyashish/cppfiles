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
    vector<int>in(n+1,0),out(n+1,0);
    for(int i=0;i<m;i++){
         see(eu[i],ev[i]);
        in[ev[i]]++;out[eu[i]]++;
        adj[eu[i]].push_back(i);
    }
    int start=-1,end=-1;
    for(int i=1;i<=n;i++){
        if(in[i]!=out[i]){
                if(in[i]==out[i]+1){
                    if(start==-1) start=i;
                    else {
                        cout<<"IMPOSSIBLE";return 0;
                    }
                }else if(in[i]==out[i]-1){
                    if(end==-1){
                        end=i;
                    }else {
                        cout<<"IMPOSSIBLE";return 0;
                    }
                }else{
                     cout<<"IMPOSSIBLE";return 0;
                }
        }
    }
    dfs(end);

    if(order.size()-1<m|| order.size()-1 <n-1){
        cout<<"IMPOSSIBLE";return 0;
    }
    reverse(order.begin(),order.end());
    for(auto x:order) put(x);
    
}