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
            ll n;see(n);
            vector<ll>a(n);
            for(auto &x:a) see(x);
            if(a.size()!=a[0]){
                put("NO");return;
            }
            vector<ll>ans(a[0]+1);
            for(int i=0;i<n;i++) ans[a[i]]+=1;
            for(int i=a[0];i>0;i--){
                ans[i-1]+=ans[i];
            }
            for(int i=0;i<n;i++){
                if(a[i]==ans[i+1]) continue;
                else {
                    put("NO");return;
                }
            }
            put("YES");
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
