//implimentation of floyd warshall algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e3;
const ll inf=1e13;
vector<vector<ll>>g(mx,vector<ll>(mx));
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;++j )
        g[i][j]=g[j][i]=inf;
    }
    for(int i=0;i<m;i++){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        g[x][y]=g[y][x]=min(g[x][y],w);
    }

    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(g[a][b]==inf) g[a][b]=-1;
        cout<<g[a][b]<<"\n";
    }
}