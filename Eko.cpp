//ItsactuallyAshish
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,M;
vector<ll>h;
bool ispossible(int mheight){
            ll wood=0;
        for(int i=0;i<N;i++){
            if(h[i]>=mheight){
                wood+=(h[i]-mheight);
            }
        }
        return wood>=M;
}

int main(){
    
    cin>>N>>M;
    h.resize(N);
    ll mheigh=0;
   for(int i=0;i<N;i++){
    cin>>h[i];
    mheigh=max(mheigh,h[i]);
   }
    ll s=0,e=1e9;
    while(e>s+1){
        ll mid=s+(e-s)/2;
        if(ispossible(mid)){
            s=mid;
        }
        else{
            e=mid-1;
        }
    }    
    if(ispossible(e)){
        cout<<e<<endl;
    }else{
        cout<<s<<endl;
    }
}