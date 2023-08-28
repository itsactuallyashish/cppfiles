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
        vector<string>s(3);
        for(auto &in:s){
            see(in);
        }
       char ch;
        if(s[0][0]==s[1][1] && s[0][0]==s[2][2]) ch=s[0][0];
        if(s[0][0]==s[1][0] && s[2][0]==s[0][0]) ch=s[0][0];
        if(s[1][0]==s[1][1] && s[1][0]==s[1][2]) ch=s[1][0];
        if(s[2][0]==s[2][1] && s[2][0]==s[2][2]) ch=s[2][0];
        if(s[0][0]==s[0][1] && s[0][0]==s[0][2]) ch=s[0][1];
        if(s[0][1]==s[1][1] && s[0][1]==s[2][1]) ch=s[0][1];
        if(s[0][2]==s[1][2] && s[0][2]==s[2][2]) ch=s[0][2];
        if(s[0][2]==s[1][1] && s[0][2] == s[2][0]) ch=s[0][2];


            
     
        if(ch=='+'|| ch=='X' || ch=='O') put(ch);
        else put("DRAW");
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
