#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


void solve() {
     int n;see(n);
     ll a[n];
     for(int i=0;i<n;i++) see(a[i]);
     int i=0,j=0;
     set<ll>st;
     int ans=0;
     while(i<n&& j<n){
        while(j<n && !st.count(a[j])){
            st.insert(a[j]);
            ans=max(ans,j-i+1);
            j++;
        }
        while(j<n && st.count(a[j])){
            st.erase(st.find(a[i]));
            i++;
        }
     }
     cout<<ans;
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
