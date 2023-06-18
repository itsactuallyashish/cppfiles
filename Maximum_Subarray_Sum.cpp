#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;
    ll val[n];
    for(int i=0;i<n;i++) cin>>val[i];
    ll csum=val[0],osum=val[0];
    for(int i=1;i<n;i++){
        if(csum>0){
            csum+=val[i];
        }else{
            csum=val[i];
        }
        osum=max(osum,csum);
    }
    cout<<osum;
}