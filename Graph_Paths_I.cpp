#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int md=1e9+7;
int n;
using matrix =vector<vector<ll>>;
vector<vector<ll>>I;
matrix mul(matrix A,matrix B){
    vector<vector<ll>>C(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][j] %md;
                C[i][j]%=md;
            }
        }

    }
    return C;
}

matrix binex(matrix x,ll y){
    matrix res=I;
    while(y>0){
        if(y&1) res= mul(res,x);
        x=mul(x,x);
        y>>=1;
    }
    return res;
}
int main(){
    int m;cin>>n>>m;
    ll k;cin>>k;
vector<vector<ll>>g(n,vector<ll>(n,0));
for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;
    x--,y--;
    g[x][y]++;
}
I.assign(n,vector<ll>(n));
for(int i=0,j=0;i<n;i++) I[i][j]=1;
    matrix ans(binex(g,k));
cout <<ans[0][n-1];//number of ways to go from 1 to n;
   
}