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
        vector<ll>x(n),y(n),z(n);
        for(int i=0;i<n;i++){
            see(x[i],y[i],z[i]);
        }
        ll sumx=0,sumy=0,sumz=0;
        sumx=accumulate(all(x),0);
        sumy=accumulate(all(y),0);
        sumz=accumulate(all(z),0);
        if(sumz==0 && sumx==0 && sumy==0)
          put("YES");
        else put("NO");
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
