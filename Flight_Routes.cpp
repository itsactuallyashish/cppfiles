#include<bits/stdc++.h>
#define ll long long
const int mxn =1e6;
const ll inf=1e16;
using namespace std;

vector<pair<int,ll>> adj[mxn];
vector<vector<ll>>dp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        // adj[y].push_back({x,w});
    }
    dp.resize(n+1);
    for(int i=1;i<=n;i++){
        dp[i].resize(k);
        for(int j=0;j<k;j++){
            dp[i][j]=inf;
        }
    }
    dp[1][0]=0;
    // dp[u][k-1]==>kth best path cost for the vertex u
    typedef pair<ll,int> pii;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        pii pr=pq.top();
        pq.pop();
        if(dp[pr.second][k-1]<pr.first)continue;
        for(auto x:adj[pr.second]){
            if(dp[x.first][k-1]<=pr.first+x.second)continue;
            else{
                dp[x.first][k-1]=pr.first+x.second;
                pq.push({pr.first+x.second,x.first});
                sort(dp[x.first].begin(),dp[x.first].end());
            }
        }
    }
    for(auto elem:dp[n]){
        cout<<elem<<" ";
    }
}