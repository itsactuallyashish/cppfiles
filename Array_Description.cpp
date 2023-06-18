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
const ll md = (10e8) + 7;
 
void solve() {
    int n,m;see(n,m);
    vector<ll>curr(m+1,0),prev(m+1,0);
    int val[n];
    for(int i=0;i<n;i++) see(val[i]);
    if(val[0]==0)
      fill(prev.begin(),prev.end(),1);
      else
    prev[val[0]]=1;
    for(int j=1;j<n;j++){
        if(val[j]==0){
            for(int i=1;i<=m;i++){
                curr[i] =(i-1>0?prev[i-1]:0) + prev[i] + (i+1<=m?prev[i+1]:0);
                 curr[i]%=md;
            }
        }else{
                int i=val[j];
                  curr[i] =(i-1>0?prev[i-1]:0) + prev[i] + (i+1<=m?prev[i+1]:0);
                      curr[i]%=md;
            }
        
       prev=curr;
       fill(curr.begin(),curr.end(),0);
       
    }
    ll ans=0;
   for(int i=1;i<=m;i++){
        ans += prev[i];
        ans%=md;
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