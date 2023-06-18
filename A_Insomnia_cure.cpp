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
        int k,l,m,n,d;
        see(k,l,m,n,d);
        int x[d+1]={0};
        for(int i=k;i<d+1;i+=k){
             x[i]=1;
        }
        for(int i=l;i<d+1;i+=l){
             x[i]=1;
        }
        for(int i=m;i<d+1;i+=m){
             x[i]=1;
        }
        for(int i=n;i<d+1;i+=n){
             x[i]=1;
        }
        int cnt=0;
        for(int i=1;i<=d;i++){
            if(x[i])
              cnt++;
        }
        put(cnt);
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
