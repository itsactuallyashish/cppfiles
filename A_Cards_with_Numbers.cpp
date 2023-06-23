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
    //      freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
           int n;see(n);
           n=2*n;
                   vector<pair<int,int>>v(n);
                unordered_map<int,int>fq;
                for(int i=0;i<n;i++){
                    see(v[i].first);
                    v[i].second=i+1;
                    fq[v[i].first]++;
                }
                for(auto it:fq){
                    if(it.second&1){
                        put(-1);return;
                    }
                }
                sort(all(v));
                for(int i=0;i<n;i+=2){
                    putl(v[i].second,v[i+1].second);
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
