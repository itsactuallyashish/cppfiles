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
        ll a;see(a);
        ll lo=1,hi=INT_MAX;
        if(a==1) {
            put(2);
            return;
        }
        ll ans=-1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            ll val = (mid * (mid -1))/2;
            if(val <=a){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        ans = ans + (a - (ans * (ans-1)/2));
        put(ans);
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
