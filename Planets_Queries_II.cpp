#include<iostream>
#include<vector>
using namespace std;
#define endl "\n"
#define ll long long
const int mxn=2e5+5;
ll dp[mxn][30];
int ln=30;
vector<bool> vis(mxn,false);
ll len[mxn];
void dfs(int v){
    if(vis[v])return;
    vis[v]=1;
    dfs(dp[v][0]);
    len[v]=len[dp[v][0]]+1;
}
int lift(int x,int y){
    if(y<=0) return x;
    int i=0;
    while(y>0){
        if(y&1)
            x=dp[x][i];
            y>>=1;
            i++;
        
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dp[i][0];
    }
    for(int LN=1;LN<ln;LN++){
        for(int i=1;i<=n;i++){
            dp[i][LN]=dp[dp[i][LN-1]][LN-1];
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    int x,y;
    while (m--)
    {
        cin>>x>>y;
        int xx=lift(x,len[x]);
        if(lift(x,len[x]-len[y])==y) cout<<len[x]-len[y]<<endl;
        else if(lift(xx,len[xx]-len[y])==y){
            cout<<len[x]+len[xx]-len[y]<<endl;
        }
        else cout<<-1<<endl;
    }
    

}