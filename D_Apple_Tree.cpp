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


int dfs(int v,int p,vector<ll>&c,vector<vector<int>>&adj){
    int cnt=0;
    for(auto c:adj[v]){
        if(c==p) continue;
        cnt++;
    }
    if(cnt==0){
        return c[v]=1;
    }
    for(auto x:adj[v]){
        if(x==p) continue;
        c[v]+=dfs(x,v,c,adj);
    }
    return c[v];
}
void solve() {
        int n;see(n);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int a,b;see(a,b);a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll>c(n+1,0);
        dfs(0,-1,c,adj);
        int m;
        see(m);
        while(m--){
            int a,b;see(a,b);
            a--,b--;
            ll ans = c[a]*c[b];
            putl(ans);
        }
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}
