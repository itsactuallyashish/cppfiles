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
            if(n==3){
                    put("NO");
                    return;
            } 

            for(int k=2;k+k*k<=n;k++){
                ll ans=1;
                ll t=k;
                 ans+=t;
                while(ans+t*k<=n){
                    ans+=t*k;
                    t=t*k;
                }
                if(ans==n){
                    put("YES");
                    // deb2(k,t);
                    return;
                }
            }
            put("NO");
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
