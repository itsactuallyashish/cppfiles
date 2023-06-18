#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;scanf("%d",&t);
    while(t--){
        long long x,y;scanf("%lld%lld",&x,&y);
        x--,y--;
        ll mx=max(x,y);
                ll p=(mx+1)*(mx+1);
        if(mx&1){
                if(x!=mx){
                p-=y;
                p-=mx-x;
            }
            else{
                p-=y;
            }
        }else{
            if(x!=mx){
                p-=x;
            }
            else{
                p-=x;
                p-=mx-y;
            }
            
        }
            printf("%lld\n",p);
    }
}