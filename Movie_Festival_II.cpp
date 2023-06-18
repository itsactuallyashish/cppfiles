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
    int n,k;
    see(n,k);
     vector<pair<ll,ll>>movies(n);
        for(int i=0;i<n;i++){
            see(movies[i].second,movies[i].first);
        }
        sort(all(movies));
      multiset<ll>endtimes;
      for(int i=0;i<k;i++) endtimes.insert(0);
      ll cnt=0;
      for(int i=0;i<n;i++){
         auto it = endtimes.upper_bound(movies[i].second);
         if(it ==endtimes.begin()) continue;
        endtimes.erase(--it);
        endtimes.insert(movies[i].first);
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
