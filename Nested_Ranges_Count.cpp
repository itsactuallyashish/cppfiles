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

struct range{
    ll l,r;
    int in;
    bool operator<(const range &other)const{
        return l==other.l?r>other.r:l<other.l;
    }
};
void solve() {
  int n;see(n);
  vector<range>ranges;
  for(int i=0;i<n;i++){
        ll a,b;
        see(a,b);
        ranges.push_back({a,b,i});
  }
  sort(all(ranges));
  indexed_set<pair<int,int>> st;
  vector<ll>contained(n,0),contains(n,0);
  for(int i=0;i<n;i++){
     st.insert({ranges[i].r,-1*i});
        contained[ranges[i].in]=st.size() - st.order_of_key({ranges[i].r,-1*i})-1;
  }
  st.clear();
  for(int i=n-1;i>=0;i--){
        st.insert({ranges[i].r,-1*i});
        contains[ranges[i].in]=st.order_of_key({ranges[i].r,-1*i});
  }
  for(int i=0;i<n;i++) put(contains[i]);
  cout<<"\n";
  for(int i=0;i<n;i++) put(contained[i]);

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
