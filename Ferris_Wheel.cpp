#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>ar(n);
    for(auto &in:ar) cin>>in;
    sort(ar.begin(),ar.end());
    int i=0,j=n-1;
    ll ans=0;
    while(i<=j){
        if(i==j) {
            ans++;
            break;
        }
        if(ar[i]+ar[j]>m){
            ans++;
            j--;
        }
        else{
            i++;j--;
            ans++;
        }
    }
    cout<<ans;
}