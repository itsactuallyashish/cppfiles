#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
const int md=1e9+7;
ll binex(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y&1) res= (res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

int main(){
    int n,m;cin>>n>>m;
    // using burnside lemma
    ll ans=0;
   for(int i=0;i<n;i++){
            ans= (ans+binex(m,__gcd(i,n)))%md;
   }
   ans=ans*binex(n,md-2)%md;
   cout<<ans;
}