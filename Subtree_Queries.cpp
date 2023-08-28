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
const int mxn=2e5+10;
ll val[mxn],flat[mxn];
vector<vector<int>>adj(mxn);
int timer=0;
int in[mxn];
int out[mxn];

void dfs(int v=1,int p=-1){
    in[v]=++timer;
    flat[in[v]]=val[v];
    for(auto ch:adj[v]){
        if(ch==p) continue;
        dfs(ch,v);
    }
    out[v]=timer;
}

ll t[2*mxn];
void update(int in,int val,int n){
            in+=n;
            t[in]=val;
            while(in>=1){
                in>>=1;
                t[in]=t[2*in]+t[2*in+1];
            }
}
ll sum(int l,int r,int n){
        ll res=0;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
                if(l&1) res+=t[l++];
                if(r&1) res+=t[--r];
        }
        return res;
}
void solve() {
        int n,q;
        see(n,q);
        for(int i=1;i<=n;i++) see(val[i]);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs();
        for(int i=1;i<=n;i++){
            update(i-1,flat[i],n);
        }

        while(q--){
            int type;
            see(type);
            if(type==2){
                int x;see(x);
                putl(sum(in[x]-1,out[x]-1,n));
            }else{
                int x;
                ll vv;
                see(x,vv);
                val[in[x]]=vv;
                update(in[x]-1,vv,n);
            }
        }
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
