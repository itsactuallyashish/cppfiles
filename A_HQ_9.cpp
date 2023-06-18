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
            string ch;
            see(ch);
            bool flag=0;
            for(int i=0;i<ch.size();i++){
                if(ch[i]=='H' || ch[i]=='Q') flag |=1;
                else if(ch[i]=='9') flag|=1;
            }
            if(flag) cout<<"YES";
            else cout<<"NO";
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
