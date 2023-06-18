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
    ll n,k;see(n,k);
    ll val[n];
    for(int i=0;i<n;i++) cin>>val[i];
    ll pre=0;
    unordered_map<ll,int>seen;
    ll cnt=0;
    seen[0]=1;
    for(int i=0;i<n;i++){
        pre+=val[i];
        cnt+=seen[pre-k];
        seen[pre]++;

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
