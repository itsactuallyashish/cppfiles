#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << ""), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << ""), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()

vector<int>g[105];
int n,m;

bool valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]==1)
     return 1;
    return 0;
}
bool vis[105][105]={false};
void dfs(int i,int j,int ch){
    if(i==n&& j==m) return;
    vis[i][j]=1;
    int x[]={0,0,-1,1};
    int y[]={1,-1,0,0};
        g[i][j]=ch;
    if(ch==2) ch=3;
    else if(ch==3) ch=2;
    for(int k=0;k<4;k++){
        if(valid(i+x[k],j+y[k]))
            dfs(i+x[k],j+y[k],ch);
    }
}
void solve() {
        see(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch;see(ch);
                if(ch=='-'){
                    g[i].push_back(0);
                    vis[i][j]=1;
                }
                else g[i].push_back(1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                   dfs(i,j,2);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(g[i][j]==0) put('-');
                else if(g[i][j]==2) put('B');
                else put('W');
            putl();
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
