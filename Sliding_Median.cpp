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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using indexed_set= tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
    ll n,k;see(n,k);
    ll val[n];
        for(int i=0;i<n;i++) cin>>val[i];
    
    indexed_set<pair<ll,int>>st;
    for(int i=0;i<k;i++)
      st.insert({val[i],i});
      put(st.find_by_order((k-1)/2)->first );
     for(int i=1;i<n-k+1;i++){
        st.erase({val[i-1],i-1});
        st.insert({val[i+k-1],i+k-1});
        put(st.find_by_order((k-1)/2)->first);
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
