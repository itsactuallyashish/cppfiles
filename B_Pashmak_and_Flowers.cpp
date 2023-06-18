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
            vector<ll>b(n);
            for(auto &in :b) see(in);
            sort(all(b));
            unordered_map<ll,ll>mp;
            for(int i=0;i<n;i++){
                mp[b[i]]++;
            }
            b.erase(unique(all(b)),b.end());
            ll mx=b.back() - b[0];
            vector<pair<ll,ll>>pr;
            for(int i=0;i<=b.size()/2;i++){
                if(b[n-i-1]-b[i]==mx){
                    pr.push_back({b[n-i-1],b[i]});
                }
            }
            ll cnt=0;
            for(auto p:pr){
                if(p.first==p.second){
                    ll x= mp[p.first];
                    cnt+=x*(x-1)/2;
                }else
                cnt+=mp[p.first]*mp[p.second];
            }
            put(mx,cnt);
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
