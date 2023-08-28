#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
int n;
constexpr int mxn=2e5+9;
vector<ll>value(mxn,0);
vector<int>adj[mxn];
int d[mxn];
constexpr int lg=19;
int up[lg+2][mxn];
void dfs(int v=1,int p=-1){
    up[0][v]=p;
    for(auto c:adj[v]){
        if(c==p) continue;
        d[c]=d[v]+1;
        dfs(c,v);
    }
}

void init(){
        for(int i=1;i<=lg;i++){
            for(int x=1;x<=n;x++){
                up[i][x]=up[i-1][up[i-1][x]];
            }
        }
}
int lca(int a,int b ){
        if(d[a]<d[b]) swap(a,b);
         ll diff=d[a]-d[b];
        for(ll mask=lg;mask>=0;mask--){
            if((1<<mask)&diff){
                a=up[mask][a];
            }
        }
        if(a==b){
            return a;
        }else{
            for(ll mask=lg;mask>=0;mask--){
                if(up[mask][a]!=up[mask][b]){
                    a=up[mask][a];
                    b=up[mask][b];
                }
            }
            return up[0][a];
        }
}
void sol(int v,int p){
    for(auto c:adj[v]){
        if(c==p) continue;
        sol(c,v);
        value[v]+=value[c];
    }
}
void solve() {
        int q;
        see(n,q);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        d[1]=0;
        dfs();
        init();
        while(q--){
            int a,b;
            see(a,b);
            value[a]+=1;
            value[b]+=1;
            int x=lca(a,b);
            value[x]-=1;
            if(up[0][x]!=-1) value[up[0][x]]-=1;
        }
        sol(1,-1);
        for(int i=1;i<=n;i++)
            put(value[i]);

}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
