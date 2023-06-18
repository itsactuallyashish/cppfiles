#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll binex(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1){
            res = (res * a)%m;
        }
        a= (a  * a ) %m;
        b>>=1;
    }
    return res;
}
ll mul(ll a,ll b){
    ll res = (a%mod) * (b%mod) %mod;
    return res;
}
int main(){
    ll n;cin>>n;
    ll ans=0;
    for(ll i=1,j;i<=n;i=j){
            ll q=n / i;
            j=n/q +1;
            ll y = mul(mul(j,j-1),binex(2,mod-2,mod));
            ll x = mul(mul(i,i-1),binex(2,mod-2,mod));
            ll res= (y- x + mod)%mod;
            ans = (ans + mul(q,res)) %mod;
    }
    cout<<ans;
}