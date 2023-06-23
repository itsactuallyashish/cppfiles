#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


void dfs(int v,int p,vector<vector<int>>&adj,vector<int>&wt,vector<ll>&ans,ll x){
     x = x+wt[v];
     if(x<0){
        x=0;
     }
     if(p!=-1)
      ans[v] = max(ans[p],x);
    //  deb2(ans[v],v);
    for(auto child:adj[v]){
        if(child==p) continue;
        
        dfs(child,v,adj,wt,ans,x);
       
    }
}
void solve() {
   
        int n;see(n);
        vector<vector<int>>adj(n+10);
        vector<int>wt(n+10,0);
        wt[1]=1;
        int cnt=1;
        cnt++;
        vector<pair<int,int>>q;
        for(int i=0;i<n;i++){
            char ch;see(ch);
            if(ch=='+'){
                int a,b;
                see(a,b);
                adj[a].push_back(cnt);
                adj[cnt].push_back(a);
                wt[cnt]=b;
                cnt++;
            }else{
                int a,b,c;
                see(a,b,c);
                q.push_back({b,c});
            }
        }
        vector<ll>mx(n+10,INT_MIN);
        vector<ll>mn(n+10,INT_MIN);
        mn[1]=-1;
        mx[1]=1;
        dfs(1,-1,adj,wt,mx,0);
        for(int i=1;i<=n;i++) wt[i]=-1*wt[i];
        dfs(1,-1,adj,wt,mn,0);
        for(int i=1;i<=n;i++) mn[i]=-1*mn[i];
        for(auto &x:q){
            if(x.second==0){
                putl("YES");continue;
            }
            if(x.first==1){
                if(x.second==-1*wt[1])putl("YES");
                else putl("NO");
                continue;
            }
            if(mx[x.first] >=x.second && mn[x.first]<=x.second){
                putl("YES");
            }
            else putl("NO");
        }

    

}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
       
    }

}
