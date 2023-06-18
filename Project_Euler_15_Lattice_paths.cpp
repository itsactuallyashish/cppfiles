#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
const int mod=1e9+7;
ll fac[1003];
int binex(int a,int b,int m){
    int result=1;
    while(b>0){
        if(b&1){
            result=(result * 1ll *a) % m;
        }
        a=(a*1ll*a)%m;
        b>>=1;
    }
    return result;
}
void fact(){
    for(int i=2;i<1003;i++){
        fac[i]=(fac[i-1] * i )%mod;
    }
}
ll inverse(int c){
    return binex(c,mod-2,mod);
}
ll comb(int n,int p){
    ll res=(fac[n+p] * inverse(fac[n]*fac[p] %mod)) %mod;

    return res;
}

int main() {
    fac[0]=1;
    fac[1]=1;
    fact();
    int t;cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        cout<<comb(n,m)<<"\n";
    }  
    return 0;
}