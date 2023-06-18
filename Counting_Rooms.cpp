#include<bits/stdc++.h>
using namespace std;
const int mx=1e3+10;
vector<vector<bool>> mt(mx,vector<bool>(mx)) ,vis(mx,vector<bool>(mx,false));
int n,m;
vector<pair<int,int>>p={{-1,0},{0,1},{1,0},{0,-1}};
bool isvalid(int x,int y){
    if(x<0 || x>=n || y<0|| y>=m) return false;
    if(vis[x][y]) return false;
    return true;
}
void dfs(int x,int y){
    vis[x][y]=1;
    for(auto &pr: p){
        if(isvalid(x+pr.first,y+pr.second)) dfs(x+pr.first,y+pr.second);
    }
}
int main(){
    cin>>n>>m;
    char ch;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        cin>>ch;
        if(ch=='.') mt[i][j]=1;
         else vis[i][j]=1;
         
      }
    int ans=0;
      for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        if(!vis[i][j]){
            dfs(i,j);
            ans++;
        }
      }
      cout<<ans;

}