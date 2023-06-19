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
            ll y,k,n;
            see(y,k,n);
            if(n-1<y) {
                put(-1);return;
            }
            vector<int>ans;
            for(int i=y/k+1;i<=n/k;i++){
                ans.push_back(k*i-y);
            }
            if(ans.size()==0){
                put(-1);
            }
            else {
                for(auto in :ans){
                    put(in);
                }
            }
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
