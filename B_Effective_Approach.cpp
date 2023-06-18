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
        int n;
        see(n);
        vector<ll>val(n);
        for(auto &v:val) see(v);
        map<int,int>mp;
        int cnt=0;
        for(auto v:val){
            cnt++;
            mp[v]=cnt;
        }
        map<int,int>mp2;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt++;
            mp2[val[i]]=cnt;
        }
        int q;see(q);
        ll cnt1=0,cnt2=0;
        while(q--){
            ll x;see(x);
            cnt1+=mp[x];
            cnt2+=mp2[x];
        }
        put(cnt1,cnt2);
        
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
