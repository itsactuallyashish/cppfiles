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
        ll n,k;see(n,k);
        int i=0,j=0;
        ll cnt=0;
        map<ll,int>mp;
        ll val[n];
        for(int i=0;i<n;i++) cin>>val[i];
        while(i<n){
            while(j<n && (mp.size()<k || mp.count(val[j])>0)){
                mp[val[j]]++;
                j++;
            }
            cnt+=(j-i);
            mp[val[i]]--;
            if(mp[val[i]]==0) mp.erase(val[i]);
            i++;
        }
        put(cnt);
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
