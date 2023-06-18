#include<bits/stdc++.h>
using namespace std;
int n,m;
int mask=1;
vector<string>flow;
vector<vector<int>>vis;
int x[]={1,0};
int y[]={0,1};
bool valid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || flow[x][y]=='#')
                return false;
            if(vis[x][y]&mask)
                    return false;
            return true;
}
void dfs(int i,int j){
    
    vis[i][j]|=mask;
    
    for(int k=0;k<2;k++){
        if(valid(i+x[k],j+y[k])){
           dfs(i+x[k],j+y[k]);
           return;//most crucial step (aborts further checking of other paths if found)

        }
    }
}
int main(){
cin>>n>>m;

vis.assign(n,vector<int>(m,0));

for(int i=0;i<n;i++){
    string s;
    cin>>s;
    flow.push_back(s);
}
//setting one path of dfs by 1;
dfs(0,0);

 swap(x[0],x[1]);
 swap(y[0],y[1]);

 // setting other by 2 and meeting point of both will be set by 3 which is our potential target
 mask=2;
 dfs(0,0);
 
        int x;
        int ans=INT_MAX;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>x;
        if(vis[i][j]==3) 
            ans=min(ans,x);
    }
 }
 cout<<ans;
}