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
        if(n==0){
            put(0);return;
        }
        int mx=1;
        int h,m;
        see(h,m);
        int cnt=1;
        for(int i=1;i<n;i++){
            int h1,m1;
            see(h1,m1);
            if(h1==h && m1==m ){
                cnt++;
                mx = max(cnt,mx);
            }else {
                cnt=1;
                h=h1;m=m1;
            }
        }
        put(mx);
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
