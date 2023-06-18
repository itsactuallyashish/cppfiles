#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;
    ll x;cin>>x;
    vector<pair<ll,int>>val;
    for(int i=0;i<n;i++){
        ll xi;cin>>xi;
        val.push_back({xi,i});
    }
    sort(val.begin(),val.end());
    int i=0,j=n-1;
    while(i<j){
        if(val[i].first+val[j].first>x) j--;
        else if(val[i].first+val[j].first<x) i++;
        else {
            cout<<val[j].second+1<<" "<< val[i].second+1;
            exit(0);
        }
    }

    cout<<"IMPOSSIBLE";
}