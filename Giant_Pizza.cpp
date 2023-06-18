#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
const int mxn=2e5+4;
vector<int>who(mxn,-1);
vector<int>adj[mxn],g[mxn];
stack<int>s;
vector<bool>vis(mxn,false);
void dfs(int u){
    vis[u]=1;
    for(auto x:adj[u]){
        if(!vis[x]) 
            dfs(x);
    }
    s.push(u);
}
void scc(int u,int a){
    who[u]=a;
    for(auto x:g[u]){
        if(who[x]==-1)
          scc(x,a);
    }
}
int main(){
    int n,m;see(n,m);
        char x,y;
    for(int i=0,a,b;i<n;i++){
        see(x,a,y,b);
        a=2*a,b=2*b;
        if(x=='-')  a=a^1;
        if(y=='-')  b=b^1;
        adj[a^1].push_back(b);
        adj[b^1].push_back(a);
        g[b].push_back(a^1);
        g[a].push_back(b^1);

    }
    for(int i=2;i<=2*m+1;i++){
        if(!vis[i])
                dfs(i);
    }
     int cnt=1;
    while(!s.empty()){
        int r=s.top();s.pop();
        if(who[r]==-1){
            scc(r,cnt);
            cnt++;
        }
    }
    string res="";
    for(int i=1;i<=m;i++){
        if(who[2*i+1]==who[2*i]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        else if(who[2*i+1]<who[2*i]){
             res+='+';
        }
        else res+='-';
    }
    for(auto ch:res)
     put(ch);
    
}

