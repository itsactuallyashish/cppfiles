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
const ll mod= 1073741824;
const int mxn = 1e6+4;
int isprime[mxn]={1};
void sieve(){
        isprime[0]=isprime[1]=1;
        for(int i=2;i<mxn;i++)
           isprime[i]=i;
        for(int i=2;i*i<mxn;i++){
            if(isprime[i]==i){
                for(int j=i+i;j<mxn;j+=i)
                    if(isprime[j]==j)
                      isprime[j]=i;
            }
        }
}
int get_factor(int x){
   int ans=1;
   while(x!=1){
        int cnt=1;
        int p=isprime[x];
       while(x%p==0){
          x=x/p;
          cnt++;
       }
       ans = ans * (cnt);
   }
   return ans;
}
ll val[1000002];
void solve() {
            sieve();
            int n,m,k;
            see(n,m,k);
            // vector<ll>val(n*m*k+10,0);

         
            ll ans =0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    for(int x=1;x<=k;x++){
                        (ans +=get_factor(x*i*j))%mod;
                    }
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
