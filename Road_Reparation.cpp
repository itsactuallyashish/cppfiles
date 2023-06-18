#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=1e5+1;
class compare{
        public:
  bool operator()(array<ll,3>a,array<ll,3>b){
     return a[0]>b[0];
  } 
};
vector<vector<ll>> adj[mxn];
ll prim(int v)
    {   
        vector<bool>vis(v+1,false);
        ll wt=0;
        ll cnt=0;
        priority_queue<array<ll,3>,vector<array<ll,3>>,compare>pq;
        pq.push({0,0,-1});
        while(!pq.empty()){
            array<ll,3>tmp=pq.top();
            pq.pop();
            if(vis[tmp[1]]) continue;
            vis[tmp[1]]=1;
            for(auto e:adj[tmp[1]]){
                pq.push({e[1],e[0],tmp[1]});
            }
           
            wt+=tmp[0];cnt++;
        }
        if(cnt==v)// one extra counted due to ghost edge {0,0,-1} so used v instead of v-1
        return wt;
        return -1;
    }
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll wt;
        cin>>a>>b>>wt;
        a--,b--;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    ll x=prim(n);
    if(x==-1) cout<<"IMPOSSIBLE";
    else cout<<x;
}