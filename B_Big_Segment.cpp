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
        vector<pair<ll,ll>>pr;
        ll mx=LONG_LONG_MIN;
        ll mn=LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            ll x,y;see(x,y);
            mn=min(mn,x);
            mx=max(mx,y);
            pr.push_back({x,y});
        }
        for(int i=0;i<n;i++){
            if(pr[i].first==mn && pr[i].second==mx){
                put(i+1);return;
            }
        }
        put(-1);
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
