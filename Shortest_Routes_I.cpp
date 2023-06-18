#include<bits/stdc++.h>
#define ll long long
const int mxn =1e6;
const ll inf=1e16;
using namespace std;
vector<ll> dist(mxn,inf);
vector<pair<int,ll>> adj[mxn];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        // adj[y].push_back({x,w});
    }
    dist[1]=0;
    typedef pair<ll,int> pii;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll p=pq.top().first;
        int q=pq.top().second;
        pq.pop();
        if(dist[q]<p) continue;
        for(auto pr:adj[q]){
            int x=pr.first;
            ll y=pr.second;
            if(dist[x]<=y+p) continue;
            else{
                dist[x]=p+y;
                pq.push({dist[x],x});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}