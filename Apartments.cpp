#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll req[n];
    for(int i=0;i<n;i++) cin>>req[i];
    ll avail[m];
    for(int i=0;i<m;i++) cin>>avail[i];
    sort(req,req+n);
    sort(avail,avail+m);
    int i=0,j=0,matches=0;
    while(i<n){
        while(j<m && req[i]-avail[j]>k) j++;
        if(abs(req[i]-avail[j])<=k){
            i++;
            j++;
            matches++;
        }
        else i++;
    }
    cout<<matches;
}