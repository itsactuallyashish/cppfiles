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
        int n,m;
        see(n);
        vector<int>a(n);
        for(auto &in : a) see(in);
        vector<int>b(m);
        see(m);
        for(auto &in :b) see(in);
        int mxratio=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[j]%a[i]==0){
                    mxratio=b[j]/a[i];
                    mp[mxratio]++;
                }
            }
        }
        int mx=INT_MIN;
        int ans=0;
        for(auto it:mp){
            if(it.first>mx){
                mx=it.first;
                ans=it.second;
            }
        }
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
