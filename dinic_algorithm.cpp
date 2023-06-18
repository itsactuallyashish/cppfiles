#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e3+1;
const int V=5;
vector<int>level;
bool bfs(vector<vector<int>>&g,int src,int snk){
    level.assign(g.size(),-1);
    queue<int>q;
    q.push(src);
    level[src]=0;
    while(!q.empty()){
        int rem=q.front();q.pop();
        for(int i=0;i<g[rem].size();i++){
            if(rem!=i&& g[rem][i]>0&& level[i]<0){
                level[i]=level[rem]+1;
                q.push(i);
            }
        }
    }
        return level[snk]>0?1:0;
}
int sendflow(vector<vector<int>>&g,vector<int>&count,int snk,int u,int flow){
    if(u==snk){
        return flow;
    }
    if(count[u]==g[u].size()){
        return 0;
    }
        for(int x=0;x<g[u].size();x++){
            if(g[u][x]>0){
                count[u]++;
                if(level[x]==level[u]+1){
                    //find minumum capacity
                    int cur_flow=min(flow,g[u][x]);
                    
                    int mnflow=sendflow(g,count,snk,x,cur_flow);
                    if(mnflow>0){
                    g[u][x]-=mnflow;
                    g[x][u]+=mnflow;
                        return mnflow;
                    }
                }
            }
        }
        return 0;
}
int dinic(vector<vector<int>>&g){
    int mx_flow=0;
    vector<vector<int>>residual=g;
    int source=0,sink=g.size()-1;
    while(bfs(residual,source,sink)){
        vector<int>count(g.size(),0);
         while (int flow = sendflow(residual, count, sink,source, INT_MAX))
            mx_flow += flow;
    }
    
    return mx_flow;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        g[a][b]=w;
    }
    cout<<dinic(g);
}

