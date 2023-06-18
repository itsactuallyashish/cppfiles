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

bool check(char ch){
    ch = toupper(ch);
    if(ch=='A'|| ch=='E'|| ch=='I'||ch=='O'|| ch=='U'||ch=='Y')
      return 1;
    return false;
}
void solve() {
        string s;see(s);
        string res;
        for(auto ch:s){
            if(check(ch)) continue;
            res.push_back('.');
            res.push_back(tolower(ch));
        }
        put(res);
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
