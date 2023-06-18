#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;
    vector<pair<ll,ll>>events;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        events.push_back({a,b});
    }
    sort(events.begin(),events.end(),[&](pair<ll,ll>x,pair<ll,ll>y){
            return x.second<y.second;
    });
    int i=0,cnt=0;
    ll last=-1;
    while (i<n)
    {
        if(events[i].first>=last){
            cnt++;
            last=events[i].second;
        }
        i++;
    }
    cout<<cnt;
    
}