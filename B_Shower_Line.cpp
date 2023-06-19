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
    vector<int>a;
    int g[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
          see(g[i][j]);
    }
    for(int i=0;i<5;i++){
        a.push_back(i);
    }
    ll ans=0;
    
    do{
        ll mx=0;
        for(int i=0;i<5;i++){
            for(int j=i;j+1<5;j+=2){
                mx+=g[a[j]][a[j+1]]+g[a[j+1]][a[j]];
            }
        }
        ans=max(ans,mx);
    }while(next_permutation(all(a)));
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
