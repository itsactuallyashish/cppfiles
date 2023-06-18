#include<bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
typedef pair<int,int> pii;
vector<pii> g[100005];
vector<bool> vis(100005,false);
const int mod=1e9+7;
const int inf=1e17;
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    vi cost(n+1,inf),route(n+1),maxnode(n+1),minnode(n+1);
    cost[1]=0;
    route[1]=1;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        pii x=pq.top();
        int c=x.first;
        int u=x.second;
        pq.pop();
        if(cost[u]<c) continue;
        for(auto i:g[u]){
             int w=i.second;
             int v=i.first;
                if(cost[v]>c+w){
                    cost[v]=c+w;
                    route[v]=route[u];
                    maxnode[v]=maxnode[u]+1;
                    minnode[v]=minnode[u]+1;
                    pq.push({cost[v],v});
                }
                else if(cost[v]==c+w){
                    route[v]+=route[u];
                    route[v]%=mod;
                    minnode[v]=min(minnode[v],minnode[u]+1);
                    maxnode[v]=max(maxnode[v],maxnode[u]+1);

                }
                else continue;
        }

    }
    cout<<cost[n]<<" "<<route[n]<<" "<<minnode[n]<<" "<<maxnode[n];
}