#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
const int mx=1e6+10;
ll fac[mx];
const int mod=1e9+7;
void factorial(){
    fac[0]=1;
    for(int i=1;i<mx;i++){
        fac[i] = (fac[i-1] * i )%mod;
    }
}
ll binex(int a,int b){
    ll res=1;
    while(b>0){
        if(b&1) res = (res * a) %mod;
        a= (a * 1ll * a) %mod;
        b>>=1;
    }
    return res%mod;
}
ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}
ll comb(int a, int b){
   ll res = (fac[a] * binex((fac[a-b]*fac[b])%mod,mod-2))%mod;
   if(res<0) res+=mod;
   return res;
}
int main(){
    factorial();
    int t=1;
    while(t--){
        int a;cin>>a;
        ll ans=0;
        for(int i=0;i<=a;i++){
            ans = (ans + mul(comb(a,i),fac[a-i]*pow(-1,i)))%mod;
            if(ans<0) ans+=mod;
        }
        cout<<ans;
    }
}