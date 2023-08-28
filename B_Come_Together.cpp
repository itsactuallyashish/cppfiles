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
        ll x,y;
        see(x,y);
        ll a,b;
        see(a,b);
        ll p,q;
        see(p,q);
        ll cnt=0;
        if(x<=a && x<=p){
            cnt+=min(p,a)-x;
        }else if(a<x && p<x){
                cnt += abs(max(a,p)-x);
        }
        if(y<=q && y<=b){
            cnt+=min(q,b)-y;
        }else if(q<y && b<y){
             cnt += abs(max(q,b)-y);
        }
        put(cnt+1);
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
