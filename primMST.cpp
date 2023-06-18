//prims algorithm
#include<bits/stdc++.h>
using namespace std;
const int sz=10006;
vector<array<int,2>>adj[sz];
struct edges{
 int v,av,wt;
 edges(int v,int av,int wt):v(v),av(av),wt(wt){}
};
struct compare{
    bool operator()(edges a,edges b){
                return a.wt > b.wt;
    }
};
int main(){
    int N,M;
    cin>>N>>M;
    int x,y,wt;
    for(int i=0;i<M;i++){
        cin>>x>>y>>wt;
        adj[x].push_back({wt,y});
        adj[y].push_back({wt,x});
    }
    long long ans=0;
    priority_queue<edges,vector<edges>,compare> pq;
    vector<bool>visited(N+1,false);
    pq.push(edges(1,-1,0));
    while(!pq.empty()){
        edges rem=pq.top();
        pq.pop();
        if(visited[rem.v]) continue;
        ans+=rem.wt;
        visited[rem.v]=1;
        for(auto pr:adj[rem.v]){
            if(!visited[pr[1]])
                pq.push({pr[1],rem.v,pr[0]});
        }
    }
    cout<<ans;
}