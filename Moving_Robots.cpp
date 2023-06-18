#include <bits/stdc++.h>
using namespace std;
#define ld long double
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool valid(int x,int y){
    if(x<0 || x>=8 || y<0 || y>=8) return false;
        return true;
}
int main(){
    int x;cin>>x;
    ld dp[x+1][8][8];
    vector<vector<ld>>ans(8,vector<ld>(8,1));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
              for(int k=0;k<=x;k++){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++)
                            dp[k][i][j]=0;
                    }
              }
              dp[0][i][j]=1;
              for(int k=0;k<x;k++){
                for(int il=0;il<8;il++){
                    for(int jl=0;jl<8;jl++){
                        int dir=0;
                        for(int f=0;f<4;f++)
                          if(valid(il+X[f],jl+Y[f])) dir++;
                        for(int f=0;f<4;f++){
                            if(valid(il+X[f],jl+Y[f]))
                                dp[k+1][il+X[f]][jl+Y[f]]+=dp[k][il][jl]/dir;
                        }
                    }
                }

              }
              for(int il=0;il<8;il++){
                for(int jl=0;jl<8;jl++){
                    ans[il][jl]*=(1-dp[x][il][jl]);
                }
              }
        }
    }
    ld res=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            res+=(ans[i][j]);
        }
    }
    cout<<fixed<<setprecision(6)<<res;
}