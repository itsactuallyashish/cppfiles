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
    see(n,m);
    vector<int>a;
    int l=0,r=0;
    for(int i=0;i<n;i++){
        int x;see(x);
        if(x==-1) l++;
        else if(x==-2) r++;
        else a.push_back(x-1);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    int sz=a.size();
    int ans=0;
    if(l>0) ans = max(ans , min(m,l+sz-(!a.empty() && a.back()==m-1)));
    if(r>0) ans = max ( ans,min(m,r+sz - (!a.empty() && a[0]==0)));
    for(int i=0;i<sz;i++){
        ans = max(ans,min(a[i],i+l)+1+ min(m-a[i]-1,sz-i-1+r));
    }
    cout<<ans;

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
