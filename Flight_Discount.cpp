#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxn=1e6;
vector<pair<int,int>>adj[mxn];
const int inf=1e16;
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>dis(n+1,inf),path(n+1,inf);
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    pq.push({0,1,0});
    dis[1]=0;path[1]=0;
    while(!pq.empty()){
        array<int,3> ar=pq.top();
        pq.pop();
            if(ar[2]){
                if(dis[ar[1]]<ar[0]) continue;
            }
            else {
                if(path[ar[1]]<ar[0]) continue;
            }
        for(auto x:adj[ar[1]]){
            int b=x.first;
            int c=x.second;
            if(ar[2]){
                if(dis[b]>ar[0]+c){
                    dis[b]=ar[0]+c;
                    pq.push({dis[b],b,1});
                }
            }
            else{
                if(path[b]>ar[0]+c){
                    path[b]=ar[0]+c;
                    pq.push({path[b],b,0});
                }
                if(dis[b]>ar[0]+c/2){
                    dis[b]=ar[0]+c/2;
                    pq.push({dis[b],b,1});
                }
            }

        }

    }
    cout<<dis[n];

}