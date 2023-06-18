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

struct range{
        ll l,r,in;
        bool operator<(const range &other)const{
            return l==other.l?r>other.r:l<other.l;
        }
};
void solve() {
  int n;see(n);
  vector<range>ranges;
  ll a,b;
  for(int i=0;i<n;i++){
    see(a,b);
    ranges.push_back({a,b,i});
  }
  sort(all(ranges));
  ll maxend=0;
  vector<bool>contained(n,false),contains(n,false);
  for(int i=0;i<n;i++){
     if(ranges[i].r<=maxend)
        contained[ranges[i].in]=true;
    maxend= max(maxend,ranges[i].r);
  }
  ll minend=(1<<30);
  for(int i=n-1;i>=0;i--){
     if(ranges[i].r>=minend)
        contains[ranges[i].in]=1;
    minend= min(minend,ranges[i].r);
  }
  for(int i=0;i<n;i++) put(contains[i]);
  cout<<'\n';
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
