#include<bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
const int mod=1e9+7;
vi in(1e5,0);
vi g[100005];
vector<bool> vis(100005,false);
#define top front
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        in[y]++;
    }
    in[0]=-1;
    // for(int i=1;i<=n;i++) error(in[i]);
    //performing the first topological sort to prune the cycles while negelecting 1
    // priority_queue<int,vector<int>,greater<int>>pq;
    queue<int>pq;
    for(int i=2;i<=n;i++){
        if(in[i]==0){
        pq.push(i);
        }
        
    }

    while(!pq.empty()){
        int x=pq.top();
        pq.pop();
        // error(x);
        for(auto j:g[x]){
            if(j==1) continue;
            in[j]--;
            // error(j);
            if(in[j]==0) pq.push(j);
        }
    }
    // error(in[1]);
    //performing the second topological sorting condidering 1 and maintaining a count variable
    pq.push(1);
    vi count(n+1,0);
    count[1]=1;
    // for(int i=1;i<=n;i++) error(in[i]);
    while(!pq.empty()){
        int x=pq.top();
        pq.pop();
        for(auto j:g[x]){
           --in[j];
            count[j]+=count[x];
            count[j]%=mod;
            if(in[j]==0 ) pq.push(j);
        }

    }
    cout<<count[n];
}