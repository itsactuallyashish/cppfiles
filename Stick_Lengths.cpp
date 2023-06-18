#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;
    ll val[n];
    for(int i=0;i<n;i++) cin>>val[i];
    sort(val,val+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(val[i]-val[n/2]);
    }
    cout<<ans;
}
