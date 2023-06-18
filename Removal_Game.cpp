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
        vector<vector<ll>>interval_diff(n,vector<ll>(n,0));
        ll sum=0;
        ll val[n];
        for(int i=0;i<n;i++){
            see(val[i]);
            interval_diff[i][i]=val[i];
            sum+=val[i];
        }
        for(int left=n-1;left>=0;left--){
            for(int right =left+1;right<n;right++){
                interval_diff[left][right] = max({val[left] - interval_diff[left+1][right], val[right] - interval_diff[left][right-1]});
            }
        }
        put((sum + interval_diff[0][n-1] )/ 2);
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
