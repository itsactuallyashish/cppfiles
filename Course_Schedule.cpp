#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
const ll INF = 1e17;
const ll NINF = INF*(-1);
const int mxn =1e6;
vector<ll>g[mxn];
vector<ll>in_degree(mxn,0);
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        in_degree[y]++;
    }
    vector<ll>top;
    priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<=n;i++){
            if(in_degree[i]==0){
                pq.push(i);
            }
        }
            while(!pq.empty()){
                int x=pq.top();
                pq.pop();
                top.push_back(x);
                for(auto v:g[x]){
                    in_degree[v]--;
                    if(in_degree[v]==0)pq.push(v);
                }
            }
            if(top.size()==n)
            for(auto elem:top) cout<<elem<<" ";
            else cout<<"IMPOSSIBLE";

}