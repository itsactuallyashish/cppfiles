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
        vector<ll>val(n);
        for(auto &ch:val){
            cin>>ch;
        }
        ll mn=LONG_LONG_MAX;
        for(int i=0;i<n;i++)
          mn=min(mn,val[i]);
        int cnt=0;
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(val[i]==mn){
                    cnt++;
                    idx=i+1;
            } 
        }
        if(cnt==1){
            put(idx);
        }
        else cout<<"Still Rozdil";
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
