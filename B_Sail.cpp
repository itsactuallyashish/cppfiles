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
#define int long long

void solve() {
    int t,x,y,p,q;
    see(t,x,y,p,q);
    string s;see(s);
    t=0;
     for(auto ch:s){
        if(ch=='N'&& q>y){
            y++;
        }
        if(ch=='E' && p>x) x++;
        if(ch=='W'&& x>p) x--;
        if(ch=='S'&&q<y) y--;
        t++;
        if(x==p && y==q){
            put(t);
            return;
        }

     }
     put(-1);

}
  
    
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
