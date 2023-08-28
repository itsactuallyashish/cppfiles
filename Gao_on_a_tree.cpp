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
const int mxn=2e5+100;
ll val[mxn],flat[mxn];

int timer=1;
int in[mxn];
int out[mxn];
int n;

vector<int>adj[mxn];
int d[mxn];
constexpr int lg=19;
int up[lg+2][mxn];

void init(){
        for(int x=1;x<=n;x++){
            for(int i=1;i<=lg;i++){
                up[i][x]=up[i-1][up[i-1][x]];
            }
        }
}
int lca(int a,int b ){
        if(d[a]<d[b]) swap(a,b);
         ll diff=d[a]-d[b];
        for(ll mask=lg;mask>=0;mask--){
            if((1<<mask)&diff){
                a=up[mask][a];
            }
        }
        if(a==b){
            return a;
        }else{
            for(ll mask=lg;mask>=0;mask--){
                if(up[mask][a]!=up[mask][b]){
                    a=up[mask][a];
                    b=up[mask][b];
                }
            }
            return up[0][a];
        }
}
ll nodef[mxn],f[mxn];
bool res[mxn];
void dfs(int v=1,int p=0){
    in[v]=timer;
    up[0][v]=p;
    flat[in[v]]=val[v];
    timer++;
    for(auto ch:adj[v]){
        if(ch==p) continue;
        d[ch]=d[v]+1;
        dfs(ch,v);
    }
    out[v]=timer;
    flat[out[v]]=val[v];
    timer++;
}
int blk=640;
struct qu{
        int l,r,c,lca,idx;
        
};
bool comp(qu a , qu b){
                int x=a.l/blk;
                int y=b.l/blk;
                if(x!=y){
                    return x<y;
                }else return a.r<b.r;
        }
qu q[mxn];

void add(int in){
        int node=flat[in];
        nodef[node]++;
        if(nodef[node]==2){
            int c=val[node];
            f[c]--;
        }else{
            int c=val[node];
            f[c]++;
        }
}
void remove(int in){
        int node = flat[in];
        nodef[node]--;
        if(nodef[node]==1){
            int c=val[node];
            f[c]++;
        }else{
            int c=val[node];
            f[c]--;
        }
}
void solve() {
    int t=0;
    while(cin>>n){
            if(t>0) cout<<endl;
            t++;
        for(int i=0;i<=n;i++){
            f[i]=0;
            nodef[i]=0;
            adj[i].clear();
            res[i]=0;
        }
        memset(up,0,sizeof(up));
        int Q;
        see(Q);
        for(int i=1;i<=n;i++) see(val[i]);
        for(int i=0;i<n-1;i++){
            int a,b;
            see(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        d[0]=0;
        dfs();
        init();
        for(int i=1;i<=Q;i++){
            int a,b,c;
            see(a,b,c);
            if(in[a]>in[b]) swap(a,b);
            int lc=lca(a,b);
            if(a==lc){
                q[i].l=in[a];
                q[i].r=in[b];
                q[i].c=c;
                q[i].idx=i;
                q[i].lca=-1;
            }else{
                q[i].l=out[a];
                q[i].r=in[b];
                q[i].c=c;
                q[i].lca=lc;
                q[i].idx=i;
            }
            
        }
        sort(q+1,q+Q+1,comp);
        int ml=1,mr=0;
        for(int i=1;i<=Q;i++){
            int l=q[i].l;
            int r=q[i].r;
            int lc=q[i].lca;
            int idx=q[i].idx;
            int c=q[i].c;

            while(mr<r){
                mr++;add(mr);
            }
            while(ml>l){
                ml--;add(ml);
            }
            while(ml<l){
                remove(ml);
                ml++;
            }
            while(mr>r){
                remove(mr);
                mr--;
            }
            if(f[c]>0){
                res[idx]=1;
            }
            if((lc!=-1) && val[lc]==c){
                res[idx]=1;
            }

        }
            for(int i=1;i<=Q;i++){
                if(res[i]) cout<<"Find\n";
                else cout<<"NotFind\n";
            }
    }
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
