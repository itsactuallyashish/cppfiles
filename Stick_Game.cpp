#include <iostream>
#include<vector>
#include<string>
using namespace std;
#define ll long long
int main(){
    int n,k;cin>>n>>k;
    vector<int>p(k);
    for(auto &in:p) cin>>in;
    string res;
    vector<bool>dp(n+1,false);
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(auto pick:p){
            if(i-pick>=0)
            flag |= dp[i-pick]==0;
        }
        
        if(flag){
            dp[i]=true;
            res.push_back('W');
        }else{
            res.push_back('L');
        }
    }
    cout<<res;
}