#include<iostream>
using namespace std;
int D[1<<20][20], A[20][20];
int main(){
   int d=1e9+7, n,m,a,b,i,j,k;
   cin>>n>>m;
   
    for(i=0;i<m;i++){
        cin>>a>>b;
        A[--a][--b]++;
    }
    D[1][0]=1,a=(1<<n);
    for( m=2;m<a;m++){
        if(m>>(n-1)&1 && m!=a-1) continue;
        for(j=0;j<n;j++)
            if(m>>j&1)
                for( k=0;k<n;k++)
                    if(m&(1<<k) && A[k][j])
                        D[m][j]=(D[m][j]+(A[k][j]*1ll*D[m ^(1<<j)][k])%d)%d;
                       
                    
                
            
    }
    cout<<D[a-1][n-1];
 
}