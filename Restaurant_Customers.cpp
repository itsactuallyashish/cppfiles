#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<pair<ll,int>>events;
    for(int i=0;i<n;i++){
        ll s,e;
        cin>>s>>e;
        events.push_back({s,1});
        events.push_back({e,-1});
    }
    sort(events.begin(),events.end());
    ll mxcus=0,cus=0;
    for(int i=0;i<events.size();i++){
        cus+=events[i].second;
      
        mxcus=max(mxcus,cus);
    }
  cout<<mxcus;

}