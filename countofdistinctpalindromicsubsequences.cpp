#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    unordered_map<char,int>mp;
    vector<int>next(n),pre(n);
    for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                pre[i]=mp[s[i]];
            }
            else pre[i]=-1;
            mp[s[i]]=i;
    }
    for(int i=n-1;i>=0;i--){
            if(mp.find(s[i])!=mp.end()){
                next[i]=mp[s[i]];
            }
            else next[i]=n;
            mp[s[i]]=i;
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) dp[i][j]=1;
            else if(g==1) dp[i][j]=2;
            else {
                if(s[i]==s[j]){
                        int n=next[i];
                        int p=pre[j];
                        if(n>p){
                                dp[i][j]=dp[i+1][j-1]*2 + 2;
                        }else if(n<p){
                            dp[i][j]=2*dp[i+1][j-1]-dp[n+1][p-1];
                        }
                        else{

                                dp[i][j]=dp[i+1][j-1]*2 + 1;
                        }
                }else {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]- dp[i+1][j-1];
                }
            }
        }
    }
    cout<< dp[0][n-1];
}