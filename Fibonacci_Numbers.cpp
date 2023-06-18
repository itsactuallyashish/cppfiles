#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int md=1e9+7;
using matrix =vector<vector<ll>>;
matrix I={{1,0},{0,1}};
matrix M={{1,1},{1,0}};
matrix mul(matrix A,matrix B){
    matrix C={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C[i][j]+=A[i][k]*B[k][j];
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
    ll n;cin>>n;
    matrix ans(binex(M,n));
    cout<<ans[0][1]%md;
    
   
}