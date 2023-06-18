#include<iostream>
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
ll comb(int a, int b){
   ll res = (fac[a] * binex((fac[a-b]*fac[b])%mod,mod-2))%mod;
   if(res<0) res+=mod;
   return res;
}
int main(){
    factorial();
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        cout<<comb(a,b)<<"\n";
    }
}