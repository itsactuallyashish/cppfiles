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
#define int long long
const int md=(1e9+7);
const int mx=(2e5+100);
int inv[mx],fac[mx];
int sz[mx];
int n,k;
vector<int>g[mx];
ll ans=0;
int binex(int a,int b){
    int res=1;
    while(b>0){
        if(b&1) res = res * a %md;
        a = a * a %md;
        b>>=1;
    }
    return res;
}
int in(int n){
    return binex(n,md-2);
}
int c(int a,int b){
    if(b>a) return 0;
    return fac[a]*inv[b] %md * inv[a-b]%md;
}

void dfs(int v,int p){
    sz[v]=1;
    for(auto to :g[v]){
        if(to==p) continue;
        dfs(to,v);
        (ans +=c(sz[to],k/2)*c(n-sz[to],k/2))%=md;
        sz[v]+=sz[to];
    }
}
void solve() {
    fac[0]=1;
    inv[0]=1;
      for(int i=1;i<mx;i++){
        fac[i]=(fac[i-1]*i)%md;
        inv[i]= binex(fac[i],md-2);
      }  
    see(n,k);
    for(int i=0;i<n-1;i++){
            int x,y;
            see(x,y);
            x--,y--;
            g[x].push_back(y);
            g[y].push_back(x);
    }
    if(k&1){
        cout<<1;
        return;
    }
    dfs(0,-1);
   (ans *=in(c(n,k)))%=md;
   cout<<(ans+1)%md;
   
   
}
  
    
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
