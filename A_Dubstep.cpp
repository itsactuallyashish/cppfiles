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
            string s;see(s);
            string res;
            for(int i=0;i<s.size();i++){
                if(i + 2 < s.size() && s[i]=='W'&& s[i+1]=='U'&& s[i+2]=='B'){
                    i=i+2;
                    if(res.back()!='1')
                      res.push_back('1');
                }else {
                    res.push_back(s[i]);
                }
            }
            s.clear();
            for(int i=0;i<res.size();i++){
                if(i==0 && res[i]=='1'){
                    continue;
                }else if(res[i]=='1') s.push_back(' ');
                else s.push_back(res[i]);
            }
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
