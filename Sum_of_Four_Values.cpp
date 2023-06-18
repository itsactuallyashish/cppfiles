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
   int n;ll a;see(n,a);
    vector<pair<ll,int>>val;
    for(int i=0;i<n;i++){
        ll x;
        see(x);
        val.push_back({x,i});
    }
     sort(all(val));
    for(int j=0;j<n;j++){
        for(int i=j+1;i<n;i++){
            int p=i+1,q=n-1;
            while(p<q){
                if(val[p].first+val[q].first+val[i].first+val[j].first>a) q--;
                else if(val[p].first+val[q].first+val[i].first+val[j].first<a) p++;
                else {
                    put(val[p].second+1,val[q].second+1,val[i].second+1,val[j].second+1);
                    return ;
                }

            }
        }
    }
    put("IMPOSSIBLE");
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
