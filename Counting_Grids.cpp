#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int md=1e9+7;
ll binex(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y%2){
            res= res*x%md;
        }
        x=x*x%md;
        y>>=1;
    }
    return res;
}
int main(){
    ll x;cin>>x;
    ll ans=0;
    if(x%2==0){
        ans=((binex(2,x*x)+(2*binex(2,x*x/4))%md)%md+binex(2,x*x/2))%md;
    }
    else ans=(binex(2,x*x) + 2*(binex(2,(x*x-1)/4)+binex(2,(x*x-1)/4)+binex(2,(x*x-1)/2))%md)%md;
    if(ans<0) ans+=md;
    ans=ans*binex(4,md-2)%md;
    cout<<ans;
}