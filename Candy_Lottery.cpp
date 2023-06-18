#include<bits/stdc++.h>
using namespace std;
#define ld long double
ld binex(ld a,int b){
    ld res=1;
    while(b>0){
        if(b%2) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    int n,k;cin>>n>>k;
        ld res=0;
    for(int i=1;i<=k;i++){
        ld a,b;
        a=(ld)(i)/(ld)k;
        b=(ld)(i-1)/(ld)k;
        a=binex(a,n);
        b=binex(b,n);
        res+=i*(a-b);
    }
    cout<<fixed<<setprecision(6)<<res;
}