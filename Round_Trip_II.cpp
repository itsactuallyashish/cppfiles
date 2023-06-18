//cycle in an directed graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=1e6;
vector<ll>g[mxn];
stack<ll>re_stck;
vector<bool> vis(mxn,false),flag(mxn,false);
bool dfs(int v){
    vis[v]=1;
    flag[v]=1;
    re_stck.push(v);
    for(auto x:g[v]){
        if(!vis[x]){
            if(dfs(x)) return true;
        }
        if(flag[x]){
            re_stck.push(x);
            return true;
            // now we found a cycle so no more dfs
        }
    }
    re_stck.pop();
    flag[v]=0;
    return false;

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) 
            if(dfs(i)) break;
    }
    if(re_stck.empty()){
     cout<<"IMPOSSIBLE";
     return 0;
        
    }    
    vector<ll>ans;
    int end_pt=re_stck.top();
        while(!re_stck.empty()){
            int x=re_stck.top();
            re_stck.pop();
            ans.push_back(x);
            if(ans.back()==end_pt && ans.size()!=1) break;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(auto x:ans)
            cout<<x<<' ';

}