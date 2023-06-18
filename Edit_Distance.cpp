#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


void solve() {
        string s,t;
        see(s,t);
       vector<vector<ll>>dp(s.size()+1,vector<ll>(t.size()+1,INT_MAX));
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(i==0 && j==0){
                    dp[i][j]=0;
                }else if(i==0){
                    dp[i][j] = dp[i][j-1]+1;
                }else if(j==0){
                    dp[i][j] = dp[i-1][j]+1;
                }else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j]= dp[i-1][j-1];
                    }else
                    dp[i][j]= min({dp[i][j],dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
                }
            }
        }
        
        put(dp[s.size()][t.size()]);

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
