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
constexpr int lg=20;
int up[20][mxn];
void solve() {
    int n,q;see(n,q);
    up[0][1]=-1;
    for(int i=2;i<=n;i++){
            int x;see(x);
            up[0][i]=x;
    }
    for(int x=2;x<=n;x++){
        for(int i=1;i<=lg;i++){
            up[i][x]=up[i-1][up[i-1][x]];
        }
    }
    while(q--){
        int x,k;
        see(x,k);
        for(int mask=lg;mask>=0;mask--){
            if((1<<mask)&k){
                // deb(mask);
                x=up[mask][x];
            }
        }
        if(x==0)putl(-1);
         else putl(x);
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
