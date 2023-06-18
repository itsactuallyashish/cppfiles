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
        int cnt=0;
        for(int i=0;i<n;i++){
            int x;see(x);
            cnt+=x;
        }
        int ans=0;
        if(n==1){
            if(cnt&1) put(3);
            else put(2);
            return;
        }
        for(int i=1;i<=5;i++){
            if((cnt+i)%(n+1)!=1) ans++;
        }
      
        put(ans);
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
