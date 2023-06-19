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
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
        int n,m;see(n,m);
        string s;
        if(n>m){
            s.push_back('B');
            n--;
        }else if(m>n){
            s.push_back('G');
            m--;
        }
      
        for(int i=1;i<=2*min(n,m);i++){
            if(s.back()=='G') s.push_back('B');
            else s.push_back('G');
        }
     
        int x=min(n,m);
        n-=x;
        m-=x;
      
       while(n-->0) s.push_back('B');
       while(m-->0) s.push_back('G');
        put(s);
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
