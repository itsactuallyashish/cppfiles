#include <iostream>
#include<vector>
#include<set>
using namespace std;
#define ll long long
int mex(vector<int>ar){
    set<int>st;
    for(int i=0;i<ar.size();i++){
        st.insert(ar[i]);
    }
    for(int i=0;;i++){
        if(st.count(i)==0) return i;
    }
}
int main(){
    const int mx=1500;
        vector<int>dp(mx+1,0);
        for(int i=3;i<mx;i++){
            vector<int>v;
            for(int j=1;i-j>j;j++){
                v.push_back(dp[j]^dp[i-j]);
            }
            dp[i]=mex(v);
        }
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n>=1500){
            cout<<"first\n";continue;
        }
        if(dp[n]!=0) cout<<"first"<<"\n";
        else cout<<"second"<<"\n";
    }
}