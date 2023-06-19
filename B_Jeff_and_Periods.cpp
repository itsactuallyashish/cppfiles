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
            vector<ll>a(n);
            map<ll,ll>mp,ans;
            
            for(int i=0;i<n;i++){
                see(a[i]);
                if(mp.count(a[i]) && ans[a[i]]>0){
                  if(i+1 -mp[a[i]]==ans[a[i]]){
                    mp[a[i]]=i+1;
                   }else{
                        ans[a[i]]=-1;

                   } 
                }else if(mp.count(a[i]) && ans[a[i]]==0){
                            ans[a[i]]=i+1 - mp[a[i]];
                            mp[a[i]]=i+1;
                }else if(!mp.count(a[i])){
                    mp[a[i]]=i+1;
                    ans[a[i]]=0;

                }
                // for(auto pr:ans){
                //     deb2(pr.first,pr.second);
                // }
                // cerr<<endl;
            }
            ll cnt=0;
            for(auto pr:ans){
                if(pr.second!=-1) cnt++;
            }
            putl(cnt);
            for(auto pr:ans){
                if(pr.second!=-1) putl(pr.first,pr.second);
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
