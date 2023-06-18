#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const ll inf =1ll<<60;

using matrix =vector<vector<ll>>;
matrix g;
vector<vector<ll>>I;
matrix mul(matrix A,matrix B){
    vector<vector<ll>>C(A.size(),vector<ll>(B[0].size(),inf));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<A[0].size();k++){
                
                    C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
                
            
            }
        }

    }
    return C;
}
matrix binex( matrix x, ll y) {
    matrix r(x.size(), vector<ll>(x.size()));
    int f = 0;
    while (y>0){
        if (y&1) {
            if (f) r = mul(r,x);
            else r = x, f =1;
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}
int main(){
    int m;cin>>n>>m;
    ll k;cin>>k;
    g.assign(n,vector<ll>(n,inf));

for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;
    ll w;cin>>w;
    x--,y--;
    g[x][y]=min(g[x][y],w);
}
    matrix ans(binex(g,k));
    if(ans[0][n-1]<inf)
cout <<ans[0][n-1];//min cost of ways to go from 1 to n;
   else cout<<-1;
}