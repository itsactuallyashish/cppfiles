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


void solve() {
             int n;see(n);
                     vector<ll>v(n);
                     for(auto &in :v){
                        see(in);
                     }
            vector<int>pre(n+2,0),pre2(n+2,0);
            pre[0]=0;
            for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i-1];
            sort(all(v));
            pre2[0]=v[0];
             for(int i=1;i<=n;i++) pre2[i]=pre2[i-1]+v[i-1];
            int m;see(m);
            while(m--){
                int t,l,r;
                see(t,l,r);
                if(t==1){
                    putl(pre[r]-pre[l-1]);
                }else putl(pre2[r]-pre2[l-1]);
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
