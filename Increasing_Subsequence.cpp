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
const int mx=2e5+8;
int dp[mx];
void solve() {
        int n;see(n);
        int val[n];
        vector<ll>lis;
        for(int i=0;i<n;i++) see(val[i]);
        for(int i=0;i<n;i++){
            if(lis.empty() || lis.back()<val[i]){
                lis.push_back(val[i]);
            }else{
                auto it = lower_bound(all(lis),val[i]);
                if(it!=lis.end())
                 *it = val[i];
            }
        }
        put(lis.size());
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
