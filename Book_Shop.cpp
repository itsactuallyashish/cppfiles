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
        int n,m;see(n,m);
        vector<ll>prev(m+2,0),cur(m+2,0);
        int price[n],pages[n];
        for(int i=0;i<n;i++) see(price[i]);
        for(int i=0;i<n;i++) see(pages[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>=price[i-1])
                cur[j] = max(prev[j] ,prev[j-price[i-1]]+pages[i-1]);
                else cur[j] = prev[j];
            }
            prev=cur;
        }
        put(cur[m]);
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