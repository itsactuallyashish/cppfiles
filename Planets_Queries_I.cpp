#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int mxn=2e5+5;
ll dp[mxn][30];
int ln=30;
ll lift(ll x,ll y){
    for(int i=0;i<ln;i++){
        if((1<<i) &y){
            x=dp[x][i];
        }
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dp[i][0];
    }
    for(int LN=1;LN<ln;LN++){
        for(int i=1;i<=n;i++){
            dp[i][LN]=dp[dp[i][LN-1]][LN-1];
        }
    }
        ll x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        cout<<lift(x,y)<<"\n";

    }

}