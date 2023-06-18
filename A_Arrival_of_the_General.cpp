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
            int x[n];
            for(int i=0;i<n;i++){
                see(x[i]);
            }
            int mx=INT_MIN;
            int swpl=0,swpr=0;
            for(int i=0;i<n;i++){
                if(mx<x[i]){
                    swpl=i;
                    mx=x[i];
                }
            }
            int mn=INT_MAX;
            for(int i=n-1;i>=0;i--){
                if(mn>x[i]){
                    swpr=i;
                    mn=x[i];
                }
            }
            if(swpr < swpl){
                swpr=n-swpr-1;
                swpr+=swpl-1;
            }else {
                swpr=n-swpr-1;
                swpr += swpl;
            }
            put(swpr);
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
