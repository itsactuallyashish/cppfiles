#include<bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
vi v;
vi g[100005];
vector<bool> vis(100005,false);
void dfs(int i){
    if(vis[i]) return;
    vis[i]=1;
    for(auto x:g[i]) dfs(x);
    v.push_back(i);
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    vi t; int i=0,f=0;
    //retrieving the topsort order from 1 to n
    while(i<v.size()){
        if (f==0){
            if (v[i]==1) {f=1; t.push_back(1);}
        }
        else{
            t.push_back(v[i]);
        }
        i++;
    }
    //fing the longest path using  dp
    vi parent(3e5,0),dp(3e5,0);
    dp[1]=1;
    parent[1]=0;
    for(auto i:t){
        for(auto j:g[i]){
            if(dp[i]<dp[j]+1 && dp[j]){
                dp[i]=dp[j]+1;
                parent[i]=j;
            }

        }
    }
    i = n;
    vi vec;
    while(i!=0){
        vec.push_back(i); i = parent[i];
    }
    reverse(all(vec)); 
    if (vec.size()<2) {cout<<"IMPOSSIBLE"; return 0;}
    cout<<vec.size()<<"\n";
    for (auto i: vec) cout<<i<<" ";

}